#include "intervalle.h"
using namespace algo;
using namespace std;

algo::intervalle::intervalle(double a, double b)
{
	if (a <= b)
	{
		this->binf = a;
		this->bsup = b;
	}
	else
	{
		this->binf = b;
		this->bsup = a;
	}
}

double algo::intervalle::min_interv() const
{
	return this->binf;
}

double algo::intervalle::max_interv() const
{
	return this->bsup;
}

void algo::intervalle::afficher() const
{
	cout << "[" << this->binf << "," << this->bsup << "]";
}

bool algo::intervalle::operator[](double a) const
{
	if (a >= this->binf && a <= this->bsup)
		return true;
	return false;
}

bool algo::intervalle::operator[](intervalle& i) const
{
	if (this->min_interv() <= i.min_interv() && this->max_interv() >= i.max_interv())
		return true;
	return false;
}


intervalle& algo::intervalle::operator+(intervalle& i) const
{

	if ((*this)[i])
		return *(new intervalle(*this));
	else if (i[(intervalle&)(*this)])
		return i;
	else
	{
		intervalle* inter;
		if ((*this)[i.min_interv()])
		{
			inter = new intervalle(this->min_interv(), i.max_interv());
			return *inter;
		}
		if (i[(this->min_interv())])
		{
			inter = new intervalle(i.min_interv(), this->max_interv());
			return *inter;
		}
		inter = new intervalle();
		return *inter;
	}

}

intervalle& algo::intervalle::operator-(intervalle& i) const
{
	if ((*this)[i])
		return i;
	else if (i[(intervalle&)(*this)])
		return *(new intervalle(*this));
	else
	{
		intervalle* inter;
		if ((*this)[i.min_interv()])
		{

			inter = new intervalle(i.min_interv(), this->max_interv());
			return *inter;
		}
		if (i[(this->min_interv())])
		{
			inter = new intervalle(this->min_interv(), i.max_interv());
			return *inter;
		}
		inter = new intervalle();
		return *inter;
	}

}