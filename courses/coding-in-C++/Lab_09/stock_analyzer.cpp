#include <iostream>
#include <string>
#include <vector>

struct Stock
{
    std::string symbol;
    std::string market;
    std::vector<double> prices;
};

class StockAnalyzer
{
private:
    std::vector<Stock> stocks;

public:
    void add_tech_stock(const std::string &symbol)
    {
        stocks.push_back({symbol, "Tech", {}});
    }

    void add_energy_stock(const std::string &symbol)
    {
        stocks.push_back({symbol, "Energy", {}});
    }

    void add_bank_stock(const std::string &symbol)
    {
        stocks.push_back({symbol, "Bank", {}});
    }

    void add_price(const std::string &symbol, double price)
    {
        for (Stock &stock : stocks)
        {
            if (stock.symbol == symbol)
            {
                stock.prices.push_back(price);
            }
        }
    }

    void print_report()
    {
        std::cout << "=== Stock Report ===" << std::endl;

        for (const Stock &stock : stocks)
        {
            if (stock.prices.empty())
            {
                std::cout << stock.symbol << ": no prices available" << std::endl;
                continue;
            }

            double sum = 0.0;
            double min = stock.prices[0];
            double max = stock.prices[0];

            for (double price : stock.prices)
            {
                sum += price;

                if (price < min)
                {
                    min = price;
                }

                if (price > max)
                {
                    max = price;
                }
            }

            double average = sum / stock.prices.size();

            std::cout << "Symbol: " << stock.symbol << std::endl;
            std::cout << "Market: " << stock.market << std::endl;
            std::cout << "Average: " << average << std::endl;
            std::cout << "Minimum: " << min << std::endl;
            std::cout << "Maximum: " << max << std::endl;

            if (stock.market == "Tech")
            {
                if (average > 150.0)
                {
                    std::cout << "Recommendation: Hold tech stock" << std::endl;
                }
                else
                {
                    std::cout << "Recommendation: Buy tech stock" << std::endl;
                }
            }
            else if (stock.market == "Energy")
            {
                if (average > 80.0)
                {
                    std::cout << "Recommendation: Sell energy stock" << std::endl;
                }
                else
                {
                    std::cout << "Recommendation: Hold energy stock" << std::endl;
                }
            }
            else if (stock.market == "Bank")
            {
                if (average > 60.0)
                {
                    std::cout << "Recommendation: Hold bank stock" << std::endl;
                }
                else
                {
                    std::cout << "Recommendation: Buy bank stock" << std::endl;
                }
            }

            std::cout << std::endl;
        }
    }

    void export_as_csv()
    {
        std::cout << "symbol,market,average,min,max" << std::endl;

        for (const Stock &stock : stocks)
        {
            if (stock.prices.empty())
            {
                continue;
            }

            double sum = 0.0;
            double min = stock.prices[0];
            double max = stock.prices[0];

            for (double price : stock.prices)
            {
                sum += price;

                if (price < min)
                {
                    min = price;
                }

                if (price > max)
                {
                    max = price;
                }
            }

            double average = sum / stock.prices.size();

            std::cout << stock.symbol << ","
                      << stock.market << ","
                      << average << ","
                      << min << ","
                      << max << std::endl;
        }
    }
};

int main()
{
    StockAnalyzer analyzer;

    analyzer.add_tech_stock("AAPL");
    analyzer.add_energy_stock("XOM");
    analyzer.add_bank_stock("JPM");

    analyzer.add_price("AAPL", 145.0);
    analyzer.add_price("AAPL", 152.0);
    analyzer.add_price("AAPL", 158.0);

    analyzer.add_price("XOM", 75.0);
    analyzer.add_price("XOM", 83.0);

    analyzer.add_price("JPM", 55.0);
    analyzer.add_price("JPM", 64.0);

    analyzer.print_report();

    std::cout << "=== CSV Export ===" << std::endl;
    analyzer.export_as_csv();

    return 0;
}