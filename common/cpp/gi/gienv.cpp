////////////////////////////////////////////////////////////////////////////////
//
// namespace archer::gi
//     geometry interface
// gienv.cpp
//     set up geometry environment for archer::gi
//
// authored by: Jimmy
//
////////////////////////////////////////////////////////////////////////////////

#ifdef gi_using_torlerant_control

namespace archer 
{
	namespace gi 
	{
		double gi_torlerant_X				= EPS6;
		double gi_torlerant_Y				= EPS6;
		double gi_torlerant_Z				= EPS6;
		double gi_torlerant_Length			= EPS6;
		double gi_torlerant_SquareLength	= EPS12;
		double gi_torlerant_Angle			= EPS4;
		double gi_torlerant_Area			= EPS6;
		double gi_torlerant_Data			= EPS6;
	}
}

#endif

////////////////////////////////////////////////////////////////////////////////
