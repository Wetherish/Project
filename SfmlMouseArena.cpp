//
// Created by Bartek on 18.06.2022.
//

#include "SfmlMouseArena.h"

SfmlMouseArena::SfmlMouseArena(fightmenager &fight1): fight(fight1)
{

}

void SfmlMouseArena::gameplay(sf::Event &event, sf::RenderWindow &win) {
    mousePos = sf::Mouse::getPosition((win));
    if (event.type == sf::Event::MouseButtonPressed) {
        //fight.attack_enemy();

        if (event.mouseButton.button == sf::Mouse::Left) {
            if (mousePos.x >= 1450 and mousePos.x <= 1580 and mousePos.y <= 738 and mousePos.y >= 600) {
                fight.attack_hero();
                move += 1;
            }
            if (mousePos.x >= 530 and mousePos.x <= 665 and mousePos.y <= 806 and mousePos.y >= 600)
            {
               fight.cast_spel(0);
                //
            }
            if( mousePos.x >= 690 and mousePos.x <= 825 and mousePos.y <= 806 and mousePos.y >= 350)
            {

                fight.cast_spel(1);
            }
            if( mousePos.x >= 850 and mousePos.x <= 985 and mousePos.y <= 806 and mousePos.y >= 520)
            {
                fight.cast_spel(2);
            }
            if (mousePos.x >= 1010 and mousePos.x <= 1145 and mousePos.y <= 806 and mousePos.y >=229 )
            {
                fight.cast_spel(3);
            }

            if (mousePos.x >= 1170 and mousePos.x <= 1305 and mousePos.y <= 806 and mousePos.y >=49 )
            {
                fight.cast_spel(4);
            }

            if (mousePos.x >= 1330 and mousePos.x <= 1465 and mousePos.y <= 806 and mousePos.y >=49 )
            {
                fight.cast_spel(5);
            }

         }

        }

    if(move == 1)
    {
        if(fight.get_stun() == 0)
        {
            fight.attack_enemy();
        }
        fight.dekrementstun();
    }

    move = 0;
}
