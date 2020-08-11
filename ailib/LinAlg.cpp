#include "LinAlg.h"

template<class _TVal>
vector<vector<_TVal>> LinAlg<_TVal>::matrixMultiply(vector<vector<_TVal>> first, vector<vector<_TVal>> second)
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

