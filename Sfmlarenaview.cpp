//
// Created by Bartek on 18.06.2022.
//

#include "Sfmlarenaview.h"

Sfmlarenaview::Sfmlarenaview( Unit &enemy1,  SFMLmenuview &view1,  SFMLmenuview &ve1) :   enemy(enemy1),  view(view1), ve(ve1) {
    load_texture();
    set_texture();
    set_scale();
}

void Sfmlarenaview::draw(sf::RenderWindow &win) {
    view.draw_deck(win, 530,600);
    draw_knight(win);
    if(enemy.get_name() == "dragon")
    {draw_dragon(win);}
    if(enemy.get_name() == "monster")
    {draw_monster(win);}
    if(enemy.get_name() == "demon")
    {draw_demon(win);}

    view.draw_gold(win, 30,33,80,50);
    view.draw_dmg(win,30,83,80,100);
    view.draw_hp(win,30,133,80,150);
    ve.draw_gold(win,1850,33,1800,50);
    ve.draw_hp(win,1850,133,1800,150);
    ve.draw_dmg(win,1850,83,1800,100);
    view.attack(win, 1450,600,0.6);
   // view.testpion(1580,600,1,win);
    view.drawforzen(win,0,0,0.4,800);
}

void Sfmlarenaview::load_texture() {

    if(enemy.get_name()=="dragon"){
        texture_dragon.loadFromFile("../png/dragon.png");
    }
    if(enemy.get_name() == "monster")
    {
        texture_monster.loadFromFile("../png/monster.png");
    }

    if(enemy.get_name() == "demon")
    {
        texture_demon.loadFromFile("../png/demon.png");
    }

    texture_knight.loadFromFile("../png/hero.png");
}

void Sfmlarenaview::set_texture() {
    dragon.setTexture(texture_dragon);
    knight.setTexture(texture_knight);
    demon.setTexture(texture_demon);
    monster.setTexture(texture_monster);
}

void Sfmlarenaview::set_scale() {
    dragon.setScale(0.28,0.28);
    knight.setScale(0.4,0.4);
    demon.setScale(0.3,0.3);
    monster.setScale(0.5,0.5);

}

void Sfmlarenaview::draw_knight(sf::RenderWindow &win) {
    knight.setPosition(50,200);
    win.draw(knight);
}

void Sfmlarenaview::draw_dragon(sf::RenderWindow &win) {

    dragon.setPosition(1100, 100);
    win.draw(dragon);
}

void Sfmlarenaview::draw_demon(sf::RenderWindow &win) {
   demon.setPosition(1200, 100);
    win.draw(demon);
}

void Sfmlarenaview::draw_monster(sf::RenderWindow &win) {

    monster.setPosition(1400, 100);
    win.draw(monster);
}
