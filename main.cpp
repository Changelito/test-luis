
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <complex>
#include <sstream>
#include "ComplexPlane.h"

int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    int width = desktopMode.width / 2;
    int height = desktopMode.height / 2;
    
    sf::RenderWindow window(sf::VideoMode(width, height), "Mandelbrot Set");
    ComplexPlane complexPlane(width, height);
    
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;  // Error cargando la fuente
    }
    sf::Text text("", font, 14);
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (event.mouseButton.button == sf::Mouse::Left) {
                    complexPlane.zoomIn();
                    complexPlane.setCenter(mousePos);
                } else if (event.mouseButton.button == sf::Mouse::Right) {
                    complexPlane.zoomOut();
                    complexPlane.setCenter(mousePos);
                }
            }
            if (event.type == sf::Event::MouseMoved) {
                complexPlane.setMouseLocation(sf::Mouse::getPosition(window));
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        complexPlane.updateRender();
        complexPlane.loadText(text);

        window.clear();
        window.draw(complexPlane);
        window.draw(text);
        window.display();
    }

    return 0;
}
