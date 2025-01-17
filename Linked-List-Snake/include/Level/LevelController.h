#pragma once
#include <vector>

namespace Level
{
	class LevelView;
	class LevelModel;

	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

		void destroy();

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		float getCellWidth();
		float getCellHeight();

		const std::vector<Element::ElementData>& getElementDataList(int level_to_load);
	};
}