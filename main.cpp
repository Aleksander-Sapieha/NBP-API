#include "api.h"
#include <iostream>
using json = nlohmann::json;

int main() {

    json g = nbp::getCurrentGoldPrice();
    if (!g.empty() && g.is_array()) {
        std::cout << "Gold current: " << g[0]["cena"].get<double>() << "\n";
    } else {
        std::cout << "No gold price available.\n";
    }


    auto eur = nbp::getTodayCurrency("A","EUR");
    std::cout << eur.dump(2) << "\n";

    auto usdInterval = nbp::getCurrencyInterval("A", "USD", "2025-07-01", "2025-07-31");
    std::cout << usdInterval.dump(2) << "\n";

    auto tables = nbp::getLastNTables("A", 3);
    std::cout << tables.dump(2) << "\n";

    auto goldHist = nbp::getGoldPricesInterval("2025-07-01","2025-07-07");
    std::cout << goldHist.dump(2) << "\n";

    return 0;
}
