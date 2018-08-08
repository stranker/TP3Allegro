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
	delete lives;
	delete hormiguero;
	al_destroy_font(menuFont);
	al_destroy_font(titleFont);
	al_destroy_sample(music);
	al_destroy_sample(titleSound);
	al_destroy_sample(gameOverSound);
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
	titleFont = al_load_ttf_font("Asset/Font/consola.ttf", 72, 0);
	menuFont = al_load_ttf_font("Asset/Font/consola.ttf", 28, 0);
	//// SE INICIALIZA LA MUSICA
	music = al_load_sample("Asset/Sound/music.wav");
	titleSound = al_load_sample("Asset/Sound/titleSound.wav");
	gameOverSound = al_load_sample("Asset/Sound/gameOver.wav");
	// SE CREA DELTA TIME COMO TIMER
	CreateTimer();
	// SE CREA LA VENTANA
	CreateWindow();
	// SE CREAN PERSONAJES
	caracol = new Caracol(SCREEN_W / 2, SCREEN_H / 2);
	caracol->SetPosition(SCREEN_W / 2 - caracol->GetWidth() / 2, SCREEN_H / 2 - caracol->GetHeight() / 2);
	saleros = new vector<Sal*>;
	tortugas = new vector<Tortuga*>;
	lives = new vector<Sprite*>;
	hormiguero = new Hormiguero(SCREEN_W,SCREEN_H);
	for (int i = 0; i < CANT_SALEROS; i++)
		saleros->push_back(new Sal(SCREEN_W, SCREEN_H));
	for (int i = 0; i < CANT_TORTUGAS; i++)
		tortugas->push_back(new Tortuga(SCREEN_W, SCREEN_H));
	for (int i = 0; i < caracol->GetLives(); i++)
		lives->push_back(new Sprite(5 + i*70,5,"Asset/Sprite/corazon.png",0,0));
	hormiguero->Initialize(SCREEN_W, SCREEN_H);
	// SE CREA INPUT
	EventInit();
	// SE REGISTRAN IMAGENES Y EVENTOS
	al_set_target_bitmap(caracol->GetSprite());
	al_set_target_bitmap(caracol->GetRayo()->GetSprite());
	for (int i = 0; i < CANT_SALEROS; i++)
		al_set_target_bitmap(saleros->at(i)->GetSprite());
	for (int i = 0; i < CANT_TORTUGAS; i++)
		al_set_target_bitmap(tortugas->at(i)->GetSprite());
	for (int i = 0; i < caracol->GetLives(); i++)
		al_set_target_bitmap(caracol->GetSprite());
	al_set_target_bitmap(hormiguero->GetSprite());
	al_set_target_bitmap(al_get_backbuffer(display));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	al_clear_to_color(al_map_rgb(50, 75, 0));
	al_flip_display();
	al_start_timer(timer);

	al_play_sample(titleSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
	isOpen = true;
	return 0;
}

void Game::Update()
{
	al_wait_for_event(event_queue, &ev);
	if (ev.type == ALLEGRO_EVENT_TIMER) {
		redraw = true;
	}
	else if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
	{
		gameOver = true;
	}
	if (ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		if (ev.keyboard.keycode == ALLEGRO_KEY_ENTER && !isRunning)
		{
			al_set_timer_count(timer,0);
			isRunning = true;
			al_rest(0.2);
			al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
			caracol->SetPosition(SCREEN_W / 2 - caracol->GetWidth() / 2, SCREEN_H / 2 - caracol->GetHeight() / 2);
		}
		if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
		{
			gameOver = true;
		}
	}
	caracol->Update(ev, SCREEN_W, SCREEN_H);
	if (isRunning)
	{
		// UPDATE DE LOS PERSONAJES
		for (int i = 0; i < CANT_SALEROS; i++)
			saleros->at(i)->Update(SCREEN_W, SCREEN_H);
		for (int i = 0; i < CANT_TORTUGAS; i++)
			tortugas->at(i)->Update(SCREEN_W, SCREEN_H);
		for (int i = 0; i < hormiguero->GetHormigas()->size(); i++)
			hormiguero->GetHormigas()->at(i)->Update(SCREEN_W,SCREEN_H);
		if (al_get_timer_count(timer) % 600 == 0)
			hormiguero->Reset(SCREEN_W, SCREEN_H);
		// COLLISION
		for (int i = 0; i < CANT_SALEROS; i++)
		{
			if (Collision::AABB(caracol, saleros->at(i)))
			{
				caracol->SetPosition(SCREEN_W / 2 - caracol->GetWidth() / 2, SCREEN_H / 2 - caracol->GetHeight() / 2);
				saleros->at(i)->Kill(SCREEN_W, SCREEN_H);
				caracol->TakeDamage();
			}
			if ((Collision::AABB(caracol->GetRayo(), saleros->at(i)) && caracol->GetRayo()->GetActivated()))
			{
				saleros->at(i)->Kill(SCREEN_W, SCREEN_H);
				caracol->GetRayo()->SetActivated(false);
				score += 75;
			}
		}
		for (int i = 0; i < CANT_TORTUGAS; i++)
		{
			if (Collision::AABB(caracol, tortugas->at(i)))
			{
				tortugas->at(i)->Kill(SCREEN_W, SCREEN_H);
				caracol->TakeDamage();
				caracol->SetPosition(SCREEN_W / 2 - caracol->GetWidth() / 2, SCREEN_H / 2 - caracol->GetHeight() / 2);
			}
			if ((Collision::AABB(caracol->GetRayo(), tortugas->at(i)))&& caracol->GetRayo()->GetActivated())
			{
				tortugas->at(i)->Kill(SCREEN_W, SCREEN_H);
				caracol->GetRayo()->SetActivated(false);
				score += 200;
			}
		}
		for (int i = 0; i < hormiguero->GetHormigas()->size(); i++)
		{
			if (Collision::AABB(caracol, hormiguero->GetHormigas()->at(i)))
			{
				if (hormiguero->GetHormigas()->at(i)->IsAlive())
				{
					hormiguero->GetHormigas()->at(i)->Kill();
					caracol->TakeDamage();
					caracol->SetPosition(SCREEN_W / 2 - caracol->GetWidth() / 2, SCREEN_H / 2 - caracol->GetHeight() / 2);
				}
			}
			if (Collision::AABB(caracol->GetRayo(), hormiguero->GetHormigas()->at(i)))
			{
				if (hormiguero->GetHormigas()->at(i)->IsAlive())
				{
					hormiguero->GetHormigas()->at(i)->Kill();
					caracol->GetRayo()->SetActivated(false);
					score += 100;
				}
			}
		}
		// CHECK VIDA PERSONAJE
		if (!caracol->isAlive())
		{
			gameOver = true;
			al_rest(1);
		}
	}
	if (gameOver)
	{
		al_stop_samples();
		al_play_sample(gameOverSound, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
		al_clear_to_color(al_map_rgb(0, 0, 0));
		al_draw_text(titleFont, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2 + 50, ALLEGRO_ALIGN_CENTRE, "GAME OVER");
		al_draw_text(titleFont, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2 - 50, ALLEGRO_ALIGN_CENTRE, ("FINAL SCORE "+ to_string(score)).c_str());
		al_flip_display();
		al_rest(4);
	}
}

void Game::Draw()
{
	if (redraw && al_is_event_queue_empty(event_queue)) {
		redraw = false;
		al_clear_to_color(al_map_rgb(50, 75, 0));
		if (caracol->GetRayo()->GetActivated())
			caracol->GetRayo()->Draw();
		if (isRunning)
		{
			hormiguero->Draw();
			for (int i = 0; i < CANT_SALEROS; i++)
				saleros->at(i)->Draw();
			for (int i = 0; i < CANT_TORTUGAS; i++)
				tortugas->at(i)->Draw();
			for (int i = 0; i < caracol->GetLives(); i++)
				lives->at(i)->Draw();
			for (int i = 0; i < hormiguero->GetHormigas()->size(); i++)
				if (hormiguero->GetHormigas()->at(i)->IsAlive())
					hormiguero->GetHormigas()->at(i)->Draw();
			string scoreText = "SCORE " + to_string(score);
			al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, 10, ALLEGRO_ALIGN_CENTRE, scoreText.c_str());
		}
		else
		{
			al_draw_text(titleFont, al_map_rgb(255, 255, 255), SCREEN_W / 2, SCREEN_H / 2 - 150, ALLEGRO_ALIGN_CENTRE, "SNAILWORM SHIM");
			al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H - 100, ALLEGRO_ALIGN_CENTRE, "PRESS ENTER TO START GAME");
			al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H - 200, ALLEGRO_ALIGN_CENTRE, "USE ARROWS TO MOVE AND SPACE TO FIRE!");
			al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, SCREEN_H - 50, ALLEGRO_ALIGN_CENTRE, "PRESS ESC TO EXIT");
		}
		caracol->Draw();
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
		delete lives;
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

bool Game::IsGameOver() const
{
	return gameOver;
}

bool Game::IsOpen() const
{
	return isOpen;
}

ALLEGRO_EVENT Game::GetEvent() const
{
	return ev;
}

ALLEGRO_DISPLAY* Game::GetDisplay() const
{
	return display;
}

ALLEGRO_EVENT_QUEUE* Game::GetEventQueue() const
{
	return event_queue;
}
