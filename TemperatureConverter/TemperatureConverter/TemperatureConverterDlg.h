/****************************************************************************************
	Author:     VS2022 MFC Generated Code
	Brief:      TemperatureConverterDlg.cpp header file
****************************************************************************************/

#pragma once


// CTemperatureConverterDlg dialog
class CTemperatureConverterDlg : public CDialogEx
{
// Construction
public:
	CTemperatureConverterDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEMPERATURECONVERTER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileExit();
	afx_msg void OnHelpAbout();
	afx_msg void OnCbnSelchangeDegreetypeInput();
	afx_msg void OnCbnSelchangeDegreetypeOutput();
	afx_msg void OnEnChangeTemperatureInput();
	afx_msg void OnBnClickedButtonZero();
	afx_msg void OnBnClickedButtonOne();
	afx_msg void OnBnClickedButtonTwo();
	afx_msg void OnBnClickedButtonThree();
	afx_msg void OnBnClickedButtonFour();
	afx_msg void OnBnClickedButtonFive();
	afx_msg void OnBnClickedButtonSix();
	afx_msg void OnBnClickedButtonSeven();
	afx_msg void OnBnClickedButtonEight();
	afx_msg void OnBnClickedButtonNine();
	afx_msg void OnBnClickedButtonClearentry();
	afx_msg void OnBnClickedButtonDecimal();
	afx_msg void OnBnClickedButtonBackspace();
	afx_msg void OnBnClickedButtonValuespecifier();
};
