#pragma once
#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;
using std::ostream;

class DietPlan //Majority of this class is similar to Andy's (Starter Example Provided By Andy)
{
public:
	DietPlan(); //Default Constructor
	DietPlan(int newGoal, string newPlanName, string newDate); //Another Option: DietPlan(int newGoal = 0, string newPlanName = "", string newDate = "") - No Default Constructor Needed
	DietPlan(const DietPlan &copy); // shallow copy
	~DietPlan(); //Destructor

	DietPlan & operator=(const DietPlan &copy);

	string getDate() const;
	string getName() const;
	int getGoalCalories() const;
	//Setters displays what was changed
	void setDate(const string newDate);  // note: this function requires a copy of the string - string copy constructor is used!
	void setName(const string &newName); // note: this function accepts a reference to a string - no copy constructor is used!
	void setGoalCalories(const int &newCalories);

	void editName();
	void editGoal();
	void editDate();
private:
	int mGoalCalories;
	string mDate;
	string mName;
};
//NonMember Functions
fstream & operator>> (fstream &fileHandler, DietPlan &plan);
fstream & operator<< (fstream &fileHandler, DietPlan &plan);
ostream & operator<< (ostream &output, const DietPlan &plan);