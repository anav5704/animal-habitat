#include <iostream>
#include "animal.h"
#include "habitat.h"

int main()
{
    Animal **forestAnimals = new Animal *[3];
    Animal **oceanAnimals = new Animal *[3];

    forestAnimals[0] = new Bird(1, "Eagle", 10);
    forestAnimals[1] = new Mammal(2, "Tiger", 6);
    forestAnimals[2] = new Reptile(3, "Snake", true);
    cout << endl;

    oceanAnimals[0] = new Fish(4, "Tuna", 7);
    oceanAnimals[1] = new Fish(5, "Jellyfish", 0);
    oceanAnimals[2] = new Amphibian(6, "Frog", 0);
    cout << endl;

    Habitat *forest = new Forest(7, "Forest", "Tropical");
    Habitat *ocean = new Ocean(8, "Ocean", "Upper");
    cout << endl;

    forest->addAnimals(forestAnimals, 3);
    cout << endl;

    ocean->addAnimals(oceanAnimals, 3);
    cout << endl;

    forest->printDetails();
    cout << endl;

    ocean->printDetails();
    cout << endl;

    for (int i = 0; i < 3; i++)
    {
        forestAnimals[i]->printDetails();
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        oceanAnimals[i]->printDetails();
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        delete forestAnimals[i];
        delete oceanAnimals[i];
    }

    delete[] forestAnimals;
    delete[] oceanAnimals;

    delete forest;
    delete ocean;

    cout << "[LOG] Program ended with no errors" << endl;

    return 0;
}
