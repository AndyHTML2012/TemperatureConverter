/****************************************************************************************
	Author:     VS2022 MFC Generated Code
	Brief:      Main header file for the Temperature Converter application
****************************************************************************************/

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CTemperatureConverterApp:
// See TemperatureConverter.cpp for the implementation of this class
//

class CTemperatureConverterApp : public CWinApp
{
public:
	CTemperatureConverterApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CTemperatureConverterApp theApp;
