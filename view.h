#include <SFML/Graphics.hpp>
sf::View view;

// Переменные для отслеживания текущего и целевого масштаба
float currentZoom = 1.0f;
float targetZoom = 1.0f;


sf::View getPlayerCoordinateForView(float x, float y) {
	float tempX = x; float tempY = y;
	//if (x < 320) tempX = 320;//убираем из вида левую сторону
	//if (y < 240) tempY = 240;//верхнюю сторону
	//if (y > 554) tempY = 554;//нижнюю сторону	
	view.setCenter(tempX, tempY);
	return view;
}
sf::View changeView() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		view.zoom(1.0001f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		view.zoom(1.0001f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		view.zoom(1.0001f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		view.zoom(1.0001f);
	}
	return view;
}