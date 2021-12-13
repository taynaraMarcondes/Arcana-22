#include "fortuna.h"
#include "personagem.h"
#include <ctime>

void Fortuna::updateStats()
{
  atq = 10 + pre * 3 + vel * 2 + atqbas * 2;
  def = 3 + defbas * 3 + hp / 50;
}

void Fortuna::attack(Personagem &inimigo)
{
  if (this->getAtkEnabled())
  {
    if (inimigo.getDef() > this->atq)
    {
      inimigo.setDef(inimigo.getDef() - this->atq);
    }
    else if (inimigo.getDef() > 0)
    {
      inimigo.takeHit(this->atq - inimigo.getDef());
      inimigo.setDef(0);
    }
    else
    {
      inimigo.takeHit(this->atq);
    }
  }
}

void Fortuna::defend()
{
  srand(time(NULL));

  int op = rand() % 25;
  def += (def * op) / 100;
}

void Fortuna::wheelOfFortune()
{
  srand(time(NULL));

  int op = rand() % 5;
  switch (op)
  {
  case 1:
    atkEnabled = true;
    defEnabled = false;
    break;

  case 2:
    atkEnabled = false;
    defEnabled = true;
    break;

  case 3:
    atkEnabled = false;
    defEnabled = false;
    break;

  case 4:
    hp += (hp * (rand() % 10)) / 100;
    break;

  case 5:
    hp -= (hp * (rand() % 10)) / 100;
    break;

  default:
    break;
  }
}