#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include "Definitions.h"
#include <vector>
#include "Barrier.h"
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <cstdlib>     /* srand, rand */
#include <time.h>       /* time */

class LevelManager
{
public:
	LevelManager(int maxCount, int width, int height);
	~LevelManager();
	std::vector<Barrier> generate_barriers(std::vector <Barrier>& barriers);
private:
	Size m_board;
	int m_maxBarrierHeight;
	int m_barrierWidth;
	int m_minDistenceBetweenBarriers;
	int m_maxDistenceBetweenBarriers;
	unsigned m_barrierMaxCount;
	int m_minBarrierTunel;
	int m_maxBarrierTunel;
};
#endif // !LEVELMANAGER_H

