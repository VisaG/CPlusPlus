/*
 * a5_2client.cpp
 *
 *  Created on: Jun 10, 2013
 *      Author: visa
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "a5_2_creature.h"
#include "a5_2_human.h"
#include "a5_2_elf.h"
#include "a5_2_demon.h"
#include "a5_2_cyber.h"
#include "a5_2_balrog.h"

using namespace std;

void battleArena(creature *creature1, creature *creature2);

int main() {
    srand(time(0));

    human h1;
    elf e1;
    cyberdemon c1;
    balrog b1;

    human h(20, 30);
    elf e(40, 50);
    cyberdemon c(60, 70);
    balrog b(80, 90);

    cout << "default human strength/hitpoints: " << h1.getStrength() << "/"
            << h1.getHitpoints() << endl;
    cout << "default elf strength/hitpoints: " << e1.getStrength() << "/"
            << e1.getHitpoints() << endl;
    cout << "default cyberdemon strength/hitpoints: " << c1.getStrength() << "/"
            << c1.getHitpoints() << endl;
    cout << "default balrog strength/hitpoints: " << b1.getStrength() << "/"
            << b1.getHitpoints() << endl;
    cout << "non-default human strength/hitpoints: " << h.getStrength() << "/"
            << h.getHitpoints() << endl;
    cout << "non-default elf strength/hitpoints: " << e.getStrength() << "/"
            << e.getHitpoints() << endl;
    cout << "non-default cyberdemon strength/hitpoints: " << c.getStrength()
            << "/" << c.getHitpoints() << endl;
    cout << "non-default balrog strength/hitpoints: " << b.getStrength() << "/"
            << b.getHitpoints() << endl;
    cout << endl << endl;

    cout << "Examples of " << h.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = h.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Examples of " << e.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = e.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Examples of " << c.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = c.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    cout << "Examples of " << b.getSpecies() << " damage: " << endl;
    for (int i = 0; i < 10; i++) {
        int damage = b.getDamage();
        cout << " Total damage = " << damage << endl;
        cout << endl;
    }
    cout << endl;

    elf e11(50, 50);
    balrog b11(50, 50);
    human h11(15, 120);
    elf e12(50, 100);
    cyberdemon c15(25, 65);

    battleArena(&e11, &b11);
    battleArena(&e12, &h11);
    battleArena(&c15, &e12);
    battleArena(&b11, &c15);

}

void battleArena(creature *creature1, creature *creature2) {

    cout << "Battle Arena starts between " << creature1->getSpecies() << " and "
            << creature2->getSpecies() << endl << endl;

    bool done = false;
    int counter = 0;

    while (!done) {
        if (creature1->getHitpoints() <= 0 && creature2->getHitpoints() <= 0) {
            cout << "Its a tie a between " << creature1->getSpecies() << " and "
                    << creature2->getSpecies() << endl << endl;
            done = true;
        } else {
            if ((creature1->getHitpoints() > 0 && creature2->getHitpoints() < 0)
                    || (creature2->getHitpoints() > 0
                            && creature1->getHitpoints() < 0)) {

                if (creature1->getHitpoints() > creature2->getHitpoints()) {
                    cout << creature1->getSpecies() << " won the battle "
                            << endl << endl;
                } else {

                    cout << creature2->getSpecies() << " won the battle "
                            << endl << endl;
                }

                done = true;
            }
        }
        if (!done) {

            int damageC1 = creature1->getDamage();
            int damageC2 = creature2->getDamage();

            cout << endl;
            cout << "Damage inflicted by " << creature1->getSpecies() << " "
                    << damageC1 << endl;
            cout << "Damage inflicted by " << creature2->getSpecies() << " "
                    << damageC2 << endl << endl;

            cout << "Hit points by " << creature1->getSpecies() << " "
                    << creature1->getHitpoints() << endl;
            cout << "Hit points by " << creature2->getSpecies() << " "
                    << creature2->getHitpoints() << endl << endl;

            creature2->setHitpoints(creature2->getHitpoints() - damageC1);
            creature1->setHitpoints(creature1->getHitpoints() - damageC2);

            cout << "Resulting hitpoints after battle [round " << ++counter
                    << "] on " << creature1->getSpecies() << " is: "
                    << creature1->getHitpoints() << endl;

            cout << "Resulting hitpoints after battle [round " << counter
                    << "] on " << creature2->getSpecies() << " is: "
                    << creature2->getHitpoints() << endl << endl;

        }
    }
}

