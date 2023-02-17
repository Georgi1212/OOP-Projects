#ifndef __CAGE_CPP
#define __CAGE_CPP

#include "Cage.hpp"

Cage::Cage()
{
	cageId = 0;
	size = 0;
	climate = OTHERCLIMATE; 
	era = OTHERERA;
}

Cage::Cage(unsigned int _cageId, unsigned int _size, Climate _climate, Era _era)
{
	cageId = _cageId;
	size = _size;
	climate = _climate;
	era = _era;
}

void Cage::addDinosaur(Dinosaur& dinosaur)
{
	dinosaur.setCageId(this->cageId);
	dinosaurs.push_back(dinosaur);
}

void Cage::removeDinosaur(String& name)
{
	int index = 0;
	
	for(unsigned int i = 0; i < this->dinosaurs.getSize(); ++i)
	{
		if(dinosaurs[i].getName() == name)
		{
			this->dinosaurs.deleteAt(i);
			break;
		}
	}
}

void Cage::addFood(Food food, unsigned int quantity)
{
	switch(food)
	{
		case GRASS: foodStorage.addGrass(quantity); break;
		case MEAT: foodStorage.addMeat(quantity); break;
		case FISH: foodStorage.addFish(quantity); break;
		default: cerr << "Unknown food. "; break;
	}
}

void Cage::removeFood(Food food, unsigned int quantity)
{
	switch(food)
	{
		case GRASS: foodStorage.removeGrass(quantity); break;
		case MEAT: foodStorage.removeMeat(quantity); break;
		case FISH: foodStorage.removeFish(quantity); break;
		default: cerr << "Unknown food. "; break;
	}
}

void Cage::setClimate (Climate _climate)
{
	this->climate = _climate;
}

const int Cage::getCageId() const
{
	return this->cageId;
}

const int Cage::getCurrentSizeInCage() const
{
	return this->dinosaurs.getSize();
}

Climate Cage::getClimate() const
{
	return this->climate;
}

Era Cage::getEra() const
{
	return this->era;
}

Vector<Dinosaur> Cage::getDinosaurs() const{
	return this->dinosaurs;
}

bool Cage::isThereAnySpaceInCage()
{
	return dinosaurs.getSize() < size;
}

bool Cage::isThisCageSuitable(Dinosaur& dinosaur)
{
	if(era != dinosaur.getEra() && dinosaurs[0].getKindOfDino() != dinosaur.getKindOfDino() && dinosaurs.getSize() >= size)
	{
		return false;
	}
	
	return true;
}

void Cage::printCage() const
{
	cout << "Id: " << cageId << endl;
	cout << "Size: " << size << endl;
	cout << "Climate: ";
		switch(climate)
		{
			case TERRESTRIAL: cout << "Terrestrial" << endl; break;
			case AIR: cout << "Air" << endl; break;
			case WATER: cout << "Water"<< endl ;break;
			default: cerr << "Other climate. "; break; 
		}
		
	cout << "Era: ";
		switch(era)
		{
			case TRIAS: cout << "Trias" << endl; break;
			case CHALK: cout << "Chalk" << endl; break;
			case JURA: cout << "Jura" << endl; break;
			default: cerr << "Other era. "; break;
		}
	
	cout << "Meat Quantity: " << foodStorage.getMeat() << "; Grass Quantity: " << foodStorage.getGrass() << "; Fish Quantity: " << foodStorage.getFish() << endl;
	
	for (unsigned int i = 0; i < dinosaurs.getSize(); ++i)
	{
		dinosaurs[i].printDinosaur();
	}
}

std::ostream& operator<<(std::ostream& out, const Cage& cg)
{
	out << "Cage id: " << cg.cageId << " | Size: " << cg.size << " | Climate: ";
	switch(cg.climate)
	{
		case (Climate)0: out << "TERRESTRIAL "; break;
	    case (Climate)1: out << "AIR "; break;
		case (Climate)2: out << "WATER "; break;
		default: out << "OTHER "; break;
	}
	
	out << " | Era: ";
	switch(cg.era)
	{
		case (Era)0: out << "TRIAS "; break;
	    case (Era)1: out << "CHALK "; break;
		case (Era)2: out << "JURA "; break;
		default: out << "OTHER "; break;
	}
	out << endl;
	out << "Dinosaurs in cage with id " << cg.cageId << ":" << endl;
	for (unsigned int i = 0; i < cg.dinosaurs.getSize(); ++i)
	{
		out << "	" << i << ". " << cg.dinosaurs[i] << endl;
	}
	out << endl;

	out << "Meat Quantity: " << cg.foodStorage.getMeat() << "; Grass Quantity: " << cg.foodStorage.getGrass() << "; Fish Quantity: " << cg.foodStorage.getFish() << endl;
	out << endl;
	out << endl;
	return out;
}

std::istream& operator>>(std::istream& in, Cage& cg)
{
	int cageId;
	int size;
	int temp_climate;
	int temp_era;
	//Climate other_climate;
	//Era other_era;
	
	in >> cg.cageId >> cg.size; //>> other_climate >> other_era;
	//cg.setClimate(other_climate);
	//cg.setEra(other_era);
	
	in >> temp_climate;
	cg.climate = (Climate)temp_climate;
	
	in >> temp_era;
	cg.era = (Era)temp_era;

	return in;
}

#endif
