#include "UserIteractionManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

void UserIteractionManager::start_listening(sf::RenderWindow& window) {
	sf::Event event;   // create an event;
	if (window.pollEvent(event))
	{
		//window will be closed after pressing ESC
	        if(event.type == sf::Event::Closed)
	          {
	             window.close();
                   }
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
			std::cout<<"event case 1"<<std::endl;
			m_delegate->did_press_key(UserActionKeyEscape);   
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
		{	
			m_delegate->did_press_key(UserActionKeySpace);
		}
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
		{
			std::cout<<"event case 3"<<std::endl;
			m_delegate->did_press_key(UserActionKeyPause);
		}

	}
}

void UserIteractionManager::wait_for_action(sf::RenderWindow& window) {
	sf::Event event;
	while(window.isOpen()) 
	{
		if(window.pollEvent(event)) {
			std::cout<<"event"<<std::endl;
			if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
				m_delegate->did_press_key(UserActionKeyEscape);
				break;
			}
		}
	}
}

void UserIteractionManager::wait_for_action_after_game_over(sf::RenderWindow& window) {
	sf::Event event;
	while(window.isOpen()) 
	{
	  if(window.pollEvent(event)) {

	    if(event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
	 exit(1);
    }
}
	}
}

