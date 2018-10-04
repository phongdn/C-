#include "ExercisePlan.h"

exercisePlan::exercisePlan()
{
	this->mGoalSteps = 0;
	this->mPlanName = "";
	this->mDate = "";
	//cout << "Inside of ExercisePlan constructor" << endl;
}
exercisePlan::exercisePlan(int newGoal, string newPlanName, string newDate)
{
	this->mGoalSteps = newGoal;
	this->mPlanName = newPlanName;
	this->mDate = newDate;
	//cout << "Inside of ExercisePlan constructor" << endl;
}

exercisePlan::exercisePlan(const exercisePlan &copyObject) //Shallow Copy
{
	this->mGoalSteps = copyObject.getGoalSteps();
	this->mDate = copyObject.getDate();
	this->mPlanName = copyObject.getPlanName();
	//cout << "Inside of ExercisePlan COPY constructor" << endl;
}

exercisePlan::~exercisePlan()
{
	//cout << "inside of ExercisePlan destructor!" << endl;
	//ExercisePlan does not create variables using dynamic memory
	//This method does nothing
}

exercisePlan & exercisePlan::operator= (const exercisePlan &copyObject)
{
	this->mGoalSteps = copyObject.getGoalSteps();
	this->mDate = copyObject.getDate();
	this->mPlanName = copyObject.getPlanName();
	//cout << "Inside of ExercisePlan COPY Operator" << endl;

	return (*this);
}

int exercisePlan::getGoalSteps() const
{
	return this->mGoalSteps;
}

string exercisePlan::getPlanName() const
{
	return this->mPlanName;
}

string exercisePlan::getDate() const
{
	return this->mDate;
}

void exercisePlan::setGoalSteps(const int &newGoal)
{
	cout << "New Goal Steps: " << newGoal << endl;
	this->mGoalSteps = newGoal;
}

void exercisePlan::setPlanName(const string &newPlanName)
{
	cout << "New Plan Name: " << newPlanName << endl;
	this->mPlanName = newPlanName;
}

void exercisePlan::setDate(const string newDate)
{
	cout << "New Date: " << newDate << endl;
	this->mDate = newDate;
}

void exercisePlan::editName()
{
	string userInput = "";
	cout << "Enter a new Plan Name: " << endl;
	getline(cin, userInput);
	this->setPlanName(userInput);
}

void exercisePlan::editGoal()
{
	int newGoal = 0;
	cout << "Enter new Goal Steps (Integer): " << endl;
	cin >> newGoal;
	setGoalSteps(newGoal);
}

void exercisePlan::editDate()
{
	string userInput = "";
	cout << "Enter a new Date: " << endl;
	getline(cin, userInput);
	this->setDate(userInput);
}

//NonMember Functions:

fstream & operator>> (fstream &fileHandler, exercisePlan &plan)
{
	if (!fileHandler.is_open())
	{
		return fileHandler;
	}
	char line[100] = "";
	
	fileHandler.getline(line, 100);
	plan.setPlanName(line);
	fileHandler.getline(line, 100);
	plan.setDate(line);
	fileHandler.getline(line, 100);
	plan.setGoalSteps(atoi(line));
	fileHandler.getline(line, 100); //This will be the blank line
	
	return fileHandler;
}

fstream & operator<< (fstream &fileHandler, exercisePlan &plan)
{
	if (!fileHandler.is_open())
	{
		return fileHandler;
	}
	
	fileHandler << plan.getPlanName();
	fileHandler << plan.getDate();
	fileHandler << plan.getGoalSteps();

	return fileHandler;
}

ostream & operator<< (ostream &output, const exercisePlan &plan)
{
	output << plan.getPlanName() << endl;
	output << plan.getDate() << endl;
	output << plan.getGoalSteps() << endl;
	return output;
}