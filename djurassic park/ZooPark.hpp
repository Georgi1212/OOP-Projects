#ifndef __ZOOPARK_HPP
#define __ZOOPARK_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "Vector.hpp"
#include "String.hpp"
#include "KindOfDino.hpp"
#include "Type.hpp"
#include "Gender.hpp"
#include "Food.hpp"
#include "Era.hpp"
#include "Climate.hpp"
#include "Cage.cpp"
#include "CageOtherInfo.hpp"
#include "Dinosaur.cpp"
#include "DinosaurOtherInfo.cpp"
#include "FoodStorage.cpp"

using namespace std;

class ZooPark{
    public:
        void intro();
        void commands();

    private:
        void AddingCageIdAndSizeOfCage(unsigned int& size, unsigned int& cageId);
};

void ZooPark::intro(){
    std::cout << "---Welcome to the Dino park!---" << std::endl;
	std::cout << "WARNING: The commands you will type are CASE-SENSITIVE!" << std::endl;
	std::cout << "Type help if you need more information." << std::endl;
	std::cout << std::endl;
}

void ZooPark::commands(){
    //Dinosaur dinosaur;
	String name;
	KindOfDino kind;
	Gender gender;
	Food food;
	Era era;
	Climate climate;
	Type type;
	unsigned int cageId;
	
	Vector<Dinosaur> dinosaurs;
	Vector<Cage> cages;
	Vector<Food> foods;
	
	//Cage cage;
	unsigned int size;
	
	FoodStorage foodStorage;
	unsigned int quantity;
    string command;

    do
	{	
		std::cout << "> ";
		std::getline(std::cin, command,'\n');

		if(command == "help")
		{
			std::cout << std::endl;
			std::cout << "---Information---" << std::endl;
			std::cout << "The following commands are supported:" << std::endl;
			std::cout << "add dinosaur -> Adding new dinosaur;" << std::endl;
			std::cout << "add cage -> Adding cage;" << std::endl; // 
			std::cout << "add food -> Adding food to storage;" << std::endl;
			std::cout << "remove dinosaur -> Removing dinosaur;" << std::endl;
			std::cout << "exit -> Ends the program." << std::endl;
			std::cout << std::endl;
		}
		
		else if (command == "add dinosaur")
		{
			String name;
			KindOfDino kind;
			Gender gender;
			Food food;
			Era era;
			Climate climate;
			Type type;
			unsigned int cageId;

			std::cout << "Enter the name: ";
			std::cin >> name;
			
			std::cout << std::endl;
			
			std::cout << "Enter the gender (0-MALE | 1-FEMALE): ";
			std::cin >> gender;
			
			std::cout << std::endl;
			
			std::cout << "Enter the era (0-TRIAS | 1-CHALK | 2-JURA): ";
			std::cin >> era;
			
			std::cout << endl;
			
			std::cout << "Enter the kind (0-CARNIVOROUS | 1-HERBIVOROUS | 2-AQUATIC | 3-FLYING): ";
			std::cin >> kind; 
			
			std::cout << std::endl;
			
			std::cout << "Enter the type (0-PLESIOSAURUS | 1-BROTOSAURUS | 2-TYRANNOSAURUS): ";
			std::cin >> type;
			
			std::cout << std::endl;
			
			std::cout << "Enter the food (0-GRASS | 1-MEAT | 2-FISH): ";
			std::cin >> food;
			
			std::cout << std::endl;
			
		 	Dinosaur dinosaur(name, gender, era, kind, type, food);
			
			if(cages.getSize() > 0)
			{
				bool flag = false;
				
				for (unsigned int i = 0; i < cages.getSize(); ++i)
				{
					if(cages[i].isThisCageSuitable(dinosaur) && cages[i].isThereAnySpaceInCage())
					{
						cages[i].addDinosaur(dinosaur);
						std::cout << dinosaur.getName() << " is successfully added in the cage with id " << cages[i].getCageId() << std::endl;
						flag = true;
						break;
					}
				}
				
				if (flag == false)
				{
					std::cout << "This dinosaur is not suitable for this cage! Enter the data of the new cage where this dinosaur will be added." << std::endl;
					AddingCageIdAndSizeOfCage(size, cageId);
					Climate currentClimate = dinosaur.getClimateByKind(dinosaur.getKindOfDino());
					Cage newCage(cageId, size, currentClimate, dinosaur.getEra());

					newCage.addDinosaur(dinosaur);
					cages.push_back(newCage);
					std::cout << "Dinosaur " << name << " is successfully added in the cage with id " << cageId << std::endl;
				}
			}
			
			else
			{
				std::cout << "There is no cages! Enter the data of the first new cage." << std::endl;

				AddingCageIdAndSizeOfCage(size, cageId);
				Climate currentClimate = dinosaur.getClimateByKind(dinosaur.getKindOfDino());
				Cage newCage(cageId, size, currentClimate, dinosaur.getEra());

				newCage.addDinosaur(dinosaur);
				cages.push_back(newCage);
				std::cout << "Dinosaur " << name << " is successfully added in the cage with id " << cageId << std::endl;
			}
            dinosaurs.push_back(dinosaur);
		}
		
		else if(command == "add cage")
		{
			AddingCageIdAndSizeOfCage(size, cageId);
			
			std::cout << "Enter the climate (0-TERRESTRIAL | 1-AIR | 2-WATER): ";
			std::cin >> climate;
			
			std::cout << "Enter the era (0-TRIAS | 1-CHALK | 2-JURA): ";
			std::cin >> era;
			
			Cage newcage(cageId, size, climate, era);
			cages.push_back(newcage);
			std::cout << "You have successfully added a new cage with id " << cageId << "!" << std::endl;
			
		}
		
		else if(command == "add food")
		{
			std::cout << "Enter quantity of food: ";
			std::cin >> quantity;

			std::cout << "Enter the id of the cage you want to add this quantity of food: ";
			std::cin >> cageId;
			
			/*cout << "Enter food: (0-GRASS | 1-MEAT | 2-FISH) " << endl;
			cin >> food;*/
			
			for (unsigned int i = 0; i < cages.getSize(); ++i)
			{
				if (cages[i].getCageId() == cageId && cages[i].getClimate() == TERRESTRIAL)
				{
					food = MEAT;
					cages[i].addFood(food, quantity);

					food = GRASS;
					cages[i].addFood(food, quantity);
					cout << "There is enough meat and grass in this cage with id " << cageId << endl;
				}
				
				if (cages[i].getCageId() == cageId && cages[i].getClimate() == WATER)
				{
					food = FISH;
					cages[i].addFood(food, quantity);
					cout << "There is enough fish in this cage with id " << cageId << endl;
				}
				
				if(cages[i].getCageId() == cageId && cages[i].getClimate() == AIR)
				{
					food = GRASS;
					cages[i].addFood(food, quantity);
					food = MEAT;
					cages[i].addFood(food, quantity);
					food = FISH;
					cages[i].addFood(food, quantity);
					cout << "There is enough food in this cage with id " << cageId << endl;
				}
			}
		}
		
		else if(command == "remove dinosaur")
		{
			std::cout << "Enter cageId: ";
			std::cin >> cageId;
			
			std::cout << "Enter the name of the dino you would like to remove: ";
			std::cin >> name;

			for(int i = 0; i < cages.getSize(); i++)
			{
				if(cages[i].getCageId() == cageId)
				{
					cages[i].removeDinosaur(name);
				}
			}

			for(int i = 0; i < dinosaurs.getSize(); i++){
				if(dinosaurs[i].getName() == name)
				{
					dinosaurs.deleteAt(i);
				}
			}
			std::cout << "Dinosaur " << name << " is successfully removed from cage with id " << cageId << std::endl;
		}
		
		else if(command == "exit")
		{
            std::cout << "Goodbye" << std::endl;
            break;
        }
		
		//else
		//{
		//	std::cout << "Wrong input!" << std::endl;
		//}
		
	} while (true);

	ofstream DinosOutput("Dinos.txt");
	for (unsigned int i = 0; i < dinosaurs.getSize(); ++i)
	{
    	DinosOutput << dinosaurs[i] << '\n';
    }
    
    ofstream CagesOutput("Cages.txt");
    for (unsigned int i = 0; i< cages.getSize(); ++i)
	{
    	CagesOutput << cages[i] << '\n';
    }

}

void ZooPark::AddingCageIdAndSizeOfCage(unsigned int& size, unsigned int& cageId)
{
	cout << "Enter cageId: ";
	cin >> cageId;
	
	cout << "Size of the cage: ";
	cin >> size;
}


#endif