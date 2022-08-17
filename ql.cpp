#define WIN32_LEAN_AND_MEAN
#include <windows.h>

int wmain(int argc, wchar_t **argv)
{
	if(argc == 1)
	{
		return 1;
	}
	
	// NEVER QUOTE lpApplicationName IT SCREWS UP PARSING RESULTING IN ACESS_DENIED (ERR5)
	//LPCSTR app = "cmd /q /c C:\\ScienceDiscoverer\\DOCS\\HOMIP_PING.cmd";
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	memset(&si, 0, sizeof(si));
	si.cb = sizeof(si);
	memset(&pi, 0, sizeof(pi));
	
	// Create Process ============================================================================
	BOOL res = CreateProcess(
		NULL,				//  [I|O]  Name of the module to be executed, that's it
		argv[1],			// [IO|O]  Command line to be exectued, searches PATH, adds extention
		NULL,				//  [I|O]  Sec. Attrib. for inhereting new process by child processes
		NULL,				//  [I|O]  Sec. Attrib. for inhereting new thread by child processes
		FALSE,				//    [I]  New proc. inherits each inheritable handle
		CREATE_NO_WINDOW,	//    [I]  Process creation flags
		NULL,				//  [I|O]  Ptr to environment block of new process (inherit if NULL)
		NULL,				//  [I|O]  Full path to current directory for the process
		&si,				//    [I]  Ptr to STARTUPINFO struct, if dwFlags = 0, def. values used
		&pi);				//    [O]  Ptr to PROCESS_INFORMATION struct with new proc identification info
	// ===========================================================================================
	
	if(res)
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		return -1;
	}
	
	return 0;
}
