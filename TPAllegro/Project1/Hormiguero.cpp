#include "Hormiguero.h"


Hormiguero::Hormiguero(int SCREEN_W, int SCREEN_H) : Sprite(0,0,"Asset/Sprite/hormiguero.png", 0 ,0)
{
	Initialize(SCREEN_W, SCREEN_H);
}

Hormiguero::~Hormiguero()
{
	delete hormigas;
}

void Hormiguero::Initialize(int SCREEN_W, int SCREEN_H)
{
	SetPosition(rand() % SCREEN_W, rand() % SCREEN_H);
	hormigas = new vector<Hormiga*>;
	hormigas->push_back(new Hormiga(GetPosX(), GetPosY(), 0, -1));
	hormigas->push_back(new Hormiga(GetPosX(), GetPosY(), 0 , 1));
	hormigas->push_back(new Hormiga(GetPosX(), GetPosY(), 1, 0));
	hormigas->push_back(new Hormiga(GetPosX(), GetPosY(), -1 , 0));
}

void Hormiguero::Reset(int SCREEN_W, int SCREEN_H)
{
	SetPosition(rand() % (int)(SCREEN_W - GetWidth()), rand() % (int)(SCREEN_H-GetHeight()));
	for (int i = 0; i < hormigas->size(); i++)
	{
		hormigas->at(i)->SetPosition(GetPosX(), GetPosY());
		hormigas->at(i)->Revive();
	}
}

vector<Hormiga*>* Hormiguero::GetHormigas() const
{
	return hormigas;
}
