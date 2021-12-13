#include "louco.h"

void Louco::updateStats()
{
  defEnabled = true;
  atkEnabled = true;
  hp = 100 + 20 * (nivel - 5) + defbas * 5;

  atq = 10 + pre * 3 + vel * 2 + atqbas * 2;
  def = 3 + defbas * 3 + hp / 50;
}

void Louco::attack(Personagem &inimigo)
{
  int dano = 0;
  if (this->getAtkEnabled())
  {
    if (inimigo.getDefEnabled())
    {
      if (inimigo.getDef() > this->atq)
      {
        inimigo.setDano(0);
        inimigo.setDef(inimigo.getDef() - this->atq);
      }
      else if (inimigo.getDef() > 0)
      {
        dano = this->atq - inimigo.getDef();
        inimigo.setDano(dano);
        inimigo.takeHit(dano);
        inimigo.setDef(0);
      }
    }
    else
    {
      dano = this->atq;
      inimigo.setDano(dano);
      inimigo.takeHit(dano);
    }
  }
}

void Louco::defend()
{
  srand(time(NULL));

  int op = rand() % 25;
  def += (def * op) / 100;
}

void Louco::allocatePoint()
{
  int pontos = 40, habilidade = 0, npontos;
  nivel++;

  while (pontos != 0)
  {
    system("cls||clear");

    cout << "-----------------------------------------------------------------------------------\n"
         << "| Você subiu de nível!                                                            |\n"
         << "| Escolha uma habilidade para alocar seu ponto:\n\n                               |\n"
         << "|                                                                                 |\n"
         << "| 1. Ataque base                                                                  |\n"
         << "| 2. Defesa base                                                                  |\n"
         << "| 3. Velocidade                                                                   |\n"
         << "| 4. Precisão                                                                     |\n"
         << "-----------------------------------------------------------------------------------\n";
    cout << "> ";
    cin >> habilidade;

    cout << "-----------------------------------------------------------------------------------\n"
         << "| Digite a quantidade de pontos a ser distribuída.                                |"
         << "| Pontos disponíveis: " << pontos << "                                                             |"
         << "-----------------------------------------------------------------------------------\n";
    cout << "> ";
    cin >> npontos;

    if (npontos > pontos)
    {
      cout << "-----------------------------------------------------------------------------------\n"
           << "| A quantidade inserida não pode ser alocada pois excede os pontos disponíveis!   |"
           << "| Tente novamente.                                                                |\n"
           << "-----------------------------------------------------------------------------------\n";
      habilidade = 0;
    }

    switch (habilidade)
    {

    case 1:
      atqbas += npontos;
      pontos -= npontos;
      break;

    case 2:
      defbas += npontos;
      pontos -= npontos;
      break;

    case 3:
      vel += npontos;
      pontos -= npontos;
      break;

    case 4:
      pre += npontos;
      pontos -= npontos;
      break;

    default:
      cout << "Escolha inválida.\n";
      break;
    }
  }
}