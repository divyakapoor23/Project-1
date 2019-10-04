//Menaka Abraham
//  main.cpp
//TCES 203
//  Project 1

//This Program will computes an overall score for each applicant.

//  Created by Divya Kapoor on 9/27/19.
//  Copyright © 2019 Divya Kapoor. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

//Functions Used in the code
void admitMessage();
float getoverall_scores();
int getExamType();
float getsat_scores();
float calcsat_scores(int, int);
float getgpa_scores();
float calcgpa_scores(float, float);
float getact_scores();
float calcact_scores(int, int, int, int);
void display_scores(float, float);


int main() {
    int applicant1_scores = 0, applicant2_scores = 0;
    admitMessage();
    admitMessage();
    display_scores(applicant1_scores, applicant2_scores);
    
    return 0;
}
//Asking about the exam taken by the user
void admitMessage(){
    int sat_act = 0, second = 0;
    if (second == 2){
        cout << "Information of the applicant 2: ";
    }
    else{
        cout << "Information of the appllicant 1: ";
    }
    cout << "Do you have 1) SAT Scores or 2) ACT Scores?";
    getExamType();
    if (sat_act == 1){
        getsat_scores();
        getgpa_scores();
        getoverall_scores();
    }
    else{
        getact_scores();
        getgpa_scores();
        getoverall_scores();
    }
    second = 2;
}
//Getting the exam type 1 or 2
int getExamType(){
    int sat_act;
    cin >> sat_act;
    return sat_act;
}
// getting the overall score of the applicant
float getoverall_scores(){
    float applicant1_scores, applicant2_scores;
    int second = 0, sat_act = 0;
    float sat_applicant = 0.0, act_applicant = 0.0, gpa_scores = 0.0;
    if (second == 2){
        if (sat_act == 1){
            applicant2_scores = (sat_applicant + gpa_scores);
            return applicant2_scores;
        }
        applicant2_scores = (act_applicant + gpa_scores);
        return applicant2_scores;
    }
    else{
        if (sat_act == 1){
            applicant1_scores = (sat_applicant + gpa_scores);
            return applicant1_scores;
        }
        applicant1_scores = (act_applicant + gpa_scores);
        return applicant1_scores;
    }
}
//Asking the user for the input for sat scores and calculate the sat scores.
float getsat_scores(){
    int m_scores, v_scores, sat_applicant;
    cout << "Enter the SAT Math scores: ";
    cin >> m_scores;
    cout << "Enter the SAT Verbal scores: ";
    cin >> v_scores;
    sat_applicant = calcsat_scores(m_scores, v_scores);
    return sat_applicant;
}
//Calculating the SAT Scores for the user
float calcsat_scores(){
    int m_scores = 0, v_scores = 0;
    float sat_scores = ((2.0 * v_scores) + m_scores) / 24.0;
    return sat_scores;
}
//Getting the User input for GPA
float getgpa_scores(){
    float actual_gpa, maximum_gpa, gpa_scores;
    cout << "Enter your Actual GPA: ";
    cin >> actual_gpa;
    cout << "Enter the Maximum GPA: ";
    cin >> maximum_gpa;
    gpa_scores = calcgpa_scores(actual_gpa, maximum_gpa);
    return gpa_scores;
}

float calcgpa_scores(float gpa, float maximum_gpa){
    return (gpa / maximum_gpa)  * 100.0;
}
// Getting the user input for ACT scores
float getact_score(){
    float act_applicant;
    int e_scores, math_scores, r_scores, s_scores;
    cout << "Enter the ACT English Scores: ";
    cin >> e_scores;
    cout << "Enter the ACT Math Scores: ";
    cin >> math_scores;
    cout << "Enter the ACT Reading Scores: ";
    cin >> r_scores;
    cout << "Enter the ACT Science Scores: ";
    cin >> s_scores;
    act_applicant = calcact_scores(e_scores, math_scores, r_scores, s_scores);
    return act_applicant;
}

// Calculates the ACT Scores
float calcact_scores(int e_scores, int math_scores, int r_scores, int s_scores ){
    return (2.0 * r_scores + (e_scores + math_scores + s_scores)) / 1.8;
    
}
// Displays the scores and compare the two applicants
void display_scores(){
    float applicant1_scores = 0.0, applicant2_scores = 0.0;
    cout << "The overall score of first applicant = %0.3f \n";
    cout << "The overall score of second applicant = %0.3f \n";
    if (applicant1_scores > applicant2_scores){
        cout << "The first is better \n";
    }
    else if (applicant1_scores < applicant2_scores){
        cout << "The second applicant is better. \n";
    }
    else{
        cout << "Both applicants are better. \n";
    }
}
