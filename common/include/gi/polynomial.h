#pragma once

namespace archer
{
	namespace gi 
	{
		struct IPolynomialItem
		{
			double _coefficient;
		};

		template <int degree>
		class polynomial_item : public IPolynomialItem
		{

		public:
			polynomial_item() : _coefficient(0.) {}
			polynomial_item(const polynomial_item<degree>& item) : _coefficient(item._coefficient) {}
			polynomial_item(double coefficient) : _coefficient(coefficient) {}

		public:
			int GetDegree() const { return degree; }

			polynomial_item<degree> operator+(const polynomial_item<degree>& item)
			{
				return polynomial_item<degree>(_coefficient + item._coefficient);
			}

			polynomial_item<degree> operator-(const polynomial_item<degree>& item)
			{
				return polynomial_item<degree>(_coefficient - item._coefficient);
			}

			template <int degree2>
			polynomial_item<degree+degree2> operator*(const polynomial_item<degree2>& item)
			{
				return polynomial_item<degree+degree2>(_coefficient * item._coefficient);
			}

			template <int degree2>
			polynomial_item<degree-degree2> operator/(const polynomial_item<degree2>& item)
			{
				return polynomial_item<degree-degree2>(_coefficient / item._coefficient);
			}

			polynomial_item<degree> operator*(double x)
			{
				return polynomial_item<degree>(_coefficient * x);
			}

			polynomial_item<degree> operator/(double x)
			{
				return polynomial_item<degree>(_coefficient / x);
			}

			const polynomial_item<degree>& operator+=(const polynomial_item<degree>& item)
			{
				_coefficient += item._coefficient;
				return *this;
			}

			const polynomial_item<degree>& operator-=(const polynomial_item<degree>& item)
			{
				_coefficient -= item._coefficient;
				return *this;
			}

			const polynomial_item<degree>& operator*=(double x)
			{
				_coefficient *= x;
				return *this;
			}

			const polynomial_item<degree>& operator/=(double x)
			{
				_coefficient /= x;
				return *this;
			}
		};

		template <int degree>
		class polynomial
		{
		public:

			polynomial(void)
			{
			}

			virtual ~polynomial(void)
			{
			}
		};
	}
}
