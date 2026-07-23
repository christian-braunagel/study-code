#include <iostream>
#include <memory>
#include <string>

class Author
{
private:
    std::string name;
    int id;

public:
    Author(const std::string &name, int id)
        : name(name), id(id)
    {
        std::cout << "Author created: " << this->name << '\n';
    }

    ~Author()
    {
        std::cout << "Author destroyed: " << this->name << '\n';
    }

    const std::string &getName() const
    {
        return name;
    }

    void setName(const std::string &newName)
    {
        name = newName;
    }

    int getId() const
    {
        return id;
    }

    void setId(int newId)
    {
        id = newId;
    }
};

class Book
{
private:
    std::string title;
    std::shared_ptr<Author> author;

public:
    Book(const std::string &title, std::shared_ptr<Author> author)
        : title(title), author(std::move(author))
    {
        std::cout << "Book created: " << this->title << '\n';
    }

    ~Book()
    {
        std::cout << "Book destroyed: " << this->title << '\n';
    }

    const std::string &getTitle() const
    {
        return title;
    }

    void setTitle(const std::string &newTitle)
    {
        title = newTitle;
    }

    std::shared_ptr<Author> getAuthor() const
    {
        return author;
    }

    void setAuthor(std::shared_ptr<Author> newAuthor)
    {
        author = std::move(newAuthor);
    }

    void printInfo() const
    {
        std::cout << '"' << title << "\" by " << author->getName() << '\n';
    }
};

void lendBook(std::unique_ptr<Book> book)
{
    std::cout << "Lending book: ";
    book->printInfo();
}

int main()
{
    auto author = std::make_shared<Author>("Bjarne Stroustrup", 1);

    auto firstBook = std::make_unique<Book>("A Tour of C++", author);
    auto secondBook = std::make_unique<Book>("The C++ Programming Language", author);

    std::cout << "Author reference count: " << author.use_count() << '\n';

    lendBook(std::move(firstBook));

    if (firstBook == nullptr)
    {
        std::cout << "The first book is no longer available in the catalog.\n";
    }

    lendBook(std::move(secondBook));

    if (secondBook == nullptr)
    {
        std::cout << "The second book is no longer available in the catalog.\n";
    }

    std::cout << "Author reference count: " << author.use_count() << '\n';

    return 0;
}
