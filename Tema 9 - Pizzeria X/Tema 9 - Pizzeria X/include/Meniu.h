#include <bits/stdc++.h>
#include <MyException.h>
#include <vector>
#include <unordered_map>
#include <algorithm>
/**
    'Lista' retetelor contine (numar de ordine, ingrediente: denumire, cantitate, pret)
    Lista de comanzi contine (numarul corespunzator retetei din 'lista' de retete
                              si un pointer la Pizza sau PVegetariana)
*/
/// ajuta la crearea 'listei' de retete
class Ingrediente
{
public:
    std::string denumire;
    int cantitate;
    int pretCantitate;
};
/// ajuta la crearea listei de comenzi
template <class pizza>
struct Comanda
{
    int nrReteta;
    pizza* pointer;
};

template <typename pizza, typename pizzaVeg>
class Meniu
{
public:
    std::unordered_map <int, std::vector <Ingrediente> > retete;
    std::vector <Comanda <pizza> > comenzi;
    int sumaPizzaVeg = 0; /// suma rez. din vanz. PVegetariana
    int cnt = 0; /// contorul pentru comenzi

    //Meniu() {}

    Meniu()
    {
        std::ifstream fin ("text.in");
        int nrRetete, nrIngrediente;
        fin >> nrRetete;
        for (int i = 1; i <= nrRetete; i++)
        {
            fin >> nrIngrediente;
            std::vector <Ingrediente> reteta;
            for (int j = 1; j <= nrIngrediente; j++)
            {
                Ingrediente aux;
                fin >> aux.denumire >> aux.cantitate >> aux.pretCantitate;
                reteta.push_back(aux);
            }
            retete.insert({i, reteta});
        }
        fin.close();
    }

    ~Meniu()
    {
        for (int i = 0; i < int(comenzi.size()); i++)
            delete(comenzi[i].pointer);
        ///std::cout << "Meniu sters.";
    }

    void cumpar_pizza(pizza& p)
    {
        try
        {
            if (retete.find(p.get_nrReteta()) == retete.end())
                throw MyException();
        }
        catch (MyException ceva)
        {
            std::cout << ceva.what();
        }

        int pretul = 0;
        for (int i = 0; i < int(retete[p.get_nrReteta()].size()); i++)
            pretul += retete[p.get_nrReteta()][i].cantitate * retete[p.get_nrReteta()][i].pretCantitate;
        p.set_pret(pretul);
        Comanda<pizza> aux;
        aux.nrReteta = ++cnt;
        aux.pointer = new pizzaVeg;
        *aux.pointer = p;
        comenzi.push_back(aux);
    }

    void cumpar_pizza(pizzaVeg& p)
    {
        try
        {
            if (retete.find(p.get_nrReteta()) == retete.end())
                throw MyException();
        }
        catch (MyException ceva)
        {
            std::cout << ceva.what();
        }

        int pretul = 0;
        for (int i = 0; i < int(retete[p.get_nrReteta()].size()); i++)
            pretul += retete[p.get_nrReteta()][i].cantitate * retete[p.get_nrReteta()][i].pretCantitate;
        p.set_pret(pretul);
        Comanda<pizza> aux;
        aux.nrReteta = ++cnt;
        aux.pointer = new pizzaVeg;
        *aux.pointer = p;
        comenzi.push_back(aux);
        sumaPizzaVeg += p.get_pretVeg();
    }

    void print_comenzi()
    {
        for (int i = 0; i < int(comenzi.size()); i++)
        {
            std::cout << "Comanda numarul: (" << (i + 1) << ") este reteta ";
            std::cout << comenzi[i].nrReteta << " care contine: (nr_reteta, distanta, pret)\n";
            std::cout << *comenzi[i].pointer;
        }
    }

    void operator += (int id)
    {
        try
        {
            if (retete.find(id) == retete.end())
                throw MyException();
        }
        catch (MyException ceva)
        {
            std::cout << ceva.what();
        }

        int pretul = 0;
        for (int i = 0; i < retete[id].size(); i++)
            pretul += retete[id][i].cantitate * retete[id][i].pretCantitate;
        Comanda<pizza> aux;
        aux.nrReteta = ++cnt;
        aux.pointer = new pizza(id, 0, pretul);
        comenzi.push_back(aux);
        return;
    }

    Meniu& operator= (const Meniu& p)
    {
        retete = p.retete;
    }
};

template <typename pizza, class pizzaVeg>
std::ostream& operator<< (std::ostream& out, Meniu<pizza, pizzaVeg>& meniu)
{
    /**
    for (auto i : meniu.retete))
    {
        out << "Reteta numarul: " << i.first << "\n";
        for (int j = 0; j < int(i.second.size()); j++)
            out << i.second[j].denumire << " " << i.second[j].cantitate << " " << i.second[j].pretCantitate << "\n";
        out << "\n";
    }
    */
    for (auto i = meniu.retete.begin(); i != meniu.retete.end(); i++)
    {
        out << "Reteta numarul: " << i->first << "\n";
        for (int j = 0; j < int(i->second.size()); j++)
            out << i->second[j].denumire << " " << i->second[j].cantitate << " " << i->second[j].pretCantitate << "\n";
        out << "\n";
    }

    return out;
}

