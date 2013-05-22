#ifndef __GI_POINT_H__
#define __GI_POINT_H__

namespace archer
{
	namespace gi
	{
		template <typename TYPE, int dimension = 2>
		class point : public point<TYPE, dimension-1>
		{
		public:
			TYPE _d;

		public:
			point() {}
			virtual ~point() {}

		public:
			template <int n>
			inline TYPE d() const
			{ return this->point<TYPE, n>::_d; }

			template <int n>
			inline TYPE& d()
			{ return this->point<TYPE, n>::_d; }

			template <>
			inline TYPE d<1>() const
			{ return _x; }

			template <>
			inline TYPE& d<1>()
			{ return _x; }

			template <>
			inline TYPE d<2>() const
			{ return _y; }

			template <>
			inline TYPE& d<2>()
			{ return _y; }

			template <>
			inline TYPE d<3>() const
			{ return _z; }

			template <>
			inline TYPE& d<3>()
			{ return _z; }

			template <>
			inline TYPE d<4>() const
			{ return _w; }

			template <>
			inline TYPE& d<4>()
			{ return _w; }
		};

		template <typename TYPE>
		class point<TYPE, 0>
		{
		public:
			point() {}
			virtual ~point() {}
		};

		template <typename TYPE>
		class point<TYPE, 1> : public point<TYPE, 0>
		{
		public:
			TYPE _x;

		public:
			point() : _x(0) {}
			virtual ~point() {}

		public:
			template <int n>
			inline TYPE d() const;

			template <int n>
			inline TYPE& d();

			template <>
			inline TYPE d<1>() const
			{ return _x; }

			template <>
			inline TYPE& d<1>()
			{ return _x; }
		};

		template <typename TYPE>
		class point<TYPE, 2> : public point<TYPE, 1>
		{
		public:
			TYPE _y;

		public:
			point() : point<TYPE, 1>(), _y(0) {}
			virtual ~point() {}

		public:
			template <int n>
			inline TYPE d() const;

			template <int n>
			inline TYPE& d();

			template <>
			inline TYPE d<1>() const
			{ return _x; }

			template <>
			inline TYPE& d<1>()
			{ return _x; }

			template <>
			inline TYPE d<2>() const
			{ return _y; }

			template <>
			inline TYPE& d<2>()
			{ return _y; }
		};

		template <typename TYPE>
		class point<TYPE, 3> : public point<TYPE, 2>
		{
		public:
			TYPE _z;

		public:
			point() : point<TYPE, 2>(), _z(0) {}
			virtual ~point() {}

		public:
			template <int n>
			inline TYPE d() const;

			template <int n>
			inline TYPE& d();

			template <>
			inline TYPE d<1>() const
			{ return _x; }

			template <>
			inline TYPE& d<1>()
			{ return _x; }

			template <>
			inline TYPE d<2>() const
			{ return _y; }

			template <>
			inline TYPE& d<2>()
			{ return _y; }

			template <>
			inline TYPE d<3>() const
			{ return _z; }

			template <>
			inline TYPE& d<3>()
			{ return _z; }
		};

		template <typename TYPE>
		class point<TYPE, 4> : public point<TYPE, 3>
		{
		public:
			TYPE _w;

		public:
			point() : point<TYPE, 3>(), _w(0) {}
			virtual ~point() {}

		public:
			template <int n>
			inline TYPE d() const;

			template <int n>
			inline TYPE& d();

			template <>
			inline TYPE d<1>() const
			{ return _x; }

			template <>
			inline TYPE& d<1>()
			{ return _x; }

			template <>
			inline TYPE d<2>() const
			{ return _y; }

			template <>
			inline TYPE& d<2>()
			{ return _y; }

			template <>
			inline TYPE d<3>() const
			{ return _z; }

			template <>
			inline TYPE& d<3>()
			{ return _z; }

			template <>
			inline TYPE d<4>() const
			{ return _w; }

			template <>
			inline TYPE& d<4>()
			{ return _w; }
		};

		typedef point<double, 1> point_1d;
		typedef point<double, 2> point_2d;
		typedef point<double, 3> point_3d;
		typedef point<double, 4> point_4d;
	}
}

#endif // __GI_POINT_H__
