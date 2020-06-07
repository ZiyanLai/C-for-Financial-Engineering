/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-06
 * @lastModifiedDate: 2020-06-06
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* STL Iterators */

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
using namespace std;

// declare to use a template
template <typename T>
// define a template function Sum which takes in type T and returns a double
double Sum(const T& input)
{
    // initialize a const iterator
    typename T::const_iterator i;
    // initialize a double as our result
    double res;

    for (i = input.begin(); i != input.end(); ++i)
    {   
        // add dereference of the current index pointer
        res += *i;
    }
    // return the Sum
    return res;
}


// declare to use a template
template <typename T>
// Sum function that accepts 2 iterators
double Sum(const typename T::const_iterator& start, const typename T::const_iterator& end)
{   
    // initialize a const iterator
    typename T::const_iterator i;
    // initialize a result
    double res;
    
    for (i = start; i != end; ++i)
    {
        // add each element to result
        res += *i;
    }
    // return the sum
    return res;
}


// declare to use a template
template <typename T1, typename T2>
// define a template function Sum to handle Map
// using the feature of function overloading
double Sum(const map<T1, T2>& input)
{
    // initialize a const_iterator for Map
    typename map<T1, T2>::const_iterator i;
    // initialize a double as our result
    double res;

    for (i = input.begin(); i != input.end(); ++i)
    {   
        // add the second argument in the Map, which is the value
        res += i->second;
    }
    // return the Sum
    return res;
}


// declare to use a template
template <typename T1, typename T2>
// define a template functino Sum to take 2 iterators for Map
double Sum(const typename map<T1, T2>::const_iterator& begin, const typename map<T1, T2>::const_iterator& end)
{
    // initialize a const_iterator for Map
    typename map<T1, T2>::const_iterator i;
    // initialize a double as our result
    double res;

    for (i = begin; i != end; ++i)
    {
        res += i->second;
    }
    return res;
}



// main() 
int main()
{   
    // initialize a double variable to store the result
    double res;

    // test List
    cout << "\nNow testing List:" << endl;
    // a list of double 
    list<double> doubleList;
    cout << "elements in the double list: ";
    for (int i = 0; i < 10; ++i)
    {
        // push elements into the list
        doubleList.push_back(i);
        // print each element in the list
        cout << i << " "; 
    }
    cout << endl;
    
    // call Sum function to calculate
    res = Sum< list<double> >(doubleList);
    // print the result
    cout << "Summation of elements in the list is (using function that takes a container) " << res << endl;

    
    // call the functinon that takes iterators 
    res = Sum< list<double> >(doubleList.begin(), doubleList.end());
    // print the result
    cout << "Summation of elements in the list is (using function that takes 2 iterators) "<< res << endl;





    // test Vector
    cout << "\nNow testing Vector:" << endl;
    // initialize a number of element
    int numElem = 10;
    // initialize a vector of double
    vector<double> doubleVector;
    cout << "elements in the double vector: ";
    for (int i = 0; i < numElem; ++i)
    {
        // push elements into the vector
        double curr = i + 0.5;
        doubleVector.push_back(curr);
        // print every element in the vector
        cout << doubleVector[i] << " ";
    }
    cout << endl;

    // call Sum function to calculate
    res = Sum< vector<double> >(doubleVector);
    // print the result
    cout << "Summation of elements in the vector is (using function that takes a container) " << res << endl;

    // call the functinon that takes 2 iterators 
    res = Sum< vector<double> >(doubleVector.begin(), doubleVector.end());
    // print the result
    cout << "Summation of elements in the vector is (using function that takes 2 iterators) "<< res << endl;





    // Test Map
    cout << "\nNow testing Map:" << endl;
    // initialzie a map 
    map<string, double> myMap;
    // initialize a string list of keys
    string str[5] = {"a", "b", "c", "d", "e"};

    // fill the map
    for (int i = 0; i != 5; ++i)
    {
        myMap[str[i]] = i + 0.5;
        cout << "Key: " << str[i] << " Value: " << myMap[str[i]] << endl;
    }
    
    // call Sum function for Map to calculate
    res = Sum<string, double>(myMap);
    // print the result
    cout << "Summation of values in the map is (using function that takes a container) " << res << endl;

    // call the functinon for Map that takes 2 iterators 
    res = Sum<string, double>(myMap.begin(), myMap.end());
    // print the result
    cout << "Summation of values in the map is (using function that takes 2 iterators) " << res << endl;



    return 0;
}