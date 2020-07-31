#include "pch.h"
#include "mathutils.h"


double ktstd::Math::StdEuclideanDist(int point1[], int point2[], int dim) noexcept
{
	double sum = 0;
	for (size_t i = 0; i < dim; i++)
	{
		sum += (point1[i] - point2[i]) * (point1[i] - point2[i]); //  (p-q)^2
	}

	return sqrt(sum);
}


double ktstd::Math::StdEuclideanDist(std::vector<int> point1, std::vector<int> point2)
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

double ktstd::Math::GetMinkowskiDistance(std::vector<int> point1, std::vector<int> point2, double r)
{
	double sum = 0.0;


	for (int i = 0; i < point1.size(); i++)
	{
		sum += pow((point1[i]) - (point2[i]), r);
	}

	return pow(sum, 1.0 / r);
}