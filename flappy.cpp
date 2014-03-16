#include "flappy.hpp"
#include <iostream>

Flappy::Flappy()
{
    window.create(sf::VideoMode(287,511,32), "LEIRE BIRD");
    window.setVerticalSyncEnabled(true);

    texture_back.loadFromFile("data/Flappy_Background_day.png");
    background.setTexture(texture_back);

    map = new Map;
    score = 0;

    font.loadFromFile("data/OpenSans.ttf");

    text_score.setFont(font);
    text_score.setPosition(235,20);
    text_score.setCharacterSize(35);
    text_score.setColor(sf::Color::Black);
}

void Flappy::run()
{
    bool b_crash = false;
    while (window.isOpen())
    {
        time = clock.restart();

        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }
        if(!b_crash)
        {
            bird.update_bird(time);
            bird.animate_bird(time);
            b_crash = map->update(time, bird, score);

            std::ostringstream convert;
            convert << score;
            str_score = convert.str();
            text_score.setString(str_score);
        }
        else
        {
            delete map;
            map = new Map;
            bird.setPosition(20,250);

            score = 0;

            b_crash = false;
        }

        window.draw(background);
        window.draw(bird);
        map->draw(window);
        window.draw(text_score);

        window.display();
    }
}
