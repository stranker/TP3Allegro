#ifndef SCENE_H
#define SCENE_H

#include "Window.h"

using namespace std;

class Scene
{
private:
	Window * window = NULL;
	bool sceneRunning;
public:
	Scene();
	~Scene();
	virtual int Run(Window* window) = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	bool IsRunning() const;
	void SetRunning(bool val);
	void SetWindow(Window* _window);
	Window* GetWindow();
};

#endif