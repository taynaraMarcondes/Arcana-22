#include "juiz.h"
#include "personagem.h"

void Juiz::updateStats()
{
  atqbas = 1;
  defbas = 5;
  pre = 1;
  vel = 1;

  atq = 10 + pre * 3 + vel * 2 + atqbas * 2;
  def = 3 + defbas * 3 + hp / 50;
}

void Juiz::attack(Personagem &inimigo)
{
  if (inimigo.getDef() > this->dano)
  {
    inimigo.setDef(inimigo.getDef() - this->dano);
  }
  else if (inimigo.getDef() > 0)
  {
    inimigo.takeHit(this->dano - inimigo.getDef());
    inimigo.setDef(0);
  }
  else
  {
    inimigo.takeHit(this->dano);
  }
}

void Juiz::defend()
{
  srand(time(NULL));

  int op = rand() % 25;
  def += (def * op) / 100;
}