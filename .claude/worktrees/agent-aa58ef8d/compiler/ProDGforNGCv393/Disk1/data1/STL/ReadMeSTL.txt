ProDG for Nintendo GameCube v 3.9 - STL update         12-July-2002
-------------------------------------------------------------------

Copyright (c) SN Systems Ltd 2002, All rights reserved

This archive contains the C++ standard template library (STL) for
Pro-DG GameCube version 3.9.

INSTALLATION
------------

1. Unzip this zip archive into the root of your Pro-DG installation 
(where the environment variable SN_NGC_PATH points). Ensure
you preserve the directory structure when unzipping.

2. Locate and edit the SN.INI file contained in the root of your
Pro-DG for GameCube installation. Change the cplus_include_path
setting to:

cplus_include_path=c:<prodgroot>\include\STLport-4.5.3\stlport;c:<prodgroot>\include;c:\DolphinSDK1.0\include;c:<prodgroot>

where <prodgroot> is the root of your ProDG installation (as in
step 1)

For example, if you installed ProDG to
C:\Program Files\SN Systems\NGC the SN.INI change would read;

cplus_include_path=c:\program files\SN Systems\NGC\include\STLport-4.5.3\stlport;c:\program files\SN Systems\NGC\include;c:\DolphinSDK1.0\include;c:\program files\SN Systems\NGC

STL will now be fully operational for C++ builds.

A example file 'vector.cpp' can be found in the 'SN Demos\STL'
directory in the ProDG root. 

This release supports I/O streams, if you make use of the file
streaming member functions you will need to link with 'libstl.a'
and include a definition of malloc and free. An example method of
doing something very similar is in the dolphin demos,
cppsetupdemo.cpp in OSDEMO. Simply replace the 'new' and 'delete'
functions with malloc and free respectively:

void* malloc (size_t blocksize)
{
	if (!IsHeapInitialized)
	{
		CPPInit();
	}
	return OSAllocFromHeap(HEAP_ID, blocksize);
}

void free (void* ptr)
{
	OSFreeToHeap(HEAP_ID, ptr);
}

The function CPPInit(); would be identical to the one found in the
cppsetupdemo.cpp demo.

SUPPORT
-------
If you have any questions or feedback please send it to
ngcsupport@snsys.com  

It would be very helpful if anyone submitting a problem report
can run ngccc with no arguments and send us the version numbers of
the tools which appear under the line:

'Associated expected tools:'

Dave Brown
SN Systems
www.snsys.com