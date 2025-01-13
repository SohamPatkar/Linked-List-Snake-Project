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

	public:
		LevelService();
		~LevelService();

		void createLevel(LevelNumber level_to_load);
		void initialize();
		void update();
		void render();
	};
}