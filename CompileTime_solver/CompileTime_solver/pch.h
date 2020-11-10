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
	int iterator;

public:

	constexpr CompileTimeSolver(double Down, double Up, int MeshDepth) : sum(0), step(0), currentPoint(0),
		nextPoint(0), bottom(Down), top(Up), pointsNumber(MeshDepth), iterator(0)
	{}

	constexpr CompileTimeSolver(double Down, double Up, int MeshDepth, double (*function)(double x)) : step((Up - Down) / (MeshDepth - 1)),
		currentPoint(Down),	nextPoint(0), bottom(Down), top(Up), pointsNumber(MeshDepth), iterator(0), sum(0)
	{
		while (iterator < MeshDepth)
		{
			nextPoint = currentPoint + step;
			sum += (function(currentPoint) + function(nextPoint));
			currentPoint = nextPoint;
			++iterator;
		}
		sum *= 0.5 * step ;
	}

	CompileTimeSolver() : sum(0), step(0), currentPoint(0),
		nextPoint(0), bottom(0), top(0), pointsNumber(0), iterator(0)
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
	double tellSum()
	{
		return this->sum;
	}

};

template <typename T2>
class Output
{
private:
	T2 arg;
	T2 dynArg;
public:

	constexpr Output(T2& argument):arg(argument)
	{}

	constexpr Output()
	{}
	void getArg(T2 argument)
	{
		this->arg = argument;
	}
	constexpr 	void getDyntArg(T2 argument)
	{
		this->dynArg = argument;
	}
	void show()
	{
		cout << this->arg << endl;
	}
	void showDyn()
	{
		cout << this->dynArg << endl;
	}
};

//template <typename T2>
//class Output<T2>::	constexpr Output(T2& argument) :arg(argument)
//{}
//#include "Output.cpp"