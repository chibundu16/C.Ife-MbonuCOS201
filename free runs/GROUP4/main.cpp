/*
GROUP 4 MEMBERS
Tracy Owezie James 23120111029,
Chukwunonye Michael Ejekam 2312011016,
Olakisan Aisha Adeyinka  24120111080,
Catherine Okoede 23120111042,
NWOYE KAMSIYOCHUKWU 21120612477,
Olabalade Chukwudi Emmanuel 23120111046
IFE-MBONU BILL ODINAKA 23120111023
IFE-MBONU LEO CHIBUNDU 23120111024
*/

#include <algorithm>
#include <cctype>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#define to_lowercase(input)                                                    \
  transform(input.begin(), input.end(), input.begin(),                         \
            ::tolower) // Converting to lowercase

// Store grade points
map<string, int> grades = {pair("A", 5), pair("B", 4), pair("C", 3),
                           pair("D", 2), pair("F", 0)};
struct Student {
  string name;
  string matric_number;
  float gpa;
  vector<pair<string, int>> scores;

  void calculate_gpa() {
    int cal = 0;
    for (auto score : scores) {
      if (score.second >= 70) {
        cal += 3 * grades["A"];
      } else if (score.second <= 69 && score.second >= 60) {
        cal += 3 * grades["B"];
      } else if (score.second <= 59 && score.second >= 50) {
        cal += 3 * grades["C"];
      } else if (score.second <= 49 && score.second >= 40) {
        cal += 3 * grades["D"];
      } else {
        cal += 3 * grades["F"];
      }
    }

    gpa = (float)cal / (float)75;
  }
};

// Handles file checking
bool health_check(string filename) {
  fstream file(filename);
  if (!file.is_open()) {
    file.open(filename, ios::out);
    file << "";
    cout << "Error: " << filename << " is Empty" << endl;
    file.close();
    return false;
  }
  file.close();
  return true;
}

// Authenticate the user
string authenticate_user() {
  fstream user_file("users.txt");
  regex pattern("(\\w+)\\s+(\\w+)");

  if (!health_check("users.txt")) {
    exit(0);
  }

  while (true) {
    string line, username, password;
    cout << "Enter username :";
    cin >> username;
    cout << "Enter password :";
    cin >> password;
    while (getline(user_file, line)) {
      smatch match;
      if (regex_search(line, match, pattern) && match[1] == username &&
          match[2] == password) {
        cout << "Valid user! You may proceed." << endl;
        return match[1];
      }
    }
    cout << "Invalid user. Try again.\n" << endl;
  }
}

// Searches for a student in the student.txt file
Student get_student_record() {
  if (!health_check("students.txt"))
    return {};

  cout << "Enter Student's Matric Number: ";
  string mat_no;
  cin >> mat_no;

  fstream students_file("students.txt");
  string record;
  while (getline(students_file, record)) {
    regex pattern("([A-Za-z]+ "
                  "[A-Za-z]+)\\s+([A-Z]{3}/\\d{4}/"
                  "\\d{4})\\s+(\\d{2})\\s+(\\d{2})\\s+(\\d{2})\\s+(\\d{2})\\s+("
                  "\\d{2})\\s+(\\d\\.\\d+)");

    smatch match;
    vector<string> student_record;
    if (regex_search(record, match, pattern) && match[2] == mat_no) {
      Student student;
      student.name = match[1];
      student.matric_number = match[2];
      student.gpa = stof(match[8]);
      string courses[5] = {"CSC201", "CSC203", "SEN201", "IFT211", "MTH201"};
      for (int i = 3; i < 8; ++i)
        student.scores.push_back(pair(courses[i - 3], stoi(match[i])));
      students_file.close();
      return student;
    }
  }
  students_file.close();
  return {};
}

// Edit a student Record
void update_record() {
  Student student = get_student_record();
  if (sizeof(student) == 1) {
    cout << "Error: Student Record not found" << endl;
    return;
  }

  cout << "Record of " << student.name << endl;
  vector<string> records;
  string r;
  fstream student_file("students.txt");
  while (getline(student_file, r))
    records.push_back(r);

  for (size_t i = 0; i < records.size(); ++i) {
    r = records[i];
    stringstream s(r);
    string w;

    while (s >> w) {
      if (w == student.matric_number) {
        string new_record = student.name + " " + student.matric_number + " ";
        for (size_t j = 0; j < student.scores.size(); ++j) {
          auto score = student.scores[j];
          while (true) {
            try {
              cout << "Enter " << score.first << " Score:\n";
              string input;
              cin >> input;
              int new_score = stoi(input);
              student.scores[j].second = new_score;
              new_record += to_string(new_score) + " ";
              break;
            } catch (std::invalid_argument const &) {
              cout << "Error: Input is not a number!." << endl;
            }
          }
        }

        student.calculate_gpa();
        stringstream f;
        f << student.gpa;
        new_record += f.str();

        records[i] = new_record;

        ofstream student_file("students.txt");
        for (auto record : records) {
          student_file << record << "\n";
        }

        student_file.close();
        cout << "Record have been successfully updated";
        return;
      }
    }
  }
}

// Show all results
void view_results() {
  if (!health_check("students.txt"))
    return;

  fstream students_file("students.txt");
  string record;
  cout << "\nAll Student Results:\n";
  cout << "----------------------------------------------\n";

  printf("%20s %15s %6s %6s %6s %6s %6s %4s\n", "Name", "Matric No.", "CSC201",
         "CSC203", "SEN201", "IFT211", "MTH201", "GPA");

  while (getline(students_file, record)) {
    regex pattern("([A-Za-z]+ "
                  "[A-Za-z]+)\\s+([A-Z]{3}/\\d{4}/"
                  "\\d{4})\\s+(\\d{2})\\s+(\\d{2})\\s+(\\d{2})\\s+(\\d{2})\\s+("
                  "\\d{2})\\s+(\\d\\.\\d+)");
    smatch match;
    if (regex_search(record, match, pattern)) {
      cout << setw(20) << match[1] << " " << setw(15) << match[2] << " ";
      for (size_t i = 3; i < 8; ++i) {
        cout << setw(6) << match[i] << " ";
      }
      cout << setw(6) << match[8] << "\n";
    }
  }

  students_file.close();
}

// Shows a student Record
void view_student_record() {
  Student student = get_student_record();
  if (sizeof(student) == 1) {
    cout << "Error: Student Record not found" << endl;
    return;
  }
  cout << "\nStudent Name: " << student.name << endl;
  cout << "Matric Number: " << student.matric_number << endl;
  cout << "GPA: " << student.gpa << endl;

  cout << "Course Scores:" << endl;
  for (size_t i = 0; i < student.scores.size(); ++i) {
    cout << student.scores[i].first << " : " << student.scores[i].second
         << endl;
  }
}

// Saves a Student Record to file
void save_record_to_file() {
  Student student = get_student_record();
  if (student.matric_number.empty()) {
    cout << "Error: Student record not found" << endl;
    return;
  }

  string student_file = student.name + ".txt";
  ofstream output_file(student_file);

  if (!output_file.is_open()) {
    cout << "Error: " << student_file << " could not be opened" << endl;
    return;
  }

  output_file << "Name: " << student.name << "\n";
  output_file << "Matric No: " << student.matric_number << "\n";

  for (size_t i = 0; i < student.scores.size(); ++i) {
    output_file << student.scores[i].first << ": " << student.scores[i].second
                << "\n";
  }

  output_file << "GPA   : " << student.gpa << endl;
  output_file.close();

  cout << "Student record successfully saved to " << student_file << endl;
}

int main() {

  cout << "\t\tWelcome to the PAU Result Management System." << endl;
  string user;

  while (true) {
    cout << "Enter L to Login or Q to exit the application." << endl;
    cout << "Enter an option: ";
    string choice;
    cin >> choice;
    to_lowercase(choice);

    if (choice == "l") {
      user = authenticate_user();
      break;
    } else if (choice == "q") {
      return 0;
    } else {
      cout << "Invalid Input" << endl;
    }
  }

  cout << "\n\nWelcome, " << user << "!" << endl;
  cout << "What would you like to do today? There are multiple options to "
          "proceed from."
       << endl;

  while (true) {
    cout << "\n\tMAIN MENU" << endl;
    cout << "If you'd like to view all results, Enter V." << endl;
    cout << "If you'd like to search for an individual record, Enter S."
         << endl;
    cout << "If you'd like to update student's scores, Enter U." << endl;
    cout << "If you'd like to a save student record to a file, Enter P" << endl;
    cout << "If you'd like to exit the program, Enter E" << endl;

    string option;
    cin >> option;
    to_lowercase(option);

    try {
      if (option == "v") {
        view_results();

      } else if (option == "s") {
        view_student_record();

      } else if (option == "u") {
        update_record();

      } else if (option == "e") {
        cout << "Do you want to exit.Enter yes or no" << endl;
        string Enter;
        cin >> Enter;

        if (Enter == "yes") {
          return 0;
        } else if (Enter == "no") {
          continue;
        } else {
          throw Enter;
        }

      } else if (option == "p") {
        save_record_to_file();
      }

    } catch (string n) {
      cout << "Invalid Enter \"" << n << "\"" << endl;
    }
  }
}
