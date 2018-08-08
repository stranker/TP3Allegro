#include "GameScene.h"

Game::Game()
{
	Initialize();
}

Game::~Game()
{
	// SE DESTRUYEN LOS OBJETOS
	delete caracol;
	delete saleros;
	delete tortugas;
	delete lives;
	delete hormiguero;
	al_destroy_font(menuFont);
	al_destroy_font(titleFont);
	al_destroy_sample(music);
}

void Game::Initialize()
{
	titleFont = al_load_ttf_font("Asset/Font/consola.ttf", 72, 0);
	menuFont = al_load_ttf_font("Asset/Font/consola.ttf", 28, 0);
	//// SE INICIALIZA LA MUSICA
	music = al_load_sample("Asset/Sound/music.wav");
	// SE CREAN PERSONAJES
	caracol = new Caracol(SCREEN_W / 2, SCREEN_H / 2);
	caracol->SetPosition(SCREEN_W / 2 - caracol->GetWidth() / 2, SCREEN_H / 2 - caracol->GetHeight() / 2);
	saleros = new vector<Sal*>;
	tortugas = new vector<Tortuga*>;
	lives = new vector<Sprite*>;
	hormiguero = new Hormiguero();
	for (int i = 0; i < CANT_SALEROS; i++)
		saleros->push_back(new Sal());
	for (int i = 0; i < CANT_TORTUGAS; i++)
		tortugas->push_back(new Tortuga());
	for (int i = 0; i < caracol->GetLives(); i++)
		lives->push_back(new Sprite(5 + i * 70, 5, "Asset/Sprite/corazon.png", 0, 0));
	hormiguero->Initialize();
	// SE CREA INPUT
	EventInit();
	// SE REGISTRAN IMAGENES Y EVENTOS
	//al_set_target_bitmap(caracol->GetSprite());
	//al_set_target_bitmap(caracol->GetRayo()->GetSprite());
	for (int i = 0; i < CANT_SALEROS; i++)
		al_set_target_bitmap(saleros->at(i)->GetSprite());
	for (int i = 0; i < CANT_TORTUGAS; i++)
		al_set_target_bitmap(tortugas->at(i)->GetSprite());
	for (int i = 0; i < caracol->GetLives(); i++)
		al_set_target_bitmap(caracol->GetSprite());
	//al_set_target_bitmap(hormiguero->GetSprite());
	al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	al_set_timer_count(GetTimer(), 0);
	SetRunning(true);
}

void Game::Update()
{
	EventManager();
	// UPDATE DE LOS PERSONAJES
	caracol->Update(GetEvent());
	for (int i = 0; i < CANT_SALEROS; i++)
		saleros->at(i)->Update();
	for (int i = 0; i < CANT_TORTUGAS; i++)
		tortugas->at(i)->Update();
	for (int i = 0; i < hormiguero->GetHormigas()->size(); i++)
		hormiguero->GetHormigas()->at(i)->Update();
	if (al_get_timer_count(GetTimer()) % 600 == 0)
		hormiguero->Reset();
	// COLLISION
	for (int i = 0; i < CANT_SALEROS; i++)
	{
		if (Collision::AABB(caracol, saleros->at(i)))
		{
			caracol->Collision(saleros->at(i));
			saleros->at(i)->Kill();
		}
		if ((Collision::AABB(caracol->GetRayo(), saleros->at(i)) && caracol->GetRayo()->GetActivated()))
		{
			saleros->at(i)->Kill();
			caracol->GetRayo()->SetActivated(false);
			score += 75;
		}
	}
	for (int i = 0; i < CANT_TORTUGAS; i++)
	{
		if (Collision::AABB(caracol, tortugas->at(i)))
		{
			tortugas->at(i)->Kill();
			caracol->TakeDamage();
			caracol->SetPosition(SCREEN_W / 2 - caracol->GetWidth() / 2, SCREEN_H / 2 - caracol->GetHeight() / 2);
		}
		if ((Collision::AABB(caracol->GetRayo(), tortugas->at(i))) && caracol->GetRayo()->GetActivated())
		{
			tortugas->at(i)->Kill();
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

void Game::Draw()
{
	al_clear_to_color(al_map_rgb(20, 75, 0));
	if (caracol->GetRayo()->GetActivated())
		caracol->GetRayo()->Draw();
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
	caracol->Draw();
	al_flip_display();
}

bool Game::IsGameOver() const
{
	return gameOver;
}