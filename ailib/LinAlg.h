#include "pch.h"
#ifndef LinAlg_HEADER
#define LinAlg_HEADER
template<class _TVal>
class LinAlg
{
public:
	static vector<vector<_TVal>> MatrixMultiply(vector<vector<_TVal>> first, vector<vector<_TVal>> second);
	static vector<vector<_TVal>> MatrixVectorDecrise(vector<vector<_TVal>> matrix, vector<_TVal> vector);
	static vector<vector<_TVal>> MatrixSquare(vector<vector<_TVal>> matrix);
	static vector<vector<_TVal>> SumBy2thAxis(vector<vector<_TVal>> matrix);
	static vector<vector<_TVal>> MultiplyMatrixBy2thAxis(vector<vector<_TVal>> matrix, _TVal scalar);
	static vector<vector<_TVal>> AddMatrixBy2thAxis(vector<vector<_TVal>> matrix, _TVal scalar);
	static vector<vector<_TVal>> MatrixExp(vector<vector<_TVal>> matrix);
	static vector<vector<_TVal>> MatrixPow(vector<vector<_TVal>> matrix, int power);
	static vector<vector<_TVal>> Transponse(vector<vector<_TVal>> matrix);
	static double OptimizedParallelMultiply(const _TVal** matrixA, const _TVal** matrixB, _TVal** matrixC, int dimension);
};


#endif