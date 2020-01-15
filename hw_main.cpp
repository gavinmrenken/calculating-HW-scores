//
// hw_main.cpp
// Project 4
// Created by Gavin Renken on 10/22/19. 
// Copyright @ 2019 Gavin Renken. All rights reserved. 
// 

#include "HomeworkList.h"
#include <iostream>
#include <string>
#include <iomanip>


int main() {

	// collecting information on the user's name via a string 
	std::string student_name;
	std::cout << "Enter student's name: ";
	std::getline(std::cin,student_name);

	// referencing the header file, creating two variables from main and inputting data from user back into referenced functions 
	HomeworkList list;
	int score;
	int maxPossible;  
	std::cout << "Enter score and max as two values: ";
	std::cin >> score >> maxPossible;
	list.addScore(score, maxPossible);

	// checking to see if the user has more information to input 
	std::string yes_no; 
	std::cout << "More scores? y/n: ";
	std::cin >> yes_no; 
	while (yes_no == "y") {
		std::cout << "Enter score and max as two values: ";
		std::cin >> score >> maxPossible;
		list.addScore(score, maxPossible);
		std::cout << "More scores? y/n: ";
		std::cin >> yes_no;
	}

	// asking user for the number of scores to be utilized and inputting it back into the function 
	int topNumber;
	std::cout << "How many scores should be used in computing the HW grade? ";
	std::cin >> topNumber;
	list.percentageFromBest(topNumber);
	std::cout << std::setprecision(4);  // setting precision value to include two decimal places 

	// reporting back results 
	std::cout << "The homework grade for " << student_name << " based on the best " << topNumber << " homework scores out of " << list.numberOfHWs() << " is " << list.percentageFromBest(topNumber) << "%." << '\n';

	// reporting back how well the user did based upon their score percentage 
	if (list.percentageFromBest(topNumber) >= 95) {
		std::cout << "This is excellent.";
	}
	else if (list.percentageFromBest(topNumber) >= 80 && score < 95) {
		std::cout << "This is good.";
	}
	else if (list.percentageFromBest(topNumber) >= 70 && score < 80) {
		std::cout << "This is decent.";
	}
	else if (list.percentageFromBest(topNumber) < 70) {
		std::cout << "This is poor.";
	}

	return 0; 
}
