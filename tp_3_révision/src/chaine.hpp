#ifndef CHAINE_HPP_38703
#define CHAINE_HPP_38703

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <typeinfo>
#include "demangle.hpp"


class ExceptionChaine : public std::exception {
    private:
        std::string typeName;
        std::string message;
    public:
        template <typename T> 
        ExceptionChaine(const T &) {
            typeName = demangle(typeid(T).name());
            message = "Conversion en chaine impossible pour '" + typeName + "'"; 
        }

        const char * what() const noexcept   override {
            return message.c_str();
        }
};

template <typename T>
std::string chaine(const T & valeur) {
    try {
        throw ExceptionChaine(valeur);
    } catch(const std::exception& e) {
        throw;
    }
};

std::string chaine(const std::string & valeur) {
    return valeur;
};

std::string chaine(int i) {
    std::stringstream cout;
    cout << i;
    return cout.str();
};

std::string chaine(double d) {
    return std::to_string(d);
};


#endif