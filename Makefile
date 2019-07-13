LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all:
	@echo "** Building the game"
	g++ -g -std=c++11 -c "Barrier.cpp"  -o Barrier.o
	g++ -g -std=c++11 -c "Cit.cpp" -o Cit.o
	g++ -g -std=c++11 -c "FlappyCit.cpp"  -o FlappyCit.o
	g++ -g -std=c++11 -c "GameEngine.cpp" -o GameEngine.o
	g++ -g -std=c++11 -c "GameObject.cpp" -o GameObject.o
	g++ -g -std=c++11 -c "LevelManager.cpp" -o LevelManager.o
	g++ -g -std=c++11 -c "Main.cpp" -o  Main.o
	g++ -g -std=c++11 -c "PhysicBody.cpp" -o PhysicBody.o
	g++ -g -std=c++11 -c "PhysicsEngine.cpp" -o PhysicEngine.o
	g++ -g -std=c++11 -c "PhysicWorld.cpp" -o PhysicWorld.o
	g++ -g -std=c++11 -c "Renderer.cpp" -o Renderer.o
	g++ -g -std=c++11 -c "StdFlapp.cpp"  -o StdFlapp.o
	g++ -g -std=c++11 -c "UserIteractionManager.cpp" -o UserIteractionManager.o
	g++ -o sfml-app Barrier.o Cit.o  FlappyCit.o GameEngine.o  GameObject.o LevelManager.o Main.o PhysicBody.o PhysicEngine.o PhysicWorld.o Renderer.o StdFlapp.o UserIteractionManager.o $(LIBS)

clean:
	@echo "** Removing object files and executable..."
	 rm -f thegame

install:
	 @echo '** Installing...'
	 cp thegame /usr/bin

uninstall:
	@echo '** Uninstalling...'
	rm thegame
