#include <SFML/Graphics.hpp>
#include <iostream>
#include "GeometrVector.h"
#include <vector>

std::vector<Entity> initSnake(Entity head, int length)
{
    std::vector<Entity> container;
    for (size_t i = 0; i < length; i++)
    {
        container.push_back(
            Entity{
                head.getPosition(),
                head.getSize(),
                1.0f - 1.0f / length * i,
                head.getVelocity()
            }
        );
    }

    return container;
};

void moveSnake(Entity head, std::vector<Entity>& snake) {
    Entity curr = head;
    Entity prev = snake[0];

    snake[0] = curr;

    // Обновляем позиции и свет всех звеньев цепочки, кроме головы
    float size = static_cast<float>(snake.size());
    for (int i = 1; i < snake.size(); i++) {
        curr = prev;
        prev = snake[i];
        snake[i] = curr;

        // Обновляем свет звена
        float light = (size - i) / size;
        snake[i].setLight(light);

        // Обновляем размера звена
        float sizeOfCell = head.getSize() + i / size * head.getSize();
        snake[i].setSize(sizeOfCell);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Movement");
    window.setFramerateLimit(60);

    Entity head(
        GeometrVector{ (float)window.getSize().x / 2, (float)window.getSize().y / 2 },
        4.0f,
        1.0f,
        GeometrVector{ 0.0, 0.0 }
    );

    std::vector<Entity> snake = initSnake(head, 100);

    float impulse = 2;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            head.setVelocity(GeometrVector{ impulse, 0.0 });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            head.setVelocity(GeometrVector{ -impulse, 0.0 });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            head.setVelocity(GeometrVector{ 0.0, -impulse });
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            head.setVelocity(GeometrVector{ 0.0, impulse });
        }
        else {
            head.setVelocity(GeometrVector{ 0.0, 0.0 });
        }

        head.setPosition(head.getPosition() + head.getVelocity());
        moveSnake(head, snake);
        
        
        window.clear();
        for (size_t i = 0; i < snake.size(); i++)
        {
            sf::CircleShape dot(snake[i].getSize());
            if (i > 0 && snake[i].getVelocity() == GeometrVector{ 0.0, 0.0 })
                dot.setFillColor(sf::Color::Color(255, 0, 0, 0));
            else
                dot.setFillColor(sf::Color::Color(255, 0, 0, snake[i].getLight() * 255));
            dot.move(snake[i].getPosition().getX(), snake[i].getPosition().getY());

            window.draw(dot);
        }
        
        window.display();
    }

    return 0;
}