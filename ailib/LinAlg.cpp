#include "LinAlg.h"

template<class _TVal>
vector<vector<_TVal>> LinAlg<_TVal>::MatrixMultiply(vector<vector<_TVal>> first, vector<vector<_TVal>> second)
{
	vector<vector<_TVal>> result;

	for (size_t i = 0; i < first[0].size(); i++)
	{
		vector<_TVal> temp;
		for (size_t j = 0; j < second.size(); j++)
		{
			

			_TVal sum = 0;

			for (size_t k = 0; k < second[0].size(); k++)
			{
				sum += first[i][k] * second[k][j];
			}

			temp.push_back(sum);
		}
		result.push_back(temp);
	}


	return result;
}

template<class _TVal>
vector<vector<_TVal>> LinAlg<_TVal>::MatrixVectorDecrise(vector<vector<_TVal>> matrix, vector<_TVal> vect)
{
	if (vect.size() == matrix[0].size())
	{
		vector<vector<_TVal>> result;
		for (size_t t = 0; t < matrix.size(); t++)
		{
			vector<_TVal> temp;
			for (size_t i = 0; i < vect.size(); i++)
			{
				temp.push_back(matrix[t][i] - vect[i]);
			}
			result.push_back(temp);
		}
		return result;
	}
	return vector<vector<_TVal>>();

}

template<class _TVal>
vector<vector<_TVal>> LinAlg<_TVal>::MatrixSquare(vector<vector<_TVal>> matrix)
{
	vector<vector<_TVal>> res;

	for (size_t i = 0; i < matrix.size(); i++)
	{
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			matrix[i][j] *= matrix[i][j];
		}
	}

	return res;
}

template<class _TVal>
vector<vector<_TVal>> LinAlg<_TVal>::SumBy2thAxis(vector<vector<_TVal>> matrix)
{
	vector<vector<_TVal>> res;

	for (size_t i = 0; i < matrix.size(); i++)
	{
		double sum = 0;
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			sum += matrix[i][j];
		}
		vector<double> temp;
		temp.push_back(sum);
		res.push_back(temp);
	}
	return res;
}

template<class _TVal>
vector<vector<_TVal>> LinAlg<_TVal>::MultiplyMatrixBy2thAxis(vector<vector<_TVal>> matrix, _TVal scalar)
{
	vector<vector<_TVal>> res;

	for (size_t i = 0; i < matrix.size(); i++)
	{
		vector<double> temp;
		for (size_t j = 0; j < matrix[0].size(); j++)
		{
			temp.push_back(matrix[i][j] * scalar);
		}

		temp.push_back(sum);
		res.push_back(temp);
	}
	return res;
}