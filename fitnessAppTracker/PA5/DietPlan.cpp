#include "DietPlan.h"

//Most Functions provided by Andy
DietPlan::DietPlan()
{
	this->mDate = "";
	this->mName = "";
	this->mGoalCalories = 0;
	//cout << "Inside of DietPlan constructor" << endl;
}

DietPlan::DietPlan(int newGoal, string newPlanName, string newDate)
{
	this->mDate = newDate;
	this->mName = newPlanName;
	this->mGoalCalories = newGoal;
	//cout << "Inside of DietPlan constructor" << endl;
}

DietPlan::DietPlan(const DietPlan &copy) //Shallow Copy
{
	this->mDate = copy.getDate();
	this->mName = copy.mName;
	this->mGoalCalories = copy.mGoalCalories;
	//cout << "Inside of ExercisePlan COPY constructor" << endl;
}

DietPlan::~DietPlan()
{
	//cout<<"inside DietPlan destructor!<<endl;
	//dietPlans does not create variables using dynamic memory
	//This method does nothing
}

DietPlan & DietPlan::operator=(const DietPlan &copy)
{
	this->mDate = copy.getDate();
	this->mName = copy.mName;
	this->mGoalCalories = copy.mGoalCalories;
	//cout << "Inside of ExercisePlan COPY Operator Function" << endl;

	return (*this);
}

string DietPlan::getDate() const
{
	return this->mDate;
}

string DietPlan::getName() const
{
	return this->mName;
}

int DietPlan::getGoalCalories() const
{
	return this->mGoalCalories;
}

void DietPlan::setName(const string &newName)
{
	cout << "New Plan Name: " << newName << endl;
	this->mName = newName;
}

void DietPlan::setDate(const string newDate)
{
	cout << "New Date: " << newDate << endl;
	this->mDate = newDate;
}

void DietPlan::setGoalCalories(const int &newCalories)
{
	cout << "New Goal Calories: " << newCalories << endl;
	this->mGoalCalories = newCalories;
}

void DietPlan::editName()
{
	string userInput = "";
	cout << "Enter a new Plan Name: " << endl;
	getline(cin, userInput);
	this->setName(userInput);
}

void DietPlan::editGoal()
{
	int newGoal = 0;
	cout << "Enter a new Goal Calories (Integer): " << endl;
	cin >> newGoal;
	this->setGoalCalories(newGoal);
}

void DietPlan::editDate()
{
	string userInput = "";
	cout << "Enter a new Date: " << endl;
	getline(cin, userInput);
	this->setDate(userInput);
}

fstream & operator >> (fstream &fileHandler, DietPlan &plan)
{
	if (!fileHandler.is_open())
	{
		return fileHandler;
	}
	char line[100] = "";

	fileHandler.getline(line, 100);
	plan.setName(line);
	fileHandler.getline(line, 100);
	plan.setDate(line);
	fileHandler.getline(line, 100);
	plan.setGoalCalories(atoi(line));
	fileHandler.getline(line, 100); //This will be the blank line

	return fileHandler;

}
fstream & operator<< (fstream &fileHandler, DietPlan &plan)
{
	if (!fileHandler.is_open())
	{
		return fileHandler;
	}

	fileHandler << plan.getName();
	fileHandler << plan.getDate();
	fileHandler << plan.getGoalCalories();

	return fileHandler;
}

ostream & operator<< (ostream &output, const DietPlan &plan)
{
	output << plan.getName() << endl;
	output << plan.getDate() << endl;
	output << plan.getGoalCalories() << endl;
	return output;
}