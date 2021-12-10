/* [Gary Landstrom]
* [CS-210]
* [11/10/2021] */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void ClearScreen(){
    
    int i;

    // This will exeicute 40 times clearing the screen of any previous output.

    for( i = 0; i < 40; ++i){ 
        
        cout << endl; 
    }
    
    // Code source SNHU announcements: https://learn.snhu.edu/d2l/lms/news/main.d2l?ou=895781 

}

void OptionMenu(){ 

    /* Using the text allignment manipulators proved more efficent in some areas but ultimately led to more lines of code. 
     * The use of the text manipulators could provide more consistant outputs if the strings or integers printed are prone-
     * to change, for the user input menu I don't think this is the most efficent choice. It did help me learn the text- 
     * manipulators though. 
    */
    
    cout << "              " << setfill('*') << setw(23) << "*\n"; 

    cout << "              " << left << setfill(' ') << setw(21) << "* 1-Add One Hour"; 
    cout << right << "*\n";                                                            

    cout << "              " << left << setfill(' ') << setw(21) << "* 2-Add One Minute"; 
    cout << right << "*\n";                                                              

    cout << "              " << left << setfill(' ') << setw(21) << "* 3-Add One Second"; 
    cout << right << "*\n";                                                              

    cout << "              " << left << setfill(' ') << setw(21) << "* 4-End Program"; 
    cout << right << "*\n";                                                           

    cout << "              " << setfill('*') << setw(23) << "*\n"; 

    
    // I chose to implement the text alignment manipulators to help reinforce and learn the information.
}

void ClockDisplay(int hour12, int hour24, int minute, int seconds, string dayNight){ 

    /* Before I figured out how to print a leading zero on any single digit integers the use of the-
     * text manipulators made it possible to output a box with fixed allignments. Of course right after-
     * I got this working I also found a forum that helped me print integers with a leading 0 making- 
     * my efforts nothing more than an exercise in applying text allignment manipulators.
     */

    // Note the white space, each represents a new line to be printed. 

    cout << setfill('*') << setw(23) << "*";                    
    cout << "     " << setfill('*') << setw(23) << "*\n";     
    
    cout << "*    " << setfill(' ') << left << setw(17) << "12-Hour Clock" << right << "*";           
    cout << "     *    " << setfill(' ') << left << setw(16) << "24-Hour Clock" << right << "*\n";     
    
    cout << left << "*";                                                            
    cout << "       " << right << setfill('0') << setw(2) << hour12 << ":";        
    cout << right << setfill('0') << setw(2) << minute << ":";                    
    cout << right << setfill('0') << setw(2) << seconds;           
    cout << right << dayNight;                                                  
    cout << right << setfill(' ') << setw(4) << "*";                           

    cout << "     *";                                                               
    cout << "       "  << right << setfill('0') << setw(2) << hour24 << ":";       
    cout << right << setfill('0') << setw(2) << minute << ":";          
    cout << right << setfill('0') << setw(2) << seconds;                         
    cout << right << setfill(' ') << setw(7) << "*\n";                          
    
    cout << setfill('*') << setw(23) << "*";                    
    cout << "     " << setfill('*') << setw(23) << "*\n";      

    // The information used to print a leading zero was sourced here: 
    //Den, N. D. (2019, April 4). Print leading zeros with C++ output operator. Tutorialspoint. Retrieved November 9, 2021, from https://www.tutorialspoint.com/print-leading-zeros-with-cplusplus-output-operator

}

string UserInput(){ 

    int hour12, hour24, minute, seconds, userIn; 
    string dayNight; 

    // I opted to use the same variable names in the scope of this function for readability and simplicity.

    hour12 = 8;
    hour24 = 8;
    minute = 55; 
    seconds = 55;
    dayNight = " AM";

    // each time something is to be printed there are three function calls, the first will clear the screen, the second will update and-
    // print the new clocks and the third will print the user input menu. This is my favorite part of the entire project. 

    ClearScreen(); 
    ClockDisplay(hour12, hour24, minute, seconds, dayNight); 
    OptionMenu();  

    while (userIn != 4){ 

        // the while loop will execute as long as userIn is not 4, leading with the UserIn scanner ensures nothing changes without user input. 
        
        cin >> userIn; 

        // while not in the scope of the assignment I feel it is important to include some indication for invalid input.

        if (userIn <= 0 || userIn >= 4){ 
           
            ClearScreen();
            ClockDisplay(hour12, hour24, minute, seconds, dayNight); 
            OptionMenu();
            cout << "Invalid Input.\n"; 

        }

    
        if (userIn == 1){
            hour12 = hour12 + 1; 
            hour24 = hour24  + 1;

            // A basic check to determine whether it is AM or PM the choice to link this with hour24 made the logic much easier to write. 

            if (hour24 >= 12 && hour24 < 23){ 
                dayNight = " PM";
            }

            else {
                dayNight = " AM"; 
            }

            // Basic parameters for both clock hour displays.

            if (hour12 > 12){ 
                hour12 = 1; 
            }

            if (hour24 > 23){ 
                hour24 = 0; 
            }

            ClearScreen(); 
            ClockDisplay(hour12, hour24, minute, seconds, dayNight); 
            OptionMenu(); 

        }

        if (userIn == 2){ 
            minute = minute + 1;

            // Basic parameter check initiates after the minute is incremented. 

            if (minute > 59){ 
                minute = 0;
            }

            ClearScreen(); 
            ClockDisplay(hour12, hour24, minute, seconds, dayNight); 
            OptionMenu(); 

        }

        if (userIn == 3){ // Checks userIn value, if true iterate seconds by 1.
            seconds = seconds + 1;

            // Same parameter check, also initiates after the variable is incremented. 

            if (seconds > 59){ 
                seconds = 0;
            }

            ClearScreen(); 
            ClockDisplay(hour12, hour24, minute, seconds, dayNight); 
            OptionMenu();

        }

        // This is the only input option that does not print the clocks and option menu. 
        // This design ensures that the users knows the program is terminated. 

        if (userIn == 4){ 
            ClearScreen(); 
            cout << "Program Terminated."; 
        }

    }

    // Returns nothing because when userIn is 4 the program is terminated.

    return " \n"; 

}

int main(){

    // The goal was to have next to no code in the main(). I am quite happy with the result.
    
    cout << UserInput(); 

    return 0;

}