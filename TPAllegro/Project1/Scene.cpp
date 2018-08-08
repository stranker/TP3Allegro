#include "Scene.h"

Scene::Scene(int _SCREEN_W, int _SCREEN_H, int _FPS)
{
	SCREEN_W = _SCREEN_W;
	SCREEN_H = _SCREEN_H;
	FPS = _FPS;
	Initialize();
}

Scene::~Scene()
{
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
}

int Scene::Initialize()
{
	// SE INICIALIZA LA LIBRERIA ALLEGRO
	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	// SE INICIALIZA SOPORTE IMAGENES
	if (!al_init_image_addon()) {
		al_show_native_message_box(display, "Error", "Error", "Failed to initialize al_init_image_addon!",
			NULL, ALLEGRO_MESSAGEBOX_ERROR);
		return 0;
	}
	// SE INICIALIZA EL TECLADO
	if (!al_install_keyboard())
	{
		fprintf(stderr, "failed to initialize the Keyboard!\n");
		return -1;
	}
	// SE INICIALIZA AUDIO
	if (!al_install_audio()) {
		fprintf(stderr, "failed to initialize audio!\n");
		return -1;
	}

	if (!al_init_acodec_addon()) {
		fprintf(stderr, "failed to initialize audio codecs!\n");
		return -1;
	}

	if (!al_reserve_samples(4)) {
		fprintf(stderr, "failed to reserve samples!\n");
		return -1;
	}
	// SE INICIALIZA LOS FONT
	al_init_font_addon();
	al_init_ttf_addon();
	// SE CREA DELTA TIME COMO TIMER
	CreateTimer();
	// SE CREA LA VENTANA
	CreateWindow();
	// SE CREA INPUT
	EventInit();
	al_set_target_bitmap(al_get_backbuffer(display));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_clear_to_color(al_map_rgb(50, 75, 0));
	al_flip_display();
	al_start_timer(timer);
	return 0;
}

int Scene::EventInit()
{
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	return 0;
}

int Scene::CreateWindow()
{
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}
	return 0;
}

int Scene::CreateTimer()
{
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
	return 0;
}

void Scene::EventManager()
{
	al_wait_for_event(event_queue, &ev);
	// DIBUJAR DE NUEVO
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		redraw = true;
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		sceneRunning = false;
	}
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			sceneRunning = false;
		}
	}
}

bool Scene::CanDraw() const
{
	return redraw && al_is_event_queue_empty(event_queue);
}

bool Scene::IsRunning() const
{
	return sceneRunning;
}


ALLEGRO_DISPLAY * Scene::GetDisplay()
{
	return display;
}

ALLEGRO_EVENT_QUEUE * Scene::GetEventQueue()
{
	return event_queue;
}

ALLEGRO_TIMER * Scene::GetTimer()
{
	return timer;
}

ALLEGRO_EVENT Scene::GetEvent() const
{
	return ev;
}

void Scene::SetRedraw(bool val)
{
	redraw = val;
}

void Scene::SetRunning(bool val)
{
	sceneRunning = val;
}

int Scene::GetScreenW() const
{
	return SCREEN_W;
}

int Scene::GetScreenH() const
{
	return SCREEN_H;
}
