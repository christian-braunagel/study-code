#ifndef HEADER_HPP
#define HEADER_HPP

#include <string>

class FIA_Associative {
private:
    std::string name;
    int id;
    static int nextId;
    bool acc;
public:
    FIA_Associative(std::string name, bool acc) : name(name), acc(acc), id(++nextId) {}
    virtual void print() = 0;
    virtual ~FIA_Associative() = default;

    std::string getName() const
    {
        return this-> name;
    }

    void setName(std:: string name)
    {
        this-> name = name;
    }
    
    bool getAcc() const
    {
        return this-> acc;
    }


}; 

#endif