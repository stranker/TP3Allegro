#include "GameScene.h"

GameScene::GameScene()
{
	Initialize();
}

GameScene::~GameScene()
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

void GameScene::Initialize()
{
	titleFont = al_load_ttf_font("Asset/Font/consola.ttf", 72, 0);
	menuFont = al_load_ttf_font("Asset/Font/consola.ttf", 28, 0);
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
	lives->clear();
	for (int i = 0; i < caracol->GetLives(); i++)
		lives->push_back(new Sprite(5 + i * 70, 5, "Asset/Sprite/corazon.png", 0, 0));
	hormiguero->Initialize();
}

int GameScene::Run(Window* window)
{
	SetRunning(true);
	SetWindow(window);
	al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
	ResetGame();
	while (IsRunning() && !gameOver)
	{
		Update();
		Draw();
	}
	al_stop_samples();
	return GAME_OVER_SCENE;
}

void GameScene::Update()
{
	GetWindow()->EventManager();
	if (GetWindow()->GetEvent().keyboard.keycode == ALLEGRO_KEY_ESCAPE)
	{
		al_rest(0.2);
		SetRunning(false);
		GetWindow()->Close();
	}
	if (GetWindow()->GetEvent().type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
		al_rest(0.2);
		SetRunning(false);
	}
	// UPDATE DE LOS PERSONAJES
	caracol->Update(GetWindow()->GetEvent());
	for (int i = 0; i < CANT_SALEROS; i++)
		saleros->at(i)->Update();
	for (int i = 0; i < CANT_TORTUGAS; i++)
		tortugas->at(i)->Update();
	for (int i = 0; i < hormiguero->GetHormigas()->size(); i++)
		hormiguero->GetHormigas()->at(i)->Update();
	if (al_get_timer_count(GetWindow()->GetTimer()) % 600 == 0)
		hormiguero->Reset();
	// COLLISION
	for (int i = 0; i < CANT_SALEROS; i++)
	{
		caracol->Collision(saleros->at(i));
		caracol->GetRayo()->Collision(saleros->at(i));
	}
	for (int i = 0; i < CANT_TORTUGAS; i++)
	{
		caracol->Collision(tortugas->at(i));
		caracol->GetRayo()->Collision(tortugas->at(i));
	}
	for (int i = 0; i < hormiguero->GetHormigas()->size(); i++)
	{
		caracol->Collision(hormiguero->GetHormigas()->at(i));
		caracol->GetRayo()->Collision(hormiguero->GetHormigas()->at(i));
	}
	// CHECK VIDA PERSONAJE
	if (!caracol->IsAlive())
	{
		gameOver = true;
		al_rest(1);
		SetRunning(false);
	}
}

void GameScene::Draw()
{
	if (GetWindow()->CanDraw())
	{
		GetWindow()->Draw();
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
		string scoreText = "SCORE " + to_string(gameScore);
		al_draw_text(menuFont, al_map_rgb(0, 0, 0), SCREEN_W / 2, 10, ALLEGRO_ALIGN_CENTRE, scoreText.c_str());
		caracol->Draw();
		al_flip_display();
	}
}

bool GameScene::IsGameOver() const
{
	return gameOver;
}

void GameScene::ResetGame()
{
	gameOver = false;
	caracol->ResetStats();
	lives->clear();
	for (int i = 0; i < caracol->GetLives(); i++)
		lives->push_back(new Sprite(5 + i * 70, 5, "Asset/Sprite/corazon.png", 0, 0));
	gameScore = 0;
}
