#ifndef __GI_ENV_H__
#define __GI_ENV_H__

namespace archer
{
	namespace gi
	{
		const double EPS1		= 0.1;
		const double EPS2		= 0.01;
		const double EPS3		= 0.001;
		const double EPS4		= 0.0001;
		const double EPS5		= 0.00001;
		const double EPS6		= 0.000001;
		const double EPS7		= 0.0000001;
		const double EPS8		= 0.00000001;
		const double EPS9		= 0.000000001;
		const double EPS10		= 0.0000000001;
		const double EPS11		= 0.00000000001;
		const double EPS12		= 0.000000000001;

		#ifdef	gi_using_torlerant_control
		double	gi_torlerant_X;
		double	gi_torlerant_Y;
		double	gi_torlerant_Z;
		double	gi_torlerant_Length;
		double	gi_torlerant_SquareLength;
		double	gi_torlerant_Angle;
		double	gi_torlerant_Area;
		double	gi_torlerant_Data;
		#else
		const double gi_torlerant_X				= EPS6;
		const double gi_torlerant_Y				= EPS6;
		const double gi_torlerant_Z				= EPS6;
		const double gi_torlerant_Length		= EPS6;
		const double gi_torlerant_SquareLength	= EPS12;
		const double gi_torlerant_Angle			= EPS4;
		const double gi_torlerant_Area			= EPS6;
		const double gi_torlerant_Data			= EPS6;
		#endif

		template <typename TYPE, TYPE eps>
		bool is_zero_eps(TYPE a)
		{ return a < esp && a > -eps; }

		template <typename TYPE>
		bool is_zero(TYPE a)
		{ return is_zero<TYPE, (TYPE) gi_torlerant_Length>(a); }

		template <typename TYPE, TYPE eps>
		bool is_equal_eps(TYPE a, TYPE b)
		{ return is_zero_eps<TYPE, eps>(a-b); }

		template <typename TYPE>
		bool is_equal(TYPE a, TYPE b)
		{ return is_zero<TYPE>(a-b); }
	}
}

#endif // __GI_ENV_H__
