#pragma once
/*
-----------------------------------------------------------------------------
 File: ArrowEffects.h

 Desc: Functions that return properties of arrows based on StyleDef and PlayerOptions

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/


#include "GameConstantsAndTypes.h"
#include "StyleDef.h"

const int	ARROW_SIZE	= 64;
const float ARROW_GAP	= ARROW_SIZE;// + 2;


//	fYOffset is a vertical position in pixels relative to the center.
//	(positive if has not yet been stepped on, negative if has already passed).
//	The ArrowEffect is applied in this stage.
float ArrowGetYOffset( const PlayerNumber pn, float fNoteBeat );


//	fRotation is Z rotation of an arrow.  This will depend on the column of 
//	the arrow and possibly the Arrow effect and the fYOffset (in the case of 
//	EFFECT_DIZZY).
float ArrowGetRotation(	const PlayerNumber pn, int iCol, float fYOffset );


//	fYPos is the position of the note in pixels relative to the center.
//	(positive if has not yet been stepped on, negative if has already passed).
//	This value is fYOffset with bReverseScroll and fScrollSpeed factored in.
float ArrowGetYPos(	const PlayerNumber pn, float fYOffset );


//	fXPos is a horizontal position in pixels relative to the center of the field.
//	This depends on the column of the arrow and possibly the Arrow effect and
//	fYPos (in the case of EFFECT_DRUNK).
float ArrowGetXPos2( const PlayerNumber pn, int iCol, float fYPos );


//	fAlpha is the transparency of the arrow.  It depends on fYPos and the 
//	ArrowAppearance.
float ArrowGetAlpha( const PlayerNumber pn, float fYPos );

