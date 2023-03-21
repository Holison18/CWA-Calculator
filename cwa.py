# An application in python that calculates the cwa of users
from time import sleep
import os

class student():
    # declare variables
    name = ""
    student_id = ""
    major = ""
    cwa = 0
    student_class = ""
    courses = []
    weight = []
    grades = []

    def __init__(self,Name,Student_id,Major,Courses,Weight,Grades):
        self.name = Name
        self.student_id = Student_id
        self.major = Major
        self.courses = Courses
        self.weight = Weight
        self.grades = Grades

    def calculate_cwa(self):
        total_grade = 0
        total_weight = 0
        for i in self.courses:
            total_grade += self.courses[i] * self.weight[i]
            total_weight += self.weight[i]
            i+=1
        cwa = total_grade/total_weight
        if cwa >= 70:
            self.student_class = "First Class"
        elif cwa >=60 and cwa <70:
            self.student_class = "Second Class Upper"
        elif cwa >=50 and cwa <60:
            self.student_class = "Second Class low"
        elif cwa >=40 and cwa <60:
            self.student_class = "Pass"
        else:
            self.student_class = "Fail"


    def print_info(self):
        print("\t\t\t\tStudent's Details")
        print()
        print(f"Name:{self.name}")
        print(f"Student ID:{self.student_id}")
        print(f"Major:{self.major}")
        # iterate over the course and print them with their weights and grades
        for i in self.courses:
            print(f"Course:{i} Weight:{self.weight[i]} Grade:{self.grades[i]}")
            i+=1
        # print the cwa and class
        print(f"CWA:{self.cwa}")
        print(f"Class:{self.student_class}")
        

def main():
    # declare variables
    name = ""
    student_id = ""
    major = ""
    courses = []
    weight = []
    grades = []
    # get the student's details
    print("\t\t\tCWA Calculator\n\n")
    sleep(.5)
    print("Enter your details below")
    sleep(.5)
    name = input("Enter your name:")
    sleep(.5)
    student_id = input("Enter your student ID:")
    sleep(.5)
    major = input("Enter your major:")
    sleep(.5)
    # get the number of courses
    num_courses = int(input("Enter the number of courses:"))
    sleep(.5)
    # get the courses, weight and grades
    for i in range(num_courses):
        courses.append(input("Course Name:"))
        sleep(.5)
        weight.append(int(input("Enter the weight:")))
        sleep(.5)
        grades.append(int(input("Enter the grade:")))
    # create an object of the student class
    student1 = student(name,student_id,major,courses,weight,grades)
    # calculate the cwa
    sleep(1)
    os.system("clear")
    student1.calculate_cwa()
    # print the student's details
    student1.print_info()

if __name__ == "__main__":
    main()

