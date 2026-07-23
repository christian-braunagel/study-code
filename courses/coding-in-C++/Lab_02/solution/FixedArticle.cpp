/**
 * @file article.cpp
 * @brief Corrected implementation of the class Article.
 *
 * This version fixes the design, logic, and style issues of the faulty example.
 * The class protects its internal state, validates input values, and follows
 * the given C++ coding conventions.
 */

#include <iostream>
#include <string>

class Article
{
private:
    std::string name;
    double price;
    int stock;
    std::string category;
    int id;

public:
    /**
     * @brief Constructs a new Article object.
     *
     * Creates an article with name, price, stock, category, and id.
     * Invalid negative values for price and stock are corrected to safe defaults.
     *
     * @param[in] article_name     Name of the article
     * @param[in] article_price    Price of the article
     * @param[in] article_stock    Available stock
     * @param[in] article_category Category of the article
     * @param[in] article_id       Unique article id
     */
    Article(const std::string &article_name,
            double article_price,
            int article_stock,
            const std::string &article_category,
            int article_id);

    /**
     * @brief Sets a new price for the article.
     *
     * The price is only changed if the given value is valid.
     *
     * @param[in] new_price New article price
     * @return              True if the price was updated, otherwise false
     */
    bool set_price(double new_price);

    /**
     * @brief Reduces the stock after a sale.
     *
     * A sale is only possible if the amount is positive and enough stock exists.
     *
     * @param[in] amount Number of items to sell
     * @return           True if the sale was successful, otherwise false
     */
    bool sell(int amount);

    /**
     * @brief Increases the stock of the article.
     *
     * The stock is only increased if the amount is positive.
     *
     * @param[in] amount Number of items to add
     * @return           True if the stock was updated, otherwise false
     */
    bool restock(int amount);

    /**
     * @brief Applies a percentage discount to the current price.
     *
     * The percentage must be in the range from 0.0 to 100.0.
     *
     * @param[in] percent Discount percentage
     * @return            True if the discount was applied, otherwise false
     */
    bool apply_discount(double percent);

    /**
     * @brief Returns the current price.
     *
     * @return Current article price
     */
    double get_price() const
    {
        return price;
    }

    /**
     * @brief Returns the current stock.
     *
     * @return Current stock value
     */
    int get_stock() const
    {
        return stock;
    }

    /**
     * @brief Returns the article id.
     *
     * @return Article id
     */
    int get_id() const
    {
        return id;
    }

    /**
     * @brief Returns the article name.
     *
     * @return Constant reference to the article name
     */
    const std::string &get_name() const
    {
        return name;
    }

    /**
     * @brief Returns the article category.
     *
     * @return Constant reference to the article category
     */
    const std::string &get_category() const
    {
        return category;
    }

    /**
     * @brief Checks whether the article is available.
     *
     * An article is available if at least one item is in stock.
     *
     * @return True if stock is greater than zero, otherwise false
     */
    bool is_available() const
    {
        return stock > 0;
    }

    /**
     * @brief Prints all article information to the console.
     */
    void print_info() const;
};

Article::Article(const std::string &article_name,
                 double article_price,
                 int article_stock,
                 const std::string &article_category,
                 int article_id)
    : name(article_name),
      price(article_price),
      stock(article_stock),
      category(article_category),
      id(article_id)
{
    if (price < 0.0)
    {
        price = 0.0;
    }

    if (stock < 0)
    {
        stock = 0;
    }
}

bool Article::set_price(double new_price)
{
    if (new_price < 0.0)
    {
        return false;
    }

    price = new_price;
    return true;
}

bool Article::sell(int amount)
{
    if (amount <= 0)
    {
        return false;
    }

    if (amount > stock)
    {
        return false;
    }

    stock -= amount;
    return true;
}

bool Article::restock(int amount)
{
    if (amount <= 0)
    {
        return false;
    }

    stock += amount;
    return true;
}

bool Article::apply_discount(double percent)
{
    if ((percent < 0.0) || (percent > 100.0))
    {
        return false;
    }

    price = price - (price * percent / 100.0);
    return true;
}

void Article::print_info() const
{
    std::cout << "Article: " << name << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Price: " << price << std::endl;
    std::cout << "Stock: " << stock << std::endl;
    std::cout << "ID: " << id << std::endl;
}

int main()
{
    const double initial_price = 999.99;
    const int initial_stock = 10;
    const int article_id = 101;
    const int sell_amount = 5;
    const int restock_amount = 3;
    const double discount_percent = 10.0;

    Article article("Laptop",
                    initial_price,
                    initial_stock,
                    "Electronics",
                    article_id);

    const bool sell_success = article.sell(sell_amount);
    const bool restock_success = article.restock(restock_amount);
    const bool discount_success = article.apply_discount(discount_percent);

    if (sell_success)
    {
        std::cout << "Sell operation successful." << std::endl;
    }
    else
    {
        std::cout << "Sell operation failed." << std::endl;
    }

    if (restock_success)
    {
        std::cout << "Restock operation successful." << std::endl;
    }
    else
    {
        std::cout << "Restock operation failed." << std::endl;
    }

    if (discount_success)
    {
        std::cout << "Discount applied successfully." << std::endl;
    }
    else
    {
        std::cout << "Discount application failed." << std::endl;
    }

    if (article.is_available())
    {
        std::cout << "Article available" << std::endl;
    }
    else
    {
        std::cout << "Article not available" << std::endl;
    }

    article.print_info();

    return 0;
}