#ifndef SENTINELA_H
#define SENTINELA_H

#include "personagem.h"
#include <string>

class Sentinela : public Personagem
{
private:
  int mode = 0;

public:
  Sentinela(string n, int lvl, int ab, int db, int vl, int pr, int hp) : Personagem(n, lvl, ab, db, vl, pr, getHp(190)){};
  ~Sentinela(){};

  void updateStats();
  string returnClassName() { return "Sentinela dos Céus"; }

  void attack(Personagem &);
  void defend();
};

#endif