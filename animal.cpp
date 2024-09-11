#include <iostream>
#include "animal.h"

using namespace std;

//-------------------- Animal Implementation --------------------//

Animal::Animal()
{
    cout << "[LOG] Animal default constructor called" << endl;
}

Animal::Animal(int id, string name)
    : name(name), id(id)
{
    cout << "[LOG] Animal parameterized constructor called" << endl;
}

Animal::~Animal()
{
    delete[] habitats;
    habitats = nullptr;

    cout << "[LOG] Animal default destructor called" << endl;
}

bool Animal::habitatExists(Habitat *habitat)
{
    for (int i = 0; i < habitatCount; i++)
    {
        if (habitats[i] == habitat)
        {
            cout << "[APP] Habitat: " << habitat->name << " already exists in animal: " << name << endl;
            return true;
        }
    }

    return false;
}

void Animal::addHabitat(Habitat *habitat)
{
    // TODO: Logic to prevent recursive loop needs improvement
    if (habitatExists(habitat) || habitat->animalExists(this))
    {
        return;
    }

    // Create new dynamic array with one extra member
    Habitat **newHabitats = new Habitat *[habitatCount + 1];

    // Transfer existing habitat pointers to new array
    for (int i = 0; i < habitatCount; i++)
    {
        newHabitats[i] = habitats[i];
    }

    // Add new habitat pointer to new array
    newHabitats[habitatCount] = habitat;

    // De-allocate memory of old array
    delete[] this->habitats;

    // Assign pointer to new array
    this->habitats = newHabitats;

    ++habitatCount;

    habitat->addAnimal(this);

    cout << "[APP] Added habitat: " << habitat->name << " to animal: " << name << endl;
}

void Animal::addHabitats(Habitat *habitats[], int habitatCount)
{
    // Create new dynamic array with habitatCount extra members
    Habitat **newHabitats = new Habitat *[this->habitatCount + habitatCount];

    // Transfer existing habitat pointers to new array
    for (int i = 0; i < this->habitatCount; i++)
    {
        newHabitats[i] = this->habitats[i];
    }

    // Add new habitat pointers to new array
    for (int i = 0; i < habitatCount; i++)
    {
        habitats[i]->addAnimal(this);
        newHabitats[this->habitatCount + i] = habitats[i];
        cout << "[APP] Added animal: " << habitats[i]->name << " to habitat: " << name << endl;
    }

    // De-allocate memory of old array
    delete[] this->habitats;

    // Assign pointer to new array
    this->habitats = newHabitats;

    this->habitatCount += habitatCount;
}

void Animal::printDetails()
{
    cout << "[APP] Animal: " << this << endl;
    cout << "[APP] Id: " << id << endl;
    cout << "[APP] Name: " << name << endl;

    if (habitatCount == 0)
    {
        cout << "[APP] Animal does not belong to any habitats" << endl;
    }

    else
    {
        cout << "[APP] Habitats: ";

        for (int i = 0; i < habitatCount; i++)
        {
            cout << habitats[i]->name << " (" << habitats[i] << ")" << (habitats[i + 1] ? ", " : " ");
        }

        cout << endl;
    }
}

//-------------------- Bird Implementation --------------------//

Bird::Bird()
{
    cout << "[LOG] Bird default constructor called" << endl;
}

Bird::Bird(int id, string name, double wingSpan)
    : Animal(id, name), wingSpan(wingSpan)
{
    cout << "[LOG] Bird parameterized constructor called" << endl;
}

Bird::~Bird()
{
    cout << "[LOG] Bird default destructor called" << endl;
}

void Bird::printDetails()
{
    cout << "[APP] Bird: " << this << endl;
    Animal::printDetails();
    cout << "[APP] Wing span: " << wingSpan << endl;
}

//-------------------- Fish Implementation --------------------//

Fish::Fish()
{
    cout << "[LOG] Fish default constructor called" << endl;
}

Fish::Fish(int id, string name, int finCount)
    : Animal(id, name), finCount(finCount)
{
    cout << "[LOG] Fish parameterized constructor called" << endl;
}

Fish::~Fish()
{
    cout << "[LOG] Fish default destructor called" << endl;
}

void Fish::printDetails()
{
    cout << "[APP] Fish: " << this << endl;
    Animal::printDetails();
    cout << "[APP] Fin count: " << finCount << endl;
}

//-------------------- Mammal Implementation --------------------//

Mammal::Mammal()
{
    cout << "[LOG] Mammal default constructor called" << endl;
}

Mammal::Mammal(int id, string name, int mammaryGlandCount)
    : Animal(id, name), mammaryGlandCount(mammaryGlandCount)
{
    cout << "[LOG] Mammal parameterized constructor called" << endl;
}

Mammal::~Mammal()
{
    cout << "[LOG] Mammal default destructor called" << endl;
}

void Mammal::printDetails()
{
    cout << "[APP] Mammal: " << this << endl;
    Animal::printDetails();
    cout << "[APP] Mammary gland count: " << mammaryGlandCount << endl;
}

//-------------------- Reptile Implementation --------------------//

Reptile::Reptile()
{
    cout << "[LOG] Reptile default constructor called" << endl;
}

Reptile::Reptile(int id, string name, bool isVenomous)
    : Animal(id, name), isVenomous(isVenomous)
{
    cout << "[LOG] Reptile parameterized constructor called" << endl;
}

Reptile::~Reptile()
{
    cout << "[LOG] Reptile default destructor called" << endl;
}

void Reptile::printDetails()
{
    cout << "[APP] Reptile: " << this << endl;
    Animal::printDetails();
    cout << "[APP] Is venomous: " << isVenomous << endl;
}

//-------------------- Amphibian Implementation --------------------//

Amphibian::Amphibian()
{
    cout << "[LOG] Amphibian default constructor called" << endl;
}

Amphibian::Amphibian(int id, string name, int skinMoisture)
    : Animal(id, name), skinMoisture(skinMoisture)
{
    cout << "[LOG] Amphibian parameterized constructor called" << endl;
}

Amphibian::~Amphibian()
{
    cout << "[LOG] Amphibian default destructor called" << endl;
}

void Amphibian::printDetails()
{
    cout << "[APP] Amphibian: " << this << endl;
    Animal::printDetails();
    cout << "[APP] Skin moisture: " << skinMoisture << endl;
}
