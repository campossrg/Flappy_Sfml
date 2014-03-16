#ifndef BIRD_HPP
#define BIRD_HPP

#include <SFML/Graphics.hpp>

class Bird : public sf::Sprite
{
public:
    Bird();
    ~Bird();
    void update_bird(sf::Time& delta);
    void animate_bird(sf::Time& delta);
private:
    sf::Texture texture_bird;
    sf::Time time_ani;

    float speed;
    int frame;
};
#endif // BIRD
