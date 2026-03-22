// clib_internal.cpp - Internal C library functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 72 functions
//
// These are stub implementations to be replaced with matching decompilations.
// Each function needs to be decompiled to match the original binary.

#include "types.h"

// Forward declarations
class EStream;
class EFile;
class ERC;
class EMat4;
class EVec3;
class EVec4;
class EStorable;
class FastAllocPool;
struct ImageProcessingManager;
struct AptSysClock;
struct DVDFileInfo;
struct DVDCommandBlock;
struct DVDDiskID;
struct GXColor;
struct GXTexObj;
struct GXTlutObj;
struct OSThread;
struct OSAlarm;
struct OSContext;
struct OSMutex;
struct OSMessageQueue;
struct GXRenderModeObj;
struct GXFifoObj;
struct GXLightObj;
struct PADStatus;
struct CARDFileInfo;
struct DSPTask;
class BString;
class BString2;
class EAnimNodeDataPos;
class iResFile;
struct FrameEffectsManager;
struct EAnimNote;
struct AptGetBytesEnum;
struct ObjectSaveTypeTable2;
struct ObjectSaveTypeTable3;
struct ObjectSaveIDTable;
struct UserDataSaveLoad;
struct SpriteIdToResIdNode;
class cSimulator;
class Neighbor;
class CasSimDescriptionS2C;
struct AptValue;
struct AptObject;
struct CBFunctorBase;

// _loadFileSize(char *, int *)
// Address: 0x80009BD4, Size: 420
void _loadFileSize(char * p0, int * p1) {
}

// _loadGeometry(char *, AptAuxLayerInfo *)
// Address: 0x8000A570, Size: 628
void _loadGeometry(char * p0, AptAuxLayerInfo * p1) {
}

// _allocateMemory
// Address: 0x8000F45C, Size: 56
void _allocateMemory() {
}

// _freeMemory
// Address: 0x8000F494, Size: 52
void _freeMemory() {
}

// _reallocateMemory
// Address: 0x8000F4C8, Size: 32
void _reallocateMemory() {
}

// _assertFail
// Address: 0x8000F4E8, Size: 44
void _assertFail() {
}

// _freeFontTable(void)
// Address: 0x80015614, Size: 4
void _freeFontTable() {
}

// _kBottomLeftWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003CF7C, Size: 824
void _kBottomLeftWallsEndCapTest(CTilePt & p0, TileWalls & p1, TileWallsSegment p2, DiagonalSideSelector p3) {
}

// _kTopRightWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003D2B4, Size: 848
void _kTopRightWallsEndCapTest(CTilePt & p0, TileWalls & p1, TileWallsSegment p2, DiagonalSideSelector p3) {
}

// _kBottomRightWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003D604, Size: 848
void _kBottomRightWallsEndCapTest(CTilePt & p0, TileWalls & p1, TileWallsSegment p2, DiagonalSideSelector p3) {
}

// _kTopLeftWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003D954, Size: 848
void _kTopLeftWallsEndCapTest(CTilePt & p0, TileWalls & p1, TileWallsSegment p2, DiagonalSideSelector p3) {
}

// _kHorizDiagWallskTopEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003DCA4, Size: 940
void _kHorizDiagWallskTopEndCapTest(CTilePt & p0, TileWalls & p1, TileWallsSegment p2, DiagonalSideSelector p3) {
}

// _kHorizDiagWallskBottomEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003E050, Size: 940
void _kHorizDiagWallskBottomEndCapTest(CTilePt & p0, TileWalls & p1, TileWallsSegment p2, DiagonalSideSelector p3) {
}

// _kVertDiagWallskRightEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003E3FC, Size: 940
void _kVertDiagWallskRightEndCapTest(CTilePt & p0, TileWalls & p1, TileWallsSegment p2, DiagonalSideSelector p3) {
}

// _kVertDiagWallskLeftEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003E7A8, Size: 940
void _kVertDiagWallskLeftEndCapTest(CTilePt & p0, TileWalls & p1, TileWallsSegment p2, DiagonalSideSelector p3) {
}

// _Default2dArrayAlloc(unsigned int)
// Address: 0x800519A0, Size: 56
void _Default2dArrayAlloc(unsigned int p0) {
}

// _Default2dArrayFree(void *)
// Address: 0x800519D8, Size: 52
void _Default2dArrayFree(void * p0) {
}

// _MotiveSort(void *, void *)
// Address: 0x801A8D78, Size: 84
void _MotiveSort(void * p0, void * p1) {
}

// _ParseNode(CDirtyXmlNode *, unsigned char *)
// Address: 0x803AFF98, Size: 108
void _ParseNode(CDirtyXmlNode * p0, unsigned char * p1) {
}

// _ParseNumChildNodes(unsigned char *)
// Address: 0x803B0004, Size: 148
void _ParseNumChildNodes(unsigned char * p0) {
}

// _ParseChildNodes(CDirtyXmlNode **, int, unsigned char *)
// Address: 0x803B0098, Size: 204
void _ParseChildNodes(CDirtyXmlNode ** p0, int p1, unsigned char * p2) {
}

// _ParseLevel(CDirtyXmlNode *, unsigned char *)
// Address: 0x803B0164, Size: 92
void _ParseLevel(CDirtyXmlNode * p0, unsigned char * p1) {
}

// _Parse(CDirtyXmlNode *, CDirtyXmlNode *, unsigned char *)
// Address: 0x803B01C0, Size: 116
void _Parse(CDirtyXmlNode * p0, CDirtyXmlNode * p1, unsigned char * p2) {
}

// _ParseNumber(unsigned char *, unsigned int *)
// Address: 0x803B0B28, Size: 64
void _ParseNumber(unsigned char * p0, unsigned int * p1) {
}

// _SecsToTime(tm *, unsigned int)
// Address: 0x803B0B68, Size: 500
void _SecsToTime(tm * p0, unsigned int p1) {
}

// _TimeToSecs(tm *)
// Address: 0x803B0D5C, Size: 208
void _TimeToSecs(tm * p0) {
}

// _XmlContentChar(unsigned char *, unsigned char *)
// Address: 0x803B0E2C, Size: 404
void _XmlContentChar(unsigned char * p0, unsigned char * p1) {
}

// _XmlContentFind(unsigned char *)
// Address: 0x803B0FC0, Size: 76
void _XmlContentFind(unsigned char * p0) {
}

// _XmlAttribFind(unsigned char *, unsigned char *)
// Address: 0x803B100C, Size: 412
void _XmlAttribFind(unsigned char * p0, unsigned char * p1) {
}

// _XmlAttribFindByIndex(unsigned char *, int)
// Address: 0x803B11A8, Size: 312
void _XmlAttribFindByIndex(unsigned char * p0, int p1) {
}

// _puts_r
// Address: 0x803C1158, Size: 136
void _puts_r() {
}

// _vfflush
// Address: 0x803C2D18, Size: 48
void _vfflush() {
}

// _vfwrite
// Address: 0x803C2D48, Size: 212
void _vfwrite() {
}

// _vfprintf_r
// Address: 0x803C2EF4, Size: 5188
void _vfprintf_r() {
}

// _vfiprintf_r
// Address: 0x803C4448, Size: 4852
void _vfiprintf_r() {
}

// _setlocale_r
// Address: 0x803C573C, Size: 436
void _setlocale_r() {
}

// _localeconv_r
// Address: 0x803C58F0, Size: 12
void _localeconv_r() {
}

// _mbtowc_r
// Address: 0x803C66C8, Size: 796
void _mbtowc_r() {
}

// _fopen_r
// Address: 0x803C6DE8, Size: 236
void _fopen_r() {
}

// _cleanup_r
// Address: 0x803C6F04, Size: 40
void _cleanup_r() {
}

// _cleanup
// Address: 0x803C6F2C, Size: 36
void _cleanup() {
}

// _fwalk
// Address: 0x803C7334, Size: 128
void _fwalk() {
}

// _close_r
// Address: 0x803C7780, Size: 80
void _close_r() {
}

// _fstat_r
// Address: 0x803C77D0, Size: 88
void _fstat_r() {
}

// _lseek_r
// Address: 0x803C7828, Size: 88
void _lseek_r() {
}

// _open_r
// Address: 0x803C7880, Size: 92
void _open_r() {
}

// _read_r
// Address: 0x803C78DC, Size: 88
void _read_r() {
}

// _write_r
// Address: 0x803C7934, Size: 88
void _write_r() {
}

// _exit
// Address: 0x803C8060, Size: 8
void _exit() {
}

// _ExitProcess
// Address: 0x803D4858, Size: 32
void _ExitProcess() {
}

// _passthruToMemFree(void *, unsigned int)
// Address: 0x803E71B4, Size: 44
void _passthruToMemFree(void * p0, unsigned int p1) {
}

// _profileInit(void)
// Address: 0x803E71E0, Size: 4
void _profileInit() {
}

// _AptValidate(void)
// Address: 0x803E7EB0, Size: 8
void _AptValidate() {
}

// _addScreenGrabToSavedInputs(void)
// Address: 0x803E8160, Size: 136
void _addScreenGrabToSavedInputs() {
}

// _playbackSavedInputs(unsigned int)
// Address: 0x803E8378, Size: 4036
void _playbackSavedInputs(unsigned int p0) {
}

// _AptInternalRender(void)
// Address: 0x803E9528, Size: 80
void _AptInternalRender() {
}

// _isIndex(char *)
// Address: 0x80405718, Size: 76
void _isIndex(char * p0) {
}

// _getCharacterGridPosition(EAStringC &, int *, int *)
// Address: 0x8041B3F0, Size: 244
void _getCharacterGridPosition(EAStringC & p0, int * p1, int * p2) {
}

// _ActionConditionFlagToActionEventFlags(int)
// Address: 0x8041B89C, Size: 96
void _ActionConditionFlagToActionEventFlags(int p0) {
}

// _matrix_vecMult(float *, AptMatrix *, float *)
// Address: 0x8041BC70, Size: 76
void _matrix_vecMult(float * p0, AptMatrix * p1, float * p2) {
}

// _pointInTri(float *, float, float)
// Address: 0x8041BCBC, Size: 164
void _pointInTri(float * p0, float p1, float p2) {
}

// _constructBuiltInObjects(void)
// Address: 0x8042FB74, Size: 5412
void _constructBuiltInObjects() {
}

// _write
// Address: 0x80542A1C, Size: 80
void _write() {
}

// _printf_r
// Address: 0x805453A4, Size: 156
void _printf_r() {
}

// _sprintf_r
// Address: 0x805454EC, Size: 212
void _sprintf_r() {
}

// _strtoul_r
// Address: 0x80546AA8, Size: 408
void _strtoul_r() {
}

// _user_strerror
// Address: 0x80547538, Size: 8
void _user_strerror() {
}

// _strtol_r
// Address: 0x805486E0, Size: 432
void _strtol_r() {
}

// _f_bss
// Address: 0x806E4720, Size: 0
void _f_bss() {
}

// _e_bss
// Address: 0x8078CF80, Size: 0
void _e_bss() {
}

// _stack_end
// Address: 0x80791880, Size: 0
void _stack_end() {
}

// _stack_addr
// Address: 0x807A1880, Size: 0
void _stack_addr() {
}
