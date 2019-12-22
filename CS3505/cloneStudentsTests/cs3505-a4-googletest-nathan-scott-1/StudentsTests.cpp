//Scott Neville & Nathan Donaldson
//CS 3505 Assignment 4
// Fall 2016

#include "gtest/gtest.h"
#include "gtest/gtest-spi.h" //required for testing for segfault
#include "Students.h"
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;


//helper method
std::string numberofNamesTestIntToString(int i);

/********

         basic cases:

*********/

TEST (StudentsTestsBasic, addStudents) {
  Students s;
  s.addUser("Scott", 10);
  s.addUser("Nathan", 11);
  s.addPhoneNumbers(11, "555-641-1459");
  EXPECT_EQ("555-641-1459", s.phoneForName("Nathan"));
  EXPECT_EQ(2, s.numberOfNames());
}

TEST (StudentsTestsBasic, outOfRangeExceptions) {
  Students s;
  EXPECT_THROW(s.gradeForName("Peter Jensen"), std::out_of_range);
  EXPECT_THROW(s.idForName("Schmittywerbenyangermanjensen"), std::out_of_range);
  EXPECT_THROW(s.phoneForName("Ace Ventura"), std::out_of_range);
}

TEST (StudentsTestsBasic, removeStudent) {
  Students s;
  s.addUser("Nathan Donaldson", 140);
  s.addGrade(140, 'A');
  s.addPhoneNumbers(140, "I'm a phone number!");
  s.removeStudent("Nathan Donaldson");
  EXPECT_EQ(0,s.numberOfNames());
  EXPECT_FALSE(s.nameExists("Schmittywerbenyangermanjensen"));
  EXPECT_THROW(s.gradeForName("Nathan Donaldson"), std::out_of_range);
  EXPECT_THROW(s.idForName("Nathan Donaldson"), std::out_of_range);
  EXPECT_THROW(s.phoneForName("Nathan Donaldson"), std::out_of_range);
}

TEST (StudentsTestsBasic, removeListTests) {
  Students s;
  s.addUser("Nathan Donaldson", 140);
  s.removeStudent("Nathan Donaldson");
  EXPECT_EQ(0,s.numberOfNames());

  s.addUser("Scott Neville", 252);
  s.addUser("Ace Ventura", 11);
  s.addUser("Peter Jensen", 220);
  vector<std::string> names;
  names.push_back("Ace Ventura");
  names.push_back("Peter Jensen");
  names.push_back("Scott Neville");
  EXPECT_EQ(3, s.removeList(names));
  EXPECT_EQ(0, s.removeList(names));
  EXPECT_EQ(0, s.numberOfNames());
}

TEST (StudentsTestsBasic, storeAndRetrieve) {
  Students s;
  s.addUser("Nathan Donaldson", 64);
  s.addPhoneNumbers(64, "555-555-5555");
  s.addGrade(64, 'F');

  EXPECT_TRUE(s.nameExists("Nathan Donaldson"));
  EXPECT_EQ('F', s.gradeForName("Nathan Donaldson"));
  EXPECT_EQ("555-555-5555", s.phoneForName("Nathan Donaldson"));
  EXPECT_EQ(1,s.numberOfNames());
  EXPECT_EQ(64, s.idForName("Nathan Donaldson"));
}


//Testing for problems in numberOfNames
TEST (StudentsTestsBasic, numberOfNamesTest)
{
  Students s;

  //Test for 10 people
  for(int i = 0; i < 10; i++)
  {
    s.addUser(numberofNamesTestIntToString(i), i);
  }

  EXPECT_EQ(10, s.numberOfNames());
  s.clearAll();

  //Test for 100 people
  for(int i = 0; i < 100; i++)
  {
    s.addUser(numberofNamesTestIntToString(i), i);
  }

  EXPECT_EQ(100, s.numberOfNames());
  s.clearAll();

  //Test for 1000 people
  for(int i = 0; i < 1000; i++)
  {
    s.addUser(numberofNamesTestIntToString(i), i);
  }

  EXPECT_EQ(1000, s.numberOfNames());
  s.clearAll();

  //Test for 10000 people
  for(int i = 0; i < 10000; i++)
  {
    s.addUser(numberofNamesTestIntToString(i), i);
  }

  EXPECT_EQ(10000, s.numberOfNames());
  s.clearAll();

  //Testing if duplicates with same name and id
  s.addUser("Nate", 25);
  s.addUser("Nate", 25);
  EXPECT_EQ(1, s.numberOfNames());
  s.clearAll();

  //Testing if duplicates with same name but different id
  s.addUser("Nate", 25);
  s.addUser("Nate", 15);
  EXPECT_EQ(1, s.numberOfNames());
  s.clearAll();

  //Testing if duplicates with same name but different id
  s.addUser("Nate", 25);
  s.addUser("Fred", 25);
  EXPECT_EQ(2, s.numberOfNames());
  s.clearAll();

  //Seems to work as it should, numberOfNames keeps track of how many unique names.
}


//This is used for converting int to string, used in above test.
std::string numberofNamesTestIntToString(int i)
{

  string Result;

  stringstream convert;

  convert << i;

  Result = convert.str();

  return Result;
}


//Testing for problems in nameExists
TEST (StudentsTestsBasic, nameExistsTest)
{
  Students s;
  EXPECT_FALSE(s.nameExists("Schmitty"));
  s.addUser("Nathan", 12345);
  EXPECT_TRUE(s.nameExists("Nathan"));

  //Seems to work
}

//Testing for phone Retrieval
TEST(StudentsTestsBasic, addPhone) {
  Students s;
  s.addUser("I have a phone", 2);
  s.addPhoneNumbers(2, "801-222-5555");
  ASSERT_EQ("801-222-5555", s.phoneForName("I have a phone"));
}

TEST(StudentsTestsBasic, clearAll) {
  Students s;
  s.addUser("Billy", 1);
  s.addUser("Jill", 2);
  s.addUser("Johan", 3);
  s.addGrade(1, 'A');
  s.addPhoneNumbers(2, "801-0018");
  s.addGrade(3, 'D');
  s.addPhoneNumbers(3, "222-9423");
  s.clearAll();

  EXPECT_THROW(s.gradeForName("Billy"), std::out_of_range);
  EXPECT_THROW(s.phoneForName("Jill"), std::out_of_range);
  EXPECT_THROW(s.gradeForName("Johan"), std::out_of_range);
  EXPECT_THROW(s.phoneForName("Johan"), std::out_of_range);
}



TEST (StudentsTestsBasic, StudentsReportGrade) { //checks if full record changes ref values on a failure
  Students s;
  s.addUser("Jim", 8);
  unsigned int id = 7;
  char grade = '7';
  std::string phone = "7";
  EXPECT_FALSE(s.fullRecord("Jim", id, phone, grade)) << "reported full record present but no info has been added beyond id"; //don't have everything yet
  EXPECT_EQ(7, id);
  EXPECT_EQ("7", phone);
  EXPECT_EQ('7', grade);

  s.addGrade(8, '8');
  EXPECT_FALSE(s.fullRecord("Jim", id, phone, grade)) << " reported full record present but phone hasn't been added yet"; //still not all
  EXPECT_EQ(7, id);
  EXPECT_EQ("7", phone);
  EXPECT_EQ('7', grade);

  s.addPhoneNumbers(8, "8"); //this result is somehow corrupted by the above?
  EXPECT_TRUE(s.fullRecord("Jim", id, phone, grade)); //now we've got it all
  EXPECT_EQ(8, id);
  EXPECT_EQ("8", phone);
  EXPECT_EQ('8', grade);
}

TEST (StudentsTestsBasic, StudentReportPhone) {
  Students s;
  s.addUser("Jim", 8);
  unsigned int id = 7;
  char grade = '7';
  std::string phone = "7";

  s.addPhoneNumbers(8, "8");
  EXPECT_FALSE(s.fullRecord("Jim", id, phone, grade));
  EXPECT_EQ(id, 7);
  EXPECT_EQ(phone, "7");
  EXPECT_EQ(grade, '7');
}



/************

        Function behavior testing:

*************/

TEST (StudentsTestsBoundary, idMutableTest) {
  Students s;
  s.addUser("S", 1);
  s.addUser("c", 2);
  s.addUser("o", 1<<2);
  s.addUser("t", 1<<4);
  s.addUser("N", 1<<8);
  s.addUser("e", 3 + (1<<8));
  s.addUser("v", 8);

  EXPECT_EQ(1, s.idForName("S"));
  EXPECT_EQ(2, s.idForName("c"));
  EXPECT_EQ(4, s.idForName("o"));
  EXPECT_EQ(1<<4, s.idForName("t"));
  EXPECT_EQ(1<<8, s.idForName("N"));
  EXPECT_EQ(3 + (1<<8), s.idForName("e"));
  EXPECT_EQ(8, s.idForName("v"));
}


//Testing for problems in gradeForNameTest
TEST (StudentsTestsBoundary, gradeForNameTest)
{
  Students s;

  EXPECT_THROW(s.gradeForName("Johnny"), std::out_of_range); //throws because name is not in the system.
  s.addUser("Johnny", 2222222);
  EXPECT_THROW(s.gradeForName("Johnny"), std::out_of_range); //throws because id is not in the system
  s.addGrade(2222222, '!'); //Checking if can use special character for grade.
  EXPECT_EQ('!', s.gradeForName("Johnny")); //Function should work correctly.
  s.addGrade(2222222, '8'); //Checking if can use number for grade.
  EXPECT_EQ('8', s.gradeForName("Johnny")); //Function should work correctly.

  //This method seems to throw exceptions when it is supposed to and seems to be working.
}


//addUser testing
TEST (StudentsTestsBoundary, addUser_Testing)
{
  Students s;

  s.addUser("0", 0);   //Allows numbers to be used as names
  s.addUser("0", 0);
  EXPECT_EQ(0, s.idForName("0"));
  EXPECT_EQ(1,s.numberOfNames()); //Does not duplicate people with same name and id          EXPECTED FAIL!!

  s.addUser("!", 0);  //Allows special characters to be used as names
  EXPECT_EQ(1, s.numberOfNames()); //Allows two students with different name to have same id number            EXPECTED FAIL!!

  s.addGrade(0, 'A');
  EXPECT_EQ('A', s.gradeForName("!"));
  EXPECT_EQ('A', s.gradeForName("0")); //Updates grades for both students with same id number

  s.addPhoneNumbers(0, "k");  //Can add other characters for phone number
  EXPECT_EQ("k", s.phoneForName("!"));
  EXPECT_EQ("k", s.phoneForName("0")); //Updates phone numbers for both students with same id number

  EXPECT_EQ(0, s.idForName("!"));
  EXPECT_EQ(0, s.idForName("0")); //id's are correct for both names

  s.clearAll();

  s.addUser("Freddy", 27);
  s.addUser("Freddy", 37);

  EXPECT_EQ(27, s.idForName("Freddy"));




  //So from this test we can see that students with same name and user id cannot be added to the system. Students with the same id but different name can be added to the system. Students with the same name can be effected with data problems too. Students with same id get grades and numbers updated at the same time.


}



TEST (StudentsTestsBoundary, StudentsTestsEQ) { //attempts to fiddle with the memory and pointers of each object - tests swapping, saving, and editing
  Students students1;
  Students students2;
  Students students3;
  students1.addUser("Scott", 941530);

  ASSERT_EQ(students1.numberOfNames(), 1);
  ASSERT_EQ(students2.numberOfNames(), 0);

  students1.addGrade(941530, 'Q');
  students1.addPhoneNumbers(941530, "773-0152");
  students3 = students1;
  //check that student 3 has stuff from student 1
  ASSERT_EQ(students3.numberOfNames(), 1);
  ASSERT_EQ(students3.gradeForName("Scott"), 'Q');
  ASSERT_EQ(students3.phoneForName("Scott"), "773-0152");

  students1 = students2;
  //check that student 1 is reset
  ASSERT_EQ(students1.numberOfNames(), 0);

  students2.addUser("Nathan", 55);
  //check that student 1 is immune to changes in student 2
  ASSERT_EQ(students1.numberOfNames(), 0);
}

TEST (StudentsTestsBoundary, StudentsStrange ) {
  Students s;
  s.addPhoneNumbers(3, "7"); //this is the 'wrong' order to do things
  s.addGrade(3, 'Q');
  s.addUser("Scott", 3);
  ASSERT_EQ(s.phoneForName("Scott"), "7");
  ASSERT_EQ(s.gradeForName("Scott"), 'Q');
}



TEST (StudentsTestsBoundary, ID4Name) {
  Students s;
  s.addUser("Scott", 0);
  s.addUser("Nate", 1);
  EXPECT_EQ(s.idForName("Scott"), 0);
  EXPECT_EQ(s.idForName("Nate"), 1);
}

//Testing for problems in idForName
TEST (StudentsTestsBoundary, idForNameTests)
{
  Students s;

  EXPECT_THROW( s.idForName("Johnny"), std::out_of_range);

  s.addUser("Johnny", 01);      //Partner said 0 is not allowed for 1st digit, testing it as well.
  EXPECT_EQ(1, s.idForName("Johnny")); //It seems that you cannot put a 0 in front

  //For this test the id seems to work just fine, but still it has problems.
}



//Testing for problems in phoneForNameTest
TEST (StudentsTestsBoundary, phoneForNameTest)
{
  Students s;

  EXPECT_THROW(s.phoneForName("Johnny"), std::out_of_range); //Should throw because name is not in the system.  EXPECTED FAIL!!! FAILED TO THROW EXCEPTION!!!!
  s.addUser("Johnny", 2222222);
  EXPECT_THROW(s.phoneForName("Johnny"), std::out_of_range); //Should throw because number is not in the system.   EXPECTED FAIL!!! FAILED TO THROW EXCEPTION!
  s.addPhoneNumbers(2222222, "Cash"); //Checking if can use letter characters for number.
  EXPECT_EQ("Cash", s.phoneForName("Johnny")); //Function should work correctly.
  s.addPhoneNumbers(2222222, "!!&^^^"); //Checking if can use special characters for number.
  EXPECT_EQ("!!&^^^", s.phoneForName("Johnny")); //Function should work correctly.

  //phoneForname does not throw exception when looking for name that is not in the map. It is documented that it should through an out_of_range exception but it throws nothing.
}



//Testing for problems in removeStudentsTest
TEST (StudentsTestsBoundary, removeStudentsTest)
{
  Students s;

  EXPECT_THROW(s.removeStudent("Johnny"), std::out_of_range); //Throws when name is not there

  s.addUser("Johnny", 25);
  s.removeStudent("Johnny");                  //Testing one person
  EXPECT_FALSE(s.nameExists("Johnny"));
  EXPECT_EQ(0, s.numberOfNames());

  s.addUser("Johnny", 25);
  s.addGrade(25, 'S');
  s.addPhoneNumbers(25, "23232");             //Testing one person with attributes added
  s.removeStudent("Johnny");
  EXPECT_THROW(s.gradeForName("Johnny"), std::out_of_range);
  EXPECT_THROW(s.idForName("Johnny"), std::out_of_range);

  EXPECT_THROW(s.phoneForName("Johnny"), std::out_of_range); //NOT THROWING EXCEPTION!!!

  s.addUser("Johnny", 25);  //Testing same name/id
  s.addUser("Johnny", 25);
  s.removeStudent("Johnny");
  EXPECT_EQ(0, s.numberOfNames());

  s.addUser("Nate", 25);     //Testing different name/same id
  s.addUser("Fred", 25);
  s.removeStudent("Nate");
  EXPECT_EQ(1, s.numberOfNames());
  EXPECT_EQ(25, s.idForName("Fred"));
  s.removeStudent("Fred");

  s.addUser("Nate", 25);     //Testing same name/different id
  s.addUser("Nate", 24);
  s.addGrade(25, 'a');
  s.addGrade(24, 'b');
  s.addPhoneNumbers(25, "phone1");
  s.addPhoneNumbers(24, "phone2");
  s.removeStudent("Nate");
  EXPECT_THROW(s.idForName("Nate"), std::out_of_range);
  EXPECT_FALSE(s.nameExists("Nate"));
  EXPECT_THROW(s.gradeForName("Nate"), std::out_of_range);

}

//Testing for problems in removeListTest
TEST (StudentsTestsBoundary, removeListTest)
{

  Students s;
                                //Testing 3 users, remove 2 
  s.addUser("Testing", 25);
  s.addUser("is", 24);
  s.addUser("fun", 23);
  vector<std::string> names;
  names.push_back("Testing");
  names.push_back("is");
  s.removeList(names);

  s.addGrade(25, 'A');              //Remove list only gets rid of things associated with id. So we can still add grades and numbers to an id;
  s.addPhoneNumbers(25, "number");

  EXPECT_FALSE(s.nameExists("Testing"));
  EXPECT_EQ(1, s.numberOfNames());

}

//Testing more on id problem
TEST (StudentsTestsBoundary, TestsFailed)
{
  Students s;

  s.addUser("Jake", 606463064);
  EXPECT_EQ(88, s.idForName("Jake"));   //This passes but i dont know why...

  s.addUser("Kaden", 0);
  EXPECT_EQ(0, s.idForName("Kaden"));

  s.addUser("Jori",123456);
  EXPECT_EQ(123456, s.idForName("Jori")); //Fails at 6 numbers here

  s.addUser("Bryce", 12345);
  EXPECT_EQ(12345, s.idForName("Bryce")); //Fails here too. number is 57

  s.addUser("Kupo", 1234);
  EXPECT_EQ(1234, s.idForName("Kupo")); //Ridiculously large number

  s.addUser("Mana", 123);
  EXPECT_EQ(123, s.idForName("Mana")); //This passes

  s.addUser("Fred", 999);
  EXPECT_EQ(999, s.idForName("Fred")); //This fails

  s.addUser("Freddy", 200);
  EXPECT_EQ(200, s.idForName("Freddy")); //This fails as well. id's seem to be screwy


  //All together it seems there are problems with the system. You can make changes to the information via id number, but can only see information based on the name. So if two people have the same id number but 2 different names, information will be screwed up because a change to one id number will change all other id numbers, whether or not they have the same name or not. Along with that, it seems like the id returned is a little weird for idForName function. I cant seem to figure out why different values are being returned instead of the initial id number used when creating a new user. A few checks worked, but im not sure why. Maybe if time is available, we will do an extensive test on that. One last problem is phoneforname, it doesnt throw an exception (as stated in documentation) when name cannot be found.

}

/*******

        deathtests:

********/


void testMethodEmptyList(){ //helpermethod for segfaultTest
  EXPECT_DEATH({std::vector<std::string> emptyNames; //default constructor means this is empty
      Students s;
      s.removeList(emptyNames);
    }, "");
}

TEST (StudentsTestsDeath, segfaultTest) { //Danielle Ensign found the docs to make this possible - the advanced Gtest docs are large. Checks that the removeList method doesn't segfault given an empty vector
  EXPECT_NONFATAL_FAILURE(testMethodEmptyList(), "");
}

void testMethodNormalList(){ //helpermethod for emptyStringCrashTest
  EXPECT_DEATH({std::vector<std::string> blankName; //default constructor means this is empty
      blankName.push_back("");
      Students s;
      s.removeList(blankName);
    }, "");
}

TEST (StudentsTestsDeath, emptyStringCrashTest) { //Danielle Ensign found the docs to make this possible - the advanced Gtest docs are large. Checks that the removeList method doesn't segfault given a vector with the empty string
  EXPECT_NONFATAL_FAILURE(testMethodNormalList(), "");
}


TEST (StudentsTestsDeath, StudentsTestsStress) { //stress test for Students
  Students s;
  string name;
  for (unsigned int i = 0; i < 10000; i++) { //add 10 thousand names - a moderately large number of names, along with misc info
    name = "Scott";
    name.append(std::to_string(i));
    s.addUser(name, i);
    s.addPhoneNumbers(i, "555-555-1357");
    s.addGrade(i, 'A');
  }
  ASSERT_EQ(s.numberOfNames(), 10000); //ensure number of names has the right value
  s.addUser("phonelessStudent", 10024); //adds an extra student with no info
  ASSERT_EQ(10001,s.numberOfNames());
  s.clearAll(); //checks clearing works on number of names
  ASSERT_EQ(s.numberOfNames(), 0);
}
