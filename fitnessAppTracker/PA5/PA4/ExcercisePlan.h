#pragma once

#include <iostream>
#include <fstream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::fstream;
using std::ofstream;

class ExcercisePlan
{
public:
	ExcercisePlan(const string &newPlanName = "", const string &newDate = "", const int &newGoalSteps = 0); 
	ExcercisePlan(const ExcercisePlan &copyObject); //shallow copy
	~ExcercisePlan(); //Destructor

	ExcercisePlan & operator= (const ExcercisePlan &copyObject);

	int getGoalSteps() const;
	string getPlanName() const;
	string getDate() const;

	void setGoalSteps(const int &newGoal);
	void setPlanName(const string &newPlanName); // note: this function accepts a reference to a string - no copy constructor is used!
	void setDate(const string newDate); // note: this function requires a copy of the string - string copy constructor is used!

	void editGoal();

private:
	string mPlanName;
	string mDate;
	int mGoalSteps;
};

fstream & operator >> (fstream &fileHandler, ExcercisePlan &plan);
fstream & operator<< (fstream &fileHandler, const ExcercisePlan &plan);
ostream & operator<< (ostream &output, const ExcercisePlan &plan);