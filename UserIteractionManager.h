#ifndef USERITERACTIONMANAGER_H
#define USERITERACTIONMANAGER_H

#include "UserIteractionDelegate.h"
#include <SFML/Graphics.hpp>

class UserIteractionManager {
private:
	UserIteractionDelegate * m_delegate;
public:
	//	UserInteractionManager();
	void start_listening(sf::RenderWindow& window);
	void wait_for_action(sf::RenderWindow& window);
	void wait_for_action_after_game_over(sf::RenderWindow& window);	
	void set_delegate(UserIteractionDelegate * delegate)
	{
		m_delegate = delegate;
	}
};

#endif
