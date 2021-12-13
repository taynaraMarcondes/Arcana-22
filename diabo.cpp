#include "diabo.h"

void Diabo::updateStats()
{
  if (hp > 0.5 * hp0)
  {
    atq = 10 + pre * 3 + vel * 2 + atqbas * 2;
    def = 3 + defbas * 3 + hp / 50;
  }

  else
  {
    atqbas = 4;
    defbas = 2;
    atq = 10 + pre * 3 + vel * 2 + atqbas * 2;
    def = 3 + defbas * 3 + hp / 50;
  }
}

void Diabo::attack(Personagem &inimigo)
{
  srand(time(NULL));
  int dano = this->atq;
  int sp1 = rand() % 100;
  int sp2 = rand() % 100;

  if (sp1 <= 10)
  {
    dano = inimigo.getHP() - 1;
  }
  if (sp2 <= 10)
  {
    inimigo.setAtkEnabled(false);
    sp2c = sp2c == 0 ? 3 : sp2c + 3;
  }
  sp2c > 0 ? sp2c-- : 0;
  if (sp2c == 0)
  {
    inimigo.setAtkEnabled(true);
  }

  if (inimigo.getDef() > dano)
  {
    inimigo.setDef(inimigo.getDef() - dano);
  }
  else if (inimigo.getDef() > 0)
  {
    inimigo.takeHit(dano - inimigo.getDef());
    inimigo.setDef(0);
  }
  else
  {
    inimigo.takeHit(dano);
  }
}

void Diabo::defend()
{
  srand(time(NULL));

  int op = rand() % 25;
  def += (def * op) / 100;
}