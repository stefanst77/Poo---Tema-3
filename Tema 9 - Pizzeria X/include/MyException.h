#include <bits/stdc++.h>
#include <exception>

class MyException : public std::exception
{
public:
    const char* what()
    {
        return "Aceasta reteta nu exista in meniu.";
    }
};
