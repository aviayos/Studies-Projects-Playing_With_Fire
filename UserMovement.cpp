#include "UserMovement.h"
#include "Player.h"



UserMovement::UserMovement(Player * obj) :MoveBehavior::MoveBehavior(obj)
{
	
}


UserMovement::~UserMovement()
{
}

void UserMovement::MoveTo(Direction_t dir)
{
	float speed = m_obj.getSpeed();
	sf::Vector2f new_pos = m_obj.getPosition();
	switch (dir)
	{
	case Right_t: new_pos += {speed, 0};
				  break;
	case Left_t: new_pos += {-speed, 0};
				 break;
	case Up_t: new_pos += {0,-speed};
				break;
	case Down_t: new_pos += {0,speed};
				 break;
	}
	
	m_obj.setPosition(new_pos);
	if (clock.getElapsedTime().asSeconds() > 0.2f) {
		m_obj.incStep();
		clock.restart();
	}
	

}
