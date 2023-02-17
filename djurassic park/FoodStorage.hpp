#ifndef __FOODSTORAGE_HPP
#define __FOODSTORAGE_HPP

#include <iostream>
#include <fstream>

using namespace std;

class FoodStorage 
{
	private:
		unsigned int grassQuantity;
		unsigned int meatQuantity;
		unsigned int fishQuantity;
		
	public:
		FoodStorage();
		
		unsigned int getGrass() const;
		unsigned int getMeat() const;
		unsigned int getFish() const;

		void addGrass(unsigned int& quantity);
		void addMeat(unsigned int& quantity);
		void addFish(unsigned int& quantity);
		
		void removeGrass(unsigned int& quantity);
		void removeMeat(unsigned int& quantity);
		void removeFish(unsigned int& quantity);
		
		//friend istream& operator>>(istream& in, FoodStorage& fst); 

		void serialize(std::ofstream& out) const;
		void deserialize(std::ifstream& in);
};

//FoodStorage::FoodStorage()
//{
//	grassQuantity = 0;
//	meatQuantity = 0;
//	fishQuantity = 0;
//}
//
//unsigned int FoodStorage::getGrass() const
//{
//	return this->grassQuantity;
//}
//
//unsigned int FoodStorage::getMeat() const
//{
//	return this->meatQuantity;
//}
//
//unsigned int FoodStorage::getFish() const
//{
//	return this->fishQuantity;
//}
//
//void FoodStorage::addGrass(unsigned int& quantity)
//{
//	grassQuantity += quantity;
//}
//
//void FoodStorage::addMeat(unsigned int& quantity)
//{
//	meatQuantity += quantity;
//}
//
//void FoodStorage::addFish(unsigned int& quantity)
//{
//	fishQuantity += quantity;
//}
//
//void FoodStorage::removeGrass(unsigned int& quantity)
//{
//	if (grassQuantity - quantity < 0)
//	{
//		cout << "Cannot remove grass."; //(throw exception)
//	}
//	
//	grassQuantity -= quantity;
//}
//
//void FoodStorage::removeMeat(unsigned int& quantity)
//{
//	if (meatQuantity - quantity < 0)
//	{
//		cout << "Cannot remove meat."; //(throw exception)
//	}
//	meatQuantity -= quantity;
//}
//
//void FoodStorage::removeFish(unsigned int& quantity)
//{
//	if (fishQuantity - quantity < 0)
//	{
//		cout << "Cannot remove fish."; //(throw exception)
//	}
//	fishQuantity -= quantity;
//}
//
///*
//std::istream& operator>>(std::istream& in, FoodStorage& fst)
//{
//	unsigned int grassQuantity;
//	unsigned int meatQuantity;
//	unsigned int fishQuantity;
//	
//	in >> fst.grassQuantity >> fst.meatQuantity >> fst.fishQuantity;
//	
//	return in;
//}*/
//
//void FoodStorage::serialize(std::ofstream& out) const
//{
//	if(out.is_open())
//	{
//		out << grassQuantity << " ";
//		out << meatQuantity << " ";
//		out << fishQuantity << " ";
//	}
//	
//	else
//	{
//		cout << "Can't open the file" << endl;
//	}
//	//out.write((const char*)&grassQuantity, sizeof(grassQuantity));
//	//out.write((const char*)&meatQuantity, sizeof(meatQuantity));
//	//out.write((const char*)&fishQuantity, sizeof(fishQuantity));
//}
//
//void FoodStorage::deserialize(std::ifstream& in)
//{
//	if(in.is_open())
//	{
//		in >> grassQuantity;
//		in >> meatQuantity;
//		in >> fishQuantity;
//	}
//	else
//	{
//		cout << "Can't open the file" << endl;
//	}
//	//in.read((char*)&grassQuantity, sizeof(grassQuantity));
//	//in.read((char*)&meatQuantity, sizeof(meatQuantity));
//	//in.read((char*)&fishQuantity, sizeof(fishQuantity));
//}

#endif
