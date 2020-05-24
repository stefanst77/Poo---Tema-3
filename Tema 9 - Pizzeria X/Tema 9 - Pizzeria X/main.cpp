#include <bits/stdc++.h>
#include <PVegetariana.h>
#include <Meniu.h>
/**
Pizzeria X testează un nou soft, dezvoltat în maniera OOP, pentru gestionarea
activității sale.

(1) Codul propriu-zis contine o clasa abstracta care contine doar metoda virtuala
pura de calcul al prețului unui produs, iar din aceasta clasa deriva clasa Pizza.

(2) În realizarea oricărui produs intra un anumit număr de ingrediente pentru care
se cunosc denumirile, cantitatile și prețul unitar.

(3) Prețul unui produs finit este data de prețul ingredientelor plus manopera
(o suma constanta fixată de producător).

(4) Daca pizza este comandata OnLine, la preț se mai adaugă și 5% din pret la fiecare
10 km parcursi de angajatul care livrează la domiciliu.

(5) Structura de date: unordered_map sau unordered_set <id_pizza, list sau vector
<ingredient>>


Cerința suplimentară:

(6) - Să se adauge toate campurile relevante pentru modelarea acestei probleme.

(7) - Să se construiască clasa template Meniu care sa gestioneze tipurie de pizza comercializate.
Clasa trebuie sa contina indexul unui produs (incrementat automat la vanzarea unui produs
prin supraincarcarea operatorului +=) și o structură de date, alocata dinamic.

(8)- Să se construiască o specializare pentru tipul Comanda_Online care sa trateze tipurile de
pizza vegetariana într-un document contabil separat din care sa rezulte valoarea totala
incasata din vanzarea acestora.

CLASE:

(1) - clasa abstracta 'ClasaBaza':
        - am doar metoda virtuala pura pentru calcularea pretului unui produs
class ClasaBaza()

(4) -  clasa 'Pizza':
        - practic clasa 'Comanda_Online' din cerinta
        - nrRetera
        - distanta
        - pret
class Pizza(nrReteta, distanta, pret) : ClasaBaza

(8) - clasa 'PVegetala'

(2) + (3) + (5) + (7) - template <> class 'Meniu':
        - avem clasele 'Ingrediente' si 'comanda' de unde vin si unordered_map-ul si vector-ul
        - prezinta structuti, functii, clase template
class Meniu(retete, comenzi, sumaPizzaVeg, cnt)
*/

int Pizza::manopera = 15;

void afisare_meniu()
{
    std::cout << "(1) Afiseaza lista de retete.\n";
    std::cout << "(2) Cumpara pizza.\n";
    std::cout << "(3) Cumpara pizza vegetariana.\n";
    std::cout << "(4) Afiseaza comenzile.\n";
    std::cout << "(5) Afiseaza de ce suma s-a cumparat pizza vegetariana.\n";
    std::cout << "(6) Exit.\n";
}

int main()
{
    /**
    constructorul de initializare copiaza din 'text.in':
    nrRetete
    (
        (nrIngrediente)
        (
            denumire
            cantitate
            pretCantitate
        )
     pune in reteta dupa ordinea in citire
    )
    */
    Meniu<Pizza, PVegetariana> M;
    //**
    do
    {
        afisare_meniu();
        int optiune;
        std::cout << "V-ati hotarat?  Ce ati ales?\n";
        std::cin >> optiune;
        std::cout << "\n";

        if (optiune == 1)
        {
            std::cout << M;
        }
        else if (optiune == 2)
        {
            int nr_reteta, distanta;
            std::cout << "Ce Reteta din meniu sa fie?  ";
            std::cin >> nr_reteta;
            std::cout << "Unde doriti sa facem comanda?\n     1. Domicilie\n     2. La restaurant\n";
            int varianta;
            std::cin >> varianta;
            if (varianta == 1)
            {
                std::cout << "Ce distanta?";
                std::cin >> distanta;
                std:: cout << "\n";
            }
            else distanta = 0;
            Pizza p(nr_reteta, distanta);
            M.cumpar_pizza(p);
            std::cout << "Va costa: " << p.get_pret() << " RON.\n\n";
        }
        else if (optiune == 3)
        {
            int nr_reteta, distanta;
            std::cout << "Ce Reteta din meniu sa fie?  ";
            std::cin >> nr_reteta;
            std::cout << "Unde doriti sa facem comanda?\n     1. Domicilie\n     2. La restaurant\n";
            int varianta;
            std::cin >> varianta;
            if (varianta == 1)
            {
                std::cout << "Ce distanta?";
                std::cin >> distanta;
                std:: cout << "\n";
            }
            else distanta = 0;
            PVegetariana p(nr_reteta, distanta);
            M.cumpar_pizza(p);
            std::cout << "Va costa: " << p.get_pret() << " RON.\n\n";
        }
        else if (optiune == 4)
        {
            M.print_comenzi();
        }
        else if (optiune == 5)
        {
            std::cout << "Vegetarienii au cumparat pizza de: " << M.sumaPizzaVeg << " RON\n\n";
        }
        else if (optiune == 6)
        {
            break;
        }
        else
        {
            std::cout << "Nu exista aceasta optiune\n\n";
            continue;
        }
    } while(true);
    //*/
    return 0;
}
