//
// Created by Bartek on 08.06.2022.
//

#include <unistd.h>
#include <synchapi.h>
#include "SFMLmenuview.h"

SFMLmenuview::SFMLmenuview(weapon &weapon1, Unit &unit, Aktioncards &cards1, menumenager &menu1) : w(weapon1),
                                                                                                   hero(unit),
                                                                                                   cards(cards1),
                                                                                                   menu(menu1) {
    font_bull_sh();
    load_texture();
    set_texture();


    setvector();
}

void SFMLmenuview::load_texture() {
    texture_fire.loadFromFile("../png/fire.png");
    texture_water.loadFromFile("../png/water.png");
    texture_earth.loadFromFile("../png/earth.png");
    texture_wind.loadFromFile("../png/wind.png");
    texture_start_combat.loadFromFile("../png/start fight.png");

    texture_test_kreska1.loadFromFile("../png/test_kreska.png");
    texture_test_kreska2.loadFromFile("../png/testkreska2.png");

    texture_gold.loadFromFile("../png/gold coin.png");
    texture_empty.loadFromFile("../png/ramka z tlem.png");
    texture_kreska.loadFromFile("../png/kreska.png");
    texture_hp.loadFromFile("../png/hearth.png");
    texture_dmg.loadFromFile("../png/sword icon.png");

    texture_miecz_ogien.loadFromFile("../png/miecz_ogien.png");
    texture_miecz_ziemia.loadFromFile("../png/miecz ziemia.png");
    texture_miecz_woda.loadFromFile("../png/miecz woda.png");
    texture_miecz_powietrze.loadFromFile("../png/miecz_pow.png");
    //miecz
    texture_buty_ogien.loadFromFile("../png/buty ogien.png");
    texture_buty_ziemia.loadFromFile("../png/buty ziemia.png");
    texture_buty_woda.loadFromFile("../png/buty woda.png");
    texture_buty_powietrze.loadFromFile("../png/buty wiatr.png");
    //nogi
    texture_spodnie_ogien.loadFromFile("../png/nogi ogien.png");
    texture_spodnie_ziemia.loadFromFile("../png/nogi ziemia.png");
    texture_spodnie_woda.loadFromFile("../png/nogi woda.png");
    texture_spodnie_powietrze.loadFromFile("../png/nogi wiatr.png");
    //helm
    texture_helm_ogien.loadFromFile("../png/helm ogien.png");
    texture_helm_ziemia.loadFromFile("../png/helm ziemia.png");
    texture_helm_woda.loadFromFile("../png/helm woda.png");
    texture_helm_powietrze.loadFromFile("../png/helm powietrze.png");
    //zbroja
    texture_zbroja_ogien.loadFromFile("../png/zbroja ogien.png");
    texture_zbroja_ziemia.loadFromFile("../png/zbroja ziemia.png");
    texture_zbroja_woda.loadFromFile("../png/zbroja woda.png");
    texture_zbroja_powietrze.loadFromFile("../png/zbroja wiatr.png");
    //
    texture_bonus_dmg.loadFromFile("../png/bonus damage.png");
    texture_deal_dmg.loadFromFile("../png/deal damage.png");
    texture_exhoust.loadFromFile("../png/exhoust.png");
    texture_exh_and_dmg.loadFromFile("../png/exhoust and damage.png");
    texture_heal.loadFromFile("../png/Heal.png");
    texture_heal_and_dmg.loadFromFile("../png/heal and damage.png");
    texture_freeze.loadFromFile("../png/freeze.png");

    texture_frozen.loadFromFile("../png/freezefire.png");


}

void SFMLmenuview::draw(sf::RenderWindow &win) {


    kreska.setPosition(0, 700);
    win.draw(kreska);
    draw_gold(win, 1850, 133, 1800, 150);
    draw_hp(win, 1850, 33, 1800, 50);
    draw_dmg(win, 1850, 83, 1800, 100);
    draw_eqlist(win);

    draw_deck(win, 800, 50);
    draw_combat(win);
//    testpion(10,10,1,winn);
//    testpion(10,180,1,winn);
//    testpion(10,350,1,winn);
//    testpion(10,520,1,winn);
//    testpion(10,164,1,winn);
//    testpion(10,334,1,winn);
//    testpion(10,504,1,winn);
//    testpion(10,674,1,winn);
//    testpion(223,229,1,winn);
//    testpion(223,384,1,winn);
//    testpion(119,384,1,winn);
//
//
//    testpion(800,350,1,winn);
//    //testpion(800,505,1,winn);
//   // testpion(223,384,1,winn);
//    testpion(960,505,1,winn);
//
//
//    testpion(800,255,1,winn);
//    testpion(930,45,1,winn);
//    testpion(950,45,1,winn);
    draw_owned(win);
    drawelement(win);


}


void SFMLmenuview::setvector() {
    for (int x = 0; x < 7; x++) {
        eqlist.push_back(menu.get_index_weapon_list(x));
    }
}

void SFMLmenuview::draw_gold(sf::RenderWindow &win, float tx_x, float tx_y, float sp_x, float sp_y) {
    float gold_scale = 0.035;
    gold.setScale(gold_scale, gold_scale);
    gold.setPosition(sp_x, sp_y);
    //
    string hajs;
    int a = hero.get_gold();
    if (a < 10)
        hajs = a + '0';
    else {
        while (a > 0) {
            hajs.push_back(a % 10 + '0');
            a /= 10;
        }
    }

    reverse(hajs.begin(), hajs.end());
    text_gold.setPosition(tx_x, tx_y);
    text_gold.setString(hajs);
    text_gold.setCharacterSize(45);
    text_gold.setFillColor(sf::Color::Yellow);


    win.draw(text_gold);
    win.draw(gold);

}

void SFMLmenuview::scale_png(float scale) {

    //scale = 0.2;

    empty.setScale(scale, scale);


    miecz_ogien.setScale(scale, scale);
    miecz_woda.setScale(scale, scale);
    miecz_ziemia.setScale(scale, scale);
    miecz_powietrze.setScale(scale, scale);

    buty_ogien.setScale(scale, scale);
    buty_woda.setScale(scale, scale);
    buty_ziemia.setScale(scale, scale);
    buty_powietrze.setScale(scale, scale);

    spodnie_ogien.setScale(scale, scale);
    spodnie_woda.setScale(scale, scale);
    spodnie_ziemia.setScale(scale, scale);
    spodnie_powietrze.setScale(scale, scale);

    zbroja_ogien.setScale(scale, scale);
    zbroja_woda.setScale(scale, scale);
    zbroja_ziemia.setScale(scale, scale);
    zbroja_powietrze.setScale(scale, scale);

    helm_ogien.setScale(scale, scale);
    helm_woda.setScale(scale, scale);
    helm_ziemia.setScale(scale, scale);
    helm_powietrze.setScale(scale, scale);

    bonus_dmg.setScale(scale, scale);
    heal.setScale(scale, scale);
    freeze.setScale(scale, scale);
    exhoust.setScale(scale, scale);
    heal_and_dmg.setScale(scale, scale);
    exh_and_dmg.setScale(scale, scale);
    deal_dmg.setScale(scale, scale);
}

void SFMLmenuview::set_texture() {
    start_combat.setTexture(texture_start_combat);
    test_kreska1.setTexture(texture_test_kreska1);
    test_kreska2.setTexture(texture_test_kreska2);

    fire.setTexture(texture_fire);
    wind.setTexture(texture_wind);
    earth.setTexture(texture_earth);
    water.setTexture(texture_water);


    kreska.setTexture(texture_kreska);
    gold.setTexture(texture_gold);
    hp.setTexture(texture_hp);
    dmg.setTexture(texture_dmg);

    miecz_ogien.setTexture(texture_miecz_ogien);
    miecz_powietrze.setTexture(texture_miecz_powietrze);
    miecz_woda.setTexture(texture_miecz_woda);
    miecz_ziemia.setTexture(texture_miecz_ziemia);

    buty_ogien.setTexture(texture_buty_ogien);
    buty_powietrze.setTexture(texture_buty_powietrze);
    buty_woda.setTexture(texture_buty_woda);
    buty_ziemia.setTexture(texture_buty_ziemia);

    spodnie_ogien.setTexture(texture_spodnie_ogien);
    spodnie_powietrze.setTexture(texture_spodnie_powietrze);
    spodnie_woda.setTexture(texture_spodnie_woda);
    spodnie_ziemia.setTexture(texture_spodnie_ziemia);

    zbroja_ogien.setTexture(texture_zbroja_ogien);
    zbroja_powietrze.setTexture(texture_zbroja_powietrze);
    zbroja_woda.setTexture(texture_zbroja_woda);
    zbroja_ziemia.setTexture(texture_zbroja_ziemia);

    helm_ogien.setTexture(texture_helm_ogien);
    helm_powietrze.setTexture(texture_helm_powietrze);
    helm_woda.setTexture(texture_helm_woda);
    helm_ziemia.setTexture(texture_helm_ziemia);

    empty.setTexture(texture_empty);

    deal_dmg.setTexture(texture_deal_dmg);
    bonus_dmg.setTexture(texture_bonus_dmg);
    exhoust.setTexture(texture_exhoust);
    freeze.setTexture(texture_freeze);
    heal.setTexture(texture_heal);
    heal_and_dmg.setTexture(texture_heal_and_dmg);
    exh_and_dmg.setTexture(texture_exh_and_dmg);

    frozen.setTexture(texture_frozen);

}

void SFMLmenuview::font_bull_sh() {
    font.loadFromFile("../fonts/HARNGTON.TTF");
    text_hp.setFont(font);
    text_dmg.setFont(font);
    text_gold.setFont(font);

    card_cost.setFont(font);
    card_name.setFont(font);
    eq_cost.setFont(font);
    eq_hp.setFont(font);
    eq_dmg.setFont(font);
    text_fire.setFont(font);
    text_water.setFont(font);
    text_earth.setFont(font);
    text_wind.setFont(font);
    winn.setFont(font);
    start.setFont(font);
}

void SFMLmenuview::draw_hp(sf::RenderWindow &win, float tx_x, float tx_y, float sp_x, float sp_y) {
    hp.setPosition(sp_x, sp_y);
    hp.setScale(0.13, 0.13);
    win.draw(hp);
    string hpvalue;
    int a = (hero.get_hp());
    while (a > 0) {
        hpvalue.push_back(a % 10 + '0');
        a /= 10;
    }
    reverse(hpvalue.begin(), hpvalue.end());

    text_hp.setPosition(tx_x, tx_y);
    text_hp.setString(hpvalue);
    text_hp.setCharacterSize(45);
    text_hp.setFillColor(sf::Color::Red);

    win.draw(text_hp);

}

void SFMLmenuview::draw_dmg(sf::RenderWindow &win, float tx_x, float tx_y, float sp_x, float sp_y) {

    dmg.setPosition(sp_x, sp_y);
    dmg.setScale(0.13, 0.13);
    win.draw(dmg);
    string dmgvalue;
    int a = (hero.get_damage());
    while (a > 0) {
        dmgvalue.push_back(a % 10 + '0');
        a /= 10;
    }
    reverse(dmgvalue.begin(), dmgvalue.end());

    text_dmg.setPosition(tx_x, tx_y);
    text_dmg.setString(dmgvalue);
    text_dmg.setCharacterSize(45);
    text_dmg.setFillColor(sf::Color::White);

    win.draw(text_dmg);
}

void SFMLmenuview::draw_eqlist(sf::RenderWindow &win) {
    scale_png(0.2);
    float Y_pos;
    float X_pos;
    float space;
    space = 10;
    Y_pos = 734;
    X_pos = 160;
    float x_card;
    float position = 0;

    for (position; position < 7; ++position) {

        if (w.get_name(menu.get_index_weapon_list(int(position))) == "empty") {
            empty.setPosition((position * X_pos) + space, Y_pos);
            win.draw(empty);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "wind sword") {
            miecz_powietrze.setPosition(position * X_pos + space, Y_pos);
            win.draw(miecz_powietrze);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "fire sword") {
            miecz_ogien.setPosition((position * X_pos) + space, Y_pos);
            win.draw(miecz_ogien);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "earth sword") {
            miecz_ziemia.setPosition((position * X_pos) + space, Y_pos);
            win.draw(miecz_ziemia);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "water sword") {
            miecz_woda.setPosition((position * X_pos) + space, Y_pos);
            win.draw(miecz_woda);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }

        if (w.get_name(menu.get_index_weapon_list(int(position))) == "wind shoes") {
            buty_powietrze.setPosition(position * X_pos + space, Y_pos);
            win.draw(buty_powietrze);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "fire shoes") {
            buty_ogien.setPosition((position * X_pos) + space, Y_pos);
            win.draw(buty_ogien);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "earth shoes") {
            buty_ziemia.setPosition((position * X_pos) + space, Y_pos);
            win.draw(buty_ziemia);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "water shoes") {
            buty_woda.setPosition((position * X_pos) + space, Y_pos);
            win.draw(buty_woda);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "wind pants") {
            spodnie_powietrze.setPosition((position * X_pos) + space, Y_pos);
            win.draw(spodnie_powietrze);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "fire pants") {
            spodnie_ogien.setPosition((position * X_pos) + space, Y_pos);
            win.draw(spodnie_ogien);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "earth pants") {
            spodnie_ziemia.setPosition((position * X_pos) + space, Y_pos);
            win.draw(spodnie_ziemia);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "water pants") {
            spodnie_woda.setPosition((position * X_pos) + space, Y_pos);
            win.draw(spodnie_woda);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }

        if (w.get_name(menu.get_index_weapon_list(int(position))) == "wind chest plate") {
            zbroja_powietrze.setPosition((position * X_pos) + space, Y_pos);
            win.draw(zbroja_powietrze);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "fire chest plate") {
            zbroja_ogien.setPosition((position * X_pos) + space, Y_pos);
            win.draw(zbroja_ogien);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "earth chest plate") {
            zbroja_ziemia.setPosition((position * X_pos) + space, Y_pos);
            win.draw(zbroja_ziemia);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "water chest plate") {
            zbroja_woda.setPosition((position * X_pos) + space, Y_pos);
            win.draw(zbroja_woda);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "wind helmet") {
            helm_powietrze.setPosition((position * X_pos) + space, Y_pos);
            win.draw(helm_powietrze);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "fire helmet") {
            helm_ogien.setPosition((position * X_pos) + space, Y_pos);
            win.draw(helm_ogien);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);

        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "earth helmet") {
            helm_ziemia.setPosition((position * X_pos) + space, Y_pos);
            win.draw(helm_ziemia);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "water helmet") {
            helm_woda.setPosition((position * X_pos) + space, Y_pos);
            win.draw(helm_woda);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        if (w.get_name(menu.get_index_weapon_list(int(position))) == "earth helmet") {
            helm_ogien.setPosition((position * X_pos) + space, Y_pos);
            win.draw(helm_ziemia);
            write_eq_cost(win, menu.get_index_weapon_list(position), (position * X_pos) + space, 690, 35);
            write_eq_hp(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 30, 690, 35);
            write_eq_dmg(win, menu.get_index_weapon_list(position), (position * X_pos) + space + 60, 690, 35);
        }
        x_card = (position * X_pos) + space;
    }
    int positionx = 0;
    for (position; position < 12; ++position) {
        if (cards.get_name(menu.get_index_cards_list((positionx))) == "empty") {
            empty.setPosition((position * X_pos) + space, Y_pos);
            win.draw(empty);
        }

        if (cards.get_name(menu.get_index_cards_list((positionx))) == "bonus damage (buff)") {
            bonus_dmg.setPosition((position * X_pos) + space, Y_pos);
            win.draw(bonus_dmg);

        }
        if (cards.get_name(menu.get_index_cards_list((positionx))) == "heal (buff)") {
            heal.setPosition((position * X_pos) + space, Y_pos);
            win.draw(heal);

        }
        if (cards.get_name(menu.get_index_cards_list((positionx))) == "heal and damage (buff)") {
            heal_and_dmg.setPosition((position * X_pos) + space, Y_pos);
            win.draw(heal_and_dmg);

        }
        if (cards.get_name(menu.get_index_cards_list((positionx))) == "freeze (nerf)") {
            freeze.setPosition((position * X_pos) + space, Y_pos);
            win.draw(freeze);

        }
        if (cards.get_name(menu.get_index_cards_list((positionx))) == "hurt (nerf)") {
            deal_dmg.setPosition((position * X_pos) + space, Y_pos);
            win.draw(deal_dmg);
        }
        if (cards.get_name(menu.get_index_cards_list((positionx))) == "exhaust (nerf)") {
            exhoust.setPosition((position * X_pos) + space, Y_pos);
            win.draw(exhoust);

        }
        if (cards.get_name(menu.get_index_cards_list((positionx))) == "exhaust and damage (nerf)") {
            exh_and_dmg.setPosition((position * X_pos) + space, Y_pos);
            win.draw(exh_and_dmg);
        }
        positionx++;
    }
}

void SFMLmenuview::draw_owned(sf::RenderWindow &win) {
    scale_png(0.15);
    float Y_pos;
    float X_pos;
    Y_pos = 172;
    X_pos = 0;
    owned.setFont(font);
    owned.setString("Your Equipment");
    owned.setCharacterSize(60);
    owned.setPosition(150, 100);
    win.draw(owned);
    for (float positionx = 1; positionx < 5; ++positionx) {
        float position = positionx - 1;
        if (w.get_name(menu.get_owned_cards(int(position))) == "empty") {
            empty.setPosition(10, 10);
            win.draw(empty);
        }
//        if (w.get_name(menu.get_owned_cards(int(position))) == "wind sword") {
//            miecz_powietrze.setPosition( X_pos, Y_pos * position );
//            winn.draw(miecz_powietrze);
//        }
//        if (w.get_name(menu.get_owned_cards(int(position))) == "fire sword") {
//            miecz_ogien.setPosition( X_pos, Y_pos * position );
//            winn.draw(miecz_ogien);
//        }
//        if (w.get_name(menu.get_owned_cards(int(position))) == "earth sword") {
//            miecz_ziemia.setPosition( X_pos, Y_pos * position );
//            winn.draw(miecz_ziemia);
//        }
//        if (w.get_name(menu.get_owned_cards(int(position))) == "water sword") {
//            miecz_woda.setPosition( X_pos, Y_pos * position );
//            winn.draw(miecz_woda);
//        }
        if (w.get_name(menu.get_owned_cards(1)) == "empty") {
            empty.setPosition(10, 10);
            win.draw(empty);
        }
        if (w.get_name(menu.get_owned_cards(2)) == "empty") {
            empty.setPosition(10, 180);
            win.draw(empty);
        }
        if (w.get_name(menu.get_owned_cards(3)) == "empty") {
            empty.setPosition(10, 350);
            win.draw(empty);
        }
        if (w.get_name(menu.get_owned_cards(4)) == "empty") {
            empty.setPosition(10, 520);
            win.draw(empty);
        }
        if (w.get_name(menu.get_owned_cards(4)) == "wind shoes") {
            buty_powietrze.setPosition(10, 520);
            win.draw(buty_powietrze);
        }
        if (w.get_name(menu.get_owned_cards(4)) == "fire shoes") {
            buty_ogien.setPosition(10, 520);
            win.draw(buty_ogien);

        }
        if (w.get_name(menu.get_owned_cards(4)) == "earth shoes") {
            buty_ziemia.setPosition(10, 520);
            win.draw(buty_ziemia);
        }
        if (w.get_name(menu.get_owned_cards(4)) == "water shoes") {
            buty_woda.setPosition(10, 520);
            win.draw(buty_woda);
        }
        if (w.get_name(menu.get_owned_cards(3)) == "wind pants") {
            spodnie_powietrze.setPosition(10, 350);
            win.draw(spodnie_powietrze);
        }
        if (w.get_name(menu.get_owned_cards(3)) == "fire pants") {
            spodnie_ogien.setPosition(10, 350);
            win.draw(spodnie_ogien);

        }
        if (w.get_name(menu.get_owned_cards(3)) == "earth pants") {
            spodnie_ziemia.setPosition(10, 350);
            win.draw(spodnie_ziemia);
        }
        if (w.get_name(menu.get_owned_cards(3)) == "water pants") {
            spodnie_woda.setPosition(10, 350);
            win.draw(spodnie_woda);
        }

        if (w.get_name(menu.get_owned_cards(2)) == "wind chest plate") {
            zbroja_powietrze.setPosition(10, 180);
            win.draw(zbroja_powietrze);
        }
        if (w.get_name(menu.get_owned_cards(2)) == "fire chest plate") {
            zbroja_ogien.setPosition(10, 180);
            win.draw(zbroja_ogien);

        }
        if (w.get_name(menu.get_owned_cards(2)) == "earth chest plate") {
            zbroja_ziemia.setPosition(10, 180);
            win.draw(zbroja_ziemia);
        }
        if (w.get_name(menu.get_owned_cards(2)) == "water chest plate") {
            zbroja_woda.setPosition(10, 180);
            win.draw(zbroja_woda);
        }
        if (w.get_name(menu.get_owned_cards(1)) == "wind helmet") {
            helm_powietrze.setPosition(10, 10);
            win.draw(helm_powietrze);
        }
        if (w.get_name(menu.get_owned_cards(1)) == "fire helmet") {
            helm_ogien.setPosition(10, 10);
            win.draw(helm_ogien);

        }
        if (w.get_name(menu.get_owned_cards(1)) == "water helmet") {
            helm_woda.setPosition(10, 10);
            win.draw(helm_woda);
        }
        if (w.get_name(menu.get_owned_cards(1)) == "earth helmet") {
            helm_ziemia.setPosition(10, 10);
            win.draw(helm_ziemia);
        }
    }
    if (w.get_name(menu.get_owned_cards(0)) == "empty") {
        empty.setPosition(120, 230);
        win.draw(empty);
    }
    if (w.get_name(menu.get_owned_cards(0)) == "wind sword") {
        miecz_powietrze.setPosition(120, 230);
        win.draw(miecz_powietrze);
    }
    if (w.get_name(menu.get_owned_cards(0)) == "fire sword") {
        miecz_ogien.setPosition(120, 230);
        win.draw(miecz_ogien);
    }
    if (w.get_name(menu.get_owned_cards(0)) == "earth sword") {
        miecz_ziemia.setPosition(120, 230);
        win.draw(miecz_ziemia);
    }
    if (w.get_name(menu.get_owned_cards(0)) == "water sword") {
        miecz_woda.setPosition(120, 230);
        win.draw(miecz_woda);
    }
}


void SFMLmenuview::draw_deck(sf::RenderWindow &win, float X_pos, float Y_pos) {
//    float Y_pos;
//    float X_pos;


    for (float position = 0; position < 6; ++position) {
        if (cards.get_name(menu.get_owned_cards(int(position + 5))) == "empty") {
            empty.setPosition(position * 150 + X_pos, Y_pos);
            win.draw(empty);
        }
        if (cards.get_name(menu.get_owned_cards(int(position + 5))) == "bonus damage (buff)") {
            bonus_dmg.setPosition(position * 150 + X_pos, Y_pos);
            win.draw(bonus_dmg);
        }
        if (cards.get_name(menu.get_owned_cards(int(position + 5))) == "heal (buff)") {
            heal.setPosition(position * 150 + X_pos, Y_pos);
            win.draw(heal);
        }
        if (cards.get_name(menu.get_owned_cards(int(position + 5))) == "heal and damage (buff)") {
            heal_and_dmg.setPosition(position * 150 + X_pos, Y_pos);
            win.draw(heal_and_dmg);
        }
        if (cards.get_name(menu.get_owned_cards(int(position + 5))) == "freeze (nerf)") {
            freeze.setPosition(position * 150 + X_pos, Y_pos);
            win.draw(freeze);
        }
        if (cards.get_name(menu.get_owned_cards(int(position + 5))) == "hurt (nerf)") {
            deal_dmg.setPosition(position * 150 + X_pos, Y_pos);
            win.draw(deal_dmg);
        }
        if (cards.get_name(menu.get_owned_cards(int(position + 5))) == "exhaust (nerf)") {
            exhoust.setPosition(position * 150 + X_pos, Y_pos);
            win.draw(exhoust);
        }
        if (cards.get_name(menu.get_owned_cards(int(position + 5))) == "exhaust and damage (nerf)") {
            exh_and_dmg.setPosition(position * 150 + X_pos, Y_pos);
            win.draw(exh_and_dmg);
        }

    }

}

void SFMLmenuview::write_eq_cost(sf::RenderWindow &win, int index, float x, float y, int size) {
    eq_cost.setPosition(x, y);
    eq_cost.setCharacterSize(size);
    string cost;
    int a = w.get_cost(index);
    while (a > 0) {
        cost.push_back(a % 10 + '0');
        a /= 10;
    }
    reverse(cost.begin(), cost.end());
    eq_cost.setString(cost);
    eq_cost.setFillColor(sf::Color::Yellow);
    win.draw(eq_cost);
}

void SFMLmenuview::write_eq_dmg(sf::RenderWindow &win, int index, float x, float y, int size) {
    if (w.get_def(index) > 9) {
        eq_dmg.setPosition(x + 10, y);
    } else
        eq_dmg.setPosition(x, y);
    eq_dmg.setCharacterSize(size);
    string cost;
    int a = w.get_damage(index);
    if (a != 0) {
        while (a > 0) {
            cost.push_back(a % 10 + '0');
            a /= 10;
        }
    } else
        cost.push_back('0');
    reverse(cost.begin(), cost.end());
    eq_dmg.setString(cost);
    eq_dmg.setFillColor(sf::Color::White);
    win.draw(eq_dmg);
}

void SFMLmenuview::write_eq_hp(sf::RenderWindow &win, int index, float x, float y, int size) {
    eq_hp.setPosition(x, y);
    eq_hp.setCharacterSize(size);
    string cost;
    int a = w.get_def(index);
    if (a != 0) {
        while (a > 0) {
            cost.push_back(a % 10 + '0');
            a /= 10;
        }
    } else
        cost.push_back('0');

    reverse(cost.begin(), cost.end());
    eq_hp.setString(cost);
    eq_hp.setFillColor(sf::Color::Red);
    win.draw(eq_hp);
}

void SFMLmenuview::draw_combat(sf::RenderWindow &win) {
    start_combat.setPosition(800, 350);
    start_combat.setScale(0.3, 0.3);
    win.draw(start_combat);
}

void SFMLmenuview::testpion(float x, float y, float scale, sf::RenderWindow &win) {
    test_kreska1.setScale(scale, scale);
    test_kreska1.setPosition(x, y);
    win.draw(test_kreska1);


}

void SFMLmenuview::drawelement(sf::RenderWindow &win) {
    string fire_str;
    string water_str;
    string earth_str;
    string wind_str;
    fire.setScale(0.1, 0.1);
    fire.setPosition(1780, 270);

    text_fire.setCharacterSize(30);
    text_fire.setPosition(1850, 290);
    fire_str.push_back(menu.get_count_fire() + '0');
    fire_str.push_back('/');
    fire_str.push_back('5');
    text_fire.setString(fire_str);
    text_fire.setFillColor(sf::Color::Red);

    win.draw(fire);
    win.draw(text_fire);
    water.setScale(0.09, 0.09);
    water.setPosition(1780, 370);
    text_water.setPosition(1850, 390);
    text_water.setFillColor(sf::Color::Blue);
    text_water.setCharacterSize(30);
    water_str.push_back(menu.get_count_water() + '0');
    water_str.push_back('/');
    water_str.push_back('5');
    text_water.setString(water_str);

    win.draw(water);
    win.draw(text_water);

    earth.setScale(0.1, 0.1);
    earth.setPosition(1780, 470);
    text_earth.setPosition(1850, 490);
    text_earth.setFillColor(sf::Color::Green);
    text_earth.setCharacterSize(30);
    earth_str.push_back(menu.get_count_earth() + '0');
    earth_str.push_back('/');
    earth_str.push_back('5');
    text_earth.setString(earth_str);

    win.draw(earth);
    win.draw(text_earth);
    text_wind.setCharacterSize(30);
    wind.setScale(0.12, 0.12);
    wind.setPosition(1780, 570);
    text_wind.setPosition(1850, 590);
    text_wind.setFillColor(sf::Color::White);
    wind_str.push_back(menu.get_count_wind() + '0');
    wind_str.push_back('/');
    wind_str.push_back('5');
    text_wind.setString(wind_str);
    win.draw(wind);
    win.draw(text_wind);

}

void SFMLmenuview::attack(sf::RenderWindow &win, float x, float y, float scale) {
    dmg.setScale(scale, scale);
    dmg.setPosition(x, y);
    win.draw(dmg);

}

void SFMLmenuview::drawforzen(sf::RenderWindow &win, float x, float y, float scale, float destination) {
    frozen.setPosition(x, y);
    frozen.setScale(scale, scale);
    //frozen.rotate(frozen.getRotation() - 90);

}

void SFMLmenuview::drawwin(sf::RenderWindow &win) {
    string winner;
    winner = "brawo udalo ci sie !!";
    winn.setString(winner);
    winn.setFillColor(sf::Color::Green);
    winn.setCharacterSize(100);
    winn.setPosition(470, 700);
    win.draw(winn);
    winner = "Nacisnij escp aby zakonczyc";
    winn.setString(winner);
    winn.setCharacterSize(100);
    winn.setPosition(300, 100);
    win.draw(winn);


}

void SFMLmenuview::drawlose(sf::RenderWindow &win) {
    string winner;
    winner = "Umareles !!";
    winn.setFillColor(sf::Color::Red);
    winn.setString(winner);
    winn.setCharacterSize(100);
    winn.setPosition(700, 700);
    win.draw(winn);
    winner = "Nacisnij escp aby zakonczyc";
    winn.setString(winner);
    winn.setCharacterSize(100);
    winn.setPosition(300, 100);
    win.draw(winn);
}

void SFMLmenuview::starting(sf::RenderWindow &win) {
    string str;
    str = "Projekt z programowania obiektowego. Gra Karciana na poczatku losujemy karty ekwipunktu oraz zaklecia ktore mozna zakupic w sklepie.";
    start.setCharacterSize(30);
    start.setPosition(50, 50);
    start.setString(str);
    win.draw(start);
    str = "Kupowanie oraz sprzedawanie odbywa sie w po przez klikniecie prawym przyciskiem na karte. ";
    start.setPosition(50, 100);
    start.setString(str);
    win.draw(start);
    str = "Po przygotowaniu sie do walki klikamy skrzyzowane miecze przechodzimy na arene";
    start.setPosition(50, 150);
    start.setString(str);
    win.draw(start);
    str = "Grafiki kart ekwipunku zostaly wykonane przez Julie Jaremczak studentke Architektury na PWR";
    start.setPosition(50, 200);
    start.setString(str);
    win.draw(start);
    str = "Pozostale grafiki zostaly pobrane z internetu oraz modyfikowane w programach takich jak paint i gimp";
    start.setPosition(50, 250);
    start.setString(str);
    win.draw(start);


}

void SFMLmenuview::cont(sf::RenderWindow &win) {
    string winner;
    winner = "brawo udalo ci sie !!";
    winn.setString(winner);
    winn.setFillColor(sf::Color::Green);
    winn.setCharacterSize(100);
    winn.setPosition(470, 700);
    win.draw(winn);
    winner = "Nacisnij esc aby kontynulowac";
    winn.setString(winner);
    winn.setCharacterSize(100);
    winn.setPosition(300, 100);
    win.draw(winn);
}












