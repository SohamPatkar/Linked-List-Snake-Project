#include "../../include/Level/LevelService.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Element/ElementData.h"

namespace Level
{
	using namespace Global;
	using namespace Element;

	LevelService::LevelService()
	{
		createLevelController();
	}

	LevelService::~LevelService()
	{
		destroy();
	}

	void LevelService::createLevel(LevelNumber level_to_load)
	{
		current_level = level_to_load;
		spawnLevelElements(level_to_load);
		spawnPlayer();
	}

	void LevelService::createLevelController()
	{
		level_controller = new LevelController();
	}

	void LevelService::spawnPlayer()
	{
		Global::ServiceLocator::getInstance()->getPlayerService()->spawnPlayer();
	}

	void LevelService::initialize()
	{
		level_controller->initialize();
	}

	void LevelService::update()
	{
		level_controller->update();
	}

	void LevelService::render()
	{
		level_controller->render();
	}

	void LevelService::destroy()
	{
		delete(level_controller);
	}

	float LevelService::getCellHeight()
	{
		return level_controller->getCellHeight();
	}

	float LevelService::getCellWidth()
	{
		return level_controller->getCellWidth();
	}

	void LevelService::spawnLevelElements(LevelNumber level_to_load)
	{
		float cell_width = level_controller->getCellWidth();
		float cell_height = level_controller->getCellHeight();

		std::vector<ElementData> element_data_list = level_controller->getElementDataList((int)level_to_load);
		ServiceLocator::getInstance()->getElementService()->spawnElements(element_data_list, cell_width, cell_height);
	}
}
