#ifndef DIABO_H
#define DIABO_H

#include "personagem.h"
#include <string>

class Diabo : public Personagem
{
private:
  int sp2c = 0;

public:
  Diabo(string n, int lvl, int ab, int db, int vl, int pr, int hp) : Personagem(n, lvl, ab, db, vl, pr, getHp(170)){};
  ~Diabo(){};

  void updateStats();
  string returnClassName() { return "Diabo"; }

  void attack(Personagem &);
  void defend();
};

#endif