#pragma once
/*
-----------------------------------------------------------------------------
 Class: NoteField

 Desc: A stream of ColorNotes that scrolls past Y==0.

 Copyright (c) 2001-2002 by the person(s) listed below.  All rights reserved.
	Chris Danford
-----------------------------------------------------------------------------
*/


#include "Sprite.h"
#include "ActorFrame.h"
#include "Song.h"
#include "BitmapText.h"
#include "PrefsManager.h"
#include "StyleDef.h"
#include "BitmapText.h"
#include "Quad.h"
#include "ArrowEffects.h"
#include "NoteDataWithScoring.h"
#include "NoteDisplay.h"


class NoteField : public NoteDataWithScoring, public ActorFrame
{
public:
	NoteField();
	virtual void Update( float fDeltaTime );
	virtual void DrawPrimitives();
	
	void	Load( NoteData* pNoteData, PlayerNumber pn, int iPixelsToDrawBehind, int iPixelsToDrawAhead );
	void	RemoveTapNoteRow( int iIndex );

	bool	m_bIsHoldingHoldNote[MAX_HOLD_NOTES];	// hack:  Need this to know when to "light up" the center of hold notes

	float	m_fBeginMarker, m_fEndMarker;	// only used with MODE_EDIT

	void FadeToFail();

protected:
	void DrawMeasureBar( const int iMeasureIndex );
	void DrawMarkerBar( const float fBeat );
	void DrawBPMText( const float fBeat, const float fBPM );
	void DrawFreezeText( const float fBeat, const float fBPM );
	void DrawBGChangeText( const float fBeat, const CString sNewBGName );

	float	m_fPercentFadeToFail;	// -1 of not fading to fail

	PlayerNumber	m_PlayerNumber;
	int				m_iPixelsToDrawBehind;
	int				m_iPixelsToDrawAhead;

	// color arrows
	NoteDisplay		m_NoteDisplay[MAX_NOTE_TRACKS];
	
	// used in MODE_EDIT
	Quad			m_rectMeasureBar;
	BitmapText		m_textMeasureNumber;
	Quad			m_rectMarkerBar;
};
