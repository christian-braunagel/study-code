#include <string>
#include <iostream>

class Note
{
private:
    std::string *text;

public:
    // Parameterized constructor
    Note(std::string text_input)
    {
        text = new std::string;
        *text = text_input;
    }
    // Copy-Constructor for Part2
    Note(const Note &otherNote)
    {
        text = new std::string;
        *text = *otherNote.text;
    }
    // destructor to delete text memory
    ~Note()
    {
        delete text;
        text = NULL;
        std::cout << "Memory released" << std::endl;
    }
    void display();
};

void Note::display()
{
    std::cout << *text << std::endl;
}

int main()
{
    Note note1("Meine Nachricht");
    Note note2 = note1;

    note1.display();
    note2.display();

    return 0;
    // Part 1 explanation:
    // When leaving the main function, the lifespan of
    // the objects end. Hence, the destructor is called.
    // Problem: Both destructors try to free the same
    // allocated memory which leads to an exception
}