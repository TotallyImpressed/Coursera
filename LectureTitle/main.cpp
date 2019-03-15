#include <iostream>
using namespace std;

struct Specialization {
    string value;
    explicit Specialization(string new_spec) {
        value = new_spec;
    }
};

struct Course {
    string value;
    explicit Course(string new_course) {
        value = new_course;
    }
};

struct Week{
    string value;
    explicit Week(string new_week) {
       value = new_week;
    }
};

struct LectureTitle {
    string specialization;
    string course;
    string week;

    LectureTitle(Specialization new_spec, Course new_course, Week new_week) {
        specialization = new_spec.value;
        course = new_course.value;
        week = new_week.value;
    }
};
