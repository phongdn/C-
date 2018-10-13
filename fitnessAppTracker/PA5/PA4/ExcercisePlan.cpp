#include "ExcercisePlan.h"

ExcercisePlan::ExcercisePlan(const string &newPlanName, const string &newDate, const int &newGoalSteps)
{
	this->mGoalSteps = newGoalSteps;
	this->mPlanName = newPlanName;
	this->mDate = newDate;
	cout << "Inside of ExercisePlan constructor" << endl;
}

ExcercisePlan::ExcercisePlan(const ExcercisePlan &copyObject) //Shallow Copy
{
	this->mGoalSteps = copyObject.mGoalSteps;
	this->mDate = copyObject.mDate;
	this->mPlanName = copyObject.mPlanName;
	cout << "Inside of ExercisePlan COPY constructor" << endl;
}

ExcercisePlan::~ExcercisePlan()
{
	cout << "inside of ExercisePlan destructor!" << endl;
	//ExercisePlan does not create variables using dynamic memory
	//This method does nothing
}

ExcercisePlan & ExcercisePlan::operator= (const ExcercisePlan &copyObject)
{
	this->mGoalSteps = copyObject.mGoalSteps;
	this->mDate = copyObject.mDate;
	this->mPlanName = copyObject.mPlanName;
	cout << "Inside of ExercisePlan COPY Overloaded Operator" << endl;

	return (*this);
}

int ExcercisePlan::getGoalSteps() const
{
	return this->mGoalSteps;
}

string ExcercisePlan::getPlanName() const
{
	return this->mPlanName;
}

string ExcercisePlan::getDate() const
{
	return this->mDate;
}

void ExcercisePlan::setGoalSteps(const int &newGoal)
{
	//cout << "New Goal Steps: " << newGoal << endl;
	this->mGoalSteps = newGoal;
}

void ExcercisePlan::setPlanName(const string &newPlanName)
{
	//cout << "New Plan Name: " << newPlanName << endl;
	this->mPlanName = newPlanName;
}

void ExcercisePlan::setDate(const string newDate)
{
	//cout << "New Date: " << newDate << endl;
	this->mDate = newDate;
}


void ExcercisePlan::editGoal() //Prompts the user for a new goal
{
	//cout << "Enter new Goal Steps (Integer): " << endl;
	cin >> this->mGoalSteps;
}


//NonMember Functions:

fstream & operator >> (fstream &fileHandler, ExcercisePlan &plan)
{
	if (!fileHandler.is_open())
	{
		return fileHandler;
	}
	char line[100] = "";

	fileHandler.getline(line, 100);
	plan.setPlanName(line);
	fileHandler.getline(line, 100);
	plan.setGoalSteps(atoi(line));
	fileHandler.getline(line, 100);
	plan.setDate(line);
	//fileHandler.getline(line, 100); //This will be the blank line

	return fileHandler;
}

fstream & operator<< (fstream &fileHandler, const ExcercisePlan &plan)
{
	if (!fileHandler.is_open())
	{
		return fileHandler;
	}

	((ofstream &)(fileHandler)) << plan.getPlanName() << endl << plan.getGoalSteps() << endl << plan.getDate();

	return fileHandler;
}

ostream & operator<< (ostream &output, const ExcercisePlan &plan)
{
	output << plan.getPlanName() << endl << plan.getGoalSteps() << endl << plan.getDate() << endl;
	return output;
}