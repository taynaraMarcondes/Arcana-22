#ifndef FORTUNA_H
#define FORTUNA_H

#include "personagem.h"
#include <string>

class Fortuna : public Personagem
{
public:
  Fortuna(string n, int lvl, int ab, int db, int vl, int pr) : Personagem(n, lvl, ab, db, vl, pr, getHp(140)){};
  ~Fortuna(){};

  void updateStats();
  string returnClassName() { return "Roda da Fortuna"; }

  void attack(Personagem &);
  void defend();
  void wheelOfFortune();
};

#endif