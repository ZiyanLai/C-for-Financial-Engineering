/*
 * fileName:          main.cpp 
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-08
 * @lastModifiedDate: 2020-06-08
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Test Statistics and Distributional Functinos in Boost */
#include <iostream>
#include <boost/math/distributions.hpp>
#include <boost/math/distributions/poisson.hpp>
#include <boost/math/distributions/exponential.hpp>
#include <vector>
using namespace std;

int main()
{
    // declare to use this namespace for convinience
    using namespace boost::math;


    cout << "Displaying Exponential Distribution:" << endl;

    // initialize lambda parameter 
    double scaleParameter1 = 0.5;

    // initialize Exponential Distribution
    // default type is double
    exponential_distribution<> myExponential1(scaleParameter1);
    // print out the mean and the standard deviation
    cout << "Mean " << mean(myExponential1)
         << ", Standard Deviation: " << standard_deviation(myExponential1) << endl;

    // initialize a random variable
    double x = 2.0;

    // calculate and print out the pdf and cdf 
    cout << "\npdf of Exponential Distribution with x = " << x << ", lambda = " << scaleParameter1 << " is " << pdf(myExponential1, x) 
         << "\ncdf of Exponential Distribution with x = " << x << ", lambda = " << scaleParameter1 << " is " << cdf(myExponential1, x) << endl;

    // use a another type instead of double
    cout << "\nUsing type float instead of default type double:" << endl;

    // initialize another scaleParameter with type float
    float scaleParameter2 = 0.5;

    // initialize Exponential Distribution with type float
    exponential_distribution<float> myExponential2(scaleParameter2);

    // print out the mean and the standard deviation 
    cout << "Mean " << mean(myExponential2)
         << ", Standard Deviation: " << standard_deviation(myExponential2) << endl;

    // calculate and print out the pdf and cdf
    cout << "\npdf of Exponential Distribution with x = " << x << ", lambda = " << scaleParameter2 << " is " << pdf(myExponential2, x) 
         << "\ncdf of Exponential Distribution with x = " << x << ", lambda = " << scaleParameter2 << " is " << cdf(myExponential2, x) << endl;


    // choose precision
    cout.precision(10);

    // other properties
    cout << "\nOther Propertirs of Exponential Distribution: \n";
	cout << "mean: " << mean(myExponential1) << endl;
	cout << "variance: " << variance(myExponential1) << endl;
	cout << "median: " << median(myExponential1) << endl;
	cout << "mode: " << mode(myExponential1) << endl;
	cout << "kurtosis excess: " << kurtosis_excess(myExponential1) << endl;
	cout << "kurtosis: " << kurtosis(myExponential1) << endl;
	cout << "characteristic function: " << chf(myExponential1, x) << endl;
	cout << "hazard: " << hazard(myExponential1, x) << endl;





    //Poisson Distribution
    cout << "\n\nDisplaying Poisson Distribution: " << endl;
    // initialize lambda parameter for Poisson Distribution
    double lambda = 3.0;
    // initialize Poisson Distribution
    poisson_distribution<double> myPoisson(lambda);
    
    // print out the mean and the standard deviation
    cout << "Mean " << mean(myPoisson)
         << ", Standard Deviation: " << standard_deviation(myPoisson) << endl;
    
    // this is because the number of event k has to be a non-negative integer in Poisson Distribution
    unsigned int k = 1;
    // calculate and print out the pdf and cdf 
    cout << "pdf of Poisson Distribution with k = " << k << ", lambda = " << lambda << " is " << pdf(myPoisson, k) 
         << "\ncdf of Poisson Distribution with k = " << k << ", lambda = " << lambda << " is " << cdf(myPoisson, k) << endl;


    // initialize 2 lists to store the pdf and cdf at different values
    // of random variables
    vector<double> pdfList;
    vector<double> cdfList;

    // initialize a start value for random variable
    double start = 0.0;
    // initialize an end value for random variable
    double end = 10.0;
    // initialize a number of intervals
    long numInterval = 30;
    // assign a start value 
    double val = start;
    // calculate the increment of each interval
    double delta = (end - start) / double(numInterval);

    cout << endl;
    // for each interval
    for (long i = 0; i != numInterval; ++i)
    {
        // calculate and push the pdf and cdf to their
        // corresponding lists
        pdfList.push_back(pdf(myPoisson, val));
        cdfList.push_back(cdf(myPoisson, val));
        val += delta;
    }

    // print out the pdf list
    cout << "pdf list: ";
    for (long i = 0; i < pdfList.size(); ++i)
    {
        cout << pdfList[i] << ", ";
    }

    // print out the cdf list
    cout << "\n\ncdf list: ";
    
    for (long i = 0; i < cdfList.size(); ++i)
    {
        cout << cdfList[i] << ", ";
    }

    return 0;

}