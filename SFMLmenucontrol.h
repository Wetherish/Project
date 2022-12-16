//
// Created by Bartek on 17.06.2022.
//

#ifndef PROJEKTZALICZENIE_264396_PT_2022_SFMLMENUCONTROL_H
#define PROJEKTZALICZENIE_264396_PT_2022_SFMLMENUCONTROL_H
#include "SFML/Graphics.hpp"
#include "weapon.h"
#include "Unit.h"
#include "Aktioncards.h"
#include "menumenager.h"
#include "SFMLmenuview.h"

class SFMLmenucontrol {

    menumenager &menu;
    sf::Vector2i mousePos;
public:
    SFMLmenucontrol(menumenager &menu1);
    void gameplay (sf::Event &event, sf::RenderWindow &win);

};


#endif //PROJEKTZALICZENIE_264396_PT_2022_SFMLMENUCONTROL_H
