#pragma once

#include <iostream>
#include "animal.h"

using namespace std;

class Animal;

//-------------------- Habitat Definition  --------------------//

class Habitat
{
public:
    int id;
    string name;
    int animalCount = 0;
    // Pointer to a dynamic array, holding pointers to animals
    Animal **animals = new Animal *[0];

    Habitat();
    Habitat(int id, string name);
    ~Habitat();

    virtual void printDetails();
    bool animalExists(Animal *animal);
    void addAnimal(Animal *animal);
    void addAnimals(Animal *animals[], int animalCount);
};

//-------------------- Forest Definition  --------------------//

class Forest : public Habitat
{
public:
    string climate;

    Forest();
    Forest(int id, string name, string climate);
    ~Forest();

    virtual void printDetails();
};

//-------------------- Ocean Definition  --------------------//

class Ocean : public Habitat
{
public:
    string zone;

    Ocean();
    Ocean(int id, string name, string zone);
    ~Ocean();

    virtual void printDetails();
};

//-------------------- Desert Definition  --------------------//

class Desert : public Habitat
{
public:
    string type;

    Desert();
    Desert(int id, string name, string type);
    ~Desert();

    virtual void printDetails();
};