// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.hpp" 
#include "UtilitiesDJD/RNG/NormalGenerator.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include <cmath>
#include <iostream>
using namespace std;

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	std::cout << std::endl << "Size of vector is " << l.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	std::vector<T>::const_iterator i;
	for (i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace



// declare to use a template
template<typename T1, typename T2, typename T3>
// function to calculate standard deviation
double StandardDeviation(const T1& valHistory, T2 r, T3 T)
{
	// initialize two helper variables
	double sumSqrVal = 0;
	double sumVal = 0;

	// initialize M, which is the number of elements in the valHistory vector
	long M = valHistory.size();

	// for each element in the vector
	for (int i = 0; i != M; ++i)
	{
		// calculate sum of square of option value
		sumSqrVal += pow(valHistory[i], 2);
		// calculate sum of option value
		sumVal += valHistory[i];
	}

	// calculate the standard deviation and return
	return sqrt((sumSqrVal - (1 / M) * pow(sumVal,2)) / (M - 1)) * exp(-r * T);
}


// declare to use a template
template<typename T1, typename T2, typename T3>
// function to calculate standard error
double StandardError(const T1& valHistory, T2 r, T3 T)
{
	// initialize M, which is the number of elements in the ValHistory vector
	long M = valHistory.size();

	// calculate the standard deviation by calling that fuction, 
	// then divided by square root of M
	// and return this value
	return StandardDeviation<vector<double>, double, double>(valHistory, r, T) / sqrt(M);
}

int main()
{
	std::cout <<  "1 factor MC with explicit Euler\n";

	// initialize Batch1 data
	OptionData Batch1;
	Batch1.K = 65.0;
	Batch1.T = 0.25;
	Batch1.r = 0.08;
	Batch1.sig = 0.3;
	Batch1.type = 1; // Batch1.type = -1; Put -1, Call +1
	
	// initialize Batch2 data
	OptionData Batch2;
	Batch2.K = 100.0;
	Batch2.T = 1.0;
	Batch2.r = 0.0;
	Batch2.sig = 0.2;
	Batch2.type = -1; // Batch2.type = -1; Put -1, Call +1

	// initialize myOption
	OptionData myOption;
	
	// set myOption equals to Batch1 or Batch2
	myOption = Batch1;	// myOption = Batch2

	double S_0 = 60; // double S_0 = 100;

	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	double VOld = S_0;
	double VNew;

	std::vector<double> x = range.mesh(N);
	

	// V2 mediator stuff
	long NSim = 50000;
	std::cout << "Number of simulations: ";
	std::cin >> NSim;

	double k = myOption.T / double (N);
	double sqrk = sqrt(k);

	// Normal random number
	double dW;
	double price = 0.0;	// Option price

	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	SDEDefinition::data = &myOption;

	/*std::vector<double> res;*/
	int coun = 0; // Number of times S hits origin

	// create a vector of double to store the value history
	vector<double> valueHistory;

	// A.
	for (long i = 1; i <= NSim; ++i)
	{ // Calculate a path at each iteration
			
		if ((i/10000) * 10000 == i)
		{// Give status after each 10000th iteration

				std::cout << "current iteration: " << i << "\n\n";
		}

		VOld = S_0;
		for (unsigned long index = 1; index < x.size(); ++index)
		{

			// Create a random number
			dW = myNormal->getNormal();
				
			// The FDM (in this case explicit Euler)
			VNew = VOld  + (k * drift(x[index-1], VOld))
						+ (sqrk * diffusion(x[index-1], VOld) * dW);

			VOld = VNew;

			// Spurious values
			if (VNew <= 0.0) coun++;
		}
		
		// calculate the current option value
		double tmp = myOption.myPayOffFunction(VNew);

		// push the current option value into valueHistory
		valueHistory.push_back(tmp);

		price += (tmp)/double(NSim);

		// calculate the standard deviation and standard error every 5000 iterations 
		if ((i / 5000) * 5000 == i)
		{
			// call the generic function to calculate standard deviation
			double SD = StandardDeviation<vector<double>, double, double>(valueHistory, myOption.r, myOption.T);
			
			// call the generic function to calculate standard error
			double SE = StandardError<vector<double>, double, double>(valueHistory, myOption.r, myOption.T);

			// print the result
			cout << "Up to iteration " << i << ", Standard Deviation: " << SD << "; Standard Error:  " << SE << "\n\n";
		}
	}
	
	// D. Finally, discounting the average price
	price *= exp(-myOption.r * myOption.T);

	// Cleanup; V2 use scoped pointer
	delete myNormal;

	std::cout << "Price, after discounting: " << price << ", " << std::endl;
	std::cout << "Number of times origin is hit: " << coun << endl;

	return 0;
}