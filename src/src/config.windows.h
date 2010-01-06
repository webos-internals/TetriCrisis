#define HAVE_SHLOBJ_H
#define HAVE_WINDOWS_H
#define PACKAGE_NAME "pacdude"
#define PACKAGE_BUGREPORT "slnthero@aol.com"
#define PACKAGE_STRING "PacDude 100% 5.0.08"
#define PACKAGE_TARNAME "pacdude"
#define PACKAGE_VERSION "5.0.08"
#define VERSION "5.0.08"

/*
	Windows Server	2008					0x0600
	Windows Vista						0x0600
	Windows Server 2003 SP1, Windows XP SP2	0x0502
	Windows Server 2003 Windows XP		0x0501
	Windows 2000						0x0500
*/
#define WINVER 0x0500
#define _WIN32_WINNT WINVER

/*
	Internet Explorer 7.0			0x0700
	Internet Explorer 6.0 SP2		0x0603
	Internet Explorer 6.0 SP1		0x0601
	Internet Explorer 6.0			0x0600
	Internet Explorer 5.5			0x0550
	Internet Explorer 5.01			0x0501
	Internet Explorer 5.0, 5.0a, 5.0b	0x0500
*/

#define _WIN32_IE 0x0500

/*
	Windows Server 2008						NTDDI_WS08
	Windows Vista Service Pack 1 (SP1)			NTDDI_VISTASP1
	Windows Vista							NTDDI_VISTA
	Windows Server 2003 Service Pack 1 (SP1)	NTDDI_WS03SP1
	Windows Server 2003						NTDDI_WS03
	Windows XP Service Pack 2 (SP2)			NTDDI_WINXPSP2
	Windows XP Service Pack 1 (SP1)			NTDDI_WINXPSP1
	Windows XP							NTDDI_WINXP
	Windows 2000 Service Pack 4 (SP4)			NTDDI_WIN2KSP4
	Windows 2000 Service Pack 3 (SP3)			NTDDI_WIN2KSP3
	Windows 2000 Service Pack 2 (SP2)			NTDDI_WIN2KSP2
	Windows 2000 Service Pack 1 (SP1)			NTDDI_WIN2KSP1
	Windows 2000							NTDDI_WIN2K
*/

#define NTDDI_VERSION NTDDI_WIN2K

#if (_WIN32_IE < 0x0400) && defined(_WIN32_WINNT) && (_WIN32_WINNT >= 0x0500)
 #error _WIN32_IE setting conflicts with _WIN32_WINNT setting
#endif
