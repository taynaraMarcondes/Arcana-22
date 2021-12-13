#include "personagem.h"
#include <iostream>
#include <ctime>

using namespace std;

// -----------------------------------------------------------------------------

// INICIA PERSONAGEM

int Personagem::getHp(int hpbase)
{
    return hpbase + 20 * (nivel - 5) + defbas * 2;
}

void Personagem::printPersonagem()
{
    system("cls||clear");

    cout << "Nome: " << name << "\n\n"
         << "Nível: " << nivel << "\n"
         << "Classe: " << returnClassName() << "\n\n"
         << "Ataque Base: " << atqbas << "\n"
         << "Defesa Base: " << defbas << "\n\n"
         << "Velocidade: " << vel << "\n"
         << "Precisao: " << pre << "\n";
}

void Personagem::upgradeLevel()
{
    nivel++;
    atqbas += randGen(nivel);
    defbas += randGen(nivel);
    vel += randGen(nivel);
    pre += randGen(nivel);
}

int randGen(int lvl)
{
    srand(time(NULL));

    unsigned int temp;

    if (lvl == 0)
    {
        return 0;
    }
    else if (lvl == 1)
    {
        return 1;
    }
    else
    {
        temp = (rand() % 100) / 10;

        if (temp < lvl && temp > 0)
        {
            return temp;
        }
        else
            randGen(lvl);
    }
}