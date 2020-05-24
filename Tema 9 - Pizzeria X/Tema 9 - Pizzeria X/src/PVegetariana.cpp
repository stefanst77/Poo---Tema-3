#include "PVegetariana.h"

int PVegetariana::calcul_Pret()
{
    return pret * (1 + distanta * 0.5) + manopera;
}
