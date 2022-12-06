/**
 * CS-102 Project 08
 * @file gpa.cpp
 * @John Donohue
 * @collaborators
 * @December 4, 2022
 */

 #include <iostream>
 #include <vector>


 using namespace std;

//Midterm Structure of two vectors to account for multiple midterm scores and weights
struct midterm{
  vector<float> _midterms;
  vector<float> _midterm_weights;
};


class Course{

private:

   midterm user_midterm;
   vector<float> _assignments;
   int _assignment_weight;
   float _participation;
   int _participation_weight;
   float _other;
   int _other_weight;

public:

   Course(){
     input();


   }
//Input method for midterms
   void get_midterms(){
     int midterm_count = 0;
     cout << "How many midterms did you have?" << endl;
     cin >> midterm_count;
     cout << "How much are you midterms weighted?" << endl;
     vector<float> mid_weights;
     for (int i = 0; i < midterm_count; i++){
       float mid_weight = 0;
       cin >> mid_weight;
       mid_weights.push_back(mid_weight);
     }
     user_midterm._midterm_weights = mid_weights;
     cout << "What grades did you get?" << endl;
     vector<float> mid_scores;
     for (int i = 0; i < midterm_count; i++){
       float midterm_score = 0;
       cin >> midterm_score;
       mid_scores.push_back(midterm_score);
     }
     user_midterm._midterms = mid_scores;
   }

//Input method for assignments
   void get_assignments(){
     int assignment_count = 0;
     cout << "How many assignments did you have?" << endl;
     cin >> assignment_count;
     cout << "How much are your assignments weighted?" << endl;
     int assignment_weight = 0;
     cin >> assignment_weight;
     _assignment_weight = assignment_weight;
     cout << "What grades did you get?" << endl;
     for (int i = 0; i < assignment_count; i++){
       int assignment_score = 0;
       cin >> assignment_score;
       _assignments.push_back(assignment_score);
     }
   }

//Input method for participation
   void get_participation(){
     cout << "How much is participation weighted?" << endl;
     int participation_weight = 0;
     cin >> participation_weight;
     _participation_weight = participation_weight;
     cout << "What grade did you get?" << endl;
     float participation_score = 0;
     cin >> participation_score;
     _participation = participation_score;
   }

//Input method for other grades
   void get_other(){
     cout << "How much is everything else weighted?" << endl;
     int other_weight = 0;
     cin >> other_weight;
     _other_weight = other_weight;
     cout << "What grade did you get?" << endl;
     float other_score = 0;
     cin >> other_score;
     _other = other_score;
   }

//Finds how much the midterms contribute to the actual grade
   float midterms_as_percentage_of_grade(){
     float total = 0;
     vector<float> percentage_scores;
     vector<float> transfer;
     transfer = user_midterm._midterms;
     for(int i = 0; i < transfer.size(); i++){
       float percentage = user_midterm._midterms[i] * .01;
       float individual_weight= percentage * user_midterm._midterm_weights[i];
       percentage_scores.push_back(individual_weight);
       total += percentage_scores[i];
     }
     return total;
   }

//Finds how much the assignments contribute to the actual grade
   float assignments_as_percentage_of_grade(){
     float total = 0;
     for (int i = 0; i < _assignments.size(); i++){
       total += _assignments[i];
     }
     total = total / _assignments.size();
     total = total * .01;
     total = total * _assignment_weight;
     return total;
   }

//Finds how much every else contributes to the actual grade
   float other_as_percentage_of_grade(){
     float total = 0;
     total = _other * .01;
     total = total * _other_weight;
     return total;
   }
//Finds how much participation contributes to the actual grade
   float participation_as_percentage_of_grade(){
     float total = 0;
     total = _participation * .01;
     total = total * _participation_weight;
     return total;
   }

//Consolidates the input functions
   void input(){
     get_midterms();
     get_assignments();
     get_participation();
     get_other();
   }

//Finds cumululative grade prior to the final
   float cumulative_grade_before_final(){
     float mids = midterms_as_percentage_of_grade();
     float assigns = assignments_as_percentage_of_grade();
     float part = participation_as_percentage_of_grade();
     float oth = other_as_percentage_of_grade();

     float cumulative = mids + assigns + part + oth;
     return cumulative;
   }
 };

 class Gradetable{

 private:
   float _final_weight;
   float _a_plus_grade;
   float _a_grade;
   float _a_minus_grade;
   float _b_plus_grade;
   float _b_grade;
   float _b_minus_grade;
   float _pass_grade;
   float _fail_grade;

 public:
   Gradetable(){
   }

//Gets the final weight
   void get_final_weight(){
     cout << "How much is your final weighted?" << endl;
     int final_weight = 0;
     cin >> final_weight;
     _final_weight = final_weight;
   }

//Determines all final grade requirements to get desired final grades in course
   void find_grade_requirement(float current__cumulative_grade){
     float difference = 97 - current__cumulative_grade;
     float required_percentage = difference / _final_weight;
     _a_plus_grade = required_percentage;

     difference = 93 - current__cumulative_grade;
     required_percentage = difference / _final_weight;
     _a_grade = required_percentage;

     difference = 90 - current__cumulative_grade;
     required_percentage = difference / _final_weight;
     _a_minus_grade = required_percentage;

     difference = 87 - current__cumulative_grade;
     required_percentage = difference / _final_weight;
     _b_plus_grade = required_percentage;

     difference = 83 - current__cumulative_grade;
     required_percentage = difference / _final_weight;
     _b_grade = required_percentage;

     difference = 80 - current__cumulative_grade;
     required_percentage = difference / _final_weight;
     _b_minus_grade = required_percentage;

     difference = 70 - current__cumulative_grade;
     required_percentage = difference / _final_weight;
     _pass_grade = required_percentage;

     difference = 60 - current__cumulative_grade;
     required_percentage = difference / _final_weight;
     _fail_grade = required_percentage;
   }

//Prints the table of required grades
   void print_grade_table(){
     cout << "YOUR REQUIRED FINAL EXAM SCORE FOR DESIRED GRADES" << endl;
     cout << "||A+: " << _a_plus_grade*100 << "%"<< endl;
     cout << "||A: " << _a_grade*100 << "%"<< endl;
     cout << "||A-: " << _a_minus_grade*100 << "%"<< endl;
     cout << "||B+: " << _b_plus_grade*100 << "%"<< endl;
     cout << "||B: " << _b_grade*100 << "%"<< endl;
     cout << "||B-: " << _b_minus_grade*100 << "%"<< endl;
     cout << "IN ORDER TO PASS THIS CLASS YOU MUST GET AT LEAST " << _pass_grade*100 << "% ON YOUR FINAL EXAM!!!" << endl;
     cout << "IN ORDER TO NOT FAIL THIS CLASS YOU MUST GET AT LEAST " << _fail_grade*100 << "% ON YOUR FINAL EXAM!!!" << endl;
   }
 };



int main(){
  Course A;
  float cumulative = A.cumulative_grade_before_final();
  Gradetable B;
  B.get_final_weight();
  B.find_grade_requirement(cumulative);
  B.print_grade_table();
}
