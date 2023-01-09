#include <iostream>
using namespace std;

// prototypes for all functions declared before main()

int UI();
float RoomModes(float x, int k);
double RT60(double x, double y, double z);
float Harmonics(float x, int& k);
void Complete();
int Repeat();

// main() begins

int main()
{
    int Loop = 1; // variable is used for the while loop
    while (Loop == 1)
    {
        int Choice = 0;
        while (Choice < 1 or Choice > 3) // validating user input
        {
            Choice = UI(); // running UI function
        }

        if (Choice == 1) // selection 1 - room mode calculator
        {
            cout << "You have selected: Room Mode Calculator" << "\n";

            float Dist;
            cout << "Please enter the distance between the boundary surfaces of the room in meters (i.e. length/width): ";
            cin >> Dist; // user inputs length/width in meters
            cout << "\n";

            int k = 1; // used to iterate while loop and print room mode number
            float a = 0; // used to call RoomModes function
            while (k < 4)
            {
                a = RoomModes(Dist, k);
                cout << "Room mode " << k << " is " << a << "Hz." << "\n"; // output printed
                k++;
            }

            Complete();
        }

        else if (Choice == 2)
        {
            cout << "You have selected: RT60 Calculator" << "\n";

            double Length, Width, Height = 0;
            cout << "Please input the length, then the width, then the height of the room in meters: " << "\n" << "\n";

            cout << "L: ";
            cin >> Length;

            cout << "W: ";
            cin >> Width;

            cout << "H: ";
            cin >> Height; // user inputs room dimensions

            double b = 0;
            b = RT60(Length, Width, Height); // variable b used to call RT60 function
            cout << "\n" << "The RT60 time for the room is " << b << " seconds." << "\n";

            Complete();

        }

        else
        {
            cout << "You have selected: Even/Odd Harmonics Calculator" << "\n";
            int EvenOdd = 0;
            float Freq; // declaring variables to pass into function

            while (EvenOdd < 1 or EvenOdd > 2) // validates user input
            {
                cout << "Enter 1 to calculate odd harmonics, enter 2 to calculate even harmonics: ";
                cin >> EvenOdd; // user inputs 1 or 2
            }

            cout << "Enter the frequency of the first harmonic in Hertz: ";
            cin >> Freq; // user inputs first harmonic
            cout << "\n";

            float c = 0;

            while (EvenOdd < 11) // iterates function
            {
                c = Harmonics(Freq, EvenOdd);
                cout << "Harmonic " << (EvenOdd-2) << " is " << c << " Hz." << "\n"; // outputs result
            }

                Complete();
        }

        Loop = Repeat();
    }
    cout << "END";

    return 0;
}

// definition of functions

// 1. User Interface
int UI()
{
    int Choice; // local variable Choice declared
    cout << "\n" << "-Calculations Menu-" << "\n" << "1. Room Mode Calculator" << "\n" << "2. RT60 Calculator" << "\n" << "3. Even/Odd Harmonics Calculator" << "\n" << "\n"; // UI outputted
    cout << "Select an option: ";
    cin >> Choice; // user inputs choice
    cout << "\n";
    return Choice;
}

// 2. Room Mode Calculator
float RoomModes(float x, int k) // two global variables passed in
{
    float Mode = 0;
    Mode = (k * 343) / (2 * x); // room mode calculation carried out
    return Mode;
}

// 3. RT60 Calculator
double RT60(double x, double y, double z) // three global variables passed in
{
    double RTTime;
    RTTime = 0.161 * ((x*y*z) / 0.5); //RT60 calculation carried out
    return RTTime;
}

// 4. Room Harmonics Calculator
float Harmonics(float x, int& k) // One variable passed in, one variable referenced
{
    float HarmK;
    HarmK = x * k; // Harmonics calculation - frequency * order of harmonic
    k += 2; // 2 added to harmonic order no. so that function can be used to iterate with
    return HarmK;
}

// 5. Completion Message
void Complete() // used after any calculation has been completed
{
    cout << "\n" << "Calculation complete! Please choose an option below: " << "\n";
}

// 6. Repeat Function
int Repeat()
{
    int Choice;
    cout << "1. New Calculation 2. Finish: " << "\n"; // options printed for user
    cin >> Choice;
    return Choice; // chosen option returned
}