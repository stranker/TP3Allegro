#include "Game.h"

Game::Game(int _SCREEN_W, int _SCREEN_H, int _FPS)
{
	SCREEN_W = _SCREEN_W;
	SCREEN_H = _SCREEN_H;
	FPS = _FPS;
	Initialize();
}

Game::~Game()
{
	// SE DESTRUYEN LOS OBJETOS
	al_destroy_timer(timer);
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	delete caracol;
	delete saleros;
	delete tortugas;
}

int Game::Initialize()
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
	// SE CREA DELTA TIME COMO TIMER
	CreateTimer();
	// SE CREA LA VENTANA
	CreateWindow();
	// SE CREAN PERSONAJES
	caracol = new Caracol(SCREEN_W / 2, SCREEN_H / 2);
	saleros = new vector<Sal*>;
	tortugas = new vector<Tortuga*>;
	for (int i = 0; i < CANT_SALEROS; i++)
		saleros->push_back(new Sal(SCREEN_W, SCREEN_H));
	for (int i = 0; i < CANT_TORTUGAS; i++)
		tortugas->push_back(new Tortuga(SCREEN_W, SCREEN_H));
	// SE CREA INPUT
	EventInit();
	// SE REGISTRAN IMAGENES Y EVENTOS
	al_set_target_bitmap(caracol->GetSprite());
	al_set_target_bitmap(caracol->GetRayo()->GetSprite());
	for (int i = 0; i < CANT_SALEROS; i++)
		al_set_target_bitmap(saleros->at(i)->GetSprite());
	for (int i = 0; i < CANT_TORTUGAS; i++)
		al_set_target_bitmap(tortugas->at(i)->GetSprite());
	al_set_target_bitmap(al_get_backbuffer(display));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(50, 75, 0));
	al_flip_display();
	al_start_timer(timer);

	return 0;
}

void Game::Update()
{
	ALLEGRO_EVENT ev;
	al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		redraw = true;
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
		gameOver = true;
	}
	// UPDATE DE LOS PERSONAJES
	caracol->Update(ev, SCREEN_W, SCREEN_H);
	for (int i = 0; i < CANT_SALEROS; i++)
		saleros->at(i)->Update(SCREEN_W, SCREEN_H);
	for (int i = 0; i < CANT_TORTUGAS; i++)
		tortugas->at(i)->Update(SCREEN_W, SCREEN_H);
	// COLLISION
	for (int i = 0; i < CANT_SALEROS; i++)
	{
		if (Collision::AABB(caracol, saleros->at(i)))
			caracol->SetPosition(SCREEN_W / 2, SCREEN_H / 2);
		if (Collision::AABB(caracol->GetRayo(), saleros->at(i)))
		{
			saleros->at(i)->Kill(SCREEN_W,SCREEN_H);
			caracol->GetRayo()->SetActivated(false);
		}
	}
	
	for (int i = 0; i < CANT_TORTUGAS; i++)
	{
		if (Collision::AABB(caracol, tortugas->at(i)))
			caracol->SetPosition(SCREEN_W / 2, SCREEN_H / 2);
		if (Collision::AABB(caracol->GetRayo(), tortugas->at(i)))
		{
			tortugas->at(i)->Kill(SCREEN_W, SCREEN_H);
			caracol->GetRayo()->SetActivated(false);
		}
	}
}

void Game::Draw()
{
	if (redraw && al_is_event_queue_empty(event_queue)) {
		redraw = false;
		al_clear_to_color(al_map_rgb(50, 75, 0));
		caracol->Draw();
		if (caracol->GetRayo()->GetActivated())
			caracol->GetRayo()->Draw();
		for (int i = 0; i < CANT_SALEROS; i++)
			saleros->at(i)->Draw();
		for (int i = 0; i < CANT_TORTUGAS; i++)
			tortugas->at(i)->Draw();
		al_flip_display();
	}
}

int Game::EventInit()
{
	event_queue = al_create_event_queue();
	if (!event_queue) {
		fprintf(stderr, "failed to create event_queue!\n");
		delete caracol;
		delete saleros;
		delete tortugas;
		al_destroy_display(display);
		al_destroy_timer(timer);
		return -1;
	}
	return 0;
}

int Game::CreateWindow()
{
	display = al_create_display(SCREEN_W, SCREEN_H);
	if (!display) {
		fprintf(stderr, "failed to create display!\n");
		al_destroy_timer(timer);
		return -1;
	}
	return 0;
}

int Game::CreateTimer()
{
	timer = al_create_timer(1.0 / FPS);
	if (!timer) {
		fprintf(stderr, "failed to create timer!\n");
		return -1;
	}
	return 0;
}

bool Game::IsGameOver()
{
	return gameOver;
}