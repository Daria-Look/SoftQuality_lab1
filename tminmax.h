// CMakeProject1.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.
// --------------------------------------------------------------------------------------------------------------------
// Вариант 2.
// Поиск минимального и максимального значений.
// Входные данные: набор чисел.
// Выходные данные: минимальное и максимальное значения чисел из входного набора.
// --------------------------------------------------------------------------------------------------------------------

#pragma once
#ifndef tminmax_H

#include <iostream>
#include <algorithm>

class TMinMax
{
public:
	TMinMax(int szArr);
	~TMinMax();

	double GetMinValue() const;
	double GetMaxValue() const;

	friend std::istream& operator >> (std::istream& in, TMinMax& tMinMax);
	friend std::ostream& operator << (std::ostream& out, TMinMax& tMinMax);

private:
	int sizeArray;
	double *pData;
	double minValue;
	double maxValue;
};

#endif // !tminmax_H