#pragma once

namespace archer
{
	namespace gi
	{
		template <typename TYPE, int m, int n>
		class dimension : public dimension<TYPE, m, n-1>
		{
		private:
			point<TYPE, m> _vector;

		public:
			dimension() : dimension<TYPE, m, n-1>() {}
			virtual ~dimension() {}

		public:
			template <int row>
			point<TYPE, m> vector()
			{ return this->dimension<TYPE, m, row>::_vector; }

			template <int row>
			point<TYPE, m>& vector()
			{ return this->dimension<TYPE, m, row>::_vector; }
		};

		template <typename TYPE, int m>
		class dimension<TYPE, m, 1>
		{
		private:
			point<TYPE, m> _vector;

		public:
			dimension() : _vector() {}
			virtual ~dimension() {}

		public:
			template <int row>
			point<TYPE, m> vector();

			template <int row>
			point<TYPE, m>& vector();

			template <>
			point<TYPE, m> vector<1>()
			{ return _vector; }

			template <>
			point<TYPE, m>& vector<1>()
			{ return _vector; }
		};
	}
}
