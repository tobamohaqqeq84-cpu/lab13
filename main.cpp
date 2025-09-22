//toba mohaqqeq
//comsc-210
//lab 13

#include <iostream>
#include <fstream>      
#include <array>        // using std::array
#include <algorithm>    
#include <numeric>     
using namespace std;

const int DAYS = 30;   // we are tracking 30 days in a month

int main() {
    array<int, DAYS> calories;  // array to store calories burned each day

    // this openes the file
    ifstream infile("calories.txt");
    if (!infile) {
        cerr << "Error: could not open calories.txt\n";
        return 1;  // stop the program if the file doesn’t open
    }

    // read 30 values from the file into the array
    for (int i = 0; i < DAYS; i++) {
        infile >> calories[i];
    }
    infile.close(); // don’t forget to close file

    // checking array size
    cout << "1. Number of days recorded: " << calories.size() << endl;

    // printing all the values (whole month)
    cout << "2. Calories burned each day: ";
    for (int val : calories) cout << val << " ";
    cout << endl;

    // accessing specific values
    cout << "3. Day 3 calories (using at()): " << calories.at(2) << endl;
    cout << "4. Day 3 calories (using []): " << calories[2] << endl;
    cout << "5. First day: " << calories.front() << endl;
    cout << "6. Last day: " << calories.back() << endl;
    cout << "7. Empty? " << (calories.empty() ? "Yes" : "No") << endl;
    cout << "8. Address of array data: " << calories.data() << endl;

    // sorting ascending
    sort(calories.begin(), calories.end());
    cout << "9. Sorted ascending: ";
    for (int val : calories) cout << val << " ";
    cout << endl;

    // sorting descending
    sort(calories.rbegin(), calories.rend());
    cout << "10. Sorted descending: ";
    for (int val : calories) cout << val << " ";
    cout << endl;

    // try to find a certain calorie value (ex: 500)
    int target = 500;
    auto it = find(calories.begin(), calories.end(), target);
    cout << "11. Value " << target;
    if (it != calories.end())
        cout << " found at position " << (it - calories.begin()) << endl;
    else
        cout << " not found.\n";

    // max, min, total, average
    cout << "12. Max calories burned: " 
         << *max_element(calories.begin(), calories.end()) << endl;
    cout << "13. Min calories burned: " 
         << *min_element(calories.begin(), calories.end()) << endl;
    cout << "14. Total calories burned this month: " 
         << accumulate(calories.begin(), calories.end(), 0) << endl;
    cout << "15. Average per day: " 
         << accumulate(calories.begin(), calories.end(), 0) / (double)calories.size() 
         << endl;

    // make some other arrays and fill them
    array<int, 5> tens;
    tens.fill(10);
    cout << "16. 5-element array of 10's: ";
    for (int val : tens) cout << val << " ";
    cout << endl;

    array<int, 5> twenties;
    fill(twenties.begin(), twenties.end(), 20);
    cout << "17. 5-element array of 20's: ";
    for (int val : twenties) cout << val << " ";
    cout << endl;

    // swap the two arrays
    tens.swap(twenties);
    cout << "18. After swap, the tens array now has: ";
    for (int val : tens) cout << val << " ";
    cout << endl;

    return 0;
    // THE END._.
}