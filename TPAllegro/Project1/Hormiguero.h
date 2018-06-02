#ifndef HORMIGUERO_H
#define HORMIGUERO_H
#include "Hormiga.h"
#include <vector>
class Hormiguero :	public Sprite
{
private:
	vector<Hormiga*> *hormigas;
public:
	Hormiguero(int SCREEN_W, int SCREEN_H);
	~Hormiguero();
	void Initialize(int SCREEN_W, int SCREEN_H);
	void Reset(int SCREEN_W, int SCREEN_H);
	vector<Hormiga*>* GetHormigas() const;
};

#endif