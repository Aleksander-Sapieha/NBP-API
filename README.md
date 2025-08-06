# NBP API C++ Wrapper

A simple C++ wrapper for the NBP API to fetch gold prices and currency exchange rates using cpr for HTTP requests and nlohmann/json for JSON parsing.
Features

    Get current gold price

    Get gold price for a specific date or date range

    Get today's currency exchange rates tables (A, B, or C)

    Fetch historical currency exchange rates for a specified period

    Simple JSON interface using nlohmann::json

### Requirements

    C++17 compatible compiler

    cpr — C++ HTTP client library

    nlohmann/json — JSON for Modern C++

### Installation

    Install dependencies (cpr and nlohmann/json) using your package manager or build from source.

    Clone this repository.

    Compile your code including api.cpp and main.cpp linking with cpr.

### Usage

    #include "api.h"
    #include <iostream>
    
    int main() {
        auto goldPriceJson = nbp::getCurrentGoldPrice();
    
        if (!goldPriceJson.empty() && goldPriceJson.is_array()) {
            std::cout << "Current gold price: " << goldPriceJson[0]["cena"].get<double>() << " PLN\n";
        } else {
            std::cerr << "Failed to fetch gold price.\n";
        }
    
        auto rates = nbp::getTodaysExchangeRates("A");
        std::cout << rates.dump(2) << std::endl;
    
        return 0;
    }
### API Functions

    json getCurrentGoldPrice();

    json getTodayGoldPrice();

    json getGoldPriceByDate(const std::string& date);

    json getGoldPricesInterval(const std::string& from, const std::string& to);

    json getLastNGoldPrices(int n);

    json getCurrentTable(const std::string& table = "A");

    json getTodayTable(const std::string& table = "A");

    json getTableByDate(const std::string& table, const std::string& date);

    json getTablesInterval(const std::string& table, const std::string& from, const std::string& to);

    json getLastNTables(const std::string& table, int n);

    json getCurrentCurrency(const std::string& table, const std::string& code);
    
    json getTodayCurrency(const std::string& table, const std::string& code);

    json getCurrencyByDate(const std::string& table, const std::string& code, const std::string& date);

    json getCurrencyInterval(const std::string& table, const std::string& code, const std::string& from, const std::string& to);
        
    json getLastNCurrency(const std::string& table, const std::string& code, int n);

### License

MIT License
