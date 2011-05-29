#include "graphic/color.hpp"
#include <sstream>

namespace Gorgon{
namespace Graphic
{
	Color::Color()
	{
		mRed   = 0.0f;
		mGreen = 0.0f;
		mBlue  = 0.0f;
		mAlpha = 0.0f;
	}
	
	Color::Color
	(
		const float& pRed,
		const float& pGreen,
		const float& pBlue,
		const float& pAlpha
	)
	{
		setRed		( pRed   );
		setGreen	( pGreen );
		setBlue		( pBlue  );
		setAlpha	( pAlpha );
	}
	
	Color::Color(const Color& pColor)
	{
		mRed	= pColor.mRed;
		mGreen	= pColor.mGreen;
		mAlpha	= pColor.mBlue;
		mAlpha	= pColor.mAlpha;
	}

	std::string Color::describe()
	{
		std::stringstream out;
		out << "Graphic::Color::describe()"				<< std::endl;
		out << "Red:   " << (int)(getRed()   * 255.0f)	<< std::endl;
		out << "Green: " << (int)(getGreen() * 255.0f)	<< std::endl;
		out << "Blue:  " << (int)(getBlue()  * 255.0f)	<< std::endl;
		out << "Alpha: " << (int)(getAlpha() * 255.0f) 	<< std::endl;
		return out.str();
	}
	

	Color Color::operator +(const Color& pColor) const
	{
		return Color
		(
			mRed   + pColor.mRed   ,
			mGreen + pColor.mGreen ,
			mBlue  + pColor.mBlue  ,
			mAlpha + pColor.mAlpha
		);
	}

	void Color::operator +=(const Color& pColor)
	{
		setRed   ( mRed   + pColor.mRed   );
		setGreen ( mGreen + pColor.mGreen );
		setBlue  ( mBlue  + pColor.mBlue  );
		setAlpha ( mAlpha + pColor.mAlpha );
	}

	Color Color::operator -(const Color& pColor) const
	{
		return Color
		(
			mRed   - pColor.mRed   ,
			mGreen - pColor.mGreen ,
			mBlue  - pColor.mBlue  ,
			mAlpha - pColor.mAlpha
		);
	}

	void Color::operator -=(const Color& pColor)
	{
		setRed   ( mRed   - pColor.mRed   );
		setGreen ( mGreen - pColor.mGreen );
		setBlue  ( mBlue  - pColor.mBlue  );
		setAlpha ( mAlpha - pColor.mAlpha );
	}

	Color Color::operator *(const Color& pColor) const
	{
		return Color
		(
			mRed   * pColor.mRed   ,
			mGreen * pColor.mGreen ,
			mBlue  * pColor.mBlue  ,
			mAlpha * pColor.mAlpha
		);
	}
	
	void Color::operator *=(const Color& pColor)
	{
		setRed   ( mRed   * pColor.mRed   );
		setGreen ( mGreen * pColor.mGreen );
		setBlue  ( mBlue  * pColor.mBlue  );
		setAlpha ( mAlpha * pColor.mAlpha );
	}

	Color Color::operator /(const Color& pColor) const
	{
		return Color
		(
			mRed   / pColor.mRed   ,
			mGreen / pColor.mGreen ,
			mBlue  / pColor.mBlue  ,
			mAlpha / pColor.mAlpha
		);
	}
	
	void Color::operator /=(const Color& pColor)
	{
		setRed   ( mRed   / pColor.mRed   );
		setGreen ( mGreen / pColor.mGreen );
		setBlue  ( mBlue  / pColor.mBlue  );
		setAlpha ( mAlpha / pColor.mAlpha );
	}
	
	bool Color::operator ==(const Color& pColor) const
	{
		return
		(
			mRed   == pColor.mRed   &&
			mGreen == pColor.mGreen &&
			mBlue  == pColor.mBlue  &&
			mAlpha == pColor.mAlpha
		);
	}
	
	bool Color::operator !=(const Color& pColor) const
	{
		return
		!(
			mRed   == pColor.mRed   &&
			mGreen == pColor.mGreen &&
			mBlue  == pColor.mBlue  &&
			mAlpha == pColor.mAlpha
		);
	}
}}

