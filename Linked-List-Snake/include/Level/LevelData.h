#pragma once
#include "Level/LevelNumber.h"

namespace Level
{
	struct LevelData
	{
		LevelNumber level_number;
		
		LevelData(LevelNumber ind)
		{
			level_number = ind;
		}
	};
}