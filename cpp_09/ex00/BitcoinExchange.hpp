#pragma once

#include <map>
#include <string>

// BitcoinExchange: loads a CSV price database and evaluates
// a user-provided input file of (date | amount) lines.
class BitcoinExchange
{
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    // Load BTC price history from a CSV file (format: date,exchange_rate)
    void loadDatabase(const std::string &filename);

    // Read input file and print evaluated results
    void processInput(const std::string &filename) const;

private:
    // std::map is used here (sorted by date string — ISO format is lexicographically ordered)
    std::map<std::string, double> _db;

    // Returns true if date string is a valid YYYY-MM-DD date
    bool isValidDate(const std::string &date) const;

    // Find the price on or before the given date (closest lower bound)
    double getPriceOnDate(const std::string &date) const;
};
