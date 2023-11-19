/****************************************************************************************
	Author:     Andres Trujillo, VS2022 MFC Generated Code
	Date:       11/18/2023
	Brief:      Program GUI dialog design and functionality implementation.
****************************************************************************************/

#include "pch.h"
#include "framework.h"
#include "TemperatureConverter.h"
#include "TemperatureConverterApp.h"
#include "TemperatureConverterDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace TemperatureConverter;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTemperatureConverterDlg dialog



CTemperatureConverterDlg::CTemperatureConverterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEMPERATURECONVERTER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTemperatureConverterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTemperatureConverterDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_FILE_EXIT, &CTemperatureConverterDlg::OnFileExit)
	ON_COMMAND(ID_HELP_ABOUT, &CTemperatureConverterDlg::OnHelpAbout)
	ON_CBN_SELCHANGE(IDC_DEGREETYPE_INPUT, &CTemperatureConverterDlg::OnCbnSelchangeDegreetypeInput)
	ON_CBN_SELCHANGE(IDC_DEGREETYPE_OUTPUT, &CTemperatureConverterDlg::OnCbnSelchangeDegreetypeOutput)
	ON_EN_CHANGE(IDC_TEMPERATURE_INPUT, &CTemperatureConverterDlg::OnEnChangeTemperatureInput)
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &CTemperatureConverterDlg::OnBnClickedButtonZero)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CTemperatureConverterDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CTemperatureConverterDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CTemperatureConverterDlg::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CTemperatureConverterDlg::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &CTemperatureConverterDlg::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SIX, &CTemperatureConverterDlg::OnBnClickedButtonSix)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CTemperatureConverterDlg::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CTemperatureConverterDlg::OnBnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CTemperatureConverterDlg::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_CLEARENTRY, &CTemperatureConverterDlg::OnBnClickedButtonClearentry)
	ON_BN_CLICKED(IDC_BUTTON_DECIMAL, &CTemperatureConverterDlg::OnBnClickedButtonDecimal)
	ON_BN_CLICKED(IDC_BUTTON_BACKSPACE, &CTemperatureConverterDlg::OnBnClickedButtonBackspace)
	ON_BN_CLICKED(IDC_BUTTON_VALUESPECIFIER, &CTemperatureConverterDlg::OnBnClickedButtonValuespecifier)
END_MESSAGE_MAP()


// CTemperatureConverterDlg message handlers

BOOL CTemperatureConverterDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	
	// Disable resizing when hovering over the window frame
	SetWindowLong(m_hWnd, GWL_STYLE, GetWindowLong(m_hWnd, GWL_STYLE) & ~WS_SIZEBOX);

	// Get a pointer to the combobox control
	CComboBox* pDegreeTypeInBox = (CComboBox*)GetDlgItem(IDC_DEGREETYPE_INPUT);
	CComboBox* pDegreeTypeOutBox = (CComboBox*)GetDlgItem(IDC_DEGREETYPE_OUTPUT);

	// Set default control option
	pDegreeTypeInBox->SetCurSel(1);
	pDegreeTypeOutBox->SetCurSel(0);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTemperatureConverterDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTemperatureConverterDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTemperatureConverterDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTemperatureConverterDlg::OnFileExit()
{
	// Exits application
	PostQuitMessage(0);
}


void CTemperatureConverterDlg::OnHelpAbout()
{
	// Show About App dialog
	CAboutDlg AboutDlg;
	AboutDlg.DoModal();
}


void CTemperatureConverterDlg::OnCbnSelchangeDegreetypeInput()
{
	OnEnChangeTemperatureInput();
}


void CTemperatureConverterDlg::OnCbnSelchangeDegreetypeOutput()
{
	OnEnChangeTemperatureInput();
}


void CTemperatureConverterDlg::OnEnChangeTemperatureInput()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureOutput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_OUTPUT);
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// String that will get printed to output box
	CString strOutText;

	// GET INPUT MEASUREMENT SYSTEM TYPE

		// Get pointer to inputType selection
	CComboBox* pMeasureTypeIn = (CComboBox*)GetDlgItem(IDC_DEGREETYPE_INPUT);

		// Get current input type selection
	int selectedIndexIn = pMeasureTypeIn->GetCurSel();
	MeasurementType inputType = static_cast<MeasurementType>(selectedIndexIn);

	// GET DEGREES VALUE

		// Get the current text in the textbox
	CString strInText;
	pTemperatureInput->GetWindowText(strInText);

		// convert degrees string value to double
	double inputValue = _tstof(strInText);

	Temperature InputTemperature(inputValue, inputType);

	// GET OUTPUT MEASUREMENT SYSTEM TYPE

		// Get pointer to outputType selection
	CComboBox* pMeasureTypeOut = (CComboBox*)GetDlgItem(IDC_DEGREETYPE_OUTPUT);

		// Get current output type selection
	int selectedIndexOut = pMeasureTypeOut->GetCurSel();
	MeasurementType outputType = static_cast<MeasurementType>(selectedIndexOut);

	// CONVERT TEMPERATURE

	Temperature OutputTemperature = ConvertTemperatureTo(outputType, InputTemperature);

		// Format temperature for output box
	double outputValue = OutputTemperature.GetValue();
	
		// Get output value
	strOutText.Format(_T("%.6f"), outputValue);

		// Set the new text in the textbox
	pTemperatureOutput->SetWindowText(strOutText);
}

void CTemperatureConverterDlg::OnBnClickedButtonZero()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("0"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonOne()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("1"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonTwo()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("2"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonThree()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("3"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonFour()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("4"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonFive()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("5"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonSix()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("6"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonSeven()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("7"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonEight()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("8"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonNine()
{
	// Get a pointer to the textbox control
	CEdit* pTemperatureInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the textbox
	CString strText;
	pTemperatureInput->GetWindowText(strText);

	// Append number to the existing text
	strText.Append(_T("9"));

	// Set the new text in the textbox
	pTemperatureInput->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonClearentry()
{
	// Get a pointer to the edit controls
	CEdit* pInput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);
	CEdit* pOutput = (CEdit*)GetDlgItem(IDC_TEMPERATURE_OUTPUT);

	// Clear the text in the edit controls
	pInput->SetWindowText(_T(""));
	pOutput->SetWindowText(_T(""));

	// Re-enable the decimal button
	CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON_DECIMAL);
	pButton->EnableWindow(TRUE);
}


void CTemperatureConverterDlg::OnBnClickedButtonDecimal()
{
	// Get a pointer to the edit control
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the edit control
	CString strText;
	pEdit->GetWindowText(strText);

	// Check if the text already contains a decimal point
	if (strText.Find('.') == -1)
	{
		// Append the decimal point to the text
		strText.AppendChar('.');

		// Set the new text in the edit control
		pEdit->SetWindowText(strText);

		// Disable the decimal button
		CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON_DECIMAL);
		pButton->EnableWindow(FALSE);
	}
}


void CTemperatureConverterDlg::OnBnClickedButtonBackspace()
{
	// Get a pointer to the edit control
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the edit box
	CString strText;
	pEdit->GetWindowText(strText);

	// Check if the last character is a decimal point
	if (!strText.IsEmpty() && strText[strText.GetLength() - 1] == '.')
	{
		// Enable the decimal button
		CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON_DECIMAL);
		pButton->EnableWindow(TRUE);
	}

	// Remove the last character from the text
	if (!strText.IsEmpty())
	{
		strText.Delete(strText.GetLength() - 1);
	}

	// Set the new text in the edit box
	pEdit->SetWindowText(strText);
}


void CTemperatureConverterDlg::OnBnClickedButtonValuespecifier()
{
	// Get a pointer to the edit control
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_TEMPERATURE_INPUT);

	// Get the current text in the edit box
	CString strText;
	pEdit->GetWindowText(strText);

	// check if there is already a negative sign
	if (!strText.IsEmpty() && strText[0] == '-') // remove negative sign on click
	{
		// Remove the negative sign
		strText.Delete(0);
	}
	else
	{
		// Add a negative sign at the beginning of the string
		strText.Insert(0, _T("-"));
	}

	// Set the new text in the edit box
	pEdit->SetWindowText(strText);
}
