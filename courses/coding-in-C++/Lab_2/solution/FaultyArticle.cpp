// Problem: File header is missing.
// Why: Reduces readability of the file and violates the coding conventions.
#include <iostream>
#include <string>
#include <iomanip>
// Problem: <iomanip> is never used.
// Why: It increases the project size and reduces readability for no reason.
using namespace std;
// Problem: "using namespace std;" is discouraged by the coding conventions.
// Why: It pollutes the global namespace and can cause name conflicts in larger projects.

class Article
{
public:
    string name;
    // Problem: Member variable is public.
    // Why: This breaks encapsulation because external code can modify the internal state directly.

    double price;
    // Problem: Member variable is public.
    // Why: External code can assign invalid values such as negative prices.

    int stock;
    // Problem: Member variable is public.
    // Why: External code can set invalid stock values and bypass validation logic.

    string *category;
    // Problem: Raw pointer used for std::string although dynamic allocation is unnecessary here.
    // Why: This complicates the design and introduces manual memory management risks.

    int id;
    // Problem: Member variable is public.
    // Why: External code can modify the article id directly, which breaks encapsulation
    // and may violate consistency rules for object identity.

    // Problem: Missing method documentation
    //  Why: Reduces readability of the file and violates the coding conventions.
    Article(string name, double price, int stock, string category, int id)
    {
        name = name;
        // Problem: The parameter assigns to itself, not to the member variable.
        // Why: The member 'name' remains uninitialized because the parameter shadows it.

        price = price;
        // Problem: Same shadowing issue as above.
        // Why: The member 'price' is not initialized correctly.

        stock = stock;
        // Problem: Same shadowing issue as above.
        // Why: The member 'stock' is not initialized correctly.

        this->id = id;

        this->category = new string;
        // Problem: Dynamic allocation is unnecessary for a normal string member.
        // Why: This increases complexity and requires a destructor to avoid memory leaks.

        *this->category = category;
    }

    void setPrice(double price)
    {
        price = price;
        // Problem: Again the parameter assigns to itself.
        // Why: The member 'price' is never updated.
    }

    void sell(int amount)
    {
        stock = stock - amount;
        // Problem: No validation of amount and no stock check.
        // Why: Negative or too-large values can create an invalid object state.
    }

    void restock(int amount)
    {
        this->stock += amount;
        // Problem: No validation of amount.
        // Why: A negative restock value effectively reduces stock and breaks intended behavior.
    }

    double applyDiscount(double percent)
    {
        price = price - price * percent / 100;
        // Problem: No validation of the discount percentage.
        // Why: Values above 100 or below 0 can lead to nonsensical prices.

        return price;
    }

    double getPrice()
    {
        return price;
        // Problem: Method is not marked const.
        // Why: It does not modify the object and should express read-only intent.
    }

    bool isAvailable()
    {
        if (stock > 0)
            return true;
        else
            return false;
        // Problem: Missing braces violate the formatting rules.
        // Why: Omitting braces reduces readability and increases error risk in maintenance.

        // Problem: The logic is unnecessarily verbose.
        // Why: "return stock > 0;" would be clearer and simpler.
    }

    void printInfo()
    {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
        // Problem: Method is not marked const.
        // Why: It only reads object state and should therefore be a const member function.
    }
    // Problem: No destructor is defined.
    // Why: The dynamically allocated string in 'category' is never deleted, causing a memory leak.
};

int main()
{
    Article a("Laptop", 999.99, 10, "Electronics", 101);
    // Problem: Magic numbers are used directly.
    // Why: Unnamed values reduce readability and intent compared to named constants.

    a.sell(15);
    // Problem: Selling more than available stock is allowed.
    // Why: This can produce a negative stock value.

    a.restock(-5);
    // Problem: Negative restocking is accepted.
    // Why: This makes the method semantically incorrect.

    a.price = -100;
    // Problem: Direct write access to a public member bypasses validation.
    // Why: The object can enter an invalid state with a negative price.

    a.applyDiscount(150);
    // Problem: A discount above 100% is accepted.
    // Why: This may result in a negative or otherwise invalid price.

    if (a.isAvailable())
        cout << "Article available" << endl;
    // Problem: Missing braces around if body.
    // Why: This violates the formatting conventions and harms readability.

    a.printInfo();
}

// Part 3: Answers to the questions

// 1. Why is the use of new for the category attribute problematic in this case?
// The use of new is problematic because dynamic memory allocation is not needed here.
// category is just a normal string value that can be stored directly as std::string.
// Using new makes the design more complex, requires manual memory management,
// and introduces the risk of memory leaks if delete is forgotten.

// 2. What could happen if multiple objects of this class are copied?
// If multiple objects are copied, the default copy constructor would copy the pointer value only.
// This means both objects would point to the same dynamically allocated string.
// As a result, changing the category through one object would also affect the other object.
// In addition, if a destructor were added later, both objects might try to delete the same memory,
// which could cause undefined behavior such as a double delete.

// 3. Why should some methods be marked as const?
// Some methods should be marked as const because they do not modify the object state.
// Marking them const expresses read-only intent, improves safety,
// and allows these methods to be called on const objects.
// Typical examples in this class are getPrice(), isAvailable(), and printInfo().

// 4. What risks arise from allowing direct access to price and stock?
// Direct access to price and stock breaks encapsulation.
// External code can assign invalid values, for example a negative price or negative stock.
// This bypasses validation rules and may put the object into an invalid state.
// As a result, the class can no longer guarantee correct and predictable behavior.