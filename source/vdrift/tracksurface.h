#ifndef _TRACKSURFACE_H
#define _TRACKSURFACE_H

#include <string>
#include <assert.h>
#include "cartire.h"

const static char csTRKsurf[8/*NumTypes*/][10] =
{	"[none]", "Asphalt", "Grass", "Gravel", "Concrete", "Sand", "Cobbles", "[all]"	};

class TRACKSURFACE
{
public:
	enum TYPE
	{	NONE=0, ASPHALT, GRASS, GRAVEL, CONCRETE, SAND, COBBLES, NumTypes	};

	TYPE type;
	float bumpWaveLength, bumpAmplitude;
	float frictionTread;  //, frictionNonTread;
	float rollingDrag;  //, rollResist;
	std::string name, tireName;  // .tire file source (without ".tire")

	CARTIRE* tire;  /// tire params set
	
	static CARTIRE* pTireDefault;
	
	TRACKSURFACE() :
		type(GRASS),
		bumpWaveLength(10.f), bumpAmplitude(0.f),
		frictionTread(1.0f), //frictionNonTread(0.9f),
		rollingDrag(1.f), //rollResist(1.f),
		tireName("DEFAULT"),
		tire(CARTIRE::None())
	{	}
	
	void setType(unsigned int i)
	{
		type = i < NumTypes ? (TYPE)i : NumTypes;
	}

	bool operator==(const TRACKSURFACE& t) const
	{
		return (type == t.type)
			&& (bumpWaveLength == t.bumpWaveLength)	&& (bumpAmplitude == t.bumpAmplitude)
			&& (frictionTread == t.frictionTread) //&& (frictionNonTread == t.frictionNonTread)
			//&& (rollResist == t.rollResist)
			&& (rollingDrag == t.rollingDrag) && (tire == t.tire);
	}
	
	static const TRACKSURFACE * None()
	{
		static const TRACKSURFACE s;
		return &s;
	}
};

#endif //_TRACKSURFACE_H
