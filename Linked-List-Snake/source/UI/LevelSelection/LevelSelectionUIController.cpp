#include "../../include/UI/LevelSelection/LevelSelectionUIController.h"
#include "../../include/Global/ServiceLocator.h"
#include "../../include/Global/Config.h"
#include "../../include/Main/GameService.h"
#include "../../include/Level/LevelNumber.h"

namespace UI
{
	namespace LevelSelection
	{
		LevelSelectionUIController::LevelSelectionUIController()
		{
			background_image = new UI::UIElement::ImageView();
			level_one_button = new UI::UIElement::ButtonView();
			level_two_button = new UI::UIElement::ButtonView();
			menu_button = new UI::UIElement::ButtonView();
		}

		LevelSelectionUIController::~LevelSelectionUIController()
		{
			delete(background_image);
			delete(level_one_button);
			delete(level_two_button);
			delete(menu_button);
		}

		void LevelSelectionUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerCallback();
		}

		void LevelSelectionUIController::update()
		{

		}

		void LevelSelectionUIController::render()
		{

		}

		void LevelSelectionUIController::initializeButtons()
		{
			level_one_button->initialize("Level One", Global::Config::level_one_button_texture_path, button_width, button_height, sf::Vector2f(0, level_one_y_position));
			level_two_button->initialize("Level Two", Global::Config::level_two_button_texture_path, button_width, button_height, sf::Vector2f(0, level_two_y_position));
			menu_button->initialize("Menu", Global::Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(0, level_one_y_position));

			level_one_button->setCentreAlinged();
			level_two_button->setCentreAlinged();
			menu_button->setCentreAlinged();
		}

		void LevelSelectionUIController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = Global::ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Global::Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}

		void LevelSelectionUIController::registerCallback()
		{
			level_one_button->registerCallbackFuntion(std::bind(&singleLinkedListButtonCallback, this));
			level_two_button->registerCallbackFuntion(std::bind(&doubleLinkedListButtonCallback, this));
			menu_button->registerCallbackFuntion(std::bind(&menuButtonCallback, this));
		}
		
		void LevelSelectionUIController::singleLinkedListButtonCallback()
		{
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			Main::GameService::setGameState(Main::GameState::GAMEPLAY);
			Global::ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::ONE);
		}

		void LevelSelectionUIController::doubleLinkedListButtonCallback()
		{
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			Main::GameService::setGameState(Main::GameState::GAMEPLAY);
			Global::ServiceLocator::getInstance()->getLevelService()->createLevel(Level::LevelNumber::TWO);
		}

		void LevelSelectionUIController::menuButtonCallback()
		{
			Global::ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			Main::GameService::setGameState(Main::GameState::MAIN_MENU);
		}

		void LevelSelectionUIController::show()
		{
			background_image->show();
			level_one_button->show();
			level_two_button->show();
			menu_button->show();
		}

	}
}