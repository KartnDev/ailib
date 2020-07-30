#include "pch.h"
#include "mathutils.h"

double ktstd::Math::StdEuclideanDist(double point1[DIMENTIONS], double point2[DIMENTIONS]) noexcept
{
	double sum = 0;
	for (size_t i = 0; i < DIMENTIONS; i++)
	{
		sum += (point1[i] - point2[i]) * (point1[i] - point2[i]); //  (p-q)^2
	}

	return sqrt(sum);
}

double ktstd::Math::StdEuclideanDist(std::vector<double> point1, std::vector<double> point2)
{
	if (point1.size() == point2.size())
	{
		double sum = 0;
		for (size_t i = 0; i < point1.size(); i++)
		{
			sum += (point1[i] - point2[i]) * (point1[i] - point2[i]); //  (p-q)^2
		}

		return sqrt(sum);
	}
	else
	{
		throw new std::exception("pointsof the distanse in different dimentions!");
	}
}
double ktstd::Math::StdEuclideanDist(std::vector<string> point1, std::vector<string> point2)
{
	if (point1.size() == point2.size())
	{
		double sum = 0;
		for (size_t i = 0; i < point1.size(); i++)
		{
			sum += (stod (point1[i]) - stod (point2[i])) * (stod (point1[i]) - stod (point2[i])); //  (p-q)^2
		}

		return sqrt(sum);
	}
	else
	{
		throw new std::exception("pointsof the distanse in different dimentions!");
	}
}