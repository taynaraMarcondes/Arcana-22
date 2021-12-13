#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <string>

using namespace std;

class Personagem
{
protected:
	string name;

	int hp;					// health points during battle
	int hp0;				// health points, hp = 100 + 20 * (nivel - 5) + vit * 5
	int nivel;			// nivel inicial = 5, sobe toda vez que ganha uma luta
	int atqbas = 0; // Ataque base
	int defbas = 0; // Defesa base
	int vel = 0;		// velocidade
	int pre = 0;		// precisão

	int atq; // quanto de dano dá no oponente
	int def; // quanto de dano do oponente é mitigado

	int dano = 0; // dano recebido na batalha
	bool defEnabled = false;
	bool atkEnabled = false;

public:
	Personagem() = default;
	Personagem(string n, int lvl = 0, int ab = 0, int db = 0, int vl = 0, int pr = 0, int hp = 0)
	{
		name = n;
		nivel = lvl;
		atqbas = ab;
		defbas = db;
		vel = vl;
		pre = pr;
		hp0 = hp;
		hp0 = hp0;
	};
	~Personagem(){};

	void setPoints();
	void upgradeLevel();
	int getHp(int hpbase);
	virtual void updateStats(int hpbase);

	string getName() { return name; }
	int getHP() { return hp; }
	int getLvl() { return nivel; }
	int getAtq() { return atq; }
	int getDef() { return def; }
	int getVel() { return vel; }
	int getPre() { return pre; }
	int getAtqBas() { return atqbas; }
	int getDefBas() { return defbas; }
	bool getDefEnabled() { return defEnabled; }
	bool getAtkEnabled() { return atkEnabled; }
	int getDano() { return dano; }

	void setLvl(int lvl) { nivel = lvl; }
	void setAtqbas(int ab) { atqbas = ab; }
	void setDefbas(int db) { defbas = db; }
	void setDef(int df) { def = df; }
	void setVel(int vl) { vel = vl; }
	void setPre(int pr) { pre = pr; }
	void setContadorDef() { defEnabled = false; }
	void setAtkEnabled(bool ae) { atkEnabled = ae; }
	void setDano(int d) { dano = d; }

	virtual void attack(Personagem &){};
	virtual void defend() = 0;
	void takeHit(int dano) { hp -= dano; }

	virtual string returnClassName() {}
	void printPersonagem();

	void upgradeLevel();
};

#endif
