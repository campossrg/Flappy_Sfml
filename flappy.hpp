#ifndef FLAPPY_HPP
#define FLAPPY_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <sstream>
#include "bird.hpp"
#include "map.hpp"

class Flappy
{
public:
    Flappy();
    void run();
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Time time;
    sf::Texture texture_back;
    sf::Sprite background;
    sf::Font font;
    sf::Text text_score;
    std::string str_score;

    Bird bird;
    Map *map;
    int score;
};
#endif // FLAPPY_HPP
