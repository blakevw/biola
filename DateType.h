#ifndef MY_DATETYPE_H   //Compiler directives to make sure DateType.h is included only once
#define MY_DATETYPE_H

#define LESS    -1
#define EQUAL    0
#define GREATER    1

// This is file DateType.h
// Here we declare the interface of a class so that we can
//    store the information of dates in objects of the DateType class and
//    call methods provided by these objects to process date information
// The actually implementation of the methods are inside DateType.cpp

#include <iostream>
#include <random>
using namespace std;

class DateType
{
 public:    //The following members can be called anywhere

  DateType();
  //The first constructor method to initialize a DateType object

  DateType(int newMonth, int newDay, int newYear);
  //The second constructor method to initialize a DateType object

  int YearIs();       // a method to returns year
  int MonthIs();      // a method to returns month
  int DayIs();        // a method to returns day

  bool SetDate(int newMonth, int newDay, int newYear);
  //A method to set a new date for the DateType object.
  //Return false if the date is invalid.

  void ReadDate();
  //A method to read in three integers and set them as the
  //    as the day, month, year of the DateType object to the console cout


  bool IsValidDate (int Month, int Day, int Year);
  //Check the input date to make sure it is a valid date.


  void PrintDate();
  //A method to output the contents of the Date object to the console cout

  int ComparedTo(DateType aDate);
  // Pre: the object itself and aDate should have been initialized.
  // Post:return value should be
  //     LESS, if the object itself comes before aDate.
  //    EQUAL, if the object itself is the same as aDate.
  //    GREATER, if the object itself comes after aDate.

  int ComparedCentury(DateType aDate);
    // Pre: Self and aDate have been initialized.
    // Post: return
    //    LESS, if the object itSelf comes before the century of aDate.
    //    EQUAL, if the object itSelf is in the same century as aDate.
    //    GREATER, if the object itSelf comes after the century of aDate.

  void AdvanceDays(int NumDays);
    //Modify the date by advancing it "NumDays" days into the future.

  void BackDays(int NumDays);
    //Modify the date by pushing it back "NumDays" days into the past.


 private: //The following members can be direclt accessed in DateType.cpp
  int year;
  int month;
  int day;
default_random_engine engine;


  //**********************************************************************
  // The following are new public member functions just added into Date
  //**********************************************************************

  public:

      void SetRandomDate();
        //set the contents to a valid random date

      bool operator> (const DateType & aDate);
        //Define the relationl operator >

      bool operator< (const DateType & aDate);
        //Define the relationl operator <

      bool operator== (const DateType & aDate);
        //Define the relationl operator ==

      bool operator!= (const DateType & aDate);
        //Define the relationl operator !=

      bool operator>= (const DateType & aDate);

          //Define the relationl operator >=

      bool operator<= (const DateType & aDate);

          //Define the relationl operator <=


    DateType operator+ (int numDays);
    //Define the arithmetic operator + such that it will
    //    return a separate DateType object recording a date
    //    that is numDays into the future from the DateType object
    //    performing this operation.
    //Note that the date recorded in the DateType object performing
    //    this operation should remain unchanged.
    //For example, in the following the output should be
    //    1/1/2010 and 1/3/2010 respectively.
    //         DateType d1(1,1, 2010)), d2;
    //          d2 = d1+2;
    //          d1.PrintDate();
    //          d2.PrintDate();


    DateType operator- (int numDays);
    //Define the arithmetic operator - such that it will
    //    return a separate DateType object recording a date
    //    that is numDays into the past from the Date object
    //    performing this operation.
    //Note that the date recorded in the DateType object performing
    //    this operation should remain unchanged.
    //For example, in the following the output should be
    //    1/3/2010 and 1/1/2010 respectively.
    //         DateType d1(1,3, 2010)), d2;
    //          d2 = d1-2;
    //          d1.PrintDate();
    //          d2.PrintDate();

    int operator- (const DateType & aDate);
    //Define the arithmetic operator - such that
    //    it will calculate and return the number days to go
    //    from the DateType object aDate passed as the argument
    //    to this DateType object now performing this operation
    //The number returned should be positive if aDate records
    //    a date earlier than that recorded in this date,
    //The number returned should be negative if aDate records
    //    a date later than that recorded in this date,
    //The number returned should be 0 if aDate records records
    //    the same date as that recorded in this date.
    //For example, in the following, 2 should be the output generated.
    //         DateType d1(2,16, 2010), d2(2, 14, 2010);
    //          cout << d1-d2;


     //***********************************************************************
     // The following two new global functions as I/O operators for Date.
     // They are NOT member functions in Date, but are declared as friends
     //   so that they can access the private data members of DateType objects
     //   for input and output.
     //***********************************************************************

      friend ostream & operator<< (ostream & output, const DateType & aDate);
        //For example, in the following 2/16/2010 should be the output.
        //         DateType d1(2,16, 2010);
        //          cout << d1;
        //For example, in the following 2 14 2010 should be stored
        //    into the file someFile.txt.
        //         DateType d2(2, 14, 2010); ofstream fout;
        //          fout.open("someFile.txt");
        //          fout << d2;

  
      friend istream & operator>> (istream & input, DateType & aDate);
        //For example, in the following the user will be prompted
        //    to enter the day, month, and year as a date stored in d3
        //    just like how the ReadDate method should work.
        //         DateType d3;
        //          cin >> d3;
        //For example, in the following 2 14 2010 should be read
        //    from the file someFile.txt into d4 as the date stored in d4.
        //         DateType d4 ifstream fin;
        //          fin.open("someFile.txt");
        //          fin >> d4;

};

#endif   //Compiler directives to make sure DateType.h is included only once


