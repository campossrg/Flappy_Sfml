#include "bird.hpp"
#include <iostream>

Bird::Bird() :  sf::Sprite()
{
    texture_bird.loadFromFile("data/Flappy_Bird_Sheet.bmp");
    this->setTexture(texture_bird);
    //this->setTextureRect(sf::IntRect(0,0,18,15));
    this->setScale(1.8f,1.8f);

    this->setOrigin(this->getLocalBounds().width/4.0f,this->getLocalBounds().height/2.0f);
    this->setPosition(20,250);

    this->speed = 300.0f;
    this->frame = 0;
}

Bird::~Bird()
{

}

void Bird::update_bird(sf::Time& delta)
{
    float top = this->getGlobalBounds().top;
    float bottom = this->getGlobalBounds().top + this->getGlobalBounds().height;

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && top > 0)
    {
        move(0,-delta.asSeconds() * this->speed);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && bottom < 511)
    {
        move(0,delta.asSeconds() * this->speed);
    }
}

void Bird::animate_bird(sf::Time& delta)
{
    time_ani += delta;
    std::cout << time_ani.asSeconds() << std::endl;

    if (time_ani.asSeconds() < 0.5)

        this->setTextureRect(sf::IntRect(0,0,18,15));

    else if (time_ani.asSeconds() > 0.5 && time_ani.asSeconds() < 1)

        this->setTextureRect(sf::IntRect(0,15,18,15));

    else if (time_ani.asSeconds() > 1 && time_ani.asSeconds() < 1.5)

        this->setTextureRect(sf::IntRect(0,30,18,15));

    else if (time_ani.asSeconds() > 1.5)

        time_ani = delta;

}
