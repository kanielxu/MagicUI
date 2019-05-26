// MSNLogin.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "MSNLogin.h"
#include "MSNLoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSNLoginApp

BEGIN_MESSAGE_MAP(CMSNLoginApp, CWinApp)
	//{{AFX_MSG_MAP(CMSNLoginApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSNLoginApp construction

CMSNLoginApp::CMSNLoginApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMSNLoginApp object

CMSNLoginApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMSNLoginApp initialization

BOOL CMSNLoginApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
//========Magic UI Library Call Sample Start========
	TCHAR path[MAX_PATH];
	GetModuleFileName(NULL, path, MAX_PATH);
	CString strFilePath = path;
	strFilePath = strFilePath.Left(strFilePath.ReverseFind('\\'));

	CString strSkinPath;
	strSkinPath.Format(_T("%s\\Skin\\"), strFilePath);

	m_pMSNLoginWnd = new CMSNLoginDlg();
	m_pMSNLoginWnd->Create(strSkinPath, _T("MSNLogin.xml"), _T("Global.xml"));
	m_pMainWnd = m_pMSNLoginWnd;

	return TRUE;
//========Magic UI Library Call Sample End========
}

int CMSNLoginApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWinApp::ExitInstance();
}
