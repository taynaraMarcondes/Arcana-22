#include <iostream>
#include <cstdlib>
#include <ctime>
#include "personagem.h"
#include "louco.h"
#include "cavaleiro.h"
#include "fortuna.h"
#include "juiz.h"
#include "diabo.h"
#include "sentinela.h"

using namespace std;

template <typename Classe>

int batalha(Louco &player, Classe &inimigo)
{
  player.updateStats();
  inimigo.updateStats();

  bool win = 0;
  int op, k{0};

  for (;;)
  { // ever
    system("cls||cls");

    cout << " --------------------------------------------------- \n"
         << "|                                                   |\n"
         << "|                 Inicio da Batalha!                |\n"
         << "|                                                   |\n"
         << " --------------------------------------------------- \n";

    cout << "  Turno " << k + 1 << "\n\n";

    cout << "  HP de Louco "
         << ": " << player.getHP() << "\n";
    cout << "  HP de " << inimigo.getName() << ": " << inimigo.getHP() << "\n\n";

    if (k != 0)
    {
      cout << player.getName() << " recebeu " << player.getDano() << " de dano!\n";
      cout << inimigo.getName() << " recebeu " << inimigo.getDano() << " de dano!\n\n";
    }

    bool validOp = 0;

    while (!validOp)
    {
      cout << "  1. Atacar\n"
           << "  2. Defender\n\n"
           << "  > ";

      cin >> op;

      switch (op)
      {
      case 1:
        player.attack(inimigo);
        validOp = 1;
        break;
      case 2:
        player.defend();
        validOp = 1;
        break;
      default:
        cout << "\nComando inválido. Insira outro."
             << endl;
        break;
      }
    }

    srand(time(NULL));

    op = rand() % 100;

    if (op <= 70)
    {
      inimigo.attack(player);
    }
    else
    {
      inimigo.defend();
    }

    k++;

    cout << flush;

    if (inimigo.getHP() <= 0)
    {
      system("cls||clear");
      cout << "Voce venceu a luta! Parabens!\n\n";
      system("pause");
      win = 1;
      break;
    }
    else if (player.getHP() <= 0)
    {
      system("cls||clear");
      cout << "Voce perdeu a luta!\n\n";
      system("pause");
      break;
    }
  }

  if (win)
  {
    player.allocatePoint();
    return 1;
  }
  else
  {
    while (1)
    {
      system("cls||cls");

      cout << "Voce deseja continuar jogando e repetir a luta?\n"
           << "1. Sim\n"
           << "2. Nao\n\n"
           << "> ";

      cin >> op;

      switch (op)
      {
      case 1:
        batalha(player, inimigo);
        return 0;
        break;

      case 2:
        return 0;
        break;

      default:
        cout << "Insira novamente...\n";
        getchar();
        break;
      }
    }
  }
}