#include "pch.h"
#ifndef LinAlg_HEADER
#define LinAlg_HEADER
template<class _TVal>
class LinAlg
{
public:
	static vector<vector<_TVal>> matrixMultiply(vector<vector<_TVal>> first, vector<vector<_TVal>> second);
	static double OptimizedParallelMultiply(const _TVal** matrixA, const _TVal** matrixB, _TVal** matrixC, int dimension);
};


#endif