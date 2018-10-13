///////////////////////////////////////////////////////////////////////////////
/// \file         
/// \author       AO
/// \date         
/// \brief   You are to write a basic fitness application, in C++, 
///          that allows the user of the application to manually edit 
///          “diet” and “exercise” plans.For this application you will 
///          need to create three classes : DietPlan, ExercisePlan, and FitnessAppWrapper.     
///           
///       
/// REVISION HISTORY:
/// \Date: 4/7/17 
///            
///////////////////////////////////////////////////////////////////////////////
/*******************************************************************************************
* Programmer: Phong Nguyen                                                                       *
* Class: CptS 122, Spring 2017; Lab Section 2                                            *
* Programming Assignment: PA-5 Revision                                                  *
* Date: April 7, 2017                                                                         *
* Description: This program loads exercise and diet plans from files and applies user operations *
*******************************************************************************************/

#pragma once

#include <cstdlib> // to use system("cls");

#include "DietPlan.h"
#include "ExcercisePlan.h"

class FitnessAppWrapper
{
public:
	FitnessAppWrapper(); // default constructor
	~FitnessAppWrapper(); // destructor

	void runApp(); // will drive the application
	void perform_user_selection(const int &option);

	void loadWeeklyDietPlan(); // this will call the private loadWeeklyPlan() function
	void displayWeeklyDietPlan(); // this will call the private displayWeeklyPlan() function
	void storeWeeklyDietPlan(); // this will call the private storeWeeklyPlan() function
	bool editDietPlan(); // will prompt the user for the name of the plan to edit

	void loadWeeklyExcercisePlan(); // this will call the private loadWeeklyExcercisePlan()Plan() function
	void displayWeeklyExcercisePlan(); // this will call the private displayWeeklyExcercisePlan()Plan() function
	void storeWeeklyExcercisePlan(); // this will call the private storeWeeklyExcercisePlan()Plan() function
	bool editExcercisePlan(); // will prompt the user for the name of the plan to edit
private:
	DietPlan mDPList[7]; // will store the weekly list of DietPlan objects - 1 week = 7 days
	ExcercisePlan mEPList[7]; //will store the weekly list of the Excercise plane - 1 week = 7 days

	fstream mFstrDP;    // stream object for input/output to dietPlans.txt
	fstream mFstrEP;	// stream object for excercisePlan.txt
	// private helper/utility functions
	void loadDailyPlan(fstream &fileStream, DietPlan &plan);
	void loadWeeklyPlan(fstream &fileStream, DietPlan weeklyPlan[]);
	void displayDailyPlan(const DietPlan &plan);
	void displayWeeklyPlan(const DietPlan weeklyPlan[]);
	void storeDailyPlan(fstream &fileStream, const DietPlan &plan);
	void storeWeeklyPlan(fstream &fileStream, const DietPlan weeklyPlan[]);

	void loadDailyExcercisePlan(fstream &fileStream, ExcercisePlan &plan);
	void loadWeeklyExcercisePlan(fstream &fileStream, ExcercisePlan weeklyPlan[]);
	void displayDailyExcercisePlan(const ExcercisePlan &plan);
	void displayWeeklyExcercisePlan(const ExcercisePlan weeklyPlan[]);
	void storeDailyExcercisePlan(fstream &fileStream, const ExcercisePlan &plan);
	void storeWeeklyExcercisePlan(fstream &fileStream, const ExcercisePlan weeklyPlan[]);

	void displayMenu();
};