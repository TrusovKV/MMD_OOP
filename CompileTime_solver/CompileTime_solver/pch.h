#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <cmath>
#include <math.h>
#include <gtest/gtest.h>

using namespace std;

constexpr double velosityProfile(double x) {
	return 0.3 * x * x + 2 * x - 1;
}

template <typename T1>
class CompileTimeSolver
{
private:
	double sum;
	double step;
	double currentPoint;
	double nextPoint;
	double bottom;
	double top;
	int pointsNumber;

public:

	constexpr CompileTimeSolver(double Down, double Up, int MeshDepth) : sum(0), step(0), currentPoint(0),
		nextPoint(0), bottom(Down), top(Up), pointsNumber(MeshDepth)
	{}
	CompileTimeSolver() : sum(0), step(0), currentPoint(0),
		nextPoint(0), bottom(0), top(0), pointsNumber(0)
	{
		cout << "Run-time constructor" << endl;
	}
	constexpr double Integrate(double (*function)(double x))
	{
		step = (top - bottom) / (pointsNumber - 1);
		currentPoint = bottom;
		for (int i = 0; i < pointsNumber; ++i)
		{
			nextPoint = currentPoint + step;
			sum += (function(currentPoint) + function(nextPoint));
			currentPoint = nextPoint;
		}
		return 0.5 * sum * step;
	}


};

template <typename T2>
class Output
{
private:
	T2 arg;
public:

	constexpr Output(T2& argument):arg(argument)
	{}

	constexpr Output()
	{}
	void getArg(T2 argument)
	{
		this->arg = argument;
	}
	constexpr 	void getConstArg(T2 argument)
	{
		this->arg = argument;
	}
	void show()
	{
		cout << this->arg << endl;
	}
};

//template <typename T2>
//class Output<T2>::	constexpr Output(T2& argument) :arg(argument)
//{}
//#include "Output.cpp"