//
// Created by Bartek on 08.06.2022.
//

#ifndef PROJEKTZALICZENIE_264396_PT_2022_SFMLMENUVIEW_H
#define PROJEKTZALICZENIE_264396_PT_2022_SFMLMENUVIEW_H

#include "SFML/Graphics.hpp"
#include "weapon.h"
#include "Unit.h"
#include "Aktioncards.h"
#include "menumenager.h"
#include <cmath>

class SFMLmenuview {
    vector<int> eqlist;
    weapon &w;
    Unit &hero;
    Aktioncards &cards;
    menumenager &menu;

    sf::Texture texture_kreska;
    sf::Texture texture_empty;
    sf::Texture texture_gold;
    sf::Texture texture_hp;
    sf::Texture texture_dmg;

    sf::Texture texture_miecz_ogien;
    sf::Texture texture_miecz_ziemia;
    sf::Texture texture_miecz_woda;
    sf::Texture texture_miecz_powietrze;
    sf::Texture texture_buty_ogien;
    sf::Texture texture_buty_ziemia;
    sf::Texture texture_buty_woda;
    sf::Texture texture_buty_powietrze;
    sf::Texture texture_spodnie_ogien;
    sf::Texture texture_spodnie_ziemia;
    sf::Texture texture_spodnie_woda;
    sf::Texture texture_spodnie_powietrze;
    sf::Texture texture_zbroja_ogien;
    sf::Texture texture_zbroja_ziemia;
    sf::Texture texture_zbroja_woda;
    sf::Texture texture_zbroja_powietrze;
    sf::Texture texture_helm_ogien;
    sf::Texture texture_helm_ziemia;
    sf::Texture texture_helm_woda;
    sf::Texture texture_helm_powietrze;

    sf::Texture texture_freeze;
    sf::Texture texture_bonus_dmg;
    sf::Texture texture_deal_dmg;
    sf::Texture texture_exhoust;
    sf::Texture texture_exh_and_dmg;
    sf::Texture texture_heal;
    sf::Texture texture_heal_and_dmg;

    sf::Texture texture_start_combat;

    sf::Texture texture_wind;
    sf::Texture texture_fire;
    sf::Texture texture_water;
    sf::Texture texture_earth;

    sf::Texture texture_frozen;

    sf::Texture texture_test_kreska1;
    sf::Texture texture_test_kreska2;

    sf::Sprite frozen;

    sf::Sprite test_kreska1;
    sf::Sprite test_kreska2;
    sf::Sprite freeze;
    sf::Sprite bonus_dmg;
    sf::Sprite deal_dmg;
    sf::Sprite exhoust;
    sf::Sprite exh_and_dmg;
    sf::Sprite heal;
    sf::Sprite heal_and_dmg;

    sf::Sprite start_combat;
    sf::Sprite wind;
    sf::Sprite fire;
    sf::Sprite water;
    sf::Sprite earth;

    sf::Sprite empty;
    sf::Sprite kreska;
    sf::Sprite gold;
    sf::Sprite hp;
    sf::Sprite dmg;

    sf::Sprite miecz_ogien;
    sf::Sprite miecz_ziemia;
    sf::Sprite miecz_powietrze;
    sf::Sprite miecz_woda;

    sf::Sprite buty_ogien;
    sf::Sprite buty_ziemia;
    sf::Sprite buty_powietrze;
    sf::Sprite buty_woda;

    sf::Sprite spodnie_ogien;
    sf::Sprite spodnie_ziemia;
    sf::Sprite spodnie_powietrze;
    sf::Sprite spodnie_woda;

    sf::Sprite zbroja_ogien;
    sf::Sprite zbroja_ziemia;
    sf::Sprite zbroja_powietrze;
    sf::Sprite zbroja_woda;

    sf::Sprite helm_ogien;
    sf::Sprite helm_ziemia;
    sf::Sprite helm_powietrze;
    sf::Sprite helm_woda;


    sf::Font font;

    sf::Text winn;
    sf::Text start;

    sf::Text text_gold;
    sf::Text text_hp;
    sf::Text text_dmg;
    sf::Text owned;
    sf::Text card_cost;
    sf::Text card_name;
    sf::Text eq_cost;
    sf::Text eq_hp;
    sf::Text eq_dmg;
    sf::Text text_fire;
    sf::Text text_water;
    sf::Text text_earth;
    sf::Text text_wind;

    void load_texture();

public:
    SFMLmenuview(weapon &weapon1, Unit &unit, Aktioncards &cards1, menumenager &menu1);

    void draw(sf::RenderWindow &win);

    void setvector();

    void scale_png(float scale);

    void set_texture();

    void font_bull_sh();

    void draw_gold(sf::RenderWindow &win, float tx_x, float tx_y, float sp_x, float sp_y);

    void draw_hp(sf::RenderWindow &win, float tx_x, float tx_y, float sp_x, float sp_y);

    void draw_dmg(sf::RenderWindow &win, float tx_x, float tx_y, float sp_x, float sp_y);

    void draw_eqlist(sf::RenderWindow &win);

    void draw_owned(sf::RenderWindow &win);

    void draw_deck(sf::RenderWindow &win, float X_pos, float Y_pos);

    void write_eq_cost(sf::RenderWindow &win, int index, float x, float y, int size);

    void write_eq_dmg(sf::RenderWindow &win, int index, float x, float y, int size);

    void write_eq_hp(sf::RenderWindow &win, int index, float x, float y, int size);

    void draw_combat(sf::RenderWindow &win);

    void testpion(float x, float y, float scale, sf::RenderWindow &win);

    void attack(sf::RenderWindow &win, float x, float y, float scale);

    void drawelement(sf::RenderWindow &win);

    void drawforzen(sf::RenderWindow &win, float x, float y, float scale, float rotate);

    void drawwin(sf::RenderWindow &win);

    void drawlose(sf::RenderWindow &win);

    void starting(sf::RenderWindow &win);

    void cont(sf::RenderWindow &win);


};


#endif //PROJEKTZALICZENIE_264396_PT_2022_SFMLMENUVIEW_H
