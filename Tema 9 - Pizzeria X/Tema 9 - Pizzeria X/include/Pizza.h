#include <bits/stdc++.h>
#include <ClasaBaza.h>

class Pizza : public ClasaBaza
{
    static int nrPizza;
protected:
    static int manopera;
    int nrReteta;/// a cata reteta din meniu este
    int distanta;/// distanta unde se afla clientul
    int pret;/// pretul pizzei
public:
    Pizza(int nrReteta = 0, int distanta = 0, int pret = 0);
    Pizza(const Pizza &other);
    virtual ~Pizza();

    int calcul_Pret();
    int get_nrPizza() { return nrPizza; };
    void set_pret(int ppret) { pret = ppret; }
    int get_nrReteta() { return nrReteta; }
    int get_pret() { return pret; }
    virtual void tip_Pizza() { std::cout << "Pizza simpla.\n"; }

    friend std::istream& operator>> (std::istream& , Pizza&);
    friend std::ostream& operator<< (std::ostream& , Pizza&);
    Pizza& operator= (const Pizza&);
};

