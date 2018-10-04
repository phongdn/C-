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

class exercisePlan
{
public:
	exercisePlan(); //Default Constructor
	exercisePlan(int newGoal, string newPlanName, string newDate); //Another Option: exercisePlan(int newGoal = 0, string newPlanName = "", string newDate = "") - No Default Constructor Needed
	exercisePlan(const exercisePlan &copyObject); //shallow copy
	~exercisePlan(); //Destructor

	exercisePlan & operator= (const exercisePlan &copyObject);

	int getGoalSteps() const;
	string getPlanName() const;
	string getDate() const;
	//Setters Display What was Changed
	void setGoalSteps(const int &newGoal);
	void setPlanName(const string &newPlanName); // note: this function accepts a reference to a string - no copy constructor is used!
	void setDate(const string newDate); // note: this function requires a copy of the string - string copy constructor is used!

	void editName();
	void editGoal();
	void editDate();

private:
	int mGoalSteps;
	string mPlanName;
	string mDate;
};
//Non Member Functions
fstream & operator>> (fstream &fileHandler, exercisePlan &plan);
fstream & operator<< (fstream &fileHandler, exercisePlan &plan);
ostream & operator<< (ostream &output, const exercisePlan &plan);
