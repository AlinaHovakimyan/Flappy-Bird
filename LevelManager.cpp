#include "LevelManager.h"
#include <iostream>

LevelManager::LevelManager(int maxCount, int width, int height)
{
	m_barrierMaxCount = maxCount;

	m_minBarrierTunel = 3 * height;
	m_maxBarrierTunel = 4 * height;

	m_minDistenceBetweenBarriers = static_cast<int>(2 * width);
	m_maxDistenceBetweenBarriers = static_cast<int>(2.5 * width);

	m_board = { BoardWidth, BoardHeight };
	m_maxBarrierHeight = m_board.height - m_minBarrierTunel - 3 * height;
	m_barrierWidth = BarrierInitialWidth;

	std::srand(time(NULL));
}

LevelManager::~LevelManager()
{
}

std::vector<Barrier> LevelManager::generate_barriers(std::vector<Barrier>& barriers)
{
	std::vector<Barrier> newBarriers;
	std::cout<<"generate"<<std::endl;
	int startingX = 2 * m_board.width;
	if (barriers.size() != 0) {
		startingX = barriers.back().get_origin().x;
	}
	while (barriers.size() < m_barrierMaxCount) {
		int originX = std::rand() % ( m_maxDistenceBetweenBarriers -  m_minDistenceBetweenBarriers ) + m_minDistenceBetweenBarriers + startingX + m_barrierWidth;
		int originY = BarrierUpInitialOriginY;
		Point origin = { originX,originY };

		int height = std::rand() % m_maxBarrierHeight + m_minBarrierTunel / 4;
		int width = m_barrierWidth;
		Size size = { width, height };

		Barrier barrierUp(origin, size);

		height = std::rand() % (m_board.height - barrierUp.get_size().height - m_minBarrierTunel) + m_minBarrierTunel / 4;
	        if( m_board.height - size.height - m_maxBarrierTunel > height ) {
	               height = m_board.height - size.height - m_maxBarrierTunel; 
	        }
		originY = m_board.height - height;
		origin = { originX,originY };
		size = { width,height };

		Barrier barrierDown(origin, size);
		newBarriers.push_back(barrierUp);
		newBarriers.push_back(barrierDown);
		barriers.push_back(barrierUp);
		barriers.push_back(barrierDown);
		startingX = originX;
	}
	return newBarriers;
}
