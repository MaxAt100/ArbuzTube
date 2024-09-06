#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    sf::RenderWindow window(sf::VideoMode(800, 600), "ArbuzTube", sf::Style::None);
    window.setPosition(sf::Vector2i((sf::VideoMode::getDesktopMode().width / 2) - 400,
        (sf::VideoMode::getDesktopMode().height / 2) - 300));

    sf::Clock clock;
    float opacity = 0.0f;
    sf::RectangleShape rectangle(sf::Vector2f(800.0f, 600.0f));
    rectangle.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(opacity)));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float time = clock.getElapsedTime().asSeconds();
        if (time < 1.0f) {  // Duration of the fade-in effect
            opacity = time * 255.0f;
            rectangle.setFillColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(opacity)));
        }

        window.clear();
        window.draw(rectangle);
        window.display();
    }

    return 0;
}