MSI Unpacker from JSWare

_________________________________________________________
Introduction:
_________________________________________________________

  jsMSIx.exe is a compiled executable version of the JSWare MSI
Unpacker tools. This version is designed for use by people who
want it simple... who may be intimidated by script and HTAs, or
who just don't want to deal with that complexity. 

  Also, jsMSIx.exe is designed to work on all Windows versions.
The scripted unpackers may require some editing of the code to
work on various Windows versions due to different folder
paths and other minor differences.  

  This version may also be the easiest for people using Linux. 
It has minimal dependencies and is easy to use.

_________________________________________________________
Requirements: 
_________________________________________________________

 System files MSVBVM60.DLL, CABINET.DLL and MSI.DLL

  Those 3 files are pre-installed on nearly all Windows PCs. jsMSIx.exe
should work as a standalone program on all Windows versions from
Win98 to Win10. But on Linux those 3 files might need to be installed
through WINE.

File restrictions:
  Later Windows versions may present obstacles in connection with 
file restrictions. You may need to give yourself "permission" in some 
cases. On the bright side, the JSWare unpackers are not limited
by Windows Installer "Administrative installation", which is the 
unpacking method used by some MSI unpackers. An Administrative 
installation is very simple to do. It's a function offered by many
MSI files. But it is only a partial unpacking and can only be done 
by an Administrator. Administrative installation is designed to
unpack specific files for install from a network in business settings.
Actual unpacking of an MSI unpacks the whole thing and does 
not require any special permissions.

_________________________________________________________
How to use jsMSIx.exe:
_________________________________________________________

   In the Unpacker window there is an option to select an MSI
or MSM file, as well as a folder path for unpacking.

Click "GetMSI Info" to see a list of files and Registry settings in
the MSI or MSM.

Click "Unpack MSI file" to fully unpack the MSI or MSM and write
a log file documenting the files and Registry settings.

** NOTE: With very large files an unpacking or info. retrieval 
operation can take several minutes. For example, platform SDK 
MSIs typically record information for dozens of CAB files, each
containing dozens of files. The program needs to be allowed to
finish without interruption, and without excessive CPU demand
from other software.

_________________________________________________________
Other MSI Unpacking options:
_________________________________________________________

  In addition to jsMSIx there are three script options, which are less
polished but more flexible -- for people who might want to customize
the tools.

1) MSI Unpacker - An HTA (scripted webpage) tool to unpack MSIs
and MSMs. The MSI Unpacker also provides the ability to inspect
the components and features of an installer file.

2) One-click unpacker script - Like the MSI Unpacker, but with no
interface. It's just a VBScript that unpacks MSI and MSM files.

3) jsMSI.dll - A COM DLL that can be used by script or any COM-
compatible programming language. jsMSI.dll provides a full set of
easy functions to manage MSI/MSM files. Among the functions is
a function to unpack MSIs/MSMs. There are also dozens of functions
for editing the MSI database: Create tables and records. Change
values. etc. jsMSI.dll is a "wrapper". I wraps the clunky and confusing
MSI API, with its pseudo-SQL syntax, and provides simple functions
in their place.

  jsMSIx.exe and the three options listed above all unpack an MSI in 
basically the same way. They create folders to mirror the folder 
structure used when the software is actually installed. They then 
unpack the MSI files into their respective folders. They also write 
an extensive log file that details all files in the package and lists Registry 
settings that will be made when the MSI installation is run. 

_________________________________________________________
Explanation of folder paths:
_________________________________________________________

 An MSI stores information about the destination paths of files
in an installation. Those paths are often stored as variable names
for system folder paths that vary from one computer to another.
For example, "SystemFolder" refers to the system folder path, which
is usually *but not always* C:\Windows\System32. When an installer 
is unpacked, files will typically end up in such folders, mimicking the 
actual install as closely as possible.

  Oddly, even among Microsoft MSIs, there is little standardization
of these names. The Program Files folder may show up as "ProgramFiles",
"ProgramFilesFolder", "Programs", or even "PFiles". Likewise, the
Windows folder may show up as "Windows", "WindowsFolder", or
even "Win". As long as you know about this quirk, however, it should
be fairly simple to figure out the paths. 

Example: An unpacking results in folders named "PFiles", "SystemFolder"
and "Common". Those would represent C:\Program Files, C:\Windows\System32
and C:\Program Files\Common Files on a typical system. If, on the
other hand, an MSI for the Acme Editor unpacks to a folder named "Acme"
or "Acme Editor", that would be the program folder, which will typically be
installed to C:\Program Files.

_________________________________________________________
Explanation of Registry settings:
_________________________________________________________

The Registry settings are documented in the following manner, with
the intention that anyone who wants to design their own custom
installer from an MSI can easily "auto-parse" the unpacker's log file 
-- using script or some other tool -- and write the Registry settings
themselves with minimal effort.

Each setting is on 1 line and goes like this:

Path•Value•Type

Path is the path in the Registry.
Value is the value to set.
Type is the type of value. (String, Binary, DWord, etc.)
Each part is separated by a bullet character. (ASCII Chr 149)

Example: HKCU\Software\AceAndAcme\Settings\Theme•Traditional•SZ

_________________________________________________________
Troubleshooting:
_________________________________________________________

In general, any errors will be documented in the unpacking
log file.

* File locations:

  Make sure any external CAB files that go with the MSI file to 
be unpacked are in the same folder with the MSI file.
 
* Long paths: 

  Unpacking may fail if names of files, combined with
the folder path, exceed about 250 characters. If you have problems
extracting make sure the folder path of the unpack folder is not too
long.

* MSIs inside EXEs:

   Note that some MSI files are put inside EXE files. jsMSIx.exe can
unpack those MSIs, but they must first be extracted from the
EXE. Usually a good way is to open the TEMP folder, run the installer
EXE, fish the MSI out of TEMP, then cancel the install.

* MSIs inside SFX CAB EXEs:

  Another installer variation that is more recent is an MSI file that
unpacks its own files before running. The MSI is inside a self-
executing CAB file, which unpacks the files on its own, as part of
the CAB SFX extraction process, into a folder tree in the TEMP folder! 
In those cases, jsMSIx.exe is still useful to document the files and 
Registry settings, but it needs access to the MSI file inside the SFX 
CAB.

* Permissions/Restrictions:

  The default on most Windows systems is to restrict you
from writing/deleting files in most locations. That could interfere
with the unpacker. For example, most MSIs have a CAB stored
internally. The Unpacker must extract that to unpack it. The 
extracting is done to the same location, in case you want later 
access to the CAB file. But if you don't have full permission in
the folder that holds the MSI, the Unpacker may be unable to
write the CAB file to disk and as a result be unable to find the
CAB for unpacking.
 

_________________________________________________________

*************  UPDATE HISTORY: **********************
_________________________________________________________

___________________ Update April, 2014 __________

    Over the past few years, 3 fixes were required to handle problems
with faulty Directory tables in MSIs. (The Directory Table stores the 
paths of folders in a program, so parsing it is required for unpacking
an installer's files into their destination folders.) 
  The Directory Table is very complex, often with numerous "dummy" 
entries. (For example, the MSI for Adobe Flash is merely a container 
for the EXE version of the installer. Yet the Flash MSI lists 11 folder 
paths in its Directory Table!)  
  Faulty records in the Directory Table are not uncommon, even in 
Microsoft installers. (See details in update listing below.) In an effort 
to avoid future problems, this update involves a complete rewrite of 
the code for parsing the Directory Table.


____________________ Update March, 2014 ________

This update includes 3 changes:

* Bugfix: An error would cause MSIs with external CABs to
fail when unpacked to a folder other than the folder containing
the MSI file. The unpacker was looking for the CAB in the
destination folder instead of the MSI parent folder.

* An adjustment to logging that makes sure missing external CABs
are reported missing in the log file.

* Like two earlier updates, this is a minor update to accomodate
a type of faulty Directory table. This faulty design was found in
a Garmin maps MSI. In this case the fault was a Directory table in 
which two different records indicated the root folder, which is not 
allowed under MSI rules. The result of the faulty table would be that 
the unpacker would not sort files because no folder assignments 
could be found. This update has a workaround for the faulty table.

____________________ Update April, 2013 ________

  A very minor update adding a menu for convenience and a small bugfix:
In some situations copying Registry settings to the Clipboard was
not working.

____________________ Update January, 2013 ________

  A tiny update that just adds drag-drop functionality so that
one can drop an MSI onto the path textbox rather than needing
to browse for a file.

____________________ Update July, 2011 ___________

  A very minor update to fix a small bug: The program would
sometimes crash if an MSI had a Registry table, but that table
had no items.


 ___________________ Update January, 2011 _______

   This is a minor update to deal with faulty MSIs. In rare cases the MSI 
unpackers here may have trouble with a particular MSI due to its being 
faulty. This update follows the discovery of such an MSI. 
The technical explanation:

The MSI documentation states that the MSI Directory table, listing folders 
in the install, has 3 columns:

Directory - unique ID of folder
Directory_Parent - unique ID of parent folder.
DefaultDir - name of folder when installed.

  The docs further state that there can be only 1 root folder. That folder has 
Directory property set to TARGETDIR and DefaultDir set to SourceDir. If 
there is no TARGETDIR then the ROOTDRIVE property is used. The docs also 
state that if the Directory_Parent property is the same as Directory, or if it 
is blank, then that entry represents the root folder. Up until now we were 
only aware of 1 case of a faulty MSI Directory table. It had two TARGETDIR 
entries and, oddly enough, was authored by a very well-known Microsoft MVP. 
More recently a second case has turned up, this time from Microsoft themselves. 
The file name is NetworkMonitor_Parsers.msi. It comes packed inside the Network 
MS Monitor software download. In NetworkMonitor_Parsers.msi Directory table 
there is the following:


TARGETDIR	NPLROOT		PackDir|NetworkMonitor Parsers
Base				SourceDir

  TARGETDIR is a keyword that should denote the root folder but it is not the root 
folder. "TARGETDIR" was just used as the alphanumeric ID of one of the folders! The 
root folder was named Base. Without figuring out the root folder name, unpacking 
ends up being partial at best, so this problem needed to be dealt with.

   The update involves a rewrite of the function -- in all of the unpackers -- that 
performs the job of sorting out installation folder paths. The new versions will 
look for a valid entry that has "SourceDir" in the 3rd column, with a 2nd column 
that is either blank or matches the first column. Only if no such match is found 
will it then check for entries with TARGETDIR or ROOTDRIVE in the first column.

____________________________________________

__________________ Update 11-29-2010 _________

 A minor update that allows for unpacking MSIs where there are
multiple CAB files with spanning. (Where 1 stored file is stored across
2 CAB files.)

____________________________________________

___________________ Update 11-21-2010 ________

  This is a minor, single bug fix. There was a typo in the code
that could cause a crash in some cases when clicking "Get MSI Info."
That was fixed.

_________________________________________________________

License:

You use all script code and components from JSWare at your own risk.

  The components (compiled DLL and EXE files) may be used for personal or
commercial purposes. No payment or attribution is required for either use.
The components may be redistributed if they are required as support files 
for scripts or software that you have written.
   Also, the script code may be used freely, in part or as whole scripts,
for any purpose, personal or commercial, without payment or attribution.

  I ask only that you not redistribute these scripts and components, except
as required for your direct use. Instead, please direct others to obtain copies
of JSWare scripts and components directly from www.jsware.net.

  Also, none of the code here may be redistributed under another license. If a 
work using code from JSWare is distributed with restrictions of any kind 
the code from JSWare must be kept exempt from those restrictions. 
This includes, but is not limited to, code sold for profit, code with usage restrictions
and code distributed as so-called "Open Source" with redistribution restrictions. 

                                         Joe Priestley


JSWare
www.jsware.net
jsware@jsware.net  

Please note: JSWare does not accept "webmail" from hotmail, 
yahoo, facebook, or gmail. For further explanation see:
www.jsware.net/jsware/contact.php5
