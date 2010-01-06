#if HAVE_CONFIG_H
 #include "config.h"
#endif

#if HAVE_CONFIG_WINDOWS_H
 #include "config.windows.h"
#endif

#include <string>
#include <iostream>
#include <stdlib.h>

#ifdef HAVE_UNISTD_H
 #include <unistd.h>
#endif

#ifdef HAVE_WINDOWS_H
 #include <windows.h>
#endif

#ifdef HAVE_SHLOBJ_H
 #include <shlobj.h>
#endif

#ifdef GetUserName
 #undef GetUserName
#endif

//#ifndef PATH_MAX
// #ifdef MAX_PATH
//  #define PATH_MAX MAX_PATH
// #endif
//#endif


#ifndef PATH_MAX
	#define PATH_MAX	256
#endif


#include "Settings.h"

#include <string.h>

using namespace std;

Settings::Settings(const int argc, char** argv)
{
	char* buffer = NULL;

	char* username_temp = NULL;
	char* userconfigpath_temp = NULL;
	char* runtimebinpath_temp = NULL;
	char* highscorespath_temp = NULL;
	char* datapath_temp = NULL;
#ifdef HIGHSCORESDIR
	char highscorespath_define[] = HIGHSCORESDIR;
#endif

#ifdef PKGDATADIR
	char datapath_define[] = PKGDATADIR;
#endif
	buffer = new char[PATH_MAX];

	//-----------------------------------------------------------------
	// debug_settings_verbose ?
	{
		int i;
		debug_settings_verbose = 0;

		for(i = 0; i < argc; i++)
		{
			if(strncmp(argv[i], "--debug-settings-verbose", 30) == 0) debug_settings_verbose = 1;
		}

		if(debug_settings_verbose)
		{
			cout << "debug_settings_verbose is set\n";

			// print compile time defines

			// BINDIR
			cout << "BINDIR ";
#ifdef BINDIR
 #if BINDIR
			cout << BINDIR << endl;
 #else
 			cout << "empty" << endl;
 #endif
#else
			cout << "not defined" << endl;
#endif

			// HAVE_CONFIG_H
			cout << "HAVE_CONFIG_H ";
#ifdef HAVE_CONFIG_H
			cout << "defined" << endl;
#else
			cout << "not defined" << endl;
#endif

			// HAVE_GETLOGIN
			cout << "HAVE_GETLOGIN ";
#ifdef HAVE_GETLOGIN
			cout << "defined" << endl;
#else
			cout << "not defined" << endl;
#endif

			// HAVE_READLINK
			cout << "HAVE_READLINK ";
#ifdef HAVE_READLINK
 			cout << "defined" << endl;
#else
			cout << "not defined" << endl;
#endif

			// HAVE_SHLOBJ_H
			cout << "HAVE_SHLOBJ_H ";
#ifdef HAVE_SHLOBJ_H
			cout << "defined" << endl;
#else
			cout << "not defined" << endl;
#endif

			// HAVE_UNISTD_H
			cout << "HAVE_UNISTD_H ";
#ifdef HAVE_UNISTD_H
 			cout << "defined" << endl;
#else
			cout << "not defined" << endl;
#endif

			// HAVE_WINDOWS_H
			cout << "HAVE_WINDOWS_H ";
#ifdef HAVE_WINDOWS_H
 			cout << "defined" << endl;
#else
			cout << "not defined" << endl;
#endif

			// HIGHSCORESDIR
			cout << "HIGHSCORESDIR ";
#ifdef HIGHSCORESDIR
 #if HIGHSCORESDIR
			cout << HIGHSCORESDIR << endl;
 #else
 			cout << "empty" << endl;
 #endif
#else
			cout << "not defined" << endl;
#endif

			// PKGDATADIR
			cout << "PKGDATADIR ";
#ifdef PKGDATADIR
 #if PKGDATADIR
			cout << PKGDATADIR << endl;
 #else
 			cout << "empty" << endl;
 #endif
#else
			cout << "not defined" << endl;
#endif

			// _WIN32_IE
			cout << "_WIN32_IE ";
#ifdef _WIN32_IE
 #if _WIN32_IE
			cout << _WIN32_IE << endl;
 #else
 			cout << "empty" << endl;
 #endif
#else
			cout << "not defined" << endl;
#endif
		}
	}

	//-----------------------------------------------------------------
	// get the username
	{
		if(username_temp) goto FOUND_USERNAME;

		// try posix getlogin function
#ifdef HAVE_GETLOGIN
		username_temp = getlogin();
		if(username_temp) goto FOUND_USERNAME;
#endif

		// try the windows function
#ifdef HAVE_WINDOWS_H
 #if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0500) || (NTDDI_VERSION >= NTDDI_WIN2K)
		{
			DWORD i = PATH_MAX;
			memset(buffer, 0, sizeof(char[PATH_MAX]));
			if(GetUserNameA(buffer, &i)) username_temp = buffer;
		}
		if(username_temp) goto FOUND_USERNAME;
 #endif
#endif

//#ifdef _WIN32_IE
//	cout << "_WIN32_IE " << _WIN32_IE << endl;
//#else
//	cout << "_WIN32_IE not defined" << endl;
//#endif
		// try the env variable USER
		username_temp = getenv("USER");
		if(username_temp) goto FOUND_USERNAME;

		// try the env variable LOGUSER
		username_temp = getenv("LOGUSER");
		if(username_temp) goto FOUND_USERNAME;

		// try the env variable USERNAME
		if(username_temp) goto FOUND_USERNAME;
		username_temp = getenv("USERNAME");

FOUND_USERNAME:
		// done searching,  copy the string
		if(username_temp != NULL)
		{
			username = new char[strlen(username_temp) + 1];
			strcpy(username, username_temp);
		}
		else
		{
			username = new char[sizeof("")];
			strcpy(username, "");
		}
	}
	// got username
	//--------------------------------------------------------------

	//-------------------------------------------------------------------------
	// get userconfigpath
	{
		if(userconfigpath_temp) goto FOUND_USERCONFIGDIR;

		// try the windows function
#ifdef HAVE_SHLOBJ_H
 #if (_WIN32_IE >= 0x0400)
		memset(buffer, 0, sizeof(char[PATH_MAX]));
		if(SHGetSpecialFolderPathA(NULL, buffer, CSIDL_APPDATA, TRUE)) userconfigpath_temp = buffer;
		if(userconfigpath_temp) goto FOUND_USERCONFIGDIR;
 #endif
#endif
		// try the env variable APPDATA
		userconfigpath_temp = getenv("APPDATA");
		if(userconfigpath_temp) goto FOUND_USERCONFIGDIR;

		// try the env variable HOME
		userconfigpath_temp = getenv("HOME");
		if(userconfigpath_temp) goto FOUND_USERCONFIGDIR;

FOUND_USERCONFIGDIR:
		// done searching,  copy the string
		if(userconfigpath_temp)
		{
			userconfigpath = new char[strlen(userconfigpath_temp) + sizeof("/")];
			strcpy(userconfigpath, userconfigpath_temp);
			strcat(userconfigpath, "/");
		}
		else
		{
			userconfigpath = new char[sizeof("")];
			strcpy(userconfigpath, "");
		}
	}
	// got unserconfigpath
	//------------------------------------------------------------------------

	//--------------------------------------------------------------------------
	// get runtimebinpath
	{
		if(runtimebinpath_temp) goto FOUND_RUNTIMEBINPATH;

		// try the windows function
#ifdef HAVE_WINDOWS_H
 #if (WINVER >= 0x0500) || (_WIN32_WINNT >= 0x0500) || (NTDDI_VERSION >= NTDDI_WIN2K)
		{
			DWORD i = PATH_MAX;
			memset(buffer, 0, sizeof(char[PATH_MAX]));
			if(GetModuleFileName(NULL, buffer, i))
			{
				char* app_pointer = strstr(buffer, "pacdude.exe");
				if(app_pointer) *app_pointer = 0;
				runtimebinpath_temp = buffer;
			}
		}
		if(runtimebinpath_temp) goto FOUND_RUNTIMEBINPATH;
 #endif
#endif

		// try /proc/self/exe
#ifdef HAVE_READLINK
		{
			memset(buffer, 0, sizeof(char[PATH_MAX]));
			if(readlink("/proc/self/exe", buffer, sizeof(char[PATH_MAX - 1])) > 0)
			{
				// keep the last slash and then null terminate
				*(strrchr(buffer, '/') + 1) = 0;
				runtimebinpath_temp = buffer;
			}
		}
		if(runtimebinpath_temp) goto FOUND_RUNTIMEBINPATH;
#endif

FOUND_RUNTIMEBINPATH:
		// done searching,  copy the string
		if(runtimebinpath_temp)
		{
			runtimebinpath = new char[strlen(runtimebinpath_temp) + 1];
			strcpy(runtimebinpath, runtimebinpath_temp);
		}
		else
		{
			runtimebinpath = new char[sizeof("")];
			strcpy(runtimebinpath, "");
		}
	}
	// got runtimebinpath
	//----------------------------------------------------------------------

	//---------------------------------------------------------------
	// get highscorespath
	{
		if(highscorespath_temp) goto FOUND_HIGHSCORESDIR;

		// try the windows function to get All Users/Application data
#ifdef HAVE_SHLOBJ_H
 #if (_WIN32_IE >= 0x0400)
		memset(buffer, 0, sizeof(char[PATH_MAX]));
		if(SHGetSpecialFolderPath(NULL, buffer, CSIDL_COMMON_APPDATA, TRUE)) highscorespath_temp = buffer;
		if(highscorespath_temp) goto FOUND_HIGHSCORESDIR;
 #endif
#endif

#ifdef BINDIR
 #ifdef HIGHSCORESDIR
		// compare to the bin path, if the same then use the install path
		{
			char* slash_pointer = strrchr(runtimebinpath, '/');
			*slash_pointer  = 0;
			if(strncmp(runtimebinpath, BINDIR, sizeof(char[PATH_MAX])) == 0) highscorespath_temp = highscorespath_define;
			*slash_pointer  = '/';
		}
		if(highscorespath_temp) goto FOUND_HIGHSCORESDIR;
 #endif
#endif

FOUND_HIGHSCORESDIR:
		// done searching,  copy the string
		if(highscorespath_temp)
		{
			highscorespath = new char[strlen(highscorespath_temp) + sizeof("/")];
			strcpy(highscorespath, highscorespath_temp);
			strcat(highscorespath, "/");
		}
		else
		{
			highscorespath = new char[sizeof("")];
			strcpy(highscorespath, "");
		}
	}
	// found highscorespath
	//---------------------------------------------

	//-----------------------------------------------------------
	// get datapath
	{
		if(datapath_temp) goto FOUND_DATAPATH;

		//try Filesystem Hierarchy
#ifdef BINDIR
 #ifdef PKGDATADIR
		// try the bin path first
		{
			// is the package in the installed path ?
			char* slash_pointer = strrchr(runtimebinpath, '/');
			*slash_pointer  = 0;
			if(strncmp(runtimebinpath, BINDIR, sizeof(char[PATH_MAX])) == 0) datapath_temp = datapath_define;
			*slash_pointer  = '/';
		}
		if(datapath_temp) goto FOUND_DATAPATH;
 #endif
#endif
FOUND_DATAPATH:

		// done searching,  copy the string or append the exe path
		if(datapath_temp)
		{
			datapath = new char[strlen(datapath_temp) + sizeof("/")];
			strcpy(datapath, datapath_temp);
			strcat(datapath, "/");
		}
		else
		{
			datapath = new char[strlen(runtimebinpath) + sizeof("data/")];
			sprintf(datapath, "%sdata/", runtimebinpath);
		}
	}
	// got data path
	//------------------------------------------------


	if(debug_settings_verbose)
	{
		cout << "username       " << username << endl;
		cout << "highscorespath " << highscorespath << endl;
		cout << "userconfigpath " << userconfigpath << endl;
		cout << "runtimebinpath " << runtimebinpath << endl;
		cout << "datapath       " << datapath << endl;
	}

	// all done
	//----------------------------
	delete buffer;
	delete runtimebinpath;
}

Settings::~Settings()
{
	delete username;
	delete highscorespath;
	delete userconfigpath;
	delete datapath;
}

const int Settings::GetOptionVerbose()
{
	return verbose;
}

const char* Settings::GetUserName()
{
	return username;
}

const char* Settings::GetHighScoresPath()
{
	return highscorespath;
}

const char* Settings::GetUserConfigPath()
{
	return userconfigpath;
}

const char* Settings::GetDataPath()
{
	return datapath;
}
