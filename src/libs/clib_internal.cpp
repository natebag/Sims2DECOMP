// clib_internal.cpp - Internal C library functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 529 functions
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
void _loadFileSize() {
}

// _loadGeometry(char *, AptAuxLayerInfo *)
// Address: 0x8000A570, Size: 628
void _loadGeometry() {
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
void _kBottomLeftWallsEndCapTest() {
}

// _kTopRightWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003D2B4, Size: 848
void _kTopRightWallsEndCapTest() {
}

// _kBottomRightWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003D604, Size: 848
void _kBottomRightWallsEndCapTest() {
}

// _kTopLeftWallsEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003D954, Size: 848
void _kTopLeftWallsEndCapTest() {
}

// _kHorizDiagWallskTopEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003DCA4, Size: 940
void _kHorizDiagWallskTopEndCapTest() {
}

// _kHorizDiagWallskBottomEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003E050, Size: 940
void _kHorizDiagWallskBottomEndCapTest() {
}

// _kVertDiagWallskRightEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003E3FC, Size: 940
void _kVertDiagWallskRightEndCapTest() {
}

// _kVertDiagWallskLeftEndCapTest(CTilePt &, TileWalls &, TileWallsSegment, DiagonalSideSelector)
// Address: 0x8003E7A8, Size: 940
void _kVertDiagWallskLeftEndCapTest() {
}

// _Default2dArrayAlloc(unsigned int)
// Address: 0x800519A0, Size: 56
void _Default2dArrayAlloc() {
}

// _Default2dArrayFree(void *)
// Address: 0x800519D8, Size: 52
void _Default2dArrayFree() {
}

// _MotiveSort(void *, void *)
// Address: 0x801A8D78, Size: 84
void _MotiveSort() {
}

// _ParseNode(CDirtyXmlNode *, unsigned char *)
// Address: 0x803AFF98, Size: 108
void _ParseNode() {
}

// _ParseNumChildNodes(unsigned char *)
// Address: 0x803B0004, Size: 148
void _ParseNumChildNodes() {
}

// _ParseChildNodes(CDirtyXmlNode **, int, unsigned char *)
// Address: 0x803B0098, Size: 204
void _ParseChildNodes() {
}

// _ParseLevel(CDirtyXmlNode *, unsigned char *)
// Address: 0x803B0164, Size: 92
void _ParseLevel() {
}

// _Parse(CDirtyXmlNode *, CDirtyXmlNode *, unsigned char *)
// Address: 0x803B01C0, Size: 116
void _Parse() {
}

// _ParseNumber(unsigned char *, unsigned int *)
// Address: 0x803B0B28, Size: 64
void _ParseNumber() {
}

// _SecsToTime(tm *, unsigned int)
// Address: 0x803B0B68, Size: 500
void _SecsToTime() {
}

// _TimeToSecs(tm *)
// Address: 0x803B0D5C, Size: 208
void _TimeToSecs() {
}

// _XmlContentChar(unsigned char *, unsigned char *)
// Address: 0x803B0E2C, Size: 404
void _XmlContentChar() {
}

// _XmlContentFind(unsigned char *)
// Address: 0x803B0FC0, Size: 76
void _XmlContentFind() {
}

// _XmlAttribFind(unsigned char *, unsigned char *)
// Address: 0x803B100C, Size: 412
void _XmlAttribFind() {
}

// _XmlAttribFindByIndex(unsigned char *, int)
// Address: 0x803B11A8, Size: 312
void _XmlAttribFindByIndex() {
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
void _passthruToMemFree() {
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
void _playbackSavedInputs() {
}

// _AptInternalRender(void)
// Address: 0x803E9528, Size: 80
void _AptInternalRender() {
}

// _isIndex(char *)
// Address: 0x80405718, Size: 76
void _isIndex() {
}

// _getCharacterGridPosition(EAStringC &, int *, int *)
// Address: 0x8041B3F0, Size: 244
void _getCharacterGridPosition() {
}

// _ActionConditionFlagToActionEventFlags(int)
// Address: 0x8041B89C, Size: 96
void _ActionConditionFlagToActionEventFlags() {
}

// _matrix_vecMult(float *, AptMatrix *, float *)
// Address: 0x8041BC70, Size: 76
void _matrix_vecMult() {
}

// _pointInTri(float *, float, float)
// Address: 0x8041BCBC, Size: 164
void _pointInTri() {
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

// _Xml_TopDecode
// Address: 0x8066CD18, Size: 256
void _Xml_TopDecode() {
}

// _Xml_BtmDecode
// Address: 0x8066CE18, Size: 256
void _Xml_BtmDecode() {
}

// _ctype_
// Address: 0x80672A98, Size: 257
void _ctype_() {
}

// _gxLightId
// Address: 0x806A1C04, Size: 32
void _gxLightId() {
}

// _DAYS_BEFORE_MONTH
// Address: 0x806A5620, Size: 48
void _DAYS_BEFORE_MONTH() {
}

// _aptTriangleUVidx
// Address: 0x806A5B20, Size: 48
void _aptTriangleUVidx() {
}

// _wallEndCapFnTab
// Address: 0x806A63E0, Size: 32
void _wallEndCapFnTab() {
}

// _WallSplitTestFnTab
// Address: 0x806A6400, Size: 24
void _WallSplitTestFnTab() {
}

// _segTab
// Address: 0x806A6418, Size: 24
void _segTab() {
}

// _exit_dummy_decl
// Address: 0x806C3364, Size: 4
void _exit_dummy_decl() {
}

// _aClipEvents
// Address: 0x806C6018, Size: 48
void _aClipEvents() {
}

// _aInputFlags
// Address: 0x806C61AC, Size: 84
void _aInputFlags() {
}

// _aListenerEvents
// Address: 0x806C6200, Size: 48
void _aListenerEvents() {
}

// _estring2Error
// Address: 0x806C7594, Size: 16
void _estring2Error() {
}

// _gCUICursorArrow
// Address: 0x806C766C, Size: 256
void _gCUICursorArrow() {
}

// _gCUICursorMove
// Address: 0x806C776C, Size: 256
void _gCUICursorMove() {
}

// _gCUICursorResizeLeftToRight
// Address: 0x806C786C, Size: 256
void _gCUICursorResizeLeftToRight() {
}

// _gCUICursorResizeUpToDown
// Address: 0x806C796C, Size: 256
void _gCUICursorResizeUpToDown() {
}

// _gCUICursorResizeUpLeftToDownRight
// Address: 0x806C7A6C, Size: 256
void _gCUICursorResizeUpLeftToDownRight() {
}

// _gCUICursorResizeDownLeftToUpRight
// Address: 0x806C7B6C, Size: 256
void _gCUICursorResizeDownLeftToUpRight() {
}

// _ngcPerf0Stats
// Address: 0x806CB900, Size: 768
void _ngcPerf0Stats() {
}

// _ctors
// Address: 0x806CCBF0, Size: 8
void _ctors() {
}

// _dtors
// Address: 0x806CCBF8, Size: 8
void _dtors() {
}

// _exit_dummy_ref
// Address: 0x806CCC28, Size: 4
void _exit_dummy_ref() {
}

// _app
// Address: 0x806E4848, Size: 1216
void _app() {
}

// _gAwarenessTweakTool
// Address: 0x806ECB60, Size: 48
void _gAwarenessTweakTool() {
}

// _gAutorunTweakTool
// Address: 0x806ECB90, Size: 28
void _gAutorunTweakTool() {
}

// _simsdataman
// Address: 0x806ED06C, Size: 3384
void _simsdataman() {
}

// _dummyFile
// Address: 0x806EDDA4, Size: 48
void _dummyFile() {
}

// _vGhostGreen
// Address: 0x806EEC7C, Size: 12
void _vGhostGreen() {
}

// _ESim_GreenLight
// Address: 0x806EEC88, Size: 248
void _ESim_GreenLight() {
}

// _gFlashTextColorTool
// Address: 0x806EF6B8, Size: 88
void _gFlashTextColorTool() {
}

// _gd
// Address: 0x806EF710, Size: 304
void _gd() {
}

// _sNoCtrlMessageBuff
// Address: 0x806EF840, Size: 160
void _sNoCtrlMessageBuff() {
}

// _globals
// Address: 0x806EF95C, Size: 1184
void _globals() {
}

// _vBlueBack
// Address: 0x806EFDFC, Size: 16
void _vBlueBack() {
}

// _BLUEBLACK
// Address: 0x806EFE0C, Size: 16
void _BLUEBLACK() {
}

// _WHITE
// Address: 0x806EFE1C, Size: 16
void _WHITE() {
}

// _BLACK
// Address: 0x806EFE2C, Size: 16
void _BLACK() {
}

// _YELLOW
// Address: 0x806EFE3C, Size: 16
void _YELLOW() {
}

// _BLUE
// Address: 0x806EFE4C, Size: 16
void _BLUE() {
}

// _RED
// Address: 0x806EFE5C, Size: 16
void _RED() {
}

// _GREEN
// Address: 0x806EFE6C, Size: 16
void _GREEN() {
}

// _CYAN
// Address: 0x806EFE7C, Size: 16
void _CYAN() {
}

// _MAJENTA
// Address: 0x806EFE8C, Size: 16
void _MAJENTA() {
}

// _GREAY
// Address: 0x806EFE9C, Size: 16
void _GREAY() {
}

// _LT_GREAY
// Address: 0x806EFEAC, Size: 16
void _LT_GREAY() {
}

// _DK_GREAY
// Address: 0x806EFEBC, Size: 16
void _DK_GREAY() {
}

// _ORANGE
// Address: 0x806EFECC, Size: 16
void _ORANGE() {
}

// _LT_BLUE
// Address: 0x806EFEDC, Size: 16
void _LT_BLUE() {
}

// _PRESSED
// Address: 0x806EFEEC, Size: 16
void _PRESSED() {
}

// _mFloorVecZero
// Address: 0x806EFEFC, Size: 12
void _mFloorVecZero() {
}

// _tileStripPool
// Address: 0x806EFF08, Size: 10400
void _tileStripPool() {
}

// _lightingBuffer
// Address: 0x806F2E14, Size: 47628
void _lightingBuffer() {
}

// _vertexSpanPool
// Address: 0x806FE820, Size: 1950
void _vertexSpanPool() {
}

// _hlcolor
// Address: 0x806FEFC0, Size: 12
void _hlcolor() {
}

// _hlcolor2
// Address: 0x806FEFCC, Size: 12
void _hlcolor2() {
}

// _gBlendingTweakTool
// Address: 0x806FF1D4, Size: 64
void _gBlendingTweakTool() {
}

// _gMiscTweakTool
// Address: 0x806FF214, Size: 64
void _gMiscTweakTool() {
}

// _gDirectControlTweakTool
// Address: 0x806FF254, Size: 72
void _gDirectControlTweakTool() {
}

// _gScreenshotTool
// Address: 0x806FF29C, Size: 20
void _gScreenshotTool() {
}

// _clock
// Address: 0x806FF4C0, Size: 16
void _clock() {
}

// _gSimProbe
// Address: 0x807011D8, Size: 20
void _gSimProbe() {
}

// _houseGameStatus
// Address: 0x80701350, Size: 192
void _houseGameStatus() {
}

// _gWantFearCUIMenu
// Address: 0x807017C8, Size: 24
void _gWantFearCUIMenu() {
}

// _gInnerLayerTorsoCasCUIMenu
// Address: 0x80702A50, Size: 24
void _gInnerLayerTorsoCasCUIMenu() {
}

// _gMidLayerTorsoCasCUIMenu
// Address: 0x80702A68, Size: 24
void _gMidLayerTorsoCasCUIMenu() {
}

// _gOuterLayerTorsoCasCUIMenu
// Address: 0x80702A80, Size: 24
void _gOuterLayerTorsoCasCUIMenu() {
}

// _gLowerBodyShoesCasCUIMenu
// Address: 0x80702A98, Size: 24
void _gLowerBodyShoesCasCUIMenu() {
}

// _gHeadHatHairCasCUIMenu
// Address: 0x80702AB0, Size: 24
void _gHeadHatHairCasCUIMenu() {
}

// _gTattoosFacialFeatureCasCUIMenu
// Address: 0x80702AC8, Size: 24
void _gTattoosFacialFeatureCasCUIMenu() {
}

// _gAccessoriesCasCUIMenu
// Address: 0x80702AE0, Size: 24
void _gAccessoriesCasCUIMenu() {
}

// _gAccessories2CasCUIMenu
// Address: 0x80702AF8, Size: 24
void _gAccessories2CasCUIMenu() {
}

// _vInitialSimPos
// Address: 0x80702C48, Size: 12
void _vInitialSimPos() {
}

// _vInitialSimScale
// Address: 0x80702C54, Size: 12
void _vInitialSimScale() {
}

// _gCasTweakTool
// Address: 0x80702D80, Size: 308
void _gCasTweakTool() {
}

// _gLoadSaveMenu
// Address: 0x807032E4, Size: 24
void _gLoadSaveMenu() {
}

// _gMemoryCardUsage
// Address: 0x807032FC, Size: 24
void _gMemoryCardUsage() {
}

// _levelman
// Address: 0x80703B64, Size: 3360
void _levelman() {
}

// _gLevelTuning
// Address: 0x8070B9F4, Size: 240
void _gLevelTuning() {
}

// _DirtyXml_strRetnBuf0
// Address: 0x8070BB38, Size: 128
void _DirtyXml_strRetnBuf0() {
}

// _DirtyXml_strRetnBuf1
// Address: 0x8070BBB8, Size: 128
void _DirtyXml_strRetnBuf1() {
}

// _eorFileSys
// Address: 0x807194E4, Size: 36
void _eorFileSys() {
}

// _X_AXIS
// Address: 0x80722BFC, Size: 12
void _X_AXIS() {
}

// _Y_AXIS
// Address: 0x80722C08, Size: 12
void _Y_AXIS() {
}

// _Z_AXIS
// Address: 0x80722C14, Size: 12
void _Z_AXIS() {
}

// _background
// Address: 0x80730528, Size: 952
void _background() {
}

// _mId
// Address: 0x80735990, Size: 64
void _mId() {
}

// _mShadowId
// Address: 0x807359D0, Size: 64
void _mShadowId() {
}

// _qId
// Address: 0x80735A10, Size: 16
void _qId() {
}

// _vZero
// Address: 0x80735A20, Size: 12
void _vZero() {
}

// _vAxes
// Address: 0x80735A2C, Size: 36
void _vAxes() {
}

// _sysclock
// Address: 0x80735A50, Size: 16
void _sysclock() {
}

// _idleThread
// Address: 0x80735A60, Size: 832
void _idleThread() {
}

// _debugShaders
// Address: 0x807390E0, Size: 100
void _debugShaders() {
}

// _gZoomTool
// Address: 0x807391B0, Size: 36
void _gZoomTool() {
}

// _gCUI
// Address: 0x807396E8, Size: 88
void _gCUI() {
}

// _debugmenu
// Address: 0x8073BF5C, Size: 28
void _debugmenu() {
}

// _labelColor
// Address: 0x8073BF78, Size: 12
void _labelColor() {
}

// _valueColor
// Address: 0x8073BF84, Size: 12
void _valueColor() {
}

// _debugprint
// Address: 0x8073BF90, Size: 16
void _debugprint() {
}

// _frag
// Address: 0x8073C020, Size: 56
void _frag() {
}

// _fpsIndicator
// Address: 0x8073C058, Size: 128
void _fpsIndicator() {
}

// _tweak
// Address: 0x8073F840, Size: 72
void _tweak() {
}

// _interestFade
// Address: 0x8073F888, Size: 200
void _interestFade() {
}

// _resLoader
// Address: 0x8073FA40, Size: 1040
void _resLoader() {
}

// _resPrefetch
// Address: 0x8073FE88, Size: 1048
void _resPrefetch() {
}

// _gParticleSysTuning
// Address: 0x807402A0, Size: 44
void _gParticleSysTuning() {
}

// _animman
// Address: 0x80741660, Size: 3360
void _animman() {
}

// _audiostreamman
// Address: 0x80742380, Size: 3360
void _audiostreamman() {
}

// _binaryman
// Address: 0x807430A0, Size: 3360
void _binaryman() {
}

// _characterman
// Address: 0x80743DC0, Size: 3360
void _characterman() {
}

// _datasetman
// Address: 0x80744B80, Size: 3364
void _datasetman() {
}

// _edithtreesetman
// Address: 0x807458A4, Size: 3360
void _edithtreesetman() {
}

// _flashman
// Address: 0x807465C4, Size: 3360
void _flashman() {
}

// _fontman
// Address: 0x807472E4, Size: 3360
void _fontman() {
}

// _modelman
// Address: 0x80748004, Size: 3360
void _modelman() {
}

// _movieman
// Address: 0x80748D24, Size: 3364
void _movieman() {
}

// _quickdataman
// Address: 0x80749A48, Size: 3368
void _quickdataman() {
}

// _scratchBuffMan
// Address: 0x8074A804, Size: 20
void _scratchBuffMan() {
}

// _shaderman
// Address: 0x8074A818, Size: 3360
void _shaderman() {
}

// _textureman
// Address: 0x8074CF78, Size: 3360
void _textureman() {
}

// _particleman
// Address: 0x80750408, Size: 3360
void _particleman() {
}

// _ngcAudio
// Address: 0x80751140, Size: 120
void _ngcAudio() {
}

// _ngcAudioSampleMan
// Address: 0x80752620, Size: 3368
void _ngcAudioSampleMan() {
}

// _ngcctrlman
// Address: 0x80753354, Size: 84
void _ngcctrlman() {
}

// _ngcEngine
// Address: 0x807533C0, Size: 88
void _ngcEngine() {
}

// _ngcGfx
// Address: 0x80755B58, Size: 816
void _ngcGfx() {
}

// _ngc32Mouse
// Address: 0x8075FEA0, Size: 36
void _ngc32Mouse() {
}

// _ngcRenderer
// Address: 0x80764138, Size: 18024
void _ngcRenderer() {
}

// _ngcCreateGXMutex
// Address: 0x807687BC, Size: 28
void _ngcCreateGXMutex() {
}

// _rsPrev
// Address: 0x80769778, Size: 2524
void _rsPrev() {
}

// _ngcSched
// Address: 0x8076B1D0, Size: 960
void _ngcSched() {
}

// _clampAptColorsAt128
// Address: 0x8078CFD0, Size: 4
void _clampAptColorsAt128() {
}

// _eIFloorAllocPool
// Address: 0x8078D168, Size: 4
void _eIFloorAllocPool() {
}

// _newlightint
// Address: 0x8078D190, Size: 4
void _newlightint() {
}

// _newlightfallstart
// Address: 0x8078D194, Size: 4
void _newlightfallstart() {
}

// _newlightfallend
// Address: 0x8078D198, Size: 4
void _newlightfallend() {
}

// _wallobjscale
// Address: 0x8078D19C, Size: 4
void _wallobjscale() {
}

// _hlphase
// Address: 0x8078D1A0, Size: 8
void _hlphase() {
}

// _hllastframe
// Address: 0x8078D1A8, Size: 4
void _hllastframe() {
}

// _hlfreq
// Address: 0x8078D1AC, Size: 4
void _hlfreq() {
}

// _hlstartamp
// Address: 0x8078D1B0, Size: 4
void _hlstartamp() {
}

// _hlstartlen
// Address: 0x8078D1B4, Size: 4
void _hlstartlen() {
}

// _hlpulseamp
// Address: 0x8078D1B8, Size: 4
void _hlpulseamp() {
}

// _hlpulselen
// Address: 0x8078D1BC, Size: 4
void _hlpulselen() {
}

// _hlminscalestart
// Address: 0x8078D1C0, Size: 4
void _hlminscalestart() {
}

// _hlminscalepulse
// Address: 0x8078D1C4, Size: 4
void _hlminscalepulse() {
}

// _ISOM_bUpdateWarn
// Address: 0x8078D1CC, Size: 4
void _ISOM_bUpdateWarn() {
}

// _ISOM_bInitWarn
// Address: 0x8078D1D0, Size: 4
void _ISOM_bInitWarn() {
}

// _drawbulbpos
// Address: 0x8078D1D4, Size: 4
void _drawbulbpos() {
}

// _isom_minburpscale
// Address: 0x8078D1D8, Size: 4
void _isom_minburpscale() {
}

// _isom_maxburpscale
// Address: 0x8078D1DC, Size: 4
void _isom_maxburpscale() {
}

// _adjSunIntensity
// Address: 0x8078D1E0, Size: 4
void _adjSunIntensity() {
}

// _pBoundRectDL
// Address: 0x8078D1F0, Size: 4
void _pBoundRectDL() {
}

// _cursorlightfadedur
// Address: 0x8078D200, Size: 4
void _cursorlightfadedur() {
}

// _bShowAnimNames
// Address: 0x8078D290, Size: 4
void _bShowAnimNames() {
}

// _p1head_xoff
// Address: 0x8078D3D8, Size: 4
void _p1head_xoff() {
}

// _p1head_yoff
// Address: 0x8078D3DC, Size: 4
void _p1head_yoff() {
}

// _p2head_xoff
// Address: 0x8078D3E0, Size: 4
void _p2head_xoff() {
}

// _p2head_yoff
// Address: 0x8078D3E4, Size: 4
void _p2head_yoff() {
}

// _button_yoff
// Address: 0x8078D3F0, Size: 4
void _button_yoff() {
}

// _lbutton_xoff
// Address: 0x8078D3F4, Size: 4
void _lbutton_xoff() {
}

// _rbutton_xoff
// Address: 0x8078D3F8, Size: 4
void _rbutton_xoff() {
}

// _head_win_l
// Address: 0x8078D3FC, Size: 4
void _head_win_l() {
}

// _head_win_r
// Address: 0x8078D400, Size: 4
void _head_win_r() {
}

// _head_win_t
// Address: 0x8078D404, Size: 4
void _head_win_t() {
}

// _head_win_b
// Address: 0x8078D408, Size: 4
void _head_win_b() {
}

// _quick_stat_w
// Address: 0x8078D40C, Size: 4
void _quick_stat_w() {
}

// _quick_stat_h
// Address: 0x8078D410, Size: 4
void _quick_stat_h() {
}

// _quick_stat_xoff
// Address: 0x8078D414, Size: 4
void _quick_stat_xoff() {
}

// _quick_stat_yoff
// Address: 0x8078D418, Size: 4
void _quick_stat_yoff() {
}

// _p1yshift
// Address: 0x8078D49C, Size: 4
void _p1yshift() {
}

// _p1xshift
// Address: 0x8078D4A0, Size: 4
void _p1xshift() {
}

// _2pdivBlend
// Address: 0x8078D4A4, Size: 4
void _2pdivBlend() {
}

// _assertionFailed
// Address: 0x8078D564, Size: 4
void _assertionFailed() {
}

// _bombed
// Address: 0x8078D568, Size: 4
void _bombed() {
}

// _ACT_exists
// Address: 0x8078DB04, Size: 4
void _ACT_exists() {
}

// _ACT_show_callback
// Address: 0x8078DB10, Size: 4
void _ACT_show_callback() {
}

// _ACT_hide_callback
// Address: 0x8078DB1C, Size: 4
void _ACT_hide_callback() {
}

// _BBH_exists
// Address: 0x8078DD64, Size: 4
void _BBH_exists() {
}

// _BBH_show_callback
// Address: 0x8078DD6C, Size: 4
void _BBH_show_callback() {
}

// _BBH_hide_callback
// Address: 0x8078DD74, Size: 4
void _BBH_hide_callback() {
}

// _BBH_mode
// Address: 0x8078DD7C, Size: 4
void _BBH_mode() {
}

// _BBH_price
// Address: 0x8078DD84, Size: 4
void _BBH_price() {
}

// _CXM_exists
// Address: 0x8078DDA8, Size: 4
void _CXM_exists() {
}

// _CXM_show_callback
// Address: 0x8078DDB4, Size: 4
void _CXM_show_callback() {
}

// _CXM_hide_callback
// Address: 0x8078DDC0, Size: 4
void _CXM_hide_callback() {
}

// _CXM_hourglass_show_callback
// Address: 0x8078DDCC, Size: 4
void _CXM_hourglass_show_callback() {
}

// _CXM_hourglass_hide_callback
// Address: 0x8078DDD8, Size: 4
void _CXM_hourglass_hide_callback() {
}

// _CXM_list
// Address: 0x8078DE34, Size: 4
void _CXM_list() {
}

// _CXM_hourglass_swf
// Address: 0x8078DE38, Size: 4
void _CXM_hourglass_swf() {
}

// _CXM_hourglass
// Address: 0x8078DE3C, Size: 4
void _CXM_hourglass() {
}

// _CXM_IconShader
// Address: 0x8078DE40, Size: 4
void _CXM_IconShader() {
}

// _CXM_item_backdrop
// Address: 0x8078DE44, Size: 4
void _CXM_item_backdrop() {
}

// _FAM_GETVAR_CURRENT_STATE
// Address: 0x8078DEFC, Size: 4
void _FAM_GETVAR_CURRENT_STATE() {
}

// _H2D_DPAD_UP
// Address: 0x8078DF38, Size: 4
void _H2D_DPAD_UP() {
}

// _H2D_DPAD_DOWN
// Address: 0x8078DF44, Size: 4
void _H2D_DPAD_DOWN() {
}

// _H2D_DPAD_LEFT
// Address: 0x8078DF50, Size: 4
void _H2D_DPAD_LEFT() {
}

// _H2D_DPAD_RIGHT
// Address: 0x8078DF5C, Size: 4
void _H2D_DPAD_RIGHT() {
}

// _H2D_PAUSE
// Address: 0x8078DF68, Size: 4
void _H2D_PAUSE() {
}

// _H2D_SELECT
// Address: 0x8078DF74, Size: 4
void _H2D_SELECT() {
}

// _H2D_CANCEL
// Address: 0x8078DF80, Size: 4
void _H2D_CANCEL() {
}

// _MMU_CANCEL_BUTTON
// Address: 0x8078DF94, Size: 4
void _MMU_CANCEL_BUTTON() {
}

// _MMU_LEFT_BUTTON
// Address: 0x8078DF98, Size: 4
void _MMU_LEFT_BUTTON() {
}

// _MMU_RIGHT_BUTTON
// Address: 0x8078DF9C, Size: 4
void _MMU_RIGHT_BUTTON() {
}

// _MMU_UP_BUTTON
// Address: 0x8078DFA0, Size: 4
void _MMU_UP_BUTTON() {
}

// _MMU_DOWN_BUTTON
// Address: 0x8078DFA4, Size: 4
void _MMU_DOWN_BUTTON() {
}

// _MMU_X_BUTTON
// Address: 0x8078DFA8, Size: 4
void _MMU_X_BUTTON() {
}

// _MMU_CIRCLE_BUTTON
// Address: 0x8078DFAC, Size: 4
void _MMU_CIRCLE_BUTTON() {
}

// _MMU_SET_MENU_STATE
// Address: 0x8078DFB0, Size: 4
void _MMU_SET_MENU_STATE() {
}

// _MMU_GO_UP_TREE
// Address: 0x8078DFB4, Size: 4
void _MMU_GO_UP_TREE() {
}

// _MMU_INCREMENT_CURRENT_CHOICE
// Address: 0x8078DFB8, Size: 4
void _MMU_INCREMENT_CURRENT_CHOICE() {
}

// _MMU_DECREMENT_CURRENT_CHOICE
// Address: 0x8078DFBC, Size: 4
void _MMU_DECREMENT_CURRENT_CHOICE() {
}

// _MMU_SET_CURRENT_CHOICE
// Address: 0x8078DFC0, Size: 4
void _MMU_SET_CURRENT_CHOICE() {
}

// _MMU_SET_DEVMENU_STATE
// Address: 0x8078DFC4, Size: 4
void _MMU_SET_DEVMENU_STATE() {
}

// _MMU_NGH_INDEX
// Address: 0x8078DFC8, Size: 4
void _MMU_NGH_INDEX() {
}

// _MMU_LOT_INDEX
// Address: 0x8078DFCC, Size: 4
void _MMU_LOT_INDEX() {
}

// _MMU_GETVAR_CURRENT_STATE
// Address: 0x8078DFD0, Size: 4
void _MMU_GETVAR_CURRENT_STATE() {
}

// _MMU_GETVAR_NUMBER_OF_CHOICES_FOR_CURRENT_STATE
// Address: 0x8078DFD4, Size: 4
void _MMU_GETVAR_NUMBER_OF_CHOICES_FOR_CURRENT_STATE() {
}

// _MOD_exists
// Address: 0x8078DFF0, Size: 4
void _MOD_exists() {
}

// _MOD_text_show_callback
// Address: 0x8078DFFC, Size: 4
void _MOD_text_show_callback() {
}

// _MOD_text_hide_callback
// Address: 0x8078E008, Size: 4
void _MOD_text_hide_callback() {
}

// _MOD_show_callback
// Address: 0x8078E014, Size: 4
void _MOD_show_callback() {
}

// _MOD_hide_callback
// Address: 0x8078E020, Size: 4
void _MOD_hide_callback() {
}

// _MOD_Aspiration
// Address: 0x8078E02C, Size: 4
void _MOD_Aspiration() {
}

// _MOT_exists
// Address: 0x8078E08C, Size: 4
void _MOT_exists() {
}

// _MOT_text_show_callback
// Address: 0x8078E098, Size: 4
void _MOT_text_show_callback() {
}

// _MOT_text_hide_callback
// Address: 0x8078E0A4, Size: 4
void _MOT_text_hide_callback() {
}

// _MOT_show_callback
// Address: 0x8078E0B0, Size: 4
void _MOT_show_callback() {
}

// _MOT_hide_callback
// Address: 0x8078E0BC, Size: 4
void _MOT_hide_callback() {
}

// _O2T_Close_Screen
// Address: 0x8078E188, Size: 4
void _O2T_Close_Screen() {
}

// _O2T_Get_Cam_Rot_DC
// Address: 0x8078E18C, Size: 4
void _O2T_Get_Cam_Rot_DC() {
}

// _RMD_exists
// Address: 0x8078E1C8, Size: 4
void _RMD_exists() {
}

// _RMD_SELECT_BUTTON
// Address: 0x8078E1D0, Size: 4
void _RMD_SELECT_BUTTON() {
}

// _show_tween_RMD
// Address: 0x8078E1D8, Size: 4
void _show_tween_RMD() {
}

// _hide_tween_RMD
// Address: 0x8078E1E0, Size: 4
void _hide_tween_RMD() {
}

// _RMD_title
// Address: 0x8078E1E8, Size: 4
void _RMD_title() {
}

// _RMD_btn_text
// Address: 0x8078E1F0, Size: 4
void _RMD_btn_text() {
}

// _SKL_exists
// Address: 0x8078E224, Size: 4
void _SKL_exists() {
}

// _SKL_text_show_callback
// Address: 0x8078E230, Size: 4
void _SKL_text_show_callback() {
}

// _SKL_text_hide_callback
// Address: 0x8078E23C, Size: 4
void _SKL_text_hide_callback() {
}

// _SKL_show_callback
// Address: 0x8078E248, Size: 4
void _SKL_show_callback() {
}

// _SKL_hide_callback
// Address: 0x8078E254, Size: 4
void _SKL_hide_callback() {
}

// _skill0_SKL
// Address: 0x8078E260, Size: 4
void _skill0_SKL() {
}

// _skill1_SKL
// Address: 0x8078E26C, Size: 4
void _skill1_SKL() {
}

// _skill2_SKL
// Address: 0x8078E278, Size: 4
void _skill2_SKL() {
}

// _skill3_SKL
// Address: 0x8078E284, Size: 4
void _skill3_SKL() {
}

// _skill4_SKL
// Address: 0x8078E290, Size: 4
void _skill4_SKL() {
}

// _skill5_SKL
// Address: 0x8078E29C, Size: 4
void _skill5_SKL() {
}

// _skill6_SKL
// Address: 0x8078E2A8, Size: 4
void _skill6_SKL() {
}

// _WAF_exists
// Address: 0x8078E36C, Size: 4
void _WAF_exists() {
}

// _WAF_text_show_callback
// Address: 0x8078E378, Size: 4
void _WAF_text_show_callback() {
}

// _WAF_text_hide_callback
// Address: 0x8078E384, Size: 4
void _WAF_text_hide_callback() {
}

// _WAF_show_callback
// Address: 0x8078E390, Size: 4
void _WAF_show_callback() {
}

// _WAF_hide_callback
// Address: 0x8078E39C, Size: 4
void _WAF_hide_callback() {
}

// _WAF_glow_full_complete
// Address: 0x8078E3A8, Size: 4
void _WAF_glow_full_complete() {
}

// _WAF_glow_away_complete
// Address: 0x8078E3B4, Size: 4
void _WAF_glow_away_complete() {
}

// _WAF_top_tween_complete
// Address: 0x8078E3C0, Size: 4
void _WAF_top_tween_complete() {
}

// _WAF_bottom_tween_complete
// Address: 0x8078E3CC, Size: 4
void _WAF_bottom_tween_complete() {
}

// _WAF_callout_container
// Address: 0x8078E530, Size: 4
void _WAF_callout_container() {
}

// _WAF_swf0
// Address: 0x8078E564, Size: 4
void _WAF_swf0() {
}

// _WAF_swf1
// Address: 0x8078E568, Size: 4
void _WAF_swf1() {
}

// _WAF_swf2
// Address: 0x8078E56C, Size: 4
void _WAF_swf2() {
}

// _WAF_swf3
// Address: 0x8078E570, Size: 4
void _WAF_swf3() {
}

// _WAF_swf4
// Address: 0x8078E574, Size: 4
void _WAF_swf4() {
}

// _WAF_swf5
// Address: 0x8078E578, Size: 4
void _WAF_swf5() {
}

// _WAF_swf6
// Address: 0x8078E57C, Size: 4
void _WAF_swf6() {
}

// _INT
// Address: 0x8078E5CC, Size: 4
void _INT() {
}

// _INT_exists
// Address: 0x8078E5D8, Size: 4
void _INT_exists() {
}

// _INT_reset_rel
// Address: 0x8078E5E4, Size: 4
void _INT_reset_rel() {
}

// _INT_show_callback
// Address: 0x8078E5F0, Size: 4
void _INT_show_callback() {
}

// _INT_hide_callback
// Address: 0x8078E5FC, Size: 4
void _INT_hide_callback() {
}

// _INT_anim_end
// Address: 0x8078E608, Size: 4
void _INT_anim_end() {
}

// _INT_rel
// Address: 0x8078E614, Size: 4
void _INT_rel() {
}

// _INT_bonus
// Address: 0x8078E620, Size: 4
void _INT_bonus() {
}

// _INT_reldata
// Address: 0x8078E62C, Size: 4
void _INT_reldata() {
}

// _INT_sum
// Address: 0x8078E638, Size: 4
void _INT_sum() {
}

// _INT_rel2
// Address: 0x8078E644, Size: 4
void _INT_rel2() {
}

// _INT_CXM_arrow_up
// Address: 0x8078E658, Size: 4
void _INT_CXM_arrow_up() {
}

// _INT_swf
// Address: 0x8078E65C, Size: 4
void _INT_swf() {
}

// _instanceContext
// Address: 0x8078E718, Size: 4
void _instanceContext() {
}

// _portalOffset
// Address: 0x8078E74C, Size: 4
void _portalOffset() {
}

// _register_malloc
// Address: 0x8078E970, Size: 4
void _register_malloc() {
}

// _register_free
// Address: 0x8078E974, Size: 4
void _register_free() {
}

// _impure_ptr
// Address: 0x8078E99C, Size: 4
void _impure_ptr() {
}

// _fixedStringNull
// Address: 0x8078EDC8, Size: 4
void _fixedStringNull() {
}

// _urandseed
// Address: 0x8078EDDC, Size: 4
void _urandseed() {
}

// _estring2Null
// Address: 0x8078EDF4, Size: 2
void _estring2Null() {
}

// _ngcValidateStacks
// Address: 0x8078EDF8, Size: 4
void _ngcValidateStacks() {
}

// _pApp
// Address: 0x8078EE38, Size: 4
void _pApp() {
}

// _evenodd
// Address: 0x8078EE48, Size: 4
void _evenodd() {
}

// _framecount
// Address: 0x8078EE4C, Size: 4
void _framecount() {
}

// _retracecount
// Address: 0x8078EE50, Size: 4
void _retracecount() {
}

// _d_retraces
// Address: 0x8078EE54, Size: 4
void _d_retraces() {
}

// _dt
// Address: 0x8078EE58, Size: 4
void _dt() {
}

// _gamedt
// Address: 0x8078EE5C, Size: 4
void _gamedt() {
}

// _invdt
// Address: 0x8078EE60, Size: 4
void _invdt() {
}

// _fps
// Address: 0x8078EE64, Size: 4
void _fps() {
}

// _cputime
// Address: 0x8078EE68, Size: 4
void _cputime() {
}

// _cputime_m1
// Address: 0x8078EE6C, Size: 4
void _cputime_m1() {
}

// _cputime_m2
// Address: 0x8078EE70, Size: 4
void _cputime_m2() {
}

// _rendtime
// Address: 0x8078EE74, Size: 4
void _rendtime() {
}

// _rendtime_m1
// Address: 0x8078EE78, Size: 4
void _rendtime_m1() {
}

// _rendtime_m2
// Address: 0x8078EE7C, Size: 4
void _rendtime_m2() {
}

// _time
// Address: 0x8078EE80, Size: 8
void _time() {
}

// _pExitFunc
// Address: 0x8078EEA8, Size: 4
void _pExitFunc() {
}

// _localizationShaders
// Address: 0x8078EF68, Size: 4
void _localizationShaders() {
}

// _localizationShadersCount
// Address: 0x8078EF6C, Size: 4
void _localizationShadersCount() {
}

// _lastCtrlUpdate
// Address: 0x8078EFA0, Size: 4
void _lastCtrlUpdate() {
}

// _pActualAudio
// Address: 0x8078F004, Size: 4
void _pActualAudio() {
}

// _pClockMan
// Address: 0x8078F024, Size: 4
void _pClockMan() {
}

// _ngcCtrlPads
// Address: 0x8078F028, Size: 4
void _ngcCtrlPads() {
}

// _pCtrlMan
// Address: 0x8078F02C, Size: 4
void _pCtrlMan() {
}

// _pEngine
// Address: 0x8078F038, Size: 4
void _pEngine() {
}

// _pGfx
// Address: 0x8078F0B0, Size: 4
void _pGfx() {
}

// _ngcDrawPerfStats
// Address: 0x8078F0B4, Size: 4
void _ngcDrawPerfStats() {
}

// _pKeyboard
// Address: 0x8078F0B8, Size: 4
void _pKeyboard() {
}

// _pMemoryCard
// Address: 0x8078F0C0, Size: 4
void _pMemoryCard() {
}

// _ngcMemCardCardDead
// Address: 0x8078F0C4, Size: 4
void _ngcMemCardCardDead() {
}

// _pMouse
// Address: 0x8078F0C8, Size: 4
void _pMouse() {
}

// _ngcPerfStatsEnabled
// Address: 0x8078F0F8, Size: 4
void _ngcPerfStatsEnabled() {
}

// _ngcPerf0StatCount
// Address: 0x8078F100, Size: 4
void _ngcPerf0StatCount() {
}

// _ngcUseGXDisplayList
// Address: 0x8078F108, Size: 4
void _ngcUseGXDisplayList() {
}

// _pRend
// Address: 0x8078F110, Size: 4
void _pRend() {
}

// _ngcSkip2D
// Address: 0x8078F114, Size: 4
void _ngcSkip2D() {
}

// _ngcSkipFrameEffects
// Address: 0x8078F118, Size: 4
void _ngcSkipFrameEffects() {
}

// _ngcBloomNumIterations
// Address: 0x8078F11C, Size: 4
void _ngcBloomNumIterations() {
}

// _ngcBloomInitialSize
// Address: 0x8078F120, Size: 4
void _ngcBloomInitialSize() {
}

// _ngcVBlankLimiter
// Address: 0x8078F124, Size: 4
void _ngcVBlankLimiter() {
}

// _vertsperframe
// Address: 0x8078F128, Size: 4
void _vertsperframe() {
}

// _aveclockspervert
// Address: 0x8078F12C, Size: 4
void _aveclockspervert() {
}

// _avestriplength
// Address: 0x8078F130, Size: 4
void _avestriplength() {
}

// _ngcAveClocksPerVert
// Address: 0x8078F134, Size: 4
void _ngcAveClocksPerVert() {
}

// _ngcAveStripLength
// Address: 0x8078F138, Size: 4
void _ngcAveStripLength() {
}

// _ngcStrips
// Address: 0x8078F13C, Size: 4
void _ngcStrips() {
}

// _ngcVerts
// Address: 0x8078F140, Size: 4
void _ngcVerts() {
}

// _ngcFrameCount
// Address: 0x8078F144, Size: 4
void _ngcFrameCount() {
}

// _ngcStateChangesPerFrame
// Address: 0x8078F148, Size: 4
void _ngcStateChangesPerFrame() {
}

// _ngcDrawStrips
// Address: 0x8078F14C, Size: 4
void _ngcDrawStrips() {
}

// _ngcDraw2D
// Address: 0x8078F150, Size: 4
void _ngcDraw2D() {
}

// _ngcDrawStats
// Address: 0x8078F154, Size: 4
void _ngcDrawStats() {
}

// _ngcDrawPerf
// Address: 0x8078F158, Size: 4
void _ngcDrawPerf() {
}

// _ngcDraw2ndPass
// Address: 0x8078F15C, Size: 4
void _ngcDraw2ndPass() {
}

// _ngcDrawWeighted
// Address: 0x8078F160, Size: 4
void _ngcDrawWeighted() {
}

// _ngcFakeWeightedBlendTransform
// Address: 0x8078F164, Size: 4
void _ngcFakeWeightedBlendTransform() {
}

// _ngcDrawReflection
// Address: 0x8078F168, Size: 4
void _ngcDrawReflection() {
}

// _ngcFakeReflection
// Address: 0x8078F16C, Size: 4
void _ngcFakeReflection() {
}

// _ngcIgnoreTexGen
// Address: 0x8078F170, Size: 4
void _ngcIgnoreTexGen() {
}

// _ngcShowLightmaps
// Address: 0x8078F174, Size: 4
void _ngcShowLightmaps() {
}

// _ngcDoubleLightmaps
// Address: 0x8078F178, Size: 4
void _ngcDoubleLightmaps() {
}

// _ngcTexturesEnabled
// Address: 0x8078F17C, Size: 4
void _ngcTexturesEnabled() {
}

// _ngcClipEnabled
// Address: 0x8078F180, Size: 4
void _ngcClipEnabled() {
}

// _ngcRenderEmpty
// Address: 0x8078F184, Size: 4
void _ngcRenderEmpty() {
}

// _ngcDebugVal
// Address: 0x8078F188, Size: 4
void _ngcDebugVal() {
}

// _ngcDebugIndex
// Address: 0x8078F18C, Size: 4
void _ngcDebugIndex() {
}

// _ngcBrightness
// Address: 0x8078F190, Size: 4
void _ngcBrightness() {
}

// _ngcSoftwareTC1
// Address: 0x8078F194, Size: 4
void _ngcSoftwareTC1() {
}

// _ngcTripleBuffer
// Address: 0x8078F198, Size: 4
void _ngcTripleBuffer() {
}

// _ngcBlurScale
// Address: 0x8078F19C, Size: 4
void _ngcBlurScale() {
}

// _ngcScrambleRectPixels
// Address: 0x8078F1A0, Size: 4
void _ngcScrambleRectPixels() {
}

// _gxLightMultiplier
// Address: 0x8078F1A4, Size: 4
void _gxLightMultiplier() {
}

// _ngcAlphaTestThresholdMultiplier
// Address: 0x8078F1A8, Size: 4
void _ngcAlphaTestThresholdMultiplier() {
}

// _ngcDebugGX
// Address: 0x8078F1CC, Size: 4
void _ngcDebugGX() {
}

// _ngcUseWeightBlending
// Address: 0x8078F208, Size: 4
void _ngcUseWeightBlending() {
}

// _pSched
// Address: 0x8078F2A0, Size: 4
void _pSched() {
}

// _ngcTexCount
// Address: 0x8078F2A8, Size: 4
void _ngcTexCount() {
}

// _ngcTexMem
// Address: 0x8078F2AC, Size: 4
void _ngcTexMem() {
}

// _TOTAL_FREE
// Address: 0x8078F700, Size: 4
void _TOTAL_FREE() {
}

// _LARGEST_FREE
// Address: 0x8078F704, Size: 4
void _LARGEST_FREE() {
}

// _gpAptViewer
// Address: 0x8078F738, Size: 4
void _gpAptViewer() {
}

// _gPrc
// Address: 0x8078F73C, Size: 4
void _gPrc() {
}

// _bg
// Address: 0x8078F740, Size: 1
void _bg() {
}

// _defULTextureCoord
// Address: 0x8078F7CC, Size: 8
void _defULTextureCoord() {
}

// _defLRTextureCoord
// Address: 0x8078F7D4, Size: 8
void _defLRTextureCoord() {
}

// _emptyString
// Address: 0x8078F7DC, Size: 4
void _emptyString() {
}

// _v3DHeadOff
// Address: 0x8078F80C, Size: 8
void _v3DHeadOff() {
}

// _v3DHeadOffp1
// Address: 0x8078F814, Size: 8
void _v3DHeadOffp1() {
}

// _v3DHeadOffp2
// Address: 0x8078F81C, Size: 8
void _v3DHeadOffp2() {
}

// _sHoursLookup
// Address: 0x8078F84C, Size: 4
void _sHoursLookup() {
}

// _sHours24Lookup
// Address: 0x8078F850, Size: 4
void _sHours24Lookup() {
}

// _sMinLookup
// Address: 0x8078F854, Size: 4
void _sMinLookup() {
}

// _sAM_PMLookup
// Address: 0x8078F858, Size: 4
void _sAM_PMLookup() {
}

// _sNum
// Address: 0x8078F85C, Size: 4
void _sNum() {
}

// _sAmount
// Address: 0x8078F860, Size: 4
void _sAmount() {
}

// _sName
// Address: 0x8078F864, Size: 4
void _sName() {
}

// _sLiquidate
// Address: 0x8078F868, Size: 4
void _sLiquidate() {
}

// _sDlrSgn
// Address: 0x8078F86C, Size: 4
void _sDlrSgn() {
}

// _s1000s
// Address: 0x8078F870, Size: 4
void _s1000s() {
}

// _s100s
// Address: 0x8078F874, Size: 4
void _s100s() {
}

// _sColon
// Address: 0x8078F878, Size: 4
void _sColon() {
}

// _sComma
// Address: 0x8078F87C, Size: 4
void _sComma() {
}

// _sLbrack
// Address: 0x8078F880, Size: 4
void _sLbrack() {
}

// _sRbrack
// Address: 0x8078F884, Size: 4
void _sRbrack() {
}

// _sButtonSymbol
// Address: 0x8078F888, Size: 4
void _sButtonSymbol() {
}

// _sNewLine
// Address: 0x8078F88C, Size: 4
void _sNewLine() {
}

// _sAButtNGC
// Address: 0x8078F890, Size: 4
void _sAButtNGC() {
}

// _sBButtNGC
// Address: 0x8078F894, Size: 4
void _sBButtNGC() {
}

// _sXButtNGC
// Address: 0x8078F898, Size: 4
void _sXButtNGC() {
}

// _sYButtNGC
// Address: 0x8078F89C, Size: 4
void _sYButtNGC() {
}

// _sLButtNGC
// Address: 0x8078F8A0, Size: 4
void _sLButtNGC() {
}

// _sRButtNGC
// Address: 0x8078F8A4, Size: 4
void _sRButtNGC() {
}

// _sZButtNGC
// Address: 0x8078F8A8, Size: 4
void _sZButtNGC() {
}

// _sLanalogButtNGC
// Address: 0x8078F8AC, Size: 4
void _sLanalogButtNGC() {
}

// _sRanalogButtNGC
// Address: 0x8078F8B0, Size: 4
void _sRanalogButtNGC() {
}

// _sSelectButtNGC
// Address: 0x8078F8B4, Size: 4
void _sSelectButtNGC() {
}

// _sStartButtNGC
// Address: 0x8078F8B8, Size: 4
void _sStartButtNGC() {
}

// _sWallButtonButtNGC
// Address: 0x8078F8BC, Size: 4
void _sWallButtonButtNGC() {
}

// _sCenterCursorButtonButtNGC
// Address: 0x8078F8C0, Size: 4
void _sCenterCursorButtonButtNGC() {
}

// _sDpadButtNGC
// Address: 0x8078F8C4, Size: 4
void _sDpadButtNGC() {
}

// _sHungerButtNGC
// Address: 0x8078F8C8, Size: 4
void _sHungerButtNGC() {
}

// _sComfortButtNGC
// Address: 0x8078F8CC, Size: 4
void _sComfortButtNGC() {
}

// _sHygieneButtNGC
// Address: 0x8078F8D0, Size: 4
void _sHygieneButtNGC() {
}

// _sBladderButtNGC
// Address: 0x8078F8D4, Size: 4
void _sBladderButtNGC() {
}

// _sEnergyButtNGC
// Address: 0x8078F8D8, Size: 4
void _sEnergyButtNGC() {
}

// _sFunButtNGC
// Address: 0x8078F8DC, Size: 4
void _sFunButtNGC() {
}

// _sSocialButtNGC
// Address: 0x8078F8E0, Size: 4
void _sSocialButtNGC() {
}

// _sRoomButtNGC
// Address: 0x8078F8E4, Size: 4
void _sRoomButtNGC() {
}

// _sGButtNGC
// Address: 0x8078F8E8, Size: 4
void _sGButtNGC() {
}

// _sDButtNGC
// Address: 0x8078F8EC, Size: 4
void _sDButtNGC() {
}

// _sIButtNGC
// Address: 0x8078F8F0, Size: 4
void _sIButtNGC() {
}

// _ssxButtNGC
// Address: 0x8078F8F4, Size: 4
void _ssxButtNGC() {
}

// _sdxButtNGC
// Address: 0x8078F8F8, Size: 4
void _sdxButtNGC() {
}

// _sDpadUpButtNGC
// Address: 0x8078F8FC, Size: 4
void _sDpadUpButtNGC() {
}

// _sDpadDownButtNGC
// Address: 0x8078F900, Size: 4
void _sDpadDownButtNGC() {
}

// _sDpadLeftButtNGC
// Address: 0x8078F904, Size: 4
void _sDpadLeftButtNGC() {
}

// _sDpadRightButtNGC
// Address: 0x8078F908, Size: 4
void _sDpadRightButtNGC() {
}

// _sThe1TextNGC
// Address: 0x8078F90C, Size: 4
void _sThe1TextNGC() {
}

// _sThe2TextNGC
// Address: 0x8078F910, Size: 4
void _sThe2TextNGC() {
}

// _sThe3TextNGC
// Address: 0x8078F914, Size: 4
void _sThe3TextNGC() {
}

// _sButton1NGC
// Address: 0x8078F918, Size: 4
void _sButton1NGC() {
}

// _sButton2NGC
// Address: 0x8078F91C, Size: 4
void _sButton2NGC() {
}

// _sButton3NGC
// Address: 0x8078F920, Size: 4
void _sButton3NGC() {
}

// _bInitialized
// Address: 0x8078F92C, Size: 4
void _bInitialized() {
}

// _bgThreadCompleteMU
// Address: 0x8078F93C, Size: 4
void _bgThreadCompleteMU() {
}

// _bgMUSaveGood
// Address: 0x8078F940, Size: 4
void _bgMUSaveGood() {
}

// _assertLine
// Address: 0x8078F9BC, Size: 4
void _assertLine() {
}

// _assertFile
// Address: 0x8078F9C0, Size: 4
void _assertFile() {
}

// _assertExpr
// Address: 0x8078F9C4, Size: 4
void _assertExpr() {
}

// _gzSndSys
// Address: 0x8078F9F4, Size: 4
void _gzSndSys() {
}

// _threadList
// Address: 0x80790100, Size: 8
void _threadList() {
}

// _enable_trace_log
// Address: 0x80790110, Size: 4
void _enable_trace_log() {
}

// _enable_proview
// Address: 0x80790114, Size: 4
void _enable_proview() {
}

// _pBackground
// Address: 0x80790118, Size: 4
void _pBackground() {
}

// _retracetime
// Address: 0x80790154, Size: 4
void _retracetime() {
}

// _dtlim30
// Address: 0x80790158, Size: 4
void _dtlim30() {
}

// _dtlim20
// Address: 0x8079015C, Size: 4
void _dtlim20() {
}

// _dtlim15
// Address: 0x80790160, Size: 4
void _dtlim15() {
}

// _pResLoader
// Address: 0x8079021C, Size: 4
void _pResLoader() {
}

// _collideAnimMaxRot
// Address: 0x80790238, Size: 4
void _collideAnimMaxRot() {
}

// _pAudiosampleman
// Address: 0x80790288, Size: 4
void _pAudiosampleman() {
}

// _ngcClockMan
// Address: 0x8079028C, Size: 4
void _ngcClockMan() {
}

// _ngcKeyboard
// Address: 0x8079029C, Size: 8
void _ngcKeyboard() {
}

// _ngcMemCard
// Address: 0x807902A4, Size: 8
void _ngcMemCard() {
}

// _gxWaitColor
// Address: 0x807902D8, Size: 4
void _gxWaitColor() {
}

// _tvHZ
// Address: 0x807902DC, Size: 4
void _tvHZ() {
}

// _pt
// Address: 0x80790308, Size: 4
void _pt() {
}

// _pEmptyString
// Address: 0x80790784, Size: 4
void _pEmptyString() {
}

// _iVideoMode
// Address: 0x80791294, Size: 4
void _iVideoMode() {
}

// _gxBlack
// Address: 0x807912A0, Size: 4
void _gxBlack() {
}

// _gxWhite
// Address: 0x807912A4, Size: 4
void _gxWhite() {
}
