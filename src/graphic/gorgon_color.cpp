#include "graphic/gorgon_color.hpp"

namespace Gorgon
{
	Color::Color
	(
		const int& pRed,
		const int& pGreen,
		const int& pBlue,
		const int& pAlfa
	)
	{
		set
		(
			pRed,
			pGreen,
			pBlue,
			pAlfa
		);
	}

	Color::Color(const Color& pColor)
	{
		set
		(
			pColor.getRed(),
			pColor.getGreen(),
			pColor.getBlue(),
			pColor.getAlfa()
		);
	}

	Color::Color(const int& pColor)
	{
		setRed((pColor >> 16) & 255);
		setGreen((pColor >> 8) & 255);
		setBlue((pColor) & 255);
		setAlfa((pColor >> 24) & 255);
	}

	Color::~Color()
	{
	}

	std::string Color::describe()
	{
		std::stringstream out;
		out << "Color Descriptor"		<< std::endl;
		out << "Red:   " << getRed()	<< std::endl;
		out << "Green: " << getGreen()	<< std::endl;
		out << "Blue:  " << getBlue()	<< std::endl;
		out << "Alfa:  " << getAlfa()	<< std::endl;
		return out.str();
	}
	
	void Color::setRed(const int& pRed)
	{
		if(pRed >= 0)
		{
			if(pRed <= 255)
			{
				mRed = pRed;
			}
			else
			{
				mRed = 510 - pRed;
			}
		}
		else
		{
			mRed = 0;
		}
	}

	void Color::setGreen(const int& pGreen)
	{
		if(pGreen >= 0)
		{
			if(pGreen <= 255)
			{
				mGreen = pGreen;
			}
			else
			{
				mGreen = 510 - pGreen;
			}
		}
		else
		{
			mGreen = 0;
		}
	}

	void Color::setBlue(const int& pBlue)
	{
		if(pBlue >= 0)
		{
			if(pBlue <= 255)
			{
				mBlue = pBlue;
			}
			else
			{
				mBlue = 510 - pBlue;
			}
		}
		else
		{
			mBlue = 0;
		}
	}

	void Color::setAlfa(const int& pAlfa)
	{
		if(pAlfa >= 0)
		{
			if(pAlfa <= 255)
			{
				mAlfa = pAlfa;
			}
			else
			{
				mAlfa = 510 - pAlfa;
			}
		}
		else
		{
			mAlfa = 0;
		}
	}

	void Color::set
	(
		const int& pRed,
		const int& pGreen,
		const int& pBlue,
		const int& pAlfa
	)
	{
		setRed(pRed);
		setGreen(pGreen);
		setBlue(pBlue);
		setAlfa(pAlfa);
	}

	int Color::getRed() const
	{
		return mRed;
	}

	int Color::getGreen() const
	{
		return mGreen;
	}

	int Color::getBlue() const
	{
		return mBlue;
	}

	int Color::getAlfa() const
	{
		return mAlfa;
	}

	int Color::get() const
	{
		/**
		 * @todo verificar little endian
		 */
		return
		(
			(getBlue()	<< 0)	|
			(getGreen()	<< 8)	|
			(getRed()	<< 16)	|
			(getAlfa()	<< 24)
		);
	}

	Color Color::operator +(const Color& pColor) const
	{//tentar outra coisa... return *color
		return Color
		(
			getRed()	+ pColor.getRed(),
			getGreen()	+ pColor.getGreen(),
			getBlue()	+ pColor.getBlue(),
			getAlfa()	+ pColor.getAlfa()
		);
	}

	void Color::operator +=(const Color& pColor)
	{
		set
		(
			getRed()	+ pColor.getRed(),
			getGreen()	+ pColor.getGreen(),
			getBlue()	+ pColor.getBlue(),
			getAlfa()	+ pColor.getAlfa()
		);
	}

	Color Color::operator -(const Color& pColor) const
	{
		return Color
		(
			getRed()	- pColor.getRed(),
			getGreen()	- pColor.getGreen(),
			getBlue()	- pColor.getBlue(),
			getAlfa()	- pColor.getAlfa()
		);
	}

	void Color::operator -=(const Color& pColor)
	{
		set
		(
			getRed()	- pColor.getRed(),
			getGreen()	- pColor.getGreen(),
			getBlue()	- pColor.getBlue(),
			getAlfa()	- pColor.getAlfa()
		);
	}

	Color Color::operator *(const double& pValue) const
	{
		return Color
		(
			getRed()	* pValue,
			getGreen()	* pValue,
			getBlue()	* pValue,
			getAlfa()	* pValue
		);
	}

	Color Color::operator /(const double& pValue) const
	{
		return Color
		(
			getRed()	/ pValue,
			getGreen()	/ pValue,
			getBlue()	/ pValue,
			getAlfa()	/ pValue
		);
	}
	
	bool Color::operator ==(const Color& pColor) const
	{
		return
		(
			getRed()	== pColor.getRed()		&&
			getGreen()	== pColor.getGreen()	&&
			getBlue()	== pColor.getBlue()		&&
			getAlfa()	== pColor.getAlfa()
		);
	}
	bool Color::operator !=(const Color& pColor) const
	{
		return
		!(
			getRed()	== pColor.getRed()		&&
			getGreen()	== pColor.getGreen()	&&
			getBlue()	== pColor.getBlue()		&&
			getAlfa()	== pColor.getAlfa()
		);
	}
}
