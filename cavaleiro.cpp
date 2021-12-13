#include "cavaleiro.h"
#include "personagem.h"

int i = 0;

void Cavaleiro::updateStats()
{
  if (hp > 0.3 * hp0 && i == 0)
  {
    atq = 10 + pre * 3 + vel * 2 + atqbas * 2;
    def = 3 + defbas * 3 + hp / 50;
    i++;
  }

  else if (i == 1)
  {
    atqbas = 2;
    defbas = 1;
    vel = 1;
    atq = 4 + pre * 2 + vel * 1 + atqbas * 1;
    def = 3 + defbas * 3 + hp / 50;
    i == 0;
  }
}

void Cavaleiro::attack(Personagem &inimigo)
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

void Cavaleiro::defend()
{
  srand(time(NULL));

  int op = rand() % 25;
  def += (def * op) / 100;
}