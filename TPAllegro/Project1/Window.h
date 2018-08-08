#ifndef WINDOW_H
#define WINDOW_H

#include "Resources.h"

class Window
{
private:
	ALLEGRO_DISPLAY * display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_EVENT ev;
	bool isOpen = true;
	bool redraw = true;
public:
	Window();
	~Window();
	int Initialize();
	ALLEGRO_DISPLAY* GetDisplay();
	ALLEGRO_EVENT_QUEUE* GetEventQueue();
	ALLEGRO_TIMER* GetTimer();
	ALLEGRO_EVENT GetEvent() const;
	void EventManager();
	int EventInit();
	int CreateTimer();
	int CreateWindow();
	bool CanDraw() const;
	bool IsOpen() const;
	void Draw();
};

#endif