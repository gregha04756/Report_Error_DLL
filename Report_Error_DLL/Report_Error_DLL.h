// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the REPORT_ERROR_DLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// REPORT_ERROR_DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef REPORT_ERROR_DLL_EXPORTS
#define REPORT_ERROR_DLL_API __declspec(dllexport)
#else
#define REPORT_ERROR_DLL_API __declspec(dllimport)
#endif

#define MAX_LOADSTRING 100

REPORT_ERROR_DLL_API int fnReport_Error_DLL(void);
REPORT_ERROR_DLL_API void ReportError(DWORD dwError);
REPORT_ERROR_DLL_API void ReportError(const char* pchError);