// Report_Error_DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "Report_Error_DLL.h"

REPORT_ERROR_DLL_API void ReportError(DWORD dwError)
{
	int int_result;
    TCHAR* lpErrMsg = NULL;
    TCHAR szErrMsg[1024];
	HLOCAL hLcl;
	HRESULT hRes;
    DWORD dw_result;

	dw_result= FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER|FORMAT_MESSAGE_FROM_SYSTEM,
     NULL,
     dwError,
     MAKELANGID(LANG_NEUTRAL,SUBLANG_DEFAULT),
     (LPTSTR)&lpErrMsg,
     MAX_LOADSTRING,
     NULL);
    hRes = StringCchPrintf(szErrMsg, sizeof(szErrMsg)/sizeof(TCHAR),_T("Error %d: %s"),dwError,lpErrMsg);
    int_result = MessageBox(NULL,(LPWSTR)szErrMsg,NULL,MB_OK);
    if ( lpErrMsg )
    {
        hLcl = LocalFree(lpErrMsg);
        lpErrMsg = NULL;
    }
}

REPORT_ERROR_DLL_API void ReportError(const char* pchError)
{
	int int_result;
	TCHAR* lpErrMsg = NULL;
	TCHAR szErrMsg[1024];
	PVOID pvTemp = SecureZeroMemory((PVOID)szErrMsg,sizeof(szErrMsg));
	size_t nLen = strnlen_s(pchError,sizeof(szErrMsg)/sizeof(TCHAR));
	int_result = MultiByteToWideChar(CP_ACP,
		MB_PRECOMPOSED,
		pchError,
		nLen,
		szErrMsg,
		sizeof(szErrMsg)/sizeof(TCHAR));
	int_result = MessageBox(NULL,(LPWSTR)szErrMsg,NULL,MB_OK);
	if ( lpErrMsg )
	{
		LocalFree(lpErrMsg);
		lpErrMsg = NULL;
	}
}
