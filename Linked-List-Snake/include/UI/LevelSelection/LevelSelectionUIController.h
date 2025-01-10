#pragma once
#include "../Interface/IUIController.h"'


namespace UI
{
	namespace UIElement
	{
		class ImageView;
		class ButtonView;
	}

	namespace LevelSelection
	{
		class LevelSelectionUIController : public Interface::IUIController
		{
		private:
			UIElement::ImageView* background_image;
			UIElement::ButtonView* level_one_button;
			UIElement::ButtonView* level_two_button;
			UIElement::ButtonView* menu_button;

			const float button_width = 400.f;
			const float button_height = 140.f;

			const float level_one_y_position = 500.f;
			const float level_two_y_position = 700.f;
			const float main_menu_y_position = 900.f;

			float background_alpha = 85.f;

		public:
			LevelSelectionUIController();
			~LevelSelectionUIController();

			void initialize()override;
			void update()override;
			void render()override;
			void show() override;

			void levelOneButtonCallback();
			void levelTwoButtonCallback();
			void menuButtonCallback();
			void registerButtonCallback();

			void initializeButtons();
			void initializeBackgroundImage();
		};
	}
}