#include <graphic/gorgon_mirroring.hpp>

namespace Gorgon{
namespace Graphic
{
	Mirroring::Mirroring(const Mirroring::Type& type)
	{
		mType = type;
	}

	const Mirroring::Type& Mirroring::getType() const
	{
		return mType;
	}

	void Mirroring::setType(const Mirroring::Type& type)
	{
		mType = type;
	}

	Mirroring& Mirroring::operator =(const Mirroring& mirroring)
	{
		setType(mirroring.getType());
		return *this;
	}

	Mirroring& Mirroring::operator =(const Mirroring::Type& mirroring)
	{
		setType(mirroring);
		return *this;
	}

	void Mirroring::operator += (const Mirroring& pMirroring)
	{
		//00000000	-> normal
		//00000001	-> horizontal
		//00000010	-> vertical
		//00000011	-> vertical e horizontal
		setType
		(
			static_cast<Mirroring::Type>
			(
				getType() ^ pMirroring.getType()
			)
		);
	}

	Mirroring Mirroring::operator + (const Mirroring& mirroring)
	{
		Mirroring out = (*this);
		out += mirroring;
		return out;
	}

	bool Mirroring::operator == (const Mirroring& mirroring)
	{
		return (getType() == mirroring.getType());
	}
}}
