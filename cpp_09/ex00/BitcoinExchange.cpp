#include "BitcoinExchange.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cctype>

// ── Orthodox Canonical Form ───────────────────────────────────────────────────

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _db(other._db) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _db = other._db;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// ── Database loading ──────────────────────────────────────────────────────────

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database: " + filename);

    std::string line;
    std::getline(file, line); // skip header line "date,exchange_rate"

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        // Split on comma
        size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;

        std::string date = line.substr(0, comma);
        std::string rateStr = line.substr(comma + 1);

        // Parse rate, skip malformed lines
        try
        {
            double rate = std::stod(rateStr);
            _db[date] = rate;
        }
        catch (...)
        {
            continue;
        }
    }

    if (_db.empty())
        throw std::runtime_error("Error: database is empty or unreadable.");
}

// ── Date validation ───────────────────────────────────────────────────────────

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    // Must be exactly "YYYY-MM-DD" = 10 characters
    if (date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;

    // All other chars must be digits
    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int year  = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day   = std::stoi(date.substr(8, 2));

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;

    // Days per month (index 0 = January)
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Leap year check
    bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (leap)
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

// ── Price lookup ──────────────────────────────────────────────────────────────

double BitcoinExchange::getPriceOnDate(const std::string &date) const
{
    // upper_bound gives the first entry AFTER date;
    // stepping back one gives the closest date <= date.
    auto it = _db.upper_bound(date);

    if (it == _db.begin())
        throw std::runtime_error("Error: date is before the earliest record.");

    --it;
    return it->second;
}

// ── Input processing ──────────────────────────────────────────────────────────

// Trim leading and trailing whitespace in-place
static void trim(std::string &s)
{
    size_t start = s.find_first_not_of(" \t\r\n");
    size_t end   = s.find_last_not_of(" \t\r\n");
    s = (start == std::string::npos) ? "" : s.substr(start, end - start + 1);
}

void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // skip header "date | value"

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        // Require " | " separator
        size_t sep = line.find(" | ");
        if (sep == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }

        std::string date     = line.substr(0, sep);
        std::string valueStr = line.substr(sep + 3);
        trim(date);
        trim(valueStr);

        // Validate date format
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }

        // Parse the numeric value
        double value;
        try
        {
            size_t pos;
            value = std::stod(valueStr, &pos);
            // Reject if there are trailing non-numeric characters
            if (pos != valueStr.size())
            {
                std::cerr << "Error: bad input => " << line << "\n";
                continue;
            }
        }
        catch (...)
        {
            std::cerr << "Error: bad input => " << line << "\n";
            continue;
        }

        // Range checks
        if (value < 0.0)
        {
            std::cerr << "Error: not a positive number.\n";
            continue;
        }
        if (value > 1000.0)
        {
            std::cerr << "Error: too large a number.\n";
            continue;
        }

        // Lookup price and display result
        try
        {
            double price = getPriceOnDate(date);
            std::cout << date << " => " << value << " = " << value * price << "\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << "\n";
        }
    }
}
