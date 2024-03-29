#include "MenuButton.h"
#include <iostream>

namespace neulii {

	void MenuButton::render(sf::RenderWindow& window) {

		window.draw(shadow);
		window.draw(buttonShape);
		window.draw(this->buttonText);
	}
	void MenuButton::update(long dT) {

		shadow.setPosition(x - 2, y - 2);
		shadow.setFillColor(sf::Color::Yellow);
		shadow.setSize(sf::Vector2f(width, height));

		if (isHoovered)
		{
			this->drawBackgroundcolor = this->hooverBackgroundColor;
			this->drawTextColor = this->hooverTextColor;
		}

		else
		{
			this->drawBackgroundcolor = this->normalBackgroundColor;
			this->drawTextColor = this->normalTextColor;
		}

		if (isPressed) {
			buttonShape.setPosition(x - 2, y - 2);
			buttonText.setPosition(buttonTextPosX - 2, buttonTextPosY - 2);
		}
		else {
			buttonShape.setPosition(x, y);
			buttonText.setPosition(buttonTextPosX, buttonTextPosY);
		}

		buttonShape.setFillColor(drawBackgroundcolor);
		buttonText.setFillColor(drawTextColor);
	}

	void MenuButton::setHoovered(bool hoovered) {
		this->isHoovered = hoovered;
	}

	MenuButton::MenuButton(std::string buttonText, float x, float y, float width, float height)
	{
		this->x = x;
		this->y = y;
		this->height = height;
		this->width = width;

		if (!buttonFont.loadFromFile("resources/fonts/arial.ttf")) {
			std::cout << "Fehler beim Laden der button-Schrift";

		}
		//else
		//	std::cout << "Button-Font from button \"" << buttonText << "\" loaded" << std::endl;

		drawBackgroundcolor = normalBackgroundColor;
		drawTextColor = normalBackgroundColor;

		buttonShape.setSize(sf::Vector2f(width, height));
		buttonShape.setPosition(sf::Vector2f(x, y));
		buttonShape.setFillColor(normalBackgroundColor);
		/*buttonShape.setOutlineThickness(1);
		buttonShape.setOutlineColor(sf::Color::Red);*/

		this->buttonText.setFont(buttonFont);
		this->buttonText.setString(buttonText);
		this->buttonText.setCharacterSize(20);

		this->buttonTextPosX = x + (width - this->buttonText.getLocalBounds().width) / 2;
		this->buttonTextPosY = y + (height - this->buttonText.getLocalBounds().height) / 2;

		this->buttonText.setPosition(buttonTextPosX, buttonTextPosY);
		this->buttonText.setFillColor(normalTextColor);
	}

	MenuButton::~MenuButton()
	{
	}

	sf::FloatRect MenuButton::getButtonBounds() {
		return buttonShape.getGlobalBounds();
	}

	void MenuButton::setPressed(bool pressed) {
		this->isPressed = pressed;
	}

	bool MenuButton::getIsHoovered() {
		return isHoovered;
	}

	bool MenuButton::getIsPressed() {
		return this->isPressed;
	}

	std::string MenuButton::getButtonText() {
		return this->buttonText.getString();
	}

}