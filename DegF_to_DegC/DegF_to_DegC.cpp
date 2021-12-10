#include <iostream>
#include <string>
#include <fstream>

using namespace std;

    //Declared a function of type void for the file read and conversion.
void FileReadConvert(){
   string cityName;
   int fDeg,cDeg;

    //Input file stream declared with fileA used to open FahrenheitTemperature.txt
   ifstream fileA;
   fileA.open("FahrenheitTemperature.txt");
  
    //Output file stream declared with fileB used to open/change CelsiusTemperature.txt
   ofstream fileB;
   fileB.open("CelsiusTemperature.txt");

    //Prints failed to open message if fileA does not open
   if(!fileA)   {
        cout << "Failed to open FahrenheitTemperature.txt." << endl;
    
    //While fileA is open the int cDeg is assigned the fDeg conversion. 
    //After cDeg is assigned the cityName prints in CelsiusTemperature.txt followed by a space the cDeg then newline.
   }else{      
       while(fileA >> cityName >> fDeg){
           cDeg = ((fDeg - 32) * 5)/9;
           fileB << cityName << " " << cDeg << endl;
       }
   }

    //Both files are closed after all ops are complete.
   fileA.close();
   fileB.close();
}

int main(){
    
    //function is called and all ops are executed
   FileReadConvert();

   return 0;
}