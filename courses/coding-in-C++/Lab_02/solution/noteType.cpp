/**
 * @file Note.cpp
 * @brief Demonstrates dynamic memory management and copy semantics in C++.
 */

#include <string>
#include <iostream>

/**
 * @class Note
 * @brief Represents a note containing dynamically allocated text.
 *
 * This class demonstrates manual memory management using pointers,
 * including deep copying via a copy constructor and cleanup via destructor.
 */
class Note
{
private:
    std::string *text;

public:
    /**
     * @brief Constructs a Note with given text.
     * @param text_input The text to store in the note.
     */
    Note(std::string text_input)
    {
        text = new std::string;
        *text = text_input;
    }

    /**
     * @brief Copy constructor (deep copy) for Part2.
     * @param otherNote The Note object to copy from.
     *
     * Allocates new memory and copies the content to avoid shared ownership.
     */
    Note(const Note &otherNote)
    {
        text = new std::string;
        *text = *otherNote.text;
    }
    /**
     * @brief Destructor that releases allocated memory.
     *
     * Frees the dynamically allocated string and sets the pointer to nullptr.
     */
    ~Note()
    {
        delete text;
        text = nullptr;
        std::cout << "Memory released" << std::endl;
    }
    void display();
};

/**
 * @brief Displays the stored text.
 */
void Note::display()
{
    std::cout << *text << std::endl;
}

int main()
{
    Note note1("Meine Nachricht");
    // This assignment is possible even without a copy-constructor
    // Your compiler creates a Default Copy Constructor which
    // copies every member of object1 to object2.
    // This is called shallow-copy.
    // This approach can lead to unwanted issues
    // especially when Pointers are involved
    Note note2 = note1;

    note1.display();
    note2.display();

    return 0;
    // Part 1 explanation:
    // When leaving the main function, the lifespan of
    // the objects end. Hence, the destructor is called.
    // Problem: Both destructors try to free the same
    // allocated memory which leads to an exception which
    // should be solved by a copy-constructor.
}