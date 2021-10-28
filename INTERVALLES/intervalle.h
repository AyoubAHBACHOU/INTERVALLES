#pragma once
#include <iostream>
namespace algo {
	class intervalle
	{
	private:
		double binf;
		double bsup;
	public:
		intervalle(double a = 0, double b = 0);
		double min_interv() const;
		double max_interv()const;
		void afficher() const;
		bool operator[](double a) const;
		bool operator[](intervalle& i) const;
		intervalle& operator+(intervalle& i) const;
		intervalle& operator-(intervalle& i) const;

	};

}

