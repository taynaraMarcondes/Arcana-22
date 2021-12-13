#ifndef LOUCO_H
#define LOUCO_H

#include "personagem.h"
#include <string>

class Louco : public Personagem
{
public:
  Louco(string n, int lvl, int ab, int db, int vl, int pr, int hp) : Personagem(n, lvl, ab, db, vl, pr, getHp(100)){};
  ~Louco(){};

  void updateStats();
  string returnClassName() { return "Louco"; };
  void allocatePoint();

  void attack(Personagem &);
  void defend();
};

#endif