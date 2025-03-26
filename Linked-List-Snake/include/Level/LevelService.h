#pragma once
#include "../../include/Level/LevelNumber.h"
#include "../../include/Level/LevelController.h"

namespace Level
{
	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void destroy();
		void createLevelController();
		void spawnPlayer();
		void spawnLevelElements(LevelNumber level_to_load);
		
	public:
		LevelService();
		~LevelService();

		void createLevel(LevelNumber level_to_load);
		void initialize();
		void update();
		void render();

		void spawnFood();

		float getCellWidth();
		float getCellHeight();
	};
}