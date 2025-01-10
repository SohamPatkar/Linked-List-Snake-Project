#pragma once

namespace Level
{
	class LevelController;
	enum class LevelNumber;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void destroy();
		void createLevelController();

	public:
		LevelService();
		~LevelService();

		void createLevel(LevelNumber level_to_load);
		void initialize();
		void update();
		void render();
	};
}