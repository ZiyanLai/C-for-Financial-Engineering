/*
 * fileName:          Option.cpp
 * @author:           Ziyan Lai <ziyanlai97@outlook.com>
 * @lastModifiedBy:   Ziyan Lai
 * @createdDate:      2020-06-10
 * @lastModifiedDate: 2020-06-10
 * Copyright © 2020 Ziyan Lai. All rights reserved.
*/

/* Implementation of the Option base class */


#include "Option.hpp"
#include <iostream>
using namespace std;

// initialize all parameters to 0
void Option::init()
{
	T = 0;
	K = 0;
	sig = 0;
	r = 0;
	U = 0;
	b = 0; 

}

// default constructor
Option::Option()
{
	// call the init() function
	init();
}

// constructor that takes full parameters
Option::Option(double newT, double newK, double newSig, double newR, double newB, double newU) : T(newT), K(newK), sig(newSig), 
																												 r(newR), b(newB), U(newU) {}

// copy function
void Option::copy(const Option& source)
{
	// copy over each value from the source
	T = source.T;
	K = source.K;
	sig = source.sig;
	r = source.r;
	U = source.U;
	b = source.b;
}

// constructor that takes a struct
Option::Option(const struct OptionData& sourceData) : T(sourceData.T), K(sourceData.K), sig(sourceData.sig), 
																      r(sourceData.r), U(sourceData.U), b(sourceData.b) {}


// copy constructor
Option::Option(const Option& source)
{
	// call the copy function to copy over data
	copy(source);
}

// destructor
Option::~Option() {}

// assignment operator
Option& Option::operator=(const Option& rhs)
{
	// if self assignment
	if (this == &rhs)
	{
		// return this object
		return *this;
	}

	// if not, call the copy function to copy from right hand side
	copy(rhs);
	// return this object
	return *this;

}

// helper function to print the enum to string
string enumToString(const enum ParamType& paramType)
{
	switch (paramType)
	{
	case Stock:
		return "S";
	case Strike:
		return "K";
	case Time:
		return "T";
	case IntRate:
		return "r";
	case COC:
		return "b";
	case Vol:
		return "Sig";
	default:
		return "Invalid Parameter";
	}

}

// global function to generate a mesh
vector<double> generateMesh(double start, double end, int meshSize)
{
	// initialize a vector of double to store the mesh
	vector<double> mesh;

	// calculate the stepsize
	double stepSize = (end - start) / double(meshSize);

	// set the current position to the start value
	double curr = start;

	// iterate through the number of mesh size
	for(int i = 0; i != meshSize + 1; ++i)
	{
		// push the current value into the mesh
		mesh.push_back(curr);
		// increment current by the stepSize
		curr += stepSize;
	}
	// return the mesh
	return mesh;
}

