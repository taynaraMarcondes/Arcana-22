#ifndef CAVALEIRO_H
#define CAVALEIRO_H

#include "personagem.h"
#include <string>

class Cavaleiro : public Personagem
{

public:
  Cavaleiro(string n, int lvl, int ab, int db, int vl, int pr, int hp) : Personagem(n, lvl, ab, db, vl, pr, getHp(120)){};
  ~Cavaleiro(){};

  void updateStats();
  string returnClassName() { return "Cavaleiro"; }

  void attack(Personagem &);
  void defend();
};

#endif