#include "Renderer.h" 
#include<iostream>
Renderer::Renderer() : m_window(sf::VideoMode(ActualBoardWidth, ActualBoardHeight), "Flappy Bird"), m_sound()
{
	this->m_buffer.loadFromFile("music/flappy_bird.wav");
	m_sound.setBuffer(this->m_buffer);
	m_sound.setLoop(true);
	m_sound.play();

	this->cit = true;
}

void Renderer::render(FlappyCit const & cit, int offset) {
	this->cit=! this->cit;
	UserIteractionManager user; //HETO PETQA JNJEL ES     

	if (this->m_window.isOpen())  //main loop
	{
		user.start_listening(m_window);
		// sf::Texture texture;
	        // std::cout<<cit.get_origin().x<<" "<<cit.get_origin().x+cit.get_size().width;
		if (!m_texture.loadFromFile("pics/background.png"))
		{      
			sf::String Text("Can't load background picture");
		}
		sf::Sprite background(m_texture);
		this->m_window.draw(background);
		sf::Texture flappy_tex;
		sf::Sprite flappy;	
		if (this->cit) {
			assert(flappy_tex.loadFromFile("pics/flappy.png"));
		}
		else {
			assert(flappy_tex.loadFromFile("pics/flappy_2.png"));
		}
		flappy.setTexture(flappy_tex);
		flappy.setPosition(cit.get_origin().x - offset + RenderingOffset,cit.get_origin().y);
	  std::cout<<cit.get_origin().x<<" "<<cit.get_origin().x+cit.get_size().width;
		//flappy.setOrigin(flappy_tex.getSize().x / 2, flappy_tex.getSize().y / 2);
		this->m_window.draw(flappy);
	}
}

void Renderer::render(std::vector<Barrier> const & objects, FlappyCit const & cit, int offset) {
		if (this->m_window.isOpen())  //main loop
		{      
                 	                


			render(cit, offset);
			for (auto &barrier : objects) {
				if (barrier.get_origin().x - offset < ActualBoardWidth) {
					this->render_barrier(barrier.get_origin(), barrier.get_size(),offset);
				}
				else {
					break;
				}
			}
			this->m_window.display();
		}
}

void Renderer::render_flappy_cit(Point origin, Size size,int offset) {

}

void Renderer::render_barrier(Point origin, Size size, int offset) {
	sf::Texture barrier_tex;
	sf::Sprite barrier;
	sf::Tecture barrierTopTexture;
	sf::Sprite barrierTop;
	if (origin.y == BarrierUpInitialOriginY) {
		assert(barrier_tex.loadFromFile("pics/barrier.png"));
	        assert(barrierTopTexture.loadFromFile("pics/barrier_up.png"));
		}
	else {
		assert(barrier_tex.loadFromFile("pics/barrier.png"));
	        assert(barrierTopTexture.loadFromFile("pics/barrier_down.png"));
	      	}
	barrier.setTexture(barrier_tex);
//	barrier.setPosition(200,50);
	barrier.setPosition(origin.x-offset, origin.y);
	//barrier.move(origin.x-offset,origin.y+size.height/2);
	   barrier.setScale(1,size.height/116.f);
//	barrier.scale(1,size.height/116);
//	barrier.setOrigin(origin.x-offset,origin.y);
	this->m_window.draw(barrier);
}

bool Renderer::is_open() {

	return this->m_window.isOpen();
}
