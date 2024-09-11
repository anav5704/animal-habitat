#include <iostream>
#include "habitat.h"

using namespace std;

//-------------------- Habitat Implementation --------------------//

Habitat::Habitat()
{
    cout << "[LOG] Habitat default constructor called" << endl;
}

Habitat::Habitat(int id, string name)
    : id(id), name(name)
{
    cout << "[LOG] Habitat parameterized constructor called" << endl;
}

Habitat::~Habitat()
{
    delete[] animals;
    animals = nullptr;

    cout << "[LOG] Habitat destructor called" << endl;
}

bool Habitat::animalExists(Animal *animal)
{
    for (int i = 0; i < animalCount; i++)
    {
        if (animals[i] == animal)
        {
            return true;
        }
    }

    return false;
}

void Habitat::addAnimal(Animal *animal)
{
    // TODO: Logic to prevent recursive loop needs improvement
    if (animalExists(animal) || animal->habitatExists(this))
    {
        cout << "[APP] Animal: " << animal->name << " already exists in habitat: " << name << endl;
        return;
    }

    // Create new dynamic array with one extra member
    Animal **newAnimals = new Animal *[animalCount + 1];

    // Transfer existing animal pointers to new array
    for (int i = 0; i < animalCount; i++)
    {
        newAnimals[i] = animals[i];
    }

    // Add new animal pointer to new array
    newAnimals[animalCount] = animal;

    // De-allocate memory of old array
    delete[] this->animals;

    // Assign pointer to new array
    this->animals = newAnimals;

    ++animalCount;

    animal->addHabitat(this);

    cout << "[APP] Added animal: " << animal->name << " to habitat: " << name << endl;
}

void Habitat::addAnimals(Animal *animals[], int animalCount)
{
    // Create new dynamic array with animalCount extra members
    Animal **newAnimals = new Animal *[this->animalCount + animalCount];

    // Transfer existing animal pointers to new array
    for (int i = 0; i < this->animalCount; i++)
    {
        newAnimals[i] = this->animals[i];
    }

    // Add new animal pointers to new array
    for (int i = 0; i < animalCount; i++)
    {
        animals[i]->addHabitat(this);
        newAnimals[this->animalCount + i] = animals[i];
        cout << "[APP] Added animal: " << animals[i]->name << " to habitat: " << name << endl;
    }

    // De-allocate memory of old array
    delete[] this->animals;

    // Assign pointer to new array
    this->animals = newAnimals;

    this->animalCount += animalCount;
}

void Habitat::printDetails()
{
    cout << "[APP] Habitat: " << this << endl;
    cout << "[APP] Id: " << id << endl;
    cout << "[APP] Name: " << name << endl;

    if (animalCount == 0)
    {
        cout << "[APP] Habitat does not have any animals" << endl;
    }

    else
    {
        cout << "[APP] Animals: ";

        for (int i = 0; i < animalCount; i++)
        {
            cout << animals[i]->name << " (" << animals[i] << ")" << (animals[i + 1] ? ", " : " ");
        }

        cout << endl;
    }
}

//-------------------- Forest Implementation --------------------//

Forest::Forest()
{
    cout << "[LOG] Forest default constructor called" << endl;
}

Forest::Forest(int id, string name, string climate)
    : Habitat(id, name), climate(climate)
{
    cout << "[LOG] Forest parameterized constructor called" << endl;
}

Forest::~Forest()
{
    cout << "[LOG] Forest destructor called" << endl;
}

void Forest::printDetails()
{
    cout << "[APP] Forest: " << this << endl;
    Habitat::printDetails();
    cout << "[APP] Climate: " << climate << endl;
}

//-------------------- Ocean Implementation --------------------//

Ocean::Ocean()
{
    cout << "[LOG] Ocean default constructor called" << endl;
}

Ocean::Ocean(int id, string name, string zone)
    : Habitat(id, name), zone(zone)
{
    cout << "[LOG] Ocean parameterized constructor called" << endl;
}

Ocean::~Ocean()
{
    cout << "[LOG] Ocean destructor called" << endl;
}

void Ocean::printDetails()
{
    cout << "[APP] Ocean: " << this << endl;
    Habitat::printDetails();
    cout << "[APP] Zone: " << zone << endl;
}

//-------------------- Desert Implementation --------------------//

Desert::Desert()
{
    cout << "[LOG] Desert default constructor called" << endl;
}

Desert::Desert(int id, string name, string type)
    : Habitat(id, name), type(type)
{
    cout << "[LOG] Desert parameterized constructor called" << endl;
}

Desert::~Desert()
{
    cout << "[LOG] Desert destructor called" << endl;
}

void Desert::printDetails()
{
    cout << "[APP] Desert: " << this << endl;
    Habitat::printDetails();
    cout << "[APP] Type: " << type << endl;
}
