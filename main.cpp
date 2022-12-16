#include <iostream>
#include "weapon.h"
#include "Unit.h"
#include "fightmenager.h"
#include "SfmlMouseArena.h"
#include "menumenager.h"
#include "Aktioncards.h"
#include "SFMLmenuview.h"
#include "SFMLmenucontrol.h"
#include "Sfmlarenaview.h"

#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));
    Unit good(10, 5, 50, "GIGA CHAD");
    Unit demon(100, 1000, 100, "demon");
    cout << good.get_name() << endl;
    cout << demon.get_name() << endl;
    int backupHP;
    bool is_alive = true;


    weapon itememki(10);
    Aktioncards karty(10);
    menumenager shop1(itememki, good, karty);
    shop1.clear_eq();
    menumenager shop_demon(itememki, demon, karty);
    shop_demon.clear_eq();

    SFMLmenuview sfml_menu1(itememki, good, karty, shop1);
    SFMLmenuview menu_demon(itememki, demon, karty, shop_demon);
    fightmenager fight_vs_demon(itememki, good, demon, karty, shop1);
    SFMLmenucontrol control(shop1);
    Sfmlarenaview view_vs_demon(demon, sfml_menu1, menu_demon);
    SfmlMouseArena mouse_vs_demon(fight_vs_demon);


    sf::RenderWindow start(sf::VideoMode(1920, 980), "start");
    start.setVerticalSyncEnabled(false);
    start.setFramerateLimit(30);
    while (start.isOpen()) {
        sf::Event eventstart;
        while (start.pollEvent(eventstart)) {
            if (eventstart.type == sf::Event::Closed)
                start.close();
            if (sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::Escape)) {
                start.close();
            }
        }

        start.clear();
        sfml_menu1.starting(start);
        start.display();
    }

    sf::RenderWindow Shop(sf::VideoMode(1920, 980), "Shop");
    Shop.setVerticalSyncEnabled(false);
    Shop.setFramerateLimit(30);
    while (Shop.isOpen()) {
        sf::Event event;
        while (Shop.pollEvent(event)) {
            sf::Event event;
            while (Shop.pollEvent(event)) {
                switch (event.type) {

                    case sf::Event::Closed:
                        Shop.close();
                        break;

                    case sf::Event::MouseButtonPressed:
                        switch (event.key.code) {
                            case sf::Mouse::Left: {
                                control.gameplay(event, Shop);
                                sf::Vector2i mp = sf::Mouse::getPosition(Shop);
                                break;
                            }
                            case sf::Mouse::Right: {
                                control.gameplay(event, Shop);
                                break;
                            }
                        }
                        break;

                }

            }
        }

        Shop.clear();
        sfml_menu1.draw(Shop);
        Shop.display();
    }
    sf::RenderWindow Demon_fight(sf::VideoMode(1920, 980), "Demon_fight");
    Demon_fight.setVerticalSyncEnabled(false);
    Demon_fight.setFramerateLimit(30);
    backupHP = good.get_hp();
    while (Demon_fight.isOpen()) {
        sf::Event eventDemon_fight;
        while (Demon_fight.pollEvent(eventDemon_fight)) {
            sf::Event eventDemon_fight;
            while (Demon_fight.pollEvent(eventDemon_fight)) {
                switch (eventDemon_fight.type) {

                    case sf::Event::Closed:
                        Demon_fight.close();
                        break;

                    case sf::Event::MouseButtonPressed:
                        switch (eventDemon_fight.key.code) {
                            case sf::Mouse::Left: {
                                mouse_vs_demon.gameplay(eventDemon_fight, Demon_fight);
                                sf::Vector2i mp = sf::Mouse::getPosition(Demon_fight);
                                break;
                            }
                            case sf::Mouse::Right: {
                                mouse_vs_demon.gameplay(eventDemon_fight, Demon_fight);
                                break;
                            }
                        }
                        break;

                }

            }
        }

        Demon_fight.clear();
        view_vs_demon.draw(Demon_fight);
        if (good.get_hp() > 0 and demon.get_hp() <= 0) {
            Demon_fight.clear();
            sfml_menu1.cont(Demon_fight);
            is_alive = true;
            if (sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::Escape)) {
                Demon_fight.close();

            }
        }
        if (good.get_hp() <= 0 and demon.get_hp() > 0) {
            Demon_fight.clear();
            sfml_menu1.drawlose(Demon_fight);
            is_alive = false;
            if (sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::Escape)) {
                Demon_fight.close();
            }
        }

        Demon_fight.display();
    }
    if (is_alive) {
        good.increase_gold(30);
        menumenager shop2(itememki, good, karty);
        SFMLmenucontrol control2(shop2);

        for (int i = 0; i < 11; ++i) {
            shop2.set_owned(shop1.get_owned(i), i);
        }
        SFMLmenuview sfml_menu2(itememki, good, karty, shop2);
        sf::RenderWindow sklep2(sf::VideoMode(1920, 980), "Sklep2");
        sklep2.setVerticalSyncEnabled(false);
        sklep2.setFramerateLimit(30);

        while (sklep2.isOpen()) {
            sf::Event event2;
            while (sklep2.pollEvent(event2)) {
                sf::Event event2;
                while (sklep2.pollEvent(event2)) {
                    switch (event2.type) {

                        case sf::Event::Closed:
                            sklep2.close();
                            break;

                        case sf::Event::MouseButtonPressed:
                            switch (event2.key.code) {
                                case sf::Mouse::Left: {
                                    control2.gameplay(event2, sklep2);
                                    sf::Vector2i mp = sf::Mouse::getPosition(Shop);
                                    break;
                                }
                                case sf::Mouse::Right: {
                                    control2.gameplay(event2, sklep2);
                                    break;
                                }
                            }
                            break;

                    }

                }
            }

            sklep2.clear();
            sfml_menu2.draw(sklep2);
            sklep2.display();
        }


        Unit monster(20, 20, 100, "monster");
        fightmenager fight_vs_monster(itememki, good, monster, karty, shop2);
        menumenager shop_monster(itememki, demon, karty);
        SFMLmenuview menu_monster(itememki, monster, karty, shop_monster);
        Sfmlarenaview view_vs_monster(monster, sfml_menu2, menu_monster);
        SfmlMouseArena mouse_vs_monster(fight_vs_monster);

        sf::RenderWindow Monster_fight(sf::VideoMode(1920, 980), "Monster_fight");
        Monster_fight.setVerticalSyncEnabled(false);
        Monster_fight.setFramerateLimit(30);
        backupHP = good.get_hp();
        while (Monster_fight.isOpen()) {
            sf::Event eventMonster_fight;
            while (Monster_fight.pollEvent(eventMonster_fight)) {
                sf::Event eventMonster_fight;
                while (Monster_fight.pollEvent(eventMonster_fight)) {
                    switch (eventMonster_fight.type) {

                        case sf::Event::Closed:
                            Monster_fight.close();
                            break;

                        case sf::Event::MouseButtonPressed:
                            switch (eventMonster_fight.key.code) {
                                case sf::Mouse::Left: {
                                    mouse_vs_monster.gameplay(eventMonster_fight, Monster_fight);
                                    sf::Vector2i mp = sf::Mouse::getPosition(Monster_fight);
                                    break;
                                }
                                case sf::Mouse::Right: {
                                    mouse_vs_monster.gameplay(eventMonster_fight, Monster_fight);
                                    break;
                                }
                            }
                            break;

                    }

                }
            }

            Monster_fight.clear();
            view_vs_monster.draw(Monster_fight);
            if (good.get_hp() > 0 and monster.get_hp() <= 0) {
                Monster_fight.clear();
                sfml_menu2.cont(Monster_fight);
                is_alive = true;
                if (sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::Escape)) {
                    Monster_fight.close();

                }
            }
            if (good.get_hp() <= 0 and monster.get_hp() > 0) {
                Monster_fight.clear();
                sfml_menu2.drawlose(Monster_fight);
                is_alive = false;
                if (sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::Escape)) {
                    Monster_fight.close();
                }
            }
            if (!is_alive) {
                return 0;
            }

            Monster_fight.display();
        }
        good.increase_gold(30);
        menumenager shop3(itememki, good, karty);
        SFMLmenucontrol control3(shop3);

        for (int i = 0; i < 11; ++i) {
            shop3.set_owned(shop2.get_owned(i), i);
        }
        SFMLmenuview sfml_menu3(itememki, good, karty, shop3);
        sf::RenderWindow sklep3(sf::VideoMode(1920, 980), "Sklep3");
        sklep3.setVerticalSyncEnabled(false);
        sklep3.setFramerateLimit(30);

        while (sklep3.isOpen()) {
            sf::Event event3;
            while (sklep3.pollEvent(event3)) {
                sf::Event event3;
                while (sklep3.pollEvent(event3)) {
                    switch (event3.type) {

                        case sf::Event::Closed:
                            sklep3.close();
                            break;

                        case sf::Event::MouseButtonPressed:
                            switch (event3.key.code) {
                                case sf::Mouse::Left: {
                                    control3.gameplay(event3, sklep3);

                                    break;
                                }
                                case sf::Mouse::Right: {
                                    control3.gameplay(event3, sklep3);
                                    break;
                                }
                            }
                            break;

                    }

                }
            }

            sklep3.clear();
            sfml_menu3.draw(sklep3);
            sklep3.display();
        }


        Unit dragon(20, 20, 100, "dragon");
        fightmenager fight_vs_dragon(itememki, good, dragon, karty, shop3);
        menumenager shop_dragon(itememki, demon, karty);
        SFMLmenuview menu_dragon(itememki, dragon, karty, shop_dragon);
        Sfmlarenaview view_vs_dragon(dragon, sfml_menu3, menu_dragon);
        SfmlMouseArena mouse_vs_dragon(fight_vs_dragon);

        sf::RenderWindow Dragon_fight(sf::VideoMode(1920, 980), "dragon_fight");
        Dragon_fight.setVerticalSyncEnabled(false);
        Dragon_fight.setFramerateLimit(30);
        backupHP = good.get_hp();
        while (Dragon_fight.isOpen()) {
            sf::Event eventDragon_fight;
            while (Dragon_fight.pollEvent(eventDragon_fight)) {
                sf::Event eventDragon_fight;
                while (Dragon_fight.pollEvent(eventDragon_fight)) {
                    switch (eventDragon_fight.type) {

                        case sf::Event::Closed:
                            Dragon_fight.close();
                            break;

                        case sf::Event::MouseButtonPressed:
                            switch (eventDragon_fight.key.code) {
                                case sf::Mouse::Left: {
                                    mouse_vs_dragon.gameplay(eventDragon_fight, Dragon_fight);
                                    sf::Vector2i mp = sf::Mouse::getPosition(Dragon_fight);
                                    break;
                                }
                                case sf::Mouse::Right: {
                                    mouse_vs_dragon.gameplay(eventDragon_fight, Dragon_fight);
                                    break;
                                }
                            }
                            break;

                    }

                }
            }

            Dragon_fight.clear();
            view_vs_dragon.draw(Dragon_fight);
            if (good.get_hp() > 0 and dragon.get_hp() <= 0) {
                Dragon_fight.clear();
                sfml_menu3.drawwin(Dragon_fight);
                is_alive = true;
                if (sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::Escape)) {
                    Dragon_fight.close();

                }
            }
            if (good.get_hp() <= 0 and dragon.get_hp() > 0) {
                Dragon_fight.clear();
                sfml_menu3.drawlose(Dragon_fight);
                is_alive = false;
                if (sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::Escape)) {
                    Dragon_fight.close();
                }
            }

            Dragon_fight.display();
        }

        return 0;
    }
}
