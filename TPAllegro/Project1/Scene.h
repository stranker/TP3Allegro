#ifndef SCENE_H
#define SCENE_H

#include "Resources.h"

using namespace std;

class Scene
{
private:
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT ev;
	bool sceneRunning;
	bool redraw = true;
public:
	Scene();
	~Scene();
	int Initialize();
	int EventInit();
	int CreateWindow();
	int CreateTimer();
	void EventManager();
	bool CanDraw() const;
	virtual int Run() = 0;
	virtual void Update() = 0;
	bool IsRunning() const;
	ALLEGRO_DISPLAY* GetDisplay();
	ALLEGRO_EVENT_QUEUE* GetEventQueue();
	ALLEGRO_TIMER* GetTimer();
	ALLEGRO_EVENT GetEvent() const;
	void SetRedraw(bool val);
	void SetRunning(bool val);
};

#endif