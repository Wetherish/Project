//
// Created by Bartek on 18.06.2022.
//

#ifndef PROJEKTZALICZENIE_264396_PT_2022_SFMLARENAVIEW_H
#define PROJEKTZALICZENIE_264396_PT_2022_SFMLARENAVIEW_H
#include "SFML/Graphics.hpp"
#include "weapon.h"
#include "Unit.h"
#include "Aktioncards.h"
#include "menumenager.h"
#include "SFMLmenuview.h"

class Sfmlarenaview {


    Unit &enemy;
    SFMLmenuview &view;
    SFMLmenuview &ve;

    sf::Texture texture_dragon;
    sf::Texture texture_knight;
    sf::Texture texture_demon;
    sf::Texture texture_monster;

    sf::Sprite dragon;
    sf::Sprite knight;
    sf::Sprite demon;
    sf::Sprite monster;

public:
    Sfmlarenaview( Unit &enemy1, SFMLmenuview &view1,SFMLmenuview &ve1);
    void draw(sf::RenderWindow& win);
    void load_texture();
    void set_texture();
    void set_scale();
    void draw_knight(sf::RenderWindow& win);
    void draw_demon(sf::RenderWindow& win);
    void draw_monster(sf::RenderWindow& win);
    void draw_dragon(sf::RenderWindow& win);


};


#endif //PROJEKTZALICZENIE_264396_PT_2022_SFMLARENAVIEW_H
