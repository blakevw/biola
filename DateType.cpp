// Define member functions of class DateType.
// This is file DateType.cpp.

#include "DateType.h" // gain access to specification of class
#include <iostream>
#include <ctime>
#include <random>

using namespace std;

//The first constructor method to initialize a DateType object
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
DateType::DateType()
{
   engine= default_random_engine (static_cast<unsigned int>(time(0)));
  year = 2000;
  month = 1;
  day = 1;
}


//The second constructor method to initialize a DateType object
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//  initialize day, month, year in the object
//  to 1, 1, and 2000 representing 1/1/2000
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
DateType::DateType(int newMonth, int newDay, int newYear)
{
    if(IsValidDate(newMonth,newDay,newYear)){
        year = newYear;
        month = newMonth;
        day = newDay;}
    else {
        year =2000;
        month =1;
        day=1;
        
    }
}



//A method to set a new date for the DateType object.
//Check whether newMonth, newDay, newYear compose a valid date first.
//If they do Not compose a valid date,
//   do not change the date stored in the object and then return false.
//If they do compose a valid date,
//   use newMonth, newDay, newYear to update day, month, year in the object,
//   and then return true.
bool DateType::SetDate(int newMonth, int newDay, int newYear)
{
    if(IsValidDate(newMonth,newDay,newYear)){
        year = newYear;
        month = newMonth;
        day = newDay;
        
        
        return true;
    }else return false;
}

int DateType::MonthIs()
// Accessor function for data member month.
{
  return month;
}

int DateType::YearIs()
// Accessor function for data member year.
{
  return year;
}


int DateType::DayIs()
// Accessor function for data member day.
{
    return day;
}


void DateType::ReadDate()
{
    do {
        
        
            cout << endl
            << "Read in the information of a date: " ;
            
            cout << endl << "The month is: ";
            cin >> month;
            cout << endl << "The day is: ";
            cin >> day;
            cout << endl << "The year is: ";
            cin >> year;
        
    if(!IsValidDate(month,day,year)){
        cout<< endl<< "Date is not valid try again";
    }
    } while(!IsValidDate(month,day,year));
}

void DateType::PrintDate()
{
    cout<< month<<"/"<<day<<"/"<<year;

}


int DateType::ComparedTo(DateType aDate)
// Pre: Self and aDate have been initialized.
// Post: return
//  LESS, if self comes before aDate.
//  EQUAL, if self is the same as aDate.
//  GREATER, if self comes after aDate.
{
    if(year>aDate.year){
        return GREATER;
    } else
        if(year<aDate.year){
            return LESS;
        } else
            if(month<aDate.month){
                return LESS;
            } else
            if(month>aDate.month){
                return GREATER;
            } else
                if(day<aDate.day){
                    return LESS;
                }
                if(day>aDate.day){
                    return GREATER;
                }
                else return EQUAL;
	
}

int DateType::ComparedCentury(DateType aDate)
// Pre: Self and aDate have been initialized.
// Post: return
//	LESS, if the object itSelf comes before the century of aDate.
//	EQUAL, if the object itSelf is in the same century as aDate.
//	GREATER, if the object itSelf comes after the century of aDate.
{
    if(((int)(year/100)+.5)>((int)(aDate.year/100)+.5)){
        return GREATER;
    }else if(((int)(year/100)+.5)==((int)(aDate.year/100)+.5)){
        return EQUAL;
    }else return LESS;
	
}

void DateType ::AdvanceDays(int numDays)
//advances the days num days forward
{
    if(numDays<0){
       BackDays(-numDays);
}
    while(numDays>0){
        //31 day months
        if((month==1||month==3||month==5||month==7||month==8||month==10)&& day==31){
            month++;
            day=1;
            numDays--;
            }
        else if(month==12&& day==31){
            month=1;
            year++;
            day=1;
            numDays--;
        }
            //30 day month
        else if((month==4||month==6||month==9||month==11) && day==30){
            month++;
            day=1;
            numDays--;
            //not a leap year 28 day month
        }else if(month==2 && day==28 && (year%4!=0 || (year% 100==0 && year%400 !=0))){
            month++;
            day=1;
            numDays--;
            //leap year 29 day month
        } else if(month==2 && day==29 && (year%4==0 && (year%100!=0 || year%400 ==0))){
            month++;
            day=1;
            numDays--;
        }else{
            day++;
            numDays--;
        }
   //while loop curly
    }
}
void DateType::BackDays (int numDays){
    if(numDays<0){
         AdvanceDays(-numDays);
    }
    while(numDays>0){
        //back into 31 day months
        if((month==2||month==4||month==6||month==8||month==9||month==11) && day==1){
            month--;
            day=31;
            numDays--;
        }
        //back into 30 day months
       else if((month==5||month==7||month==10||month==12)&& day==1){
            month--;
            day=30;
           numDays--;
           //january to prev year
       }else if(month==1 && day==1){
           month=12;
           day=31;
           year--;
           numDays--;
           //march aka not a leap year
       }else if(month==3 && day==1 && (year%4!=0 || (year% 100==0 && year%400 !=0))){
           month=2;
           day=28;
           numDays--;
           //leap year case
       } else if(month==3 && day==1&& (year%4==0 && (year%100!=0 || year%400 ==0))){
           month=2;
           day=29;
           numDays--;
       } else{
           day--;
           numDays--;
       }
    }
}

bool DateType::IsValidDate(int newMonth, int newDay, int newYear){
    if((newMonth==1||newMonth==3||newMonth==5||newMonth==7||newMonth==8||newMonth==10||newMonth==12)&& newDay>=1&&newDay<=31)
        return true;
        else if((newMonth==4||newMonth==6||newMonth==9||newMonth==11)&& newDay>=1&& newDay<=30)
        return true;
    //test for non leap year
    else if(newMonth==2 && (newYear%4!=0 || (newYear% 100==0 && newYear%400 !=0))&&newDay>=1 && newDay<=28)
        return true;
    else if(newMonth==2&&(newYear%4==0 && (newYear%100!=0 || newYear%400 ==0))&& newDay>=1 &&newDay<=29)
        return true;
    return false;
}
//ask why it is the same date for every instance.
void DateType::SetRandomDate(){
   // default_random_engine engine(static_cast<unsigned int>(time(0)));
    uniform_int_distribution<unsigned int> randomYear(1, 2024);
    uniform_int_distribution<unsigned int> randomMonth(1,12);
 
    year=randomYear(engine);
    month=randomMonth(engine);
    
    int temp=1;
    if(month==2){
        //leap year
        if( year%4==0 && (year%100!=0 || year%400 ==0)){
            temp=29;
        } else if((year%4!=0 || (year% 100==0 && year%400 !=0))){
            temp=28;
        }
    } else if(month==4||month==6||month==9||month==11){
        temp=30;
    } else
        temp=31;
    
    uniform_int_distribution<unsigned int> randomDay(1,temp);
    day=randomDay(engine);
    
}

bool DateType::operator> (const DateType & aDate){
    if(year>aDate.year){
        return true;
    } else if(year==aDate.year){
        if (month > aDate.month){
            return true;
        } else if (month == aDate.month){
            return day>aDate.day;
        }
    }
    return false;}

bool DateType::operator< (const DateType & aDate){
    if(year<aDate.year){
        return true;
    }else if(year==aDate.year){
        if (month< aDate.month){
            return true;
        } else if (month ==aDate.month){
            return day <aDate.day;
        }
    }
    return false;}

bool DateType::operator==(const DateType & aDate){
    return (year==aDate.year&&month==aDate.month&&day==aDate.day);
    
    }
bool DateType::operator!=(const DateType & aDate){
    return !(year==aDate.year&&month==aDate.month&&day==aDate.day);
}
bool DateType::operator>=(const DateType & aDate){
    return operator>(aDate) || operator==(aDate);
}
bool DateType::operator<=(const DateType & aDate){
    return operator<(aDate) || operator ==(aDate);
}
DateType DateType::operator+(int numDays){
    DateType resultDate(month,day,year);
    resultDate.AdvanceDays(numDays);
    return resultDate;
}
DateType DateType::operator-(int numDays){
    DateType resultDate(month,day,year);
    resultDate.BackDays(numDays);
    return resultDate;
}
int DateType::operator-(const DateType & aDate){
   //*this refers to DateType
    DateType early =*this;
    DateType late= aDate;
    
    if(*this <aDate){
        early =*this;
        late=aDate;
    } else if(*this>aDate){
        early =aDate;
        late=*this;
    } else{
        return 0;//days are equal
    }
    int numDays=0;
    while(early!=late){
        early.AdvanceDays(1);
        numDays++;
    }
    return numDays;
}

ostream & operator<< (ostream & output, const DateType & aDate){
    if(&output==&cout){
        output<<aDate.month<<'/'<<aDate.day<<'/'<<aDate.year;
    }else {
        output<<aDate.month<<' '<<aDate.day<<' '<<aDate.year;
    }
    return output;
}
istream & operator>> (istream & input, DateType & aDate){
    if(&input==&cin){
        aDate.ReadDate();
    } else{
        int tempMonth, tempDay, tempYear;
        input>>tempMonth>>tempDay>>tempYear;
        
        if(aDate.IsValidDate(tempMonth, tempDay, tempYear)){
            aDate.SetDate(tempMonth, tempDay, tempYear);
        }
    }
    
    return input;
}
