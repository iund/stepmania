#ifndef LOADING_WINDOW_COCOA
#define LOADING_WINDOW_COCOA
/*
 *  LoadingWindow_Cocoa.h
 *  stepmania
 *
 *  Created by Steve Checkoway on Thu Jul 03 2003.
 *  Copyright (c) 2003 Steve Checkoway. All rights reserved.
 *
 */

#include "LoadingWindow.h"

extern void MakeNewCocoaWindow();
extern void DisposeOfCocoaWindow();
extern void PaintCocoaWindow();
extern void SetCocoaWindowText(const char *s);

class LoadingWindow_Cocoa : public LoadingWindow {
public:
	LoadingWindow_Cocoa() { MakeNewCocoaWindow(); }
	~LoadingWindow_Cocoa() { DisposeOfCocoaWindow(); }

	void Paint() {} /* Not needed */
	void SetText(CString str) { SetCocoaWindowText(str.c_str()); }
};

#define HAVE_LOADING_WINDOW_COCOA

#endif /* LOADING_WINDOW_COCOA */
