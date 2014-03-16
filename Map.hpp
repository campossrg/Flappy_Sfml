#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>

class Map
{
public:
    Map();
    ~Map();
    bool update(sf::Time& delta, sf::Sprite& bird, int& score);
    void draw(sf::RenderWindow& window);

private:
    sf::Texture texture_pipe,
                texture_ground;
    sf::Sprite sprite_pipe_up[3],
                sprite_pipe_down[3],
                sprite_ground[2];

    float speed;
    int spacing,
        vertical_spacing,
        y;
};
#endif // MAP_HPP
