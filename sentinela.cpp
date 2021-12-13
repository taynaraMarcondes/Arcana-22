#include "sentinela.h"
#include "personagem.h"

void Sentinela::updateStats()
{

  if (hp > hp0)
  {
    atq = 10 + pre * 3 + vel * 2 + atqbas * 2 + hp / 50;
    def = 3 + defbas * 3 + hp / 50;
  }

  else if (0.33 * hp0 > hp > hp0)
  {
    vel = 3;
    atq = 10 + pre * 3 + vel * 2 + atqbas * 2;
    def = 3 + defbas * 3 + vel * 2;
  }
  else
  {
    atqbas = 3;
    vel = 4;
    atq = 10 + pre * 3 + vel * 2 + atqbas * 3;
    def = 3 + defbas * 3 + vel * 2;
  }
}

void Sentinela::attack(Personagem &inimigo)
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

void Sentinela::defend()
{
  srand(time(NULL));

  int op = rand() % 25;
  def += (def * op) / 100;
}