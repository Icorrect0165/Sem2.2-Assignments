#include <stdio.h>
#include <string.h>

// Define the Course structure
struct Course {
    char course_code[20];
    char course_name[50];
};

// Define the Grade structure
struct Grade {
    int mark;
    char the_grade;
};

// Define the Student structure
struct Student {
    char registration_number[20];
    char name[50];
    int age;
    struct Course course;
    struct Grade grades;
};

int main() {
    const int max_students = 40;
    struct Student students[max_students];

    int num_students;

    // Input the number of students
    printf("Enter the number of students (max %d): ", max_students);
    scanf("%d", &num_students);

    // Input data for each student
    for (int i = 0; i < num_students; ++i) {
        printf("\nEnter details for Student %d:\n", i + 1);

        // Input registration number
        printf("Enter registration number: ");
        scanf("%s", students[i].registration_number);

        // Input name
        printf("Enter name: ");
        scanf("%s", students[i].name);

        // Input age
        printf("Enter age: ");
        scanf("%d", &students[i].age);

        // Input course details
        printf("Enter course code: ");
        scanf("%s", students[i].course.course_code);

        printf("Enter course name: ");
        scanf("%s", students[i].course.course_name);

        // Input grade details
        printf("Enter mark: ");
        scanf("%d", &students[i].grades.mark);

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
    printf("\nDisplaying entered data for each student:\n");
    for (int i = 0; i < num_students; ++i) {
        printf("\nStudent %d:\n", i + 1);
        printf("Registration number: %s\n", students[i].registration_number);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Course code: %s\n", students[i].course.course_code);
        printf("Course name: %s\n", students[i].course.course_name);
        printf("Mark: %d\n", students[i].grades.mark);
        printf("Grade: %c\n", students[i].grades.the_grade);
    }

    return 0;
}
