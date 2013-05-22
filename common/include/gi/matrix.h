p0#ifndef __GI_MATRIX_H__
#define __GI_MATRIX_H__

namespace archer
{
	namespace gi
	{
		template <typename TYPE, int m, int n>
		class matrix : public matrix<TYPE, m, n-1>
		{
		private:
			point<TYPE, m> _vector;

		public:
			matrix() : matrix<TYPE, m, n-1>() {}
			virtual ~matrix() {}

		public:
			template <int row>
			point<TYPE, m> vector()
			{ return this->matrix<TYPE, m, row>::_vector; }

			template <int row>
			point<TYPE, m>& vector()
			{ return this->matrix<TYPE, m, row>::_vector; }
		};

		template <typename TYPE, int m>
		class matrix<TYPE, m, 1>
		{
		private:
			point<TYPE, m> _vector;

		public:
			matrix() : _vector() {}
			virtual ~matrix() {}

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

		template <typename TYPE, int n>
		class square_matrix : public matrix<TYPE, n, n>
		{
		};
	}
}

#endif // __GI_MATRIX_H__
