#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include "louco.h"
#include "cavaleiro.h"
#include "fortuna.h"
#include "juiz.h"
#include "diabo.h"
#include "sentinela.h"
#include "batalha.h"
#include <locale.h>

using namespace std;
using namespace std::this_thread;

void arrival();
void beginning();
void act1beg();
void act1end();
void act2beg();
void act2end();
void act3beg();
void act3end();
void act4beg();
void act4end();
void act5beg();
void mundo();
void morte();
void epilogo();

Louco *heroi = Louco player{"Louco", 0, 0, 0, 0, 0, 0};
Personagem *inimigo[5]
{
     new Cavaleiro("Cavaleiro", 0, 4, 1, 3, 2, 0);
     new Diabo("Diabo", 0, 2, 4, 3, 3, 0);
     new Fortuna("Fortuna", 0, 2, 2, 2, 2, 0);
     new Juiz("Juiz", 0, 1, 5, 1, 1, 0);
     new Sentinela("Sentinela", 0, 4, 2, 5, 2, 0);
};

int main()
{
     setlocale(LC_ALL, "Portuguese");

     int op = 0;
     while (op != 3)
     {
          cout << "-----------------------------------------------------------------------------------\n"
               << "| 1. Repetir história                                                              |\n"
               << "| 2. Iniciar a jornada                                                             |\n"
               << "| 3. Abandonar segunda chance                                                      |\n"
               << "-----------------------------------------------------------------------------------\n";
          cin >> op;
          switch (op)
          {
          case 1:
               arrival();
               break;
          case 2:
               beginning();
               act1beg();
               break;
          default:
               break;
          }
     }
     return 0;
}

void arrival()
{
     system("clear||cls");

     cout << "-----------------------------------------------------------------------------------\n"
          << "| Você acorda e está num lugar foram do comum, olha para os lados e... apenas breu.|\n"
          << "| Se levanta e tenta se lembrar o que aconteceu, mas falha miseravelmente.         |\n"
          << "| Alguém se aproxima!                                                              |\n"
          << "-----------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << "-----------------------------------------------------------------------------------\n"
          << "| É um homem velho vestindo um manto preto.                                        |\n"
          << "| Ele pergunta:                                                                    |\n"
          << "| \"Saudações alma perdida. Você é Louco o suficiente para encarar essa jornada?\" |\n"
          << "-----------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << "-----------------------------------------------------------------------------------\n"
          << "|                                                                                 |\n"
          << "| Você olha confuso para o estranho velho.                                        |\n"
          << "|                                                                                 |\n"
          << "-----------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << "-----------------------------------------------------------------------------------\n"
          << "| [Homem velho]:                                                                  |\n"
          << "| \"Veja, você não está mais entre os vivos e suas ações anteriores colocaram     |\n"
          << "| você em uma corda bamba. Pode escolher entre tentar conquistar uma segunda      |\n"
          << "| chance, ou cair diretamente no esquecimento. Então, qual vai ser?\"             |\n"
          << "-----------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << "-----------------------------------------------------------------------------------\n"
          << "| Você tenta digerir a situação em que se encontra e reflete um pouco.            |\n"
          << "| Depois de um certo tempo, diz:                                                  |\n"
          << "| \"Eu quero tentar\"                                                             |\n"
          << "-----------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << "-----------------------------------------------------------------------------------\n"
          << "| [Homem velho]:                                                                  |\n"
          << "| \"Certo, então realmente você é Louco, mas veremos se conseguirá mesmo.         |\n"
          << "| Eu sou um Eremita que vaga por aqui. Pode me chamar assim, se quiser.\"         |\n"
          << "-----------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << "-----------------------------------------------------------------------------------\n"
          << "| O Eremita abre sua mão e mostra para a alma.                                    |\n"
          << "| [Eremita]:                                                                      |\n"
          << "|\"Para conseguir sua segunda chance, precisa passar por cinco provações primeiro.|\n"
          << "| Fale comigo quando quiser começar.\"                                            |\n"
          << "-----------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");
}

void beginning()
{
     cout << " ----------------------------------------------------------------------------------\n"
          << "| [Eremita]:                                                                       |\n"
          << "| \"Oh vejo que escolheu desbravar as provações e lutar pela segunda chance!       |\n"
          << "| Você recebeu X pontos de experiência, ditribua-os da maneira que achar melhor.\" |\n"
          << " ----------------------------------------------------------------------------------\n";
     player.allocatePoint();
}

void act1beg()
{
     cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------------\n"
          << "|                                                     1ª PROVAÇÃO - DEMONSTRAR SUA DETERMINAÇÃO                                                           |\n"
          << "|                                                                                                                                                         |\n"
          << "| Você precisa alcançar uma princesa que está sendo mantida em uma Torre isolada da capital por questões de segurança, assim definido pelo Imperador.     |\n"
          << "| Para isso, ele precisa enfrentar o único segurança da Torre, um cavaleiro que utiliza uma Biga e uma espada como armamento.                             |\n"
          << "|                                                                                                                                                         |\n"
          << "| O cavaleiro foi designado pela Imperatriz para proteger a princesa pois ela sabia que os dois eram Amantes secretos,                                    |\n"
          << "| logo tornando sua determinação em manter sua amada a salvo em grande força e motivação para cumprir sua missão.                                         |\n"
          << " ----------------------------------------------------------------------------------------------------------------------------------------------------------\n";

     if (batalha(heroi, inimigo[0]) == 1)
     {
          act1end(Louco & player, Fortuna & inimigo);
     }
     else
     {
     }
}

void act1end()
{
     cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------------- \n"
          << "| Após cair da Biga, o cavaleiro começa a fraquejar por pensar na possibilidade de perder.   |\n"
          << "| Seu desespero se torna sua ruína e assim é derrotado pelo Louco.                                                                                          |\n"
          << " ----------------------------------------------------------------------------------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ----------------------------------------------------------------------------------------------------------- \n"
          << "| [Princesa]:                                                                                               |\n"
          << "| \"Pode ir. Você conseguiu. Já tomou o que queria, não? Pois então vá antes de que o rancor me consuma.\"  |\n"
          << "|                                                                                                           |\n"
          << "| Você sai da torre e encontra o Eremita.                                                                   |\n "
          << " ----------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ---------------------------------------------------------------------------------------------------------------------------------- \n"
          << " [Eremita]:                                                                                                                        |\n"
          << " \"A determinação do cavaleiro não resistiu à adversidade, assim causando sua derrota.                                             |\n"
          << " Se você quiser muito algo, sua determinação precisa permanecer intacta para não desistir, mesmo que você vá a falhar no fim.\"    |\n"
          << " ---------------------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");
     act2beg()
}

void act2beg()
{

     cout << " -------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
          << "|                                                     2ª PROVAÇÃO - DESAFIAR O DESTINO                                                                       |\n"
          << "|                                                                                                                                                            |\n"
          << "| O Louco encontra um jovem adulto, coberto de vestimentas peculiares, porém elegantes em um pequeno altar com uma estátua de uma mulher numa floresta densa.|\n"
          << "| Ao aproximar dele, aquele estranho se vira rapidamente e sorri.                                                                                            |\n"
          << "|                                                                                                                                                            |\n"
          << "| [Estranho]                                                                                                                                                 |\n"
          << "| \"Como está a sua sorte hoje?\"                                                                                                                            |\n"
          << "| Você logo em seguida repara seu braço no alto e invoca uma espécie de roleta perto de si                                                                   |\n"
          << "|                                                                                                                                                            |\n"
          << "| [Estranho]                                                                                                                                                 |\n"
          << "| \"Vamos ver se a Deusa da Destino está sorrindo para você.\"                                                                                               |\n"
          << "| Disse calmamente e logo desaparece entre os arbustos                                                                                                       |\n"
          << "|                                                                                                                                                            |\n"
          << "| O Louco, temendo pelo pior e inesperado, decide que a melhor escolha agora é destruir aquela Roda da Fortuna que acabara de ser invocada.                  |\n"
          << " -------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");
     if (batalha(heroi, inimigo[1]) == 1)
     {
          act2end();
     }
     else
     {
     }
}

void act2end()
{
     cout << " ----------------------------------------------------------------------------------------------------------------------------------------------------------- \n"
          << "| Aquele jovem de antes ressurge da vegetação e parabeniza o Louco por ter conseguido se sair vitorioso.                                                   |\n"
          << "| [Mago]                                                                                                                                                   |\n"
          << "| \"Parece que este Mago anda azarado ultimamente. Bom, foram suas escolhas e sorte que ganharam essa luta, e eu... aceito...\"                            |\n"
          << "| A voz do Mago começa a ficar mais baixa enquanto ele se desfaz até não sobrar nada                                                                       |\n"
          << " ----------------------------------------------------------------------------------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " --------------------------------------------------------------------------------------------------------------- \n"
          << "| O Eremita chega perto do Louco e do altar, proferindo as seguintes palavras:                                 |\n"
          << "| [Eremita]:                                                                                                   |\n"
          << "| \"Ele escolheu conquistar uma segunda chance através de apostas, já que gostava de jogos de azar antigamente.|\n"
          << "| Cultuava o acaso como uma benção divina, porque deixava a vida mais interessante\"                           |\n"
          << " --------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ---------------------------------------------------------------------------------------------------------------------------------- \n"
          << "| [Eremita]:                                                                                                                        |\n"
          << "| \"Tudo é possível, porém improvável para algumas possibilidades. Basta uma pequena escolha ou detalhe e logo                      |\n"
          << "| percorreremos um caminho diferente do esperado. E contemple, pois você consegue fazer suas decisões, seu destino.\"               |\n"
          << "| Disse o eremita após contemplar a estátua                                                                                         |\n"
          << " ---------------------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     act3beg();
}

void act3beg()
{
     cout << " ---------------------------------------------------------------------------------------------------------------------- \n"
          << "|                                          3ª PROVAÇÃO - PROVAR SUA INOCÊNCIA                                          |\n"
          << "|                                                                                                                      |\n"
          << "| O Louco chega numa espécie de praça, contudo ela se encontra vazia, a não ser por uma pessoa no centro dela.         |\n"
          << "| Você se aproxima dela e repara que ela está vendada e segura uma balança.                                            |\n"
          << "| Ao reparar sua presença, então grita apontando par ti.                                                               |\n"
          << " ---------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " -------------------------------------------------------------------------------------------------------------------------- \n"
          << "| [Juiz]:                                                                                                                  |\n"
          << "|  \"QUE COMEÇE O JULGAMENTO!\"                                                                                            |\n"
          << "|                                                                                                                          |\n"
          << "| Várias sombras começam a cercar a ágora que está a ser construída naquele momento enquanto a pessoa começa a anunciar:   |\n"
          << "| [Juiz]:                                                                                                                  |\n"
          << "| \"EU SEREI SEU JUIZ! VEJAMOS QUAIS SÃO SUAS ACUSAÇÕES: MANIPULAÇÃO, CORRUPÇÃO, CALÚNIA, TR-\"                            |\n"
          << " -------------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ------------------------------------------------------------------------------------------------------------------------------ \n"
          << "| [Louco]:                                                                                                                     |\n"
          << "|  \"PARA!\"                                                                                                                   |\n"
          << "|                                                                                                                              |\n"
          << "| O Louco, que costuma ficar calado só observando as situações, acaba, porém, com esta engatilhando                            |\n"
          << "| pequenos flashes de memória, e com elas todos os sentimentos negativos que sentiu durante os tais atos descritos pelo juiz.  |\n"
          << "| Querendo calar a boca daquela pessoa que gritava seus crimes histericamente, você decide acabar com o juiz de uma vez.       |\n"
          << " ------------------------------------------------------------------------------------------------------------------------------ \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");
     if (batalha(heroi, inimigo[2]) == 1)
     {
          act3end();
     }
     else
     {
     }
}

void act3end()
{
     cout << " ---------------------------------------------------------------------------------------------------------------------------------------------------------- \n"
          << "| Após acabar com o juiz, o Eremita aproxima-se de você, que está um pouco exaltado por causa da situação.                                                 |\n"
          << "|                                                                                                                                                          |\n"
          << "| [Eremita]:                                                                                                                                               |\n"
          << "| \"Fora acusado de tantos pecados, para apenas no fim cometer mais um. Acha mesmo que dessa forma ainda vai ser digno daquilo que você almeja?\"          |\n"
          << " ---------------------------------------------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ---------------------------------------------------------------------------------------- \n"
          << "| Você olha um pouco assustado e então fica parado refletindo a situação por um tempo,   |\n"
          << "| até se recompor, pensando enquanto observa o cadáver.                                  |\n"
          << "|                                                                                        |\n"
          << "| [Louco]:                                                                               |\n"
          << "| \"Será que ela ainda vai permanecer inabalável... a minha determinação?\"              |\n"
          << " ---------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");
     act4beg();
}

void act4beg()
{
     cout << " ---------------------------------------------------------------------------------------------------------------------- \n"
          << "|                                           4ª PROVAÇÃO - ENCARAR SEUS DEMÔNIOS                                        |\n"
          << "|                                                                                                                      |\n"
          << "| Você encontra duas pessoas do lado de fora de uma pequena capela. Eles são o Papa e a Papisa, que guardavam o local. |\n "
          << "| O primeiro abre as portas da estrutura enquanto a última lhe acolhe.                                                 |\n"
          << "|                                                                                                                      |\n"
          << "| [Papisa]:                                                                                                            |\n"
          << "|  \"Entre, pequeno cordeiro.\"                                                                                        |\n"
          << " ----------------------------------------------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ---------------------------------------------------------------------------------------------------------------------- \n"
          << "|  Após entrar, você avista um espelho no fim do interior daquele lugar.                                                |\n"
          << "|  Ao se aproximar dele, vê seu reflexo, porém nele começa a crescer alguns chifres, criar garras e esvair seus olhos.  |\n"
          << "|                                                                                                                       |\n "
          << "| [Diabo]:                                                                                                              |\n"
          << "| \"Vamos brincar um pouco. Do seu jeito, claro.\"                                                                      |\n"
          << "|                                                                                                                       |\n"
          << "|  Assim, ele sai do espelho, assustando o Louco e fazendo-o recuar.                                                    |\n"
          << " -----------------------------------------------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     if (batalha(heroi, inimigo[3]) == 1)
     {
          act4end();
     }
     else
     {
     }
}

void act4end()
{
     cout << " -------------------------------------------------------------------------------------------------------------------------------------------- \n"
          << "| [Diabo]:                                                                                                                                    |\n"
          << "| \"Nada mal. E ainda conseguiu de maneira justa. Que evolução, hein? Da próxima, assuma seus erros em vez de botar a culpa em outra coisa.\"|\n"
          << "| \"Não sou o bode de ninguém... só de mim. RÁHAHAHAHAHAHAHA.\"                                                                                 |\n"
          << " -------------------------------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ------------------------------------------------------------------------------------- \n"
          << "| Você observa a cena enquanto o Eremita, junto com o Papa e a Papisa, se aproximam   |\n"
          << "|                                                                                     |\n"
          << "| [Eremita]:                                                                           |\n"
          << "| \"Não preciso dizer mais nada. Nosso amigo aí já proferiu a verdade.\"              |\n"
          << " ------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");
     act5beg();
}

void act5beg()
{
     cout << " ------------------------------------------------------------------------------------------------------------------------------------------------- \n"
          << "|                                                     5ª PROVAÇÃO - ALCANÇAR OS CÉUS                                                              |\n"
          << "|                                                                                                                                                 |\n"
          << "| Você agora se encontra em um lugar cuja superfície é composto de um chão de água cristalina que não afunda com o andar e um céu limpo e claro,  |\n"
          << "| sem conseguir avistar nada em seu horizonte independente donde olhe.                                                                            |\n"
          << "|                                                                                                                                                 |\n"
          << "| Porém o céu começa a escurecer e dele cai rapidamente alguém coberto por uma túnica branca e com uma máscara de Lua                             |\n"
          << "| Um tempo depois, o céu começa a clarear e, junto dele, a máscara daquela figura começa a tomar um formato de Sol.                               |\n"
          << "| A entidade parte para cima do Louco.                                                                                                            |\n"
          << " ------------------------------------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     if (batalha(heroi, inimigo[4]) == 1)
     {
          mundo();
     }
     else
     {
     }
}

void mundo()
{
     cout << " ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ \n"
          << "| Após derrotar o Sentinela, ele recua um pouco de você e coloca sua mão na máscara e então começa a apertá-la até rachar, revelando ser um homem de barba e cabelos dourados. |\n"
          << "| Após isso ele aponta para atrás de si, onde surge uma Estrela, que aos poucos começa a brilhar intensamente.                                                                 |\n"
          << "|                                                                                                                                                                              |\n"
          << "| [Sentinela] :                                                                                                                                                                |\n"
          << "| \"Vamos?\"                                                                                                                                                                   |\n"
          << "| Pergunta a figura sorrindo e estendendo a mão.                                                                                                                               |\n "
          << " ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " -------------------------------------------------------------------------------------------- \n"
          << "| Você fica um pouco perplexo com a situação, mas então e levemente é empurrado para frente. |\n"
          << "| Foi obra do Eremita, que também começou a esboçar um sorriso                               |\n"
          << "|                                                                                            |\n"
          << "| [Eremita]:                                                                                  |\n"
          << "| \"Um novo amanhecer lhe espera, minha criança.\"                                           |\n "
          << " -------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ------------------------------------------------------------------------------------------------------------------------------\n"
          << "| Você olha por alguns segundos para o Eremita e faz uma reverência ao sábio, e logo começa a caminhar em direção ao Sentinela.|\n"
          << "| Ao chegar perto dele, agarra sua mão e os dois começam a andar juntos.                                                       |\n "
          << " ------------------------------------------------------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ---------------------------------------------------------------------------------------------------------------------------\n"
          << "| O Louco começa a chorar enquanto segue em direção à luz.                                                                  |\n"
          << "| Seu choramingo passam a ter um timbre mais agudo ao longo do caminho, até que os dois chegam na Estrela e tudo fica claro.|\n "
          << " ---------------------------------------------------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " ----------------------------------------------------------------------------------------------------------------------------------- \n"
          << "| Após a luz diminuir, você consegue ver que esta vinha de uma lâmpada, além de perceber um homem loiro vestindo uma roupa branca.  |\n"
          << "| que estava acolhendo um recém-nascido, acalmando você.                                                                            |\n"
          << "|                                                                                                                                   |"
          << "| [Médico]:                                                                                                                         |\n"
          << "| \"Tudo bem, já passou. Alegre-se, criança. Você já venceu, pode relaxar agora.\"                                                  |\n "
          << " ----------------------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");
     epilogo();
}

void morte()
{
     cout << " ------------------------------------------------------------------------------------------\n"
          << "| [Eremita]:                                                                                |\n"
          << "| \"Então parece que sua determinação não era suficiente para este desafio. Que pena...\"  |\n"
          << "| Você se desfaz e desaparece...                                                           |\n"
          << " ------------------------------------------------------------------------------------------\n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");
     return 0;
}

void epilogo()
{
     cout << "----------------------------------------------------------------- \n"
          << "| Enquanto isso, no antigo lugar desconhecido, estava o Eremita, |\n"
          << "| olhando para uma pessoa que parecia confusa,                   |\n"
          << "| caminhando em direção a ela.                                   |\n"
          << "----------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << " -------------------------------------------------------------------------------------------------------------------------- \n"
          << "| [Eremita]:                                                                                                               |\n"
          << "| \"Somente os Loucos o suficiente de confrontar suas impurezas e ainda conseguir superá-las no fim                        |\n"
          << "| são dignas de voltar ao Mundo. Elas se tornam a arcana 22 do baralho místico: o Renascido, símbolo de um novo começo.\"  |\n"
          << " -------------------------------------------------------------------------------------------------------------------------- \n";

     cout << "\nPressione enter pra continuar ..";
     getchar();
     system("clear||cls");

     cout << "-----------------------------------------------------------------------------------\n"
          << "| Após o breve monólogo:                                                           |\n"
          << "| [Eremita]:                                                                       |\n"
          << "| \"Saudações, alma perdida. Você é Louco o suficiente para encarar essa jornada?\"|\n"
          << "-----------------------------------------------------------------------------------\n";

     cout << "                                      FIM(?)                                         ";

     return 0;
}