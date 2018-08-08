#ifndef HORMIGUERO_H
#define HORMIGUERO_H
#include "Hormiga.h"
#include <vector>

class Hormiguero : public Sprite
{
private:
	vector<Hormiga*> *hormigas;
public:
	Hormiguero();
	~Hormiguero();
	void Initialize();
	void Reset();
	vector<Hormiga*>* GetHormigas() const;
};

#endif