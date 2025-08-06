#ifndef _API
#define _API
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

namespace nbp{
    using json = nlohmann::json;

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
} // namespace nbp

#endif // _API