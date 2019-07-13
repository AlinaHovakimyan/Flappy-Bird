#ifndef GAMEENGINE_h
#define GAMEENGINE_h

#include "PhysicBody.h"
#include "PhysicsEngine.h"
#include "PhysicWorld.h"
#include "PhysicWorldDelegate.h"
#include "Barrier.h"
#include "Cit.h"
#include "FlappyCit.h"
#include "GameObject.h"
#include "UserIteractionManager.h"
#include "UserIteractionDelegate.h"
#include "LevelManager.h"
#include "Definitions.h"
#include "Renderer.h"
#include <SFML/Graphics.hpp>
#include <vector>
	
class GameEngine :public PhysicWorldDelegate, UserIteractionDelegate {
private:
	UserIteractionManager m_userIteraction;
	FlappyCit m_flappyCit;
	std::vector<Barrier> m_barriers;
	sf::Clock m_clock;
	Renderer m_renderer;
	LevelManager m_levelManager;
	PhysicWorld m_physicWorld;
	bool m_is_running;
	bool space_pressed;
	int m_fpsCounter;

private: // Utilities
	void did_press_space();
	void did_press_escape();
	void did_press_pause();

public:
	GameEngine();

	void fatal_collision();
	void update_cit(Rect frame);
	void remove_barriers_front();

	void did_press_key(UserActionKey);
	void timer_start();
};

#endif
