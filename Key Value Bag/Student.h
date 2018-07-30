//FILE: Student.h
//CLASS PROVIDED: Student

// CONSTRUCTORS
// Student();
//Allows for the creating of an uninitialized student object
//	Student(int agey, std::string namey){age=agey; name=namey;
// Allows for the creation of a student object with member name and age defined
//
//	MEMBER FUNCTIONS
//int rage(){return age;}
// Returns the age of a specific student object
//std::string rname(){return name;}
//Returns the name of a specific student object
//	friend std::ostream &operator<<( std::ostream &output, const Student &D )
// Overloads the output operator (<<_


#ifndef STUDENT_H_
#define STUDENT_H_
#include <iostream>
class Student {
public:
	//CONSTRUCTORS
	Student();
	Student(int agey, std::string namey){age=agey; name=namey;}
	//MEMBER FUNCTIONS
	int rage(){return age;}
	friend std::ostream &operator<<( std::ostream &output, const Student &D ) {
	         output << "\nThe students name is: " << D.name
	        		 << ". The students age is: " << D.age<<std::endl;
	         return output;
	      }
	std::string rname(){return name;}

private:
	int age;
	std::string name;
};

#endif /* STUDENT_H_ */
