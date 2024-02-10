// CMakeProject1.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.
// --------------------------------------------------------------------------------------------------------------------
// Вариант 2.
// Поиск минимального и максимального значений.
// Входные данные: набор чисел.
// Выходные данные: минимальное и максимальное значения чисел из входного набора.
// --------------------------------------------------------------------------------------------------------------------

#include <algorithm>
#include <iostream>
#include <limits> 
#include <cmath>
#include "tminmax.h"

// --------------------------------------------------------------------------------------------------------------------

TMinMax::TMinMax(int szArr)
{
	if (szArr <= 0) {
		std::cout << "Invalid array size: " << szArr << '\n'; exit(1);
	}
	if (!(pData = new double[sizeArray = szArr])) { //?
		std::cout << "Memory allocation failure\n"; exit(1);
	}
	sizeArray = szArr;
}

TMinMax::~TMinMax()
{
	delete[] pData;
}

// --------------------------------------------------------------------------------------------------------------------

double TMinMax::GetMinValue() const
{
	return minValue;
}

double TMinMax::GetMaxValue() const
{
	return maxValue;
}

// --------------------------------------------------------------------------------------------------------------------

std::istream& operator >> (std::istream& in, TMinMax& tMinMax) {
	for (int i = tMinMax.sizeArray - 1; i >= 0; i--) in >> tMinMax.pData[i];

	tMinMax.minValue = *std::min_element(tMinMax.pData, tMinMax.pData + tMinMax.sizeArray);
	tMinMax.maxValue = *std::max_element(tMinMax.pData, tMinMax.pData + tMinMax.sizeArray);

	return in;
}

std::ostream& operator<<(std::ostream& out, TMinMax& tMinMax)
{
	std::cout << "max: " << tMinMax.GetMaxValue() << "\nmin: " << tMinMax.GetMinValue() << '\n';

	return out;
}

// --------------------------------------------------------------------------------------------------------------------

int main()
{
	int n; 
	std::cin >> n;

	TMinMax a(n);
	std::cin >> a;
	std::cout << a;
	
//	std::cout << "Hello CMake." << '\n';
	return 0;
}
