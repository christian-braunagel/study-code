#include <iostream>
#include <string>
#include <stdexcept>

class ConfigError : public std::logic_error
{
public:
    ConfigError(std::string message) : std::logic_error(message) {};
};

class ConfigLoader
{
public:
    bool load(std::string filename)
    {
        if (filename.empty())
        {
            throw std::invalid_argument("Filename is empty.");
        }

        if (filename.length() < 4 ||
            filename.substr(filename.length() - 4) != ".cfg")
        {
            throw std::invalid_argument("File is not a .cfg-format.");
        }

        if (filename == "missing.cfg")
        {
            throw std::runtime_error("File not found.");
        }

        if (filename == "invalid.cfg")
        {
            throw ConfigError("Invalid parameters for configuration file");
        }

        return true;
    }
};

int main()
{

    ConfigLoader loader;

    // good path
    if (loader.load("test.cfg"))
    {
        std::cout << "Good path is working" << std::endl;
    }

    try
    {
        loader.load("");
    }
    catch (const std::invalid_argument &exception)
    {
        std::cout << "Catch-Block 1: " << exception.what() << std::endl;
    }

    try
    {
        loader.load("test.txt");
    }
    catch (const std::invalid_argument &exception)
    {
        std::cout << "Catch-Block 2: " << exception.what() << std::endl;
    }

    try
    {
        loader.load("missing.cfg");
    }
    catch (const std::runtime_error &exception)
    {
        std::cout << "Catch-Block 3: " << exception.what() << std::endl;
    }

    try
    {
        loader.load("invalid.cfg");
    }
    catch (const std::logic_error &exception)
    {
        std::cout << "Catch-Block 4: " << exception.what() << std::endl;
    }
    // catches all remaining exceptions
    catch (const std::exception &exception)
    {
        std::cout << "Gonna catch em all: " << exception.what() << std::endl;
    }
}