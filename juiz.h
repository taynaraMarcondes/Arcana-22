#ifndef JUIZ_H
#define JUIZ_H

#include "personagem.h"
#include <string>

class Juiz : public Personagem
{

public:
  Juiz(string n, int lvl, int ab, int db, int vl, int pr, int hp) : Personagem(n, lvl, ab, db, vl, pr, getHp(200)){};
  ~Juiz(){};

  void updateStats();
  string returnClassName() { return "Juiz"; }

  void attack(Personagem &);
  void defend();
};

#endif