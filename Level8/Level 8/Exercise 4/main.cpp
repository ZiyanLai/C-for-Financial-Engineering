/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-08
 * @lastModifiedDate: 2020-06-08
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* test boost random */

#include <iostream>
#include <iomanip>
#include <boost/random.hpp>
#include <map>
using namespace std;

int main()
{
    // Throwing dice.
    // Mersenne Twister.
    boost::random::mt19937 myRng;

    // Set Seed
    myRng.seed(static_cast<boost::uint32_t> ( time(0)) );

    // Uniform in range [1,6]
    boost::random::uniform_int_distribution<int> six(1,6);

    //create a map to hold frequency
    map<int, long> statistics;  // to hold outcome + frequency
    int outcome;                // current outcome

    // example to generate 1 outcome
    outcome = six(myRng);
    cout << "The example outcome is: " << outcome << endl;


    // a) Generate a large number of trials and place their frequencies in map
    long trials = 1000000;
    // for this many trials
    for (long i = 0; i != trials; ++i)
    {
        // generate the current outcome
        outcome = six(myRng);
        // increment the count to the corresponding outcome
        statistics[outcome] += 1;
    }   
    // print the number of different outcomes
    cout << "\nThere are:\n\n" 
         << statistics[1] << " of 1s\n" 
         << statistics[2] << " of 2s\n" 
         << statistics[3] << " of 3s\n" 
         << statistics[4] << " of 4s\n" 
         << statistics[5] << " of 5s\n" 
         << statistics[6] << " of 6s\n";



    // b) Produce the output:
    // initiate a map to store the outcome and the frequency in decimal
    map<int, double> frequency;
    for (int i = 1; i != 7; ++i)
    {
        // for each outcome, calcualte and store their corresponding frequency in decimal
        frequency[i] = double(statistics[i]) / double(trials);
    }

    // here we set the precision to 4 decimal to make it more uniform
    cout.precision(4);
    
    // print out the frequency in percentage for each trial
    cout << "\n\nHow many trials? " << trials << "\n\n";
    for (int i = 1; i != 7; ++i)
    {       
        // print the result
         cout << "Trial " << i << " has " << frequency[1] << "% outcomes" << endl;
    }
    

    return 0; 
}