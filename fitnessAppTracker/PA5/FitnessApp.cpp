#include "FitnessApp.h"

fitnessAppWrapper::fitnessAppWrapper()
{
	fsDietPlan.open("DietPlans.txt");
	fsExercisePlan.open("ExercisePlans.txt");
	
	this->dietWeeklyPlan = new DietPlan[7];
	this->exerciseWeeklyPlan = new exercisePlan[7];
	
	this->dailyDietPlan_ptr = new DietPlan;
	this->dailyExercisePlan_ptr = new exercisePlan;

	//cout << "Inside FitnessAppWrapper constructor!" << endl;
}

fitnessAppWrapper::fitnessAppWrapper(const fitnessAppWrapper &copy) //Deep Copy
{
	dietWeeklyPlan = new DietPlan[7];
	exerciseWeeklyPlan = new exercisePlan[7];

	for (int i = 0; i < 7; i++)
	{
		dietWeeklyPlan[i].setName(copy.dietWeeklyPlan[i].getName());
		dietWeeklyPlan[i].setDate(copy.dietWeeklyPlan[i].getDate());
		dietWeeklyPlan[i].setGoalCalories(copy.dietWeeklyPlan[i].getGoalCalories());

		exerciseWeeklyPlan[i].setPlanName(copy.exerciseWeeklyPlan[i].getPlanName());
		exerciseWeeklyPlan[i].setDate(copy.exerciseWeeklyPlan[i].getDate());
		exerciseWeeklyPlan[i].setGoalSteps(copy.exerciseWeeklyPlan[i].getGoalSteps());
	}

	dailyDietPlan_ptr = new DietPlan;
	dailyExercisePlan_ptr = new exercisePlan;

	dailyDietPlan_ptr->setName(copy.dailyDietPlan_ptr->getName());
	dailyDietPlan_ptr->setDate(copy.dailyDietPlan_ptr->getDate());
	dailyDietPlan_ptr->setGoalCalories(copy.dailyDietPlan_ptr->getGoalCalories());

	dailyExercisePlan_ptr->setPlanName(copy.dailyExercisePlan_ptr->getPlanName());
	dailyExercisePlan_ptr->setDate(copy.dailyExercisePlan_ptr->getDate());
	dailyExercisePlan_ptr->setGoalSteps(copy.dailyExercisePlan_ptr->getGoalSteps());
}

fitnessAppWrapper & fitnessAppWrapper::operator= (const fitnessAppWrapper &copy) //Deep Copy
{
	dietWeeklyPlan = new DietPlan[7];
	exerciseWeeklyPlan = new exercisePlan[7];

	for (int i = 0; i < 7; i++)
	{
		dietWeeklyPlan[i].setName(copy.dietWeeklyPlan[i].getName());
		dietWeeklyPlan[i].setDate(copy.dietWeeklyPlan[i].getDate());
		dietWeeklyPlan[i].setGoalCalories(copy.dietWeeklyPlan[i].getGoalCalories());

		exerciseWeeklyPlan[i].setPlanName(copy.exerciseWeeklyPlan[i].getPlanName());
		exerciseWeeklyPlan[i].setDate(copy.exerciseWeeklyPlan[i].getDate());
		exerciseWeeklyPlan[i].setGoalSteps(copy.exerciseWeeklyPlan[i].getGoalSteps());
	}

	dailyDietPlan_ptr = new DietPlan;
	dailyExercisePlan_ptr = new exercisePlan;

	dailyDietPlan_ptr->setName(copy.dailyDietPlan_ptr->getName());
	dailyDietPlan_ptr->setDate(copy.dailyDietPlan_ptr->getDate());
	dailyDietPlan_ptr->setGoalCalories(copy.dailyDietPlan_ptr->getGoalCalories());

	dailyExercisePlan_ptr->setPlanName(copy.dailyExercisePlan_ptr->getPlanName());
	dailyExercisePlan_ptr->setDate(copy.dailyExercisePlan_ptr->getDate());
	dailyExercisePlan_ptr->setGoalSteps(copy.dailyExercisePlan_ptr->getGoalSteps());

	return(*this);
}

fitnessAppWrapper::~fitnessAppWrapper()
{
	delete[] dietWeeklyPlan;
	delete[] exerciseWeeklyPlan;
	delete(dailyDietPlan_ptr);
	delete(dailyExercisePlan_ptr);

	cout << "Inside FitnessAppWrapper destructor!" << endl;
}

void fitnessAppWrapper::runApp(void) 
{
	int userInput = 0;
	do
	{
		displayMenu();
		cout << "Choose a option (integer): " << endl;
		cin >> userInput;
		switch (userInput)
		{
		case(1):
			loadWeeklyDietPlan(this->fsDietPlan, this->dietWeeklyPlan);
			break;
		case(2):
			loadWeeklyExercisePlan(this->fsExercisePlan, this->exerciseWeeklyPlan);
			break;
		case(3):
			storeWeeklyDietPlan(this->fsDietPlan, this->dietWeeklyPlan);
			break;
		case(4):
			storeWeeklyExercisePlan(this->fsExercisePlan, this->exerciseWeeklyPlan);
			break;
		case(5):
			displayWeeklyDietPlan();
			break;
		case(6):
			displayWeeklyExercisePlan();
			break;
		case(7):
			editDailyDietPlan();
			break;
		case(8):
			editDailyExercisePlan();
			break;
		case(9):
			fsDietPlan.close();
			fsExercisePlan.close();
			break;
		default:
			cout << "INVALID CHOICE" << endl;
			break;
		}
	} while (userInput != 9);
}

void fitnessAppWrapper::displayMenu() const
{
	cout << "1.    Load weekly diet plan from file." << endl;
	cout << "2.    Load weekly exercise plan from file." << endl;
	cout << "3.    Store weekly diet plan to file." << endl;
	cout << "4.    Store weekly exercise plan to file." << endl;
	cout << "5.    Display weekly diet plan to screen." << endl;
	cout << "6.    Display weekly exercise plan to screen." << endl;
	cout << "7.    Edit daily diet plan." << endl;
	cout << "8.    Edit daily exercise plan." << endl;
	cout << "9.    Exit.   // Note: this must write the most recent weekly plans to the corresponding files." << endl;
}

void fitnessAppWrapper::editDailyDietPlan()
{
	this->dailyDietPlan_ptr->editName();
	this->dailyDietPlan_ptr->editGoal();
	this->dailyDietPlan_ptr->editDate();

	cout << dailyDietPlan_ptr << endl;
}

void fitnessAppWrapper::editDailyExercisePlan()
{
	this->dailyExercisePlan_ptr->editName();
	this->dailyExercisePlan_ptr->editGoal();
	this->dailyExercisePlan_ptr->editDate();

	cout << dailyExercisePlan_ptr << endl;
}

DietPlan fitnessAppWrapper::loadDailyDietPlan(fstream &fileStream, DietPlan &DailyPlan)
{
	fileStream >> DailyPlan;
	return DailyPlan;
}
exercisePlan fitnessAppWrapper::loadDailyExercisePlan(fstream &fileStream, exercisePlan &DailyPlan)
{
	fileStream >> DailyPlan;
	return DailyPlan;
}


void fitnessAppWrapper::loadWeeklyDietPlan(fstream &fileStream, DietPlan weeklyPlan[])
{
	for (int index = 0; index < 7; index++)
	{
		loadDailyDietPlan(fileStream, weeklyPlan[index]);
	}
}

void fitnessAppWrapper::loadWeeklyExercisePlan(fstream &fileStream, exercisePlan weeklyPlan[])
{
	for (int index = 0; index < 7; index++)
	{
		loadDailyExercisePlan(fileStream, weeklyPlan[index]);
	}
}

void fitnessAppWrapper::displayDailyDietPlan(DietPlan &Plan) const
{
	cout << Plan << endl;
}

void fitnessAppWrapper::displayDailyExercisePlan(exercisePlan &Plan) const
{
	cout << Plan << endl;
}

void fitnessAppWrapper::displayWeeklyDietPlan() const
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyDietPlan(dietWeeklyPlan[i]);
	}
}

void fitnessAppWrapper::displayWeeklyExercisePlan() const
{
	for (int i = 0; i < 7; i++)
	{
		displayDailyExercisePlan(exerciseWeeklyPlan[i]);
	}
}

void fitnessAppWrapper::storeDailyDietPlan(fstream &fileStream, DietPlan Daily)
{
	fileStream << Daily;
}

void fitnessAppWrapper::storeDailyExercisePlan(fstream &fileStream, exercisePlan Daily)
{
	fileStream << Daily;
}

void fitnessAppWrapper::storeWeeklyDietPlan(fstream &fileStream, DietPlan Weekly[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyDietPlan(fileStream, Weekly[i]);
	}
}

void fitnessAppWrapper::storeWeeklyExercisePlan(fstream &fileStream, exercisePlan Weekly[])
{
	for (int i = 0; i < 7; i++)
	{
		storeDailyExercisePlan(fileStream, Weekly[i]);
	}
}

