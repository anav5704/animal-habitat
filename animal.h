#pragma once

#include <iostream>
#include "habitat.h"

using namespace std;

class Habitat;

//-------------------- Animal Definition  --------------------//

class Animal
{
public:
    int id;
    string name;
    int habitatCount = 0;
    // Pointer to a dynamic array, holding pointers to habitats
    Habitat **habitats = new Habitat *[0];

    Animal();
    Animal(int id, string name);
    ~Animal();

    virtual void printDetails();
    bool habitatExists(Habitat *habitat);
    void addHabitat(Habitat *habitat);
    void addHabitats(Habitat *habitats[], int habitatCount);
};

//-------------------- Bird Definition  --------------------//

class Bird : public Animal
{
public:
    double wingSpan;

    Bird();
    Bird(int id, string name, double wingSpan);
    ~Bird();

    virtual void printDetails();
};

//-------------------- Fish Definition  --------------------//

class Fish : public Animal
{
public:
    int finCount;

    Fish();
    Fish(int id, string name, int finCount);
    ~Fish();

    virtual void printDetails();
};

//-------------------- Mammal Definition  --------------------//

class Mammal : public Animal
{
public:
    int mammaryGlandCount;

    Mammal();
    Mammal(int id, string name, int mammaryGlandCount);
    ~Mammal();

    virtual void printDetails();
};

//-------------------- Reptile Definition  --------------------//

class Reptile : public Animal
{
public:
    bool isVenomous;

    Reptile();
    Reptile(int id, string name, bool isVenomous);
    ~Reptile();

    virtual void printDetails();
};

//-------------------- Amphibian Definition  --------------------//

class Amphibian : public Animal
{
public:
    int skinMoisture;

    Amphibian();
    Amphibian(int id, string name, int skinMoisture);
    ~Amphibian();

    virtual void printDetails();
};
