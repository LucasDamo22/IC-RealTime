#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>
#include "Factors.h"

int main()
{
    std::ifstream arq_factors;
    arq_factors.open("factors.txt", std::ios::in);
    if (!arq_factors.is_open())
    {
        return 1;
    }

    int n_Factors;
    double coef = 0;

    arq_factors >> n_Factors;

    Factors factors[n_Factors];
    for (int i = 0; i < n_Factors; i++)
    {
        int aux1 = 0;
        int aux2 = 0;

        arq_factors >> aux1 >> aux2;

        factors[i].defineExec(aux1);
        factors[i].defineWorstExec(aux2);
    }

    for (int i = 0; i < n_Factors; i++)
    {
        double aux1 = 0;
        double aux2 = 0;

        aux1 = factors[i].getExec();
        aux2 = factors[i].getWorstExec();

        coef = coef + (aux1 / aux2);
    }

    std::ofstream arq_coef;
    arq_coef.open("coef.txt", std::ios::out);
    if (!arq_coef.is_open())
    {
        return 1;
    }

    arq_coef << "CPU Utilization factor: " << coef << std::endl;

    do
    {
        if (coef < 0.26)
        {
            arq_coef << "System is Unnecessarily safe! (under 26%)";
            break;
        }

        if (coef < 0.50)
        {
            arq_coef << "System is Very safe! (under 50%)";
            break;
        }

        if (coef < 0.68)
        {
            arq_coef << "System is Safe! (under 68%)";
            break;
        }

        if (coef == 0.69)
        {
            arq_coef << "System is on Limit! (on 69%)";
            break;
        }

        if (coef < 0.82)
        {
            arq_coef << "System is on a questionable zone (70% ~ 82%)";
            break;
        }
        if (coef < 0.99)
        {
            arq_coef << "System is on a dangerous zone! (83% ~ 99%)";
            break;
        }
        if (coef == 1.00)
        {
            arq_coef << "System is on a Critical zone! (100%)";
            break;
        }
        if (coef > 1.00)
        {
            arq_coef << "System is Overloaded zone! (>100%)";
            break;
        }
    } while (1);

    std::cout << "Check 'coef.txt'!" << std::endl;
    return 0;
}