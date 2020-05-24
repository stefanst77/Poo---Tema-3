#include <bits/stdc++.h>
#include <Pizza.h>

class PVegetariana : public Pizza
{
public:
    PVegetariana(int nrReteta = 0, int distanta = 0, int pret = 0) :
        Pizza(nrReteta, distanta, pret) {}
    PVegetariana(const PVegetariana &other) : Pizza(other) {}
    virtual void tip_pizza() { std::cout << "Pizza vegetariana.\n"; }
    int calcul_Pret();
    int get_pretVeg() { return pret; }
};
