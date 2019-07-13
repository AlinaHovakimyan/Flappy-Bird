#include "Renderer.h" 
#include<iostream>

Renderer::Renderer() : m_window(sf::VideoMode(ActualBoardWidth, ActualBoardHeight), "Flappy Bird"), m_sound()
{
	this->m_buffer.loadFromFile("music/flappy_bird.wav");
	m_sound.setBuffer(this->m_buffer);
	m_sound.setLoop(true);
	m_sound.play();
	m_score =  0;
	this->cit = true;
}

void Renderer::render(FlappyCit const & cit, int offset) {
	this->cit=! this->cit;

	if (this->m_window.isOpen())  //main loop
	{
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
		flappy.setPosition(cit.get_origin().x - offset,cit.get_origin().y);
//	    std::cout<<cit.get_origin().x<<" "<<cit.get_origin().x+cit.get_size().width;
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
                   m_score = (cit.get_origin().x - ( BoardWidth - FlappyInitialWidth ) / 2 ) / 100; // the score to print
	           std::stringstream ss;  // #include <sstream>
	           ss << m_score;
	           sf::Font font;
                   font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf");
                   sf::Text text(ss.str(),font, 50);
               	text.setColor(sf::Color::Yellow);
        	text.setStyle(sf::Text::Bold);
         	m_window.draw(text);
//		this->m_window.display();
		}
}

//void Renderer::render_flappy_cit(Point origin, Size size,int offset) {}

void Renderer::render_barrier(Point origin, Size size, int offset) {
	sf::Texture barrier_tex;
	sf::Sprite barrier;
	sf::Texture barrierTopTexture;
	sf::Sprite barrierTop;
	int barrierTopImgX = origin.x - offset;
	int barrierTopImgY = origin.y;
	assert(barrier_tex.loadFromFile("pics/barrier.png"));
	if (origin.y == BarrierUpInitialOriginY) {
		barrierTopImgY = size.height - BarrierTopImgHeight;	
	    assert(barrierTopTexture.loadFromFile("pics/barrier_up.png"));
	}
	else {
	    assert(barrierTopTexture.loadFromFile("pics/barrier_down.png"));
	}
	barrierTop.setTexture(barrierTopTexture);
	barrierTop.setPosition(barrierTopImgX, barrierTopImgY);
	barrier.setTexture(barrier_tex);
	barrier.setPosition(origin.x-offset, origin.y);
	barrier.setScale(1,size.height/BarrierImgHeight);
	this->m_window.draw(barrier);
	this->m_window.draw(barrierTop);
}

bool Renderer::is_open() {

	return this->m_window.isOpen();
}

void Renderer::render_pause_state(){
	
  this->show_logo();
}

void Renderer::display() {
	this->m_window.display();
}

void Renderer::render_game_over_state(){

	/*sf::RectangleShape rectangle(sf::Vector2f(300,300));
	rectangle.setFillColor(sf::Color::Blue);
	rectangle.setPosition(250,100);
	m_window.draw(rectangle);
*/
	sf::Font font;
        font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeMono.ttf");
       sf::Texture img;
	  img.loadFromFile("pics/gameover.png");
	  sf::Sprite img_s;
	   img_s.setTexture(img); 
	  img_s.setPosition(90,0);
	m_window.draw(img_s);

       /*	sf::Text scores("Score",font,40);
	scores.setColor(sf::Color::Black);
	scores.setStyle(sf::Text::Bold);
	scores.setPosition(300,220);
	m_window.draw(scores);

	std::stringstream ss_score;
	ss_score<<m_score;
	sf::Text score(ss_score.str(),font,30);
	score.setColor(sf::Color::Black);
	score.setPosition(300,300);
	m_window.draw(score);	 */  

//	this->m_window.display();
/*	while(1){                                                           
	sf::sleep(sf::milliseconds(100));
	}
*/
}

void Renderer::show_logo(){

        sf::Texture img;
	img.loadFromFile("pics/logo.png");
	sf::Sprite img_s;
	img_s.setTexture(img); 
	img_s.setPosition(126,0);
	m_window.draw(img_s);
        m_window.display();
}
