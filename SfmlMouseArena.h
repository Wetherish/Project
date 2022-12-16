//
// Created by Bartek on 18.06.2022.
//

#ifndef PROJEKTZALICZENIE_264396_PT_2022_SFMLMOUSEARENA_H
#define PROJEKTZALICZENIE_264396_PT_2022_SFMLMOUSEARENA_H
#include "SFML/Graphics.hpp"
#include "weapon.h"
#include "Unit.h"
#include "Aktioncards.h"
#include "menumenager.h"
#include "SFMLmenuview.h"
#include "Sfmlarenaview.h"
#include "fightmenager.h"

class SfmlMouseArena {

    fightmenager &fight;
    sf::Vector2i mousePos;
    int move = 0;

public:
    explicit SfmlMouseArena( fightmenager &fight1);
    void gameplay(sf::Event &event, sf::RenderWindow &win);
};


#endif //PROJEKTZALICZENIE_264396_PT_2022_SFMLMOUSEARENA_H
