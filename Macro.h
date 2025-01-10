#pragma once

#include "random"
#include <iostream>
#include <vector>

using namespace std;


static int GetRandomNumberInRange(const int _min, const int _max)
{
	random_device _rSeed; // Obtient un graine al�atoire
	mt19937 _gen(_rSeed()); // Initialise le g�n�rateur avec la graine
	uniform_int_distribution<> _distr(_min, _max); // D�finit la distribution (les limites)

	return _distr(_gen); // G�n�ration du nombre
}

template<typename T>
T GetRandomNumberInRange(const vector<T>& _vector)
{
	return _vector[GetRandomNumberInRange(0, static_cast<int>(_vector.size()) - 1)];
}