#include "map.hpp"
#include <iostream>

Map :: Map ()
{
    spacing = 200;
    vertical_spacing = 80;
    speed = 150;

    texture_pipe.loadFromFile("data/Flappy_Pipe.png");
    texture_ground.loadFromFile("data/Flappy_Ground.png");

    sprite_ground[0].setTexture(texture_ground);
    sprite_ground[1].setTexture(texture_ground);

    sprite_ground[0].setPosition(0,420);
    sprite_ground[1].setPosition(300,420);

    srand (time(NULL));

    for(int i = 0; i < 3; i++)
    {

        y = rand() % 200 - 300;

        sprite_pipe_up[i].setTexture(texture_pipe);
        sprite_pipe_down[i].setTexture(texture_pipe);
        sprite_pipe_up[i].setPosition(200 + i * spacing, y);
        sprite_pipe_down[i].setPosition(200 + i * spacing, y + vertical_spacing + 300);
    }
}

Map::~Map()
{

}

bool Map::update(sf::Time& delta, sf::Sprite& bird, int& score)
{
    for(int i = 0; i < 3; i++)
    {
        if(bird.getGlobalBounds().intersects(this->sprite_pipe_up[i].getGlobalBounds()) ||
           bird.getGlobalBounds().intersects((this->sprite_pipe_down[i].getGlobalBounds())) ||
           bird.getPosition().y > 420 ||
           bird.getPosition().y < 0)
        {
            std::cout << "Crash!!" << std::endl << "Leire se ha estampado!!" << std::endl;
            return true;
        }
        else
        {
            this->sprite_pipe_up[i].move(-delta.asSeconds() * this->speed,0);
            this->sprite_pipe_down[i].move(-delta.asSeconds() * this->speed,0);

            this->sprite_ground[0].move(-delta.asSeconds() * this->speed,0);
            this->sprite_ground[1].move(-delta.asSeconds() * this->speed,0);

            if(this->sprite_pipe_up[i].getPosition().x < -58)
            {
                y = rand() % 200 - 300;

                sprite_pipe_up[i].setPosition(287 + spacing, y);
                sprite_pipe_down[i].setPosition(287 + spacing, y + vertical_spacing + 300);

                score ++;
            }

            if(this->sprite_ground[0].getPosition().x < -300)
                this->sprite_ground[0].setPosition(300,420);
            else if(this->sprite_ground[1].getPosition().x < -300)
                this->sprite_ground[1].setPosition(300,420);
        }
    }
    return false;
}

void Map::draw(sf::RenderWindow& window)
{
    for(int i = 0; i < 3; i++)
    {
        window.draw(this->sprite_pipe_up[i]);
        window.draw(this->sprite_pipe_down[i]);
    }
    window.draw(this->sprite_ground[0]);
    window.draw(this->sprite_ground[1]);
}
