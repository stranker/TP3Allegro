#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}


bool Scene::IsRunning() const
{
	return sceneRunning;
}

void Scene::SetRunning(bool val)
{
	sceneRunning = val;
}

void Scene::SetWindow(Window * _window)
{
	window = _window;
}

Window * Scene::GetWindow()
{
	return window;
}
