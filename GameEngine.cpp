#include "GameEngine.h"
#include<iostream>

GameEngine::GameEngine()
	: m_levelManager(BarrierMaxCount, FlappyInitialWidth, FlappyInitialHeight),
	m_userIteraction(),
	m_renderer(), 
	m_flappyCit(),
	m_physicWorld(m_flappyCit.physic_body())
{
	std::cout<<"Game Engine Constructs: "<<std::endl;
	m_userIteraction.set_delegate(this);
	m_levelManager.generate_barriers(m_barriers);
        space_pressed = false;  	
	for (auto &barrier : m_barriers) {
		m_physicWorld.add_barrier(barrier.physic_body());
	}
	m_physicWorld.set_delegate(this);
	m_physicWorld.set_cit_velocity({DefaultHorizontalVelocity,0});
	timer_start();
}

void GameEngine::fatal_collision()
{
	std::cout<<"hello world"<<std::endl;
	//m_renderer.render_game_over_state();
	int drawingOffset = m_flappyCit.get_origin().x - (BoardWidth - FlappyInitialWidth) / 2;
	m_renderer.render(m_barriers, m_flappyCit, drawingOffset);
	m_renderer.render_game_over_state();
	m_renderer.display();
	m_is_running = false;
//	m_userIteraction.wait_for_action(m_renderer.m_window);
	m_userIteraction.wait_for_action_after_game_over(m_renderer.m_window);
}

void GameEngine::update_cit( Rect frame)
{
	m_flappyCit.update_state(frame);
}

void GameEngine::remove_barriers_front()
{
	if(m_barriers.size() <= BarrierMinCount)
	{	
		for (auto &barrier : m_levelManager.generate_barriers(m_barriers)) {
			m_physicWorld.add_barrier(barrier.physic_body());
		}
	} 
	m_barriers.erase(m_barriers.begin());
	m_barriers.erase(m_barriers.begin());
}

void GameEngine::timer_start()
{      
	 m_is_running=true;
	const float FPS = 30.0f; //The desired FPS. (The number of updates each second).

	while (m_renderer.is_open())
	{
		if (m_is_running && m_clock.getElapsedTime().asSeconds() >= 1.0f / FPS)
		{
			m_userIteraction.start_listening(m_renderer.m_window);
			m_fpsCounter = (m_fpsCounter + 1);
			int drawing_offset = m_flappyCit.get_origin().x - (BoardWidth - FlappyInitialWidth) / 2;
			m_physicWorld.fps_action();
		if(!space_pressed)
		 {
		   m_renderer.show_logo();
		}
		m_renderer.render(m_barriers, m_flappyCit, drawing_offset);
		m_renderer.display();
	                m_clock.restart();
		}
	}
}

void GameEngine::did_press_space()
{
	m_physicWorld.set_gravity_acceleration(GravityAccelaration);
	m_physicWorld.set_cit_velocity({ DefaultHorizontalVelocity, DefaultVerticalVelocity });
	space_pressed = true;
}

void GameEngine::did_press_pause()
{
	m_is_running = false;
	m_userIteraction.wait_for_action(m_renderer.m_window);
}

void GameEngine::did_press_escape()
{
	std::cout<<"escape pressed"<<std::endl;
	m_is_running = true;
	m_clock.restart();
}

void GameEngine::did_press_key(UserActionKey userActionKey)
{
	switch (userActionKey) {
	case UserActionKeySpace: did_press_space(); break;
	case UserActionKeyEscape: did_press_escape(); break;
	case UserActionKeyPause: did_press_pause(); break;
	}
}

