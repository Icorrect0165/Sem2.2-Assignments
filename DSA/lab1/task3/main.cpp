#include <iostream>
#include <string>

// Define the Course structure
struct Course {
    std::string course_code;
    std::string course_name;
};

// Define the Grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the Student structure
struct Student {
    std::string registration_number;
    std::string name;
    int age;
    Course course;
    Grade grades;
};

int main() {
    const int max_students = 40;
    Student students[max_students];

    int num_students;

    // Input the number of students
    std::cout << "Enter the number of students (max " << max_students << "): ";
    std::cin >> num_students;

    // Input data for each student
    for (int i = 0; i < num_students; ++i) {
        std::cout << "\nEnter details for Student " << i + 1 << ":\n";

        // Input registration number
        std::cout << "Enter registration number: ";
        std::cin >> students[i].registration_number;

        // Input name
        std::cout << "Enter name: ";
        std::cin >> students[i].name;

        // Input age
        std::cout << "Enter age: ";
        std::cin >> students[i].age;

        // Input course details
        std::cout << "Enter course code: ";
        std::cin >> students[i].course.course_code;

        std::cout << "Enter course name: ";
        std::cin >> students[i].course.course_name;

        // Input grade details
        std::cout << "Enter mark: ";
        std::cin >> students[i].grades.mark;

        // Calculate grade based on mark
        if (students[i].grades.mark > 69)
            students[i].grades.the_grade = 'A';
        else if (students[i].grades.mark > 59)
            students[i].grades.the_grade = 'B';
        else if (students[i].grades.mark > 49)
            students[i].grades.the_grade = 'C';
        else if (students[i].grades.mark > 39)
            students[i].grades.the_grade = 'D';
        else
            students[i].grades.the_grade = 'E';
    }

    // Display data for each student
    std::cout << "\nDisplaying entered data for each student:\n";
    for (int i = 0; i < num_students; ++i) {
        std::cout << "\nStudent " << i + 1 << ":\n";
        std::cout << "Registration number: " << students[i].registration_number << "\n";
        std::cout << "Name: " << students[i].name << "\n";
        std::cout << "Age: " << students[i].age << "\n";
        std::cout << "Course code: " << students[i].course.course_code << "\n";
        std::cout << "Course name: " << students[i].course.course_name << "\n";
        std::cout << "Mark: " << students[i].grades.mark << "\n";
        std::cout << "Grade: " << students[i].grades.the_grade << "\n";
    }

    return 0;
}

