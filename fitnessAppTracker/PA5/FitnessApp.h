#pragma once
/*******************************************************************************************
* Programmer: Phong Nguyen                                                                       *
* Class: CptS 122, Spring 2017; Lab Section 2                                            *
* Programming Assignment: PA-5                                                  *
* Date: March 8, 2017                                                                         *
* Description: This program loads exercise and diet plans from files and does file operations in C++ *
*******************************************************************************************/


#include <iostream>
#include <fstream>
#include <string>
#include "DietPlan.h"
#include "ExercisePlan.h"

using std::cin;
using std::cout;
using std::endl;
using std::fstream;
using std::string;

class fitnessAppWrapper
{
public:
	fitnessAppWrapper(); //Default Constructor
	fitnessAppWrapper(const fitnessAppWrapper &copy); //Deep Copy
	~fitnessAppWrapper(); //Destructor

	fitnessAppWrapper & operator= (const fitnessAppWrapper &copy); //Deep Copy

	void runApp(void);
	void displayMenu() const;

	void editDailyDietPlan();
	void editDailyExercisePlan();

	DietPlan loadDailyDietPlan(fstream &fileStream, DietPlan &DailyPlan);
	exercisePlan loadDailyExercisePlan(fstream &fileStream, exercisePlan &DailyPlan);
	void loadWeeklyDietPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void loadWeeklyExercisePlan(fstream &fileStream, exercisePlan weeklyPlan[]);

	void displayDailyDietPlan(DietPlan &Plan) const;
	void displayDailyExercisePlan(exercisePlan &Plan) const;
	void displayWeeklyDietPlan() const;
	void displayWeeklyExercisePlan() const;

	void storeDailyDietPlan(fstream &fileStream, DietPlan Daily);
	void storeDailyExercisePlan(fstream &fileStream, exercisePlan Daily);
	void storeWeeklyDietPlan(fstream &fileStream, DietPlan Weekly[]);
	void storeWeeklyExercisePlan(fstream &fileStream, exercisePlan Weekly[]);
	
private:
	fstream fsDietPlan;
	fstream fsExercisePlan;

	DietPlan* dailyDietPlan_ptr;
	exercisePlan* dailyExercisePlan_ptr;

	DietPlan* dietWeeklyPlan;
	exercisePlan* exerciseWeeklyPlan;
};
