#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <iostream>
#include <string>

using json = nlohmann::json;

namespace nbp {

 // -- Gold price endpoints --

    json getCurrentGoldPrice() {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/cenyzlota"});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Error: " << r.status_code << "\n"; return {};
    }

    json getTodayGoldPrice() {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/cenyzlota/today"});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "No data today: " << r.status_code << "\n"; return {};
    }

    json getGoldPriceByDate(const std::string& date) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/cenyzlota/" + date});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Error for date: " << r.status_code << "\n"; return {};
    }

    json getGoldPricesInterval(const std::string& from, const std::string& to) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/cenyzlota/" + from + "/" + to});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Interval error: " << r.status_code << "\n"; return {};
    }

    json getLastNGoldPrices(int n) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/cenyzlota/last/" + std::to_string(n)});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Last N error: " << r.status_code << "\n"; return {};
    }

    // -- Exchange rate table endpoints --

    json getCurrentTable(const std::string& table = "A") {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/tables/" + table + "/"});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Error current table: " << r.status_code << "\n"; return {};
    }

    json getTodayTable(const std::string& table = "A") {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/tables/" + table + "/today"});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Today table not available\n"; return {};
    }

    json getTableByDate(const std::string& table, const std::string& date) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/tables/" + table + "/" + date});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Table by date error\n"; return {};
    }

    json getTablesInterval(const std::string& table, const std::string& from, const std::string& to) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/tables/" + table + "/" + from + "/" + to});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Tables interval error\n"; return {};
    }

    json getLastNTables(const std::string& table, int n) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/tables/" + table + "/last/" + std::to_string(n)});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Last N tables error\n"; return {};
    }

    // -- Specific currency endpoints --

    json getCurrentCurrency(const std::string& table, const std::string& code) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/rates/" + table + "/" + code + "/"});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Currency current error\n"; return {};
    }

    json getTodayCurrency(const std::string& table, const std::string& code) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/rates/" + table + "/" + code + "/today"});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Currency today not published yet\n"; return {};
    }

    json getCurrencyByDate(const std::string& table, const std::string& code, const std::string& date) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/rates/" + table + "/" + code + "/" + date});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Currency by date error\n"; return {};
    }

    json getCurrencyInterval(const std::string& table, const std::string& code, const std::string& from, const std::string& to) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/rates/" + table + "/" + code + "/" + from + "/" + to});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Currency interval error\n"; return {};
    }

    json getLastNCurrency(const std::string& table, const std::string& code, int n) {
        auto r = cpr::Get(cpr::Url{"https://api.nbp.pl/api/exchangerates/rates/" + table + "/" + code + "/last/" + std::to_string(n)});
        if (r.status_code == 200) return json::parse(r.text);
        std::cerr << "Last N currency error\n"; return {};
    }

} // namespace nbp
