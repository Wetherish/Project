//
// Created bmousePos.y Bartek on 17.06.2022.
//

#include "SFMLmenucontrol.h"

SFMLmenucontrol::SFMLmenucontrol(menumenager &menu1): menu(menu1){

}

void SFMLmenucontrol::gameplay(sf::Event &event, sf::RenderWindow &win) {
    mousePos = sf::Mouse::getPosition((win));

    //if (event.type == sf::Event::MouseButtonPressed){

        //cout <<" pierwsze x:  "<<mousePos.x <<" y: "<< mousePos.y ;

        if(event.mouseButton.button == sf::Mouse::Left) {

            if (mousePos.x >= 10 and mousePos.x <= 145 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_eq(menu.get_index_weapon_list(0));
            }
            if (mousePos.x >= 170 and mousePos.x <= 305 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_eq(menu.get_index_weapon_list(1));
            }
            if (mousePos.x >= 330 and mousePos.x <= 465 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_eq(menu.get_index_weapon_list(2));
            }
            if (mousePos.x >= 490 and mousePos.x <= 625 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_eq(menu.get_index_weapon_list(3));
            }
            if (mousePos.x >= 650 and mousePos.x <= 785 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_eq(menu.get_index_weapon_list(4));
            }
            if (mousePos.x >= 810 and mousePos.x <= 945 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_eq(menu.get_index_weapon_list(5));
            }
            if (mousePos.x >= 970 and mousePos.x <= 1105 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_eq(menu.get_index_weapon_list(6));
            }
            if (mousePos.x >= 1130 and mousePos.x <= 1265 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_aktion(menu.get_index_cards_list(0));
            }
            if (mousePos.x >= 1290 and mousePos.x <= 1425 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_aktion(menu.get_index_cards_list(1));
            }
            if (mousePos.x >= 1450 and mousePos.x <= 1585 and mousePos.y <= 937 and mousePos.y >= 733)
            {
                menu.buy_card_aktion(menu.get_index_cards_list(2));
            }
            if (mousePos.x >= 1610 and mousePos.x <= 1745 and mousePos.y <= 937 and mousePos.y >= 733)
            {
                menu.buy_card_aktion(menu.get_index_cards_list(3));
            }
            if (mousePos.x >= 1770 and mousePos.x <= 1905 and mousePos.y <= 937 and mousePos.y >= 733) {
                menu.buy_card_aktion(menu.get_index_cards_list(4));
            }
            if (mousePos.x >= 10 and mousePos.x <= 114 and mousePos.y <= 164 and mousePos.y >= 10)
            {
                menu.sell_eq(1);
            }
            if (mousePos.x >= 10 and mousePos.x <= 114 and mousePos.y <= 334 and mousePos.y >= 180)
            {
                menu.sell_eq(2);
            }
            if( mousePos.x >= 10 and mousePos.x <= 114 and mousePos.y <= 504 and mousePos.y >= 350)
            {
                menu.sell_eq(3);
            }
            if( mousePos.x >= 10 and mousePos.x <= 114 and mousePos.y <= 674 and mousePos.y >= 520)
            {
                menu.sell_eq(4);
            }
            if (mousePos.x >= 119 and mousePos.x <= 223 and mousePos.y <= 384 and mousePos.y >=229 )
            {
                menu.sell_eq(0);
            }

            if (mousePos.x >= 800 and mousePos.x <= 935 and mousePos.y <= 255 and mousePos.y >=49 )
            {
                menu.sell_cards(0);
            }

            if (mousePos.x >= 950 and mousePos.x <= 1085 and mousePos.y <= 255 and mousePos.y >=49 )
            {
                menu.sell_cards(1);
            }
            if (mousePos.x >= 1110 and mousePos.x <= 1245 and mousePos.y <= 255 and mousePos.y >=49 )
            {
                menu.sell_cards(2);
            }
            if (mousePos.x >= 1270 and mousePos.x <= 1405 and mousePos.y <= 255 and mousePos.y >=49 )
            {
                menu.sell_cards(3);
            }
            if (mousePos.x >= 1430 and mousePos.x <= 1565 and mousePos.y <= 255 and mousePos.y >=49 )
            {
                menu.sell_cards(4);
            }
            if (mousePos.x >= 1590 and mousePos.x <= 1725 and mousePos.y <= 255 and mousePos.y >=49 )
            {
                menu.sell_cards(5);
            }

            if (mousePos.x >= 800 and mousePos.x <= 1000 and mousePos.y < 505 and mousePos.y > 350 )
            {
                win.close();
                //cout << "po x: "<<mousePos.x <<" y: "<< mousePos.y ;
            }




        }
        if(event.mouseButton.button == sf::Mouse::Right)
        {


        }

   // }

}
