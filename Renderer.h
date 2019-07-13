#ifndef RENDERER_H
#define RENDERER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>
#include <assert.h>
#include <vector>
#include <sstream>
#include "UserIteractionManager.h"
#include "GameObject.h"
#include "FlappyCit.h"
#include "Barrier.h"

class Renderer {
private:
	bool cit;
	int m_score;
	sf::SoundBuffer m_buffer;
	sf::Sound m_sound;
	sf::Texture m_texture;
	//sf::Sprite m_background;
public:
	sf::RenderWindow m_window;
public:
	Renderer();
	void render_pause_state();
	void render(FlappyCit const &, int offset);
	void render(std::vector<Barrier> const &, FlappyCit const &, int offset);
	void render_flappy_cit(Point origin, Size size,int offset);   
	void render_barrier(Point origin, Size size,int offset); 
//	void start_listening(UserIteractionManager &);
	void render_game_over_state();
	void show_logo();
	void display();
	bool is_open();
};

#endif
