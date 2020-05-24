#include "Pizza.h"

Pizza::Pizza(int nrReteta, int distanta, int pret) :
    nrReteta(nrReteta), distanta(distanta), pret(pret)
{
    nrPizza++;
}

Pizza::Pizza(const Pizza &other)
{
    nrReteta = other.nrReteta;
    distanta = other.distanta;
    pret = other.pret;
    nrPizza++;
}

Pizza::~Pizza()
{
    nrPizza--;
}

int Pizza::nrPizza{0};

int Pizza::calcul_Pret()
{
    return pret * (1 + distanta * 0.5) + manopera;
}

std::istream& operator>> (std::istream& in, Pizza& p)
{
    in >> p.nrReteta >> p.distanta >> p.pret;
    return in;
}

std::ostream& operator<< (std::ostream& out, Pizza& p)
{
    out << p.nrReteta << " ";
    out << p.distanta << " ";
    out << p.pret << "\n";
    return out;
}

Pizza& Pizza::operator=(const Pizza& p)
{
    this->nrReteta = p.nrReteta;
    this->distanta = p.distanta;
    this->pret = p.pret;
    return *this;
}

