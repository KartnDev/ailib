template<typename _TVal>
class Mixin 
{
	virtual double Score(_TVal** X, int* y, double* sample_weight = nullptr) = 0;
};
