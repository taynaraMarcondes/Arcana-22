#include <iostream>
#include "personagem.h"
#include "louco.h"
#include "cavaleiro.h"
#include "diabo.h"
#include "fortuna.h"
#include "juiz.h"
#include "sentinela.h"

using namespace std;

Louco criaPlayer()
{
  Louco player{"Louco", 0, 0, 0, 0, 0};
  player.allocatePoint();
  return player;
}
