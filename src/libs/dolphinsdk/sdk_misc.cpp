// sdk_misc.cpp - Miscellaneous SDK functions
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 414 functions
//
// These are stub implementations to be replaced with matching decompilations.
// Each function needs to be decompiled to match the original binary.

#include "types.h"
#include "stub_classes.h"

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

// ParticleManDelRefCB(void *)
// Address: 0x8050403C, Size: 48
void ParticleManDelRefCB() {
}

// AudioFrameCallback(void)
// Address: 0x80504FBC, Size: 60
void AudioFrameCallback() {
}

// readStream(EFile *, unsigned int, unsigned int)
// Address: 0x80505A6C, Size: 152
void readStream() {
}

// VMLogStats(unsigned long, unsigned long, unsigned long, unsigned long, int)
// Address: 0x80506FDC, Size: 68
void VMLogStats() {
}

// ForceReadCallback(long, DVDFileInfo *)
// Address: 0x80507020, Size: 12
void ForceReadCallback() {
}

// EventPostRetraceCallback(unsigned long)
// Address: 0x80508228, Size: 4
void EventPostRetraceCallback() {
}

// EventPreRetraceCallback(unsigned long)
// Address: 0x8050822C, Size: 4
void EventPreRetraceCallback() {
}

// ResetCallback(void)
// Address: 0x80508230, Size: 64
void ResetCallback() {
}

// ResetCheck(void)
// Address: 0x80508270, Size: 408
void ResetCheck() {
}

// DvdCheck(void)
// Address: 0x80508410, Size: 636
void DvdCheck() {
}

// EventAlarmHandler(OSAlarm *, OSContext *)
// Address: 0x8050868C, Size: 112
void EventAlarmHandler() {
}

// EventIdleThread(void *)
// Address: 0x805086FC, Size: 28
void EventIdleThread() {
}

// EventThread(void *)
// Address: 0x80508718, Size: 184
void EventThread() {
}

// XOSFontStartup(void)
// Address: 0x805087D0, Size: 196
void XOSFontStartup() {
}

// XOSFontShutdown(void)
// Address: 0x80508894, Size: 72
void XOSFontShutdown() {
}

// XOSFontSetXFB(void *, int, int)
// Address: 0x805088DC, Size: 16
void XOSFontSetXFB() {
}

// XOSFontClearScreen(void)
// Address: 0x805088EC, Size: 60
void XOSFontClearScreen() {
}

// XOSFontDrawChar(unsigned int *, int, int)
// Address: 0x80508928, Size: 204
void XOSFontDrawChar() {
}

// XOSFontGetWordSize(char *, int &, int &)
// Address: 0x805089F4, Size: 184
void XOSFontGetWordSize() {
}

// XOSFontDrawString(int, int, unsigned short *)
// Address: 0x80508C00, Size: 484
void XOSFontDrawString() {
}

// LoadTexPalette(TEXPalette **, char *)
// Address: 0x8050EB18, Size: 144
void LoadTexPalette() {
}

// UnpackTexPalette(TEXPalette *)
// Address: 0x8050EBA8, Size: 296
void UnpackTexPalette() {
}

// TexGet(TEXPalette *, unsigned int)
// Address: 0x8050ECD0, Size: 16
void TexGet() {
}

// THPGXYuv2RgbSetup(_GXRenderModeObj *)
// Address: 0x80510544, Size: 4
void THPGXYuv2RgbSetup() {
}

// THPGXYuv2RgbDraw(unsigned char *, unsigned char *, unsigned char *, short, short, short, short, short, short)
// Address: 0x80510548, Size: 476
void THPGXYuv2RgbDraw() {
}

// InitAllMessageQueue(void)
// Address: 0x80510724, Size: 184
void InitAllMessageQueue() {
}

// WaitUntilPrepare(void)
// Address: 0x805107DC, Size: 68
void WaitUntilPrepare() {
}

// PrepareReady(bool)
// Address: 0x80510820, Size: 48
void PrepareReady() {
}

// PlayControl(unsigned long)
// Address: 0x80510850, Size: 588
void PlayControl() {
}

// ProperTimingForStart(void)
// Address: 0x80510A9C, Size: 88
void ProperTimingForStart() {
}

// ProperTimingForGettingNextFrame(void)
// Address: 0x80510AF4, Size: 300
void ProperTimingForGettingNextFrame() {
}

// PushUsedTextureSet(void *)
// Address: 0x80510C20, Size: 48
void PushUsedTextureSet() {
}

// PopUsedTextureSet(void)
// Address: 0x80510C50, Size: 64
void PopUsedTextureSet() {
}

// THPAudioMixCallback(void)
// Address: 0x80510C90, Size: 412
void THPAudioMixCallback() {
}

// MixAudio(short *, short *, unsigned int)
// Address: 0x80510E2C, Size: 972
void MixAudio() {
}

// THPPlayerSetVolume(int, int)
// Address: 0x805111F8, Size: 300
void THPPlayerSetVolume() {
}

// THPPlayerGetVolume(void)
// Address: 0x80511324, Size: 56
void THPPlayerGetVolume() {
}

// CreateReadThread(long)
// Address: 0x8051135C, Size: 172
void CreateReadThread() {
}

// ReadThreadStart(void)
// Address: 0x80511408, Size: 52
void ReadThreadStart() {
}

// ReadThreadCancel(void)
// Address: 0x8051143C, Size: 60
void ReadThreadCancel() {
}

// Reader(void *)
// Address: 0x80511478, Size: 224
void Reader() {
}

// PopReadedBuffer(void)
// Address: 0x80511558, Size: 52
void PopReadedBuffer() {
}

// PushReadedBuffer(void *)
// Address: 0x8051158C, Size: 48
void PushReadedBuffer() {
}

// PopFreeReadBuffer(void)
// Address: 0x805115BC, Size: 52
void PopFreeReadBuffer() {
}

// PushFreeReadBuffer(void *)
// Address: 0x805115F0, Size: 48
void PushFreeReadBuffer() {
}

// PopReadedBuffer2(void)
// Address: 0x80511620, Size: 52
void PopReadedBuffer2() {
}

// PushReadedBuffer2(void *)
// Address: 0x80511654, Size: 48
void PushReadedBuffer2() {
}

// CreateAudioDecodeThread(long, unsigned char *)
// Address: 0x80511684, Size: 180
void CreateAudioDecodeThread() {
}

// AudioDecodeThreadStart(void)
// Address: 0x80511738, Size: 52
void AudioDecodeThreadStart() {
}

// AudioDecodeThreadCancel(void)
// Address: 0x8051176C, Size: 60
void AudioDecodeThreadCancel() {
}

// AudioDecoder(void *)
// Address: 0x805117A8, Size: 40
void AudioDecoder() {
}

// AudioDecoderForOnMemory(void *)
// Address: 0x805117D0, Size: 164
void AudioDecoderForOnMemory() {
}

// AudioDecode(THPReadBuffer *)
// Address: 0x80511874, Size: 192
void AudioDecode() {
}

// PopFreeAudioBuffer(void)
// Address: 0x80511934, Size: 52
void PopFreeAudioBuffer() {
}

// PushFreeAudioBuffer(void *)
// Address: 0x80511968, Size: 48
void PushFreeAudioBuffer() {
}

// PopDecodedAudioBuffer(int)
// Address: 0x80511998, Size: 64
void PopDecodedAudioBuffer() {
}

// PushDecodedAudioBuffer(void *)
// Address: 0x805119D8, Size: 48
void PushDecodedAudioBuffer() {
}

// CreateVideoDecodeThread(long, unsigned char *)
// Address: 0x80511A08, Size: 184
void CreateVideoDecodeThread() {
}

// VideoDecodeThreadStart(void)
// Address: 0x80511AC0, Size: 52
void VideoDecodeThreadStart() {
}

// VideoDecodeThreadCancel(void)
// Address: 0x80511AF4, Size: 60
void VideoDecodeThreadCancel() {
}

// VideoDecoder(void *)
// Address: 0x80511B30, Size: 228
void VideoDecoder() {
}

// VideoDecoderForOnMemory(void *)
// Address: 0x80511C14, Size: 348
void VideoDecoderForOnMemory() {
}

// VideoDecode(THPReadBuffer *)
// Address: 0x80511D70, Size: 296
void VideoDecode() {
}

// PopFreeTextureSet(void)
// Address: 0x80511E98, Size: 52
void PopFreeTextureSet() {
}

// PushFreeTextureSet(void *)
// Address: 0x80511ECC, Size: 48
void PushFreeTextureSet() {
}

// PopDecodedTextureSet(int)
// Address: 0x80511EFC, Size: 64
void PopDecodedTextureSet() {
}

// PushDecodedTextureSet(void *)
// Address: 0x80511F3C, Size: 48
void PushDecodedTextureSet() {
}

// ClampGenericStick(signed char *, signed char *, float, float, int, int)
// Address: 0x8051201C, Size: 316
void ClampGenericStick() {
}

// ClampGenericTrigger(unsigned char *, unsigned char, unsigned char)
// Address: 0x80512158, Size: 52
void ClampGenericTrigger() {
}

// VerifyCallback(GXWarningLevel, unsigned long, char *)
// Address: 0x80516FC0, Size: 92
void VerifyCallback() {
}

// PSMTXMultVecWithScaleAndAdd(float (*)[3], Vec *, float, Vec *)
// Address: 0x80523420, Size: 116
void PSMTXMultVecWithScaleAndAdd() {
}

// GetDB(unsigned char)
// Address: 0x80527744, Size: 152
void GetDB() {
}

// GetVoiceHandle(void)
// Address: 0x805277DC, Size: 100
void GetVoiceHandle() {
}

// enable_IRQ(void)
// Address: 0x80527840, Size: 64
void enable_IRQ() {
}

// disable_IRQ(void)
// Address: 0x80527880, Size: 72
void disable_IRQ() {
}

// ax_drop_voice_callback(void *)
// Address: 0x805278C8, Size: 100
void ax_drop_voice_callback() {
}

// get_free(Stream *&)
// Address: 0x805289E8, Size: 280
void get_free() {
}

// init_stream(Stream *, NGCStreamInfo *, unsigned char, unsigned char)
// Address: 0x80528B00, Size: 208
void init_stream() {
}

// dvd_callback(long, DVDFileInfo *)
// Address: 0x80528C58, Size: 484
void dvd_callback() {
}

// activate_stream(Stream *)
// Address: 0x80528ED4, Size: 588
void activate_stream() {
}

// stream_data(Stream *)
// Address: 0x80529120, Size: 368
void stream_data() {
}

// shutdown_stream(Stream *)
// Address: 0x80529290, Size: 136
void shutdown_stream() {
}

// stream_update_handler(void *, unsigned int, void *, unsigned int, unsigned int)
// Address: 0x80529318, Size: 108
void stream_update_handler() {
}

// get_private_index(unsigned int)
// Address: 0x80529384, Size: 64
void get_private_index() {
}

// stream_free(Stream *)
// Address: 0x805293C4, Size: 108
void stream_free() {
}

// arq_callback(unsigned int)
// Address: 0x80529494, Size: 320
void arq_callback() {
}

// HostIOEnumCallback(long)
// Address: 0x8052BFA8, Size: 12
void HostIOEnumCallback() {
}

// HostIOCallback(void)
// Address: 0x8052BFB4, Size: 12
void HostIOCallback() {
}

// CopyoutEFB(unsigned char *, unsigned int, unsigned int)
// Address: 0x8052BFC0, Size: 156
void CopyoutEFB() {
}

// CopyoutPortionEFB(unsigned char *, unsigned int, unsigned int, unsigned int)
// Address: 0x8052C05C, Size: 268
void CopyoutPortionEFB() {
}

// TakeScreenshotEFB(void *(*)(unsigned int))
// Address: 0x8052C168, Size: 112
void TakeScreenshotEFB() {
}

// TakeScreenshotXFB(void *, void *(*)(unsigned int))
// Address: 0x8052C1D8, Size: 128
void TakeScreenshotXFB() {
}

// WriteScreenshotPortionEFBtoUSB(unsigned int, void *(*)(unsigned int))
// Address: 0x8052C258, Size: 168
void WriteScreenshotPortionEFBtoUSB() {
}

// GrabChunk(unsigned int, void *, void *(*)(unsigned int), void (*)(void *))
// Address: 0x8052C300, Size: 496
void GrabChunk() {
}

// CheckMail(void *, void *(*)(unsigned int), void (*)(void *))
// Address: 0x8052C4F0, Size: 332
void CheckMail() {
}

// ConnectToUSB(void)
// Address: 0x8052C63C, Size: 140
void ConnectToUSB() {
}

// SCREENSHOTService
// Address: 0x8052C6C8, Size: 64
void SCREENSHOTService() {
}

// XFONTInit
// Address: 0x8052C708, Size: 12
void XFONTInit() {
}

// XFONTSetFrameBuffer
// Address: 0x8052C714, Size: 8
void XFONTSetFrameBuffer() {
}

// XFONTPrintf
// Address: 0x8052C71C, Size: 196
void XFONTPrintf() {
}

// XFONTSetFgColor
// Address: 0x8052C7E0, Size: 60
void XFONTSetFgColor() {
}

// XFONTPaintRow
// Address: 0x8052C81C, Size: 116
void XFONTPaintRow() {
}

// XFONTClearScreen
// Address: 0x8052C890, Size: 108
void XFONTClearScreen() {
}

// XFONTShadowRow
// Address: 0x8052C8FC, Size: 88
void XFONTShadowRow() {
}

// XFONTputString(short *, short *, char *, unsigned int *)
// Address: 0x8052C954, Size: 356
void XFONTputString() {
}

// LinkFix(void)
// Address: 0x8052CAB8, Size: 12
void LinkFix() {
}

// LLSysOpen
// Address: 0x80540694, Size: 136
void LLSysOpen() {
}

// LLSysClose
// Address: 0x8054071C, Size: 48
void LLSysClose() {
}

// LLTracerPush
// Address: 0x8054074C, Size: 64
void LLTracerPush() {
}

// LLTracerPop
// Address: 0x8054078C, Size: 60
void LLTracerPop() {
}

// LLCreate
// Address: 0x805407C8, Size: 124
void LLCreate() {
}

// LLDestroy
// Address: 0x80540844, Size: 144
void LLDestroy() {
}

// LLInsertItem
// Address: 0x805408D4, Size: 108
void LLInsertItem() {
}

// LLDestroyItem
// Address: 0x80540940, Size: 68
void LLDestroyItem() {
}

// LLDestroyNode
// Address: 0x80540984, Size: 120
void LLDestroyNode() {
}

// LLRemoveNode
// Address: 0x805409FC, Size: 136
void LLRemoveNode() {
}

// LLGrabNode
// Address: 0x80540A84, Size: 144
void LLGrabNode() {
}

// LLInsertNode
// Address: 0x80540B14, Size: 264
void LLInsertNode() {
}

// LLClean
// Address: 0x80540C1C, Size: 116
void LLClean() {
}

// PoolCreate
// Address: 0x80540C90, Size: 200
void PoolCreate() {
}

// PoolDestroy
// Address: 0x80540D58, Size: 60
void PoolDestroy() {
}

// BIG_getm(void *, int)
// Address: 0x80541330, Size: 144
void BIG_getm() {
}

// BIG_stricmp(char *, char *)
// Address: 0x805413C0, Size: 156
void BIG_stricmp() {
}

// BIG_typeofheader(void *)
// Address: 0x8054145C, Size: 132
void BIG_typeofheader() {
}

// BIG_sizeofheader(void *)
// Address: 0x805414E0, Size: 140
void BIG_sizeofheader() {
}

// BIG_debuginfo(void *, int *, unsigned int *)
// Address: 0x8054156C, Size: 256
void BIG_debuginfo() {
}

// BIG_version(void *)
// Address: 0x8054166C, Size: 52
void BIG_version() {
}

// BIG_locateentryz(void *, char *, int *, int *, int *)
// Address: 0x805416A0, Size: 1220
void BIG_locateentryz() {
}

// BIG_locateentry(void *, char *, int *, int *, int *)
// Address: 0x80541B64, Size: 32
void BIG_locateentry() {
}

// BIG_locateoffset(void *, char *)
// Address: 0x80541B84, Size: 64
void BIG_locateoffset() {
}

// BIG_locateoffsetz(void *, char *)
// Address: 0x80541BC4, Size: 64
void BIG_locateoffsetz() {
}

// BIG_pointer(void *, int)
// Address: 0x80541C04, Size: 84
void BIG_pointer() {
}

// BIG_pointerz(void *, int)
// Address: 0x80541C58, Size: 84
void BIG_pointerz() {
}

// BIG_locate(void *, char *)
// Address: 0x80541CAC, Size: 64
void BIG_locate() {
}

// BIG_locatez(void *, char *)
// Address: 0x80541CEC, Size: 64
void BIG_locatez() {
}

// BIG_locatesize(void *, char *, int *)
// Address: 0x80541D2C, Size: 84
void BIG_locatesize() {
}

// BIG_locatemany(void *, char *, void **)
// Address: 0x80541D80, Size: 144
void BIG_locatemany() {
}

// BIG_count(void *)
// Address: 0x80541E10, Size: 136
void BIG_count() {
}

// AramRequestCallback(unsigned long)
// Address: 0x80542554, Size: 12
void AramRequestCallback() {
}

// AsyncAramRequestCallback(unsigned long)
// Address: 0x80542658, Size: 156
void AsyncAramRequestCallback() {
}

// AramRequestCallback2(unsigned long)
// Address: 0x80542788, Size: 12
void AramRequestCallback2() {
}

// write
// Address: 0x80542A6C, Size: 32
void write() {
}

// close
// Address: 0x80542A8C, Size: 32
void close() {
}

// fstat
// Address: 0x80542AAC, Size: 16
void fstat() {
}

// lseek
// Address: 0x80542ABC, Size: 32
void lseek() {
}

// read
// Address: 0x80542ADC, Size: 32
void read() {
}

// open
// Address: 0x80542AFC, Size: 164
void open() {
}

// fmod
// Address: 0x80542FA0, Size: 856
void fmod() {
}

// pow
// Address: 0x805432F8, Size: 2000
void pow() {
}

// sqrt
// Address: 0x80543AC8, Size: 532
void sqrt() {
}

// fabs
// Address: 0x80543CDC, Size: 60
void fabs() {
}

// asinf
// Address: 0x80543D18, Size: 556
void asinf() {
}

// expf
// Address: 0x80543F44, Size: 556
void expf() {
}

// logf
// Address: 0x80544170, Size: 640
void logf() {
}

// log10f
// Address: 0x805443F0, Size: 268
void log10f() {
}

// powf
// Address: 0x805444FC, Size: 1780
void powf() {
}

// scalbn
// Address: 0x80544BF0, Size: 340
void scalbn() {
}

// modff
// Address: 0x80544D44, Size: 160
void modff() {
}

// copysign
// Address: 0x80544DE4, Size: 80
void copysign() {
}

// memcpyalpha
// Address: 0x8054508C, Size: 44
void memcpyalpha() {
}

// vprintf
// Address: 0x80546570, Size: 52
void vprintf() {
}

// vsprintf
// Address: 0x805465A4, Size: 92
void vsprintf() {
}

// vsnprintf
// Address: 0x80546600, Size: 116
void vsnprintf() {
}

// strtodf
// Address: 0x80546A88, Size: 32
void strtodf() {
}

// strcoll
// Address: 0x80546C78, Size: 32
void strcoll() {
}

// strcspn
// Address: 0x80546C98, Size: 112
void strcspn() {
}

// strerror
// Address: 0x80546D08, Size: 1488
void strerror() {
}

// strlwr
// Address: 0x805472D8, Size: 68
void strlwr() {
}

// strncat
// Address: 0x8054731C, Size: 172
void strncat() {
}

// strpbrk
// Address: 0x805473C8, Size: 128
void strpbrk() {
}

// strtok
// Address: 0x80547448, Size: 40
void strtok() {
}

// strtok_r
// Address: 0x80547470, Size: 200
void strtok_r() {
}

// difftime
// Address: 0x80547540, Size: 72
void difftime() {
}

// gmtime
// Address: 0x80547588, Size: 44
void gmtime() {
}

// localtime
// Address: 0x805475B4, Size: 40
void localtime() {
}

// localtime_r
// Address: 0x805475DC, Size: 600
void localtime_r() {
}

// validate_structure
// Address: 0x80547834, Size: 852
void validate_structure() {
}

// mktime
// Address: 0x80547B88, Size: 648
void mktime() {
}

// strftime
// Address: 0x80547E10, Size: 1872
void strftime() {
}

// setjmp
// Address: 0x80548560, Size: 188
void setjmp() {
}

// longjmp
// Address: 0x8054861C, Size: 196
void longjmp() {
}

// ungetc
// Address: 0x805488DC, Size: 388
void ungetc() {
}

// ScreenClear
// Address: 0x80548BD4, Size: 248
void ScreenClear() {
}

// ScreenReport
// Address: 0x80548CCC, Size: 988
void ScreenReport() {
}

// ConfigureVideo
// Address: 0x805490A8, Size: 252
void ConfigureVideo() {
}

// RGB2YUV
// Address: 0x805491A4, Size: 476
void RGB2YUV() {
}

// Halt
// Address: 0x80549558, Size: 1504
void Halt() {
}

// IsSjisLeadByte
// Address: 0x80549B38, Size: 88
void IsSjisLeadByte() {
}

// IsSjisTrailByte
// Address: 0x80549B90, Size: 64
void IsSjisTrailByte() {
}

// GetFontCode
// Address: 0x80549BD0, Size: 372
void GetFontCode() {
}

// Decode
// Address: 0x80549D44, Size: 372
void Decode() {
}

// GetFontSize
// Address: 0x80549EB8, Size: 52
void GetFontSize() {
}

// ReadROM
// Address: 0x80549FE8, Size: 140
void ReadROM() {
}

// ReadFont
// Address: 0x8054A074, Size: 804
void ReadFont() {
}

// ParseStringS
// Address: 0x8054A4D8, Size: 316
void ParseStringS() {
}

// ParseStringW
// Address: 0x8054A614, Size: 508
void ParseStringW() {
}

// ExpandFontSheet
// Address: 0x8054AAB0, Size: 940
void ExpandFontSheet() {
}

// C_MTXIdentity
// Address: 0x8054BBB4, Size: 60
void C_MTXIdentity() {
}

// PSMTXIdentity
// Address: 0x8054BBF0, Size: 44
void PSMTXIdentity() {
}

// C_MTXCopy
// Address: 0x8054BC1C, Size: 108
void C_MTXCopy() {
}

// PSMTXCopy
// Address: 0x8054BC88, Size: 52
void PSMTXCopy() {
}

// C_MTXConcat
// Address: 0x8054BCBC, Size: 680
void C_MTXConcat() {
}

// PSMTXConcat
// Address: 0x8054BF64, Size: 204
void PSMTXConcat() {
}

// C_MTXConcatArray
// Address: 0x8054C030, Size: 104
void C_MTXConcatArray() {
}

// PSMTXConcatArray
// Address: 0x8054C098, Size: 344
void PSMTXConcatArray() {
}

// C_MTXTranspose
// Address: 0x8054C1F0, Size: 156
void C_MTXTranspose() {
}

// PSMTXTranspose
// Address: 0x8054C28C, Size: 80
void PSMTXTranspose() {
}

// C_MTXInverse
// Address: 0x8054C2DC, Size: 684
void C_MTXInverse() {
}

// PSMTXInverse
// Address: 0x8054C588, Size: 248
void PSMTXInverse() {
}

// C_MTXInvXpose
// Address: 0x8054C680, Size: 540
void C_MTXInvXpose() {
}

// PSMTXInvXpose
// Address: 0x8054C89C, Size: 200
void PSMTXInvXpose() {
}

// C_MTXRotRad
// Address: 0x8054C964, Size: 112
void C_MTXRotRad() {
}

// PSMTXRotRad
// Address: 0x8054C9D4, Size: 112
void PSMTXRotRad() {
}

// C_MTXRotTrig
// Address: 0x8054CA44, Size: 260
void C_MTXRotTrig() {
}

// PSMTXRotTrig
// Address: 0x8054CB48, Size: 176
void PSMTXRotTrig() {
}

// C_MTXRotAxisRad
// Address: 0x8054CBF8, Size: 280
void C_MTXRotAxisRad() {
}

// PSMTXRotAxisRad
// Address: 0x8054CDC0, Size: 112
void PSMTXRotAxisRad() {
}

// C_MTXTrans
// Address: 0x8054CE30, Size: 60
void C_MTXTrans() {
}

// PSMTXTrans
// Address: 0x8054CE6C, Size: 52
void PSMTXTrans() {
}

// C_MTXTransApply
// Address: 0x8054CEA0, Size: 120
void C_MTXTransApply() {
}

// PSMTXTransApply
// Address: 0x8054CF18, Size: 76
void PSMTXTransApply() {
}

// C_MTXScale
// Address: 0x8054CF64, Size: 56
void C_MTXScale() {
}

// PSMTXScale
// Address: 0x8054CF9C, Size: 40
void PSMTXScale() {
}

// C_MTXScaleApply
// Address: 0x8054CFC4, Size: 148
void C_MTXScaleApply() {
}

// PSMTXScaleApply
// Address: 0x8054D058, Size: 88
void PSMTXScaleApply() {
}

// C_MTXQuat
// Address: 0x8054D0B0, Size: 240
void C_MTXQuat() {
}

// PSMTXQuat
// Address: 0x8054D1A0, Size: 164
void PSMTXQuat() {
}

// C_MTXReflect
// Address: 0x8054D244, Size: 256
void C_MTXReflect() {
}

// PSMTXReflect
// Address: 0x8054D344, Size: 112
void PSMTXReflect() {
}

// C_MTXLookAt
// Address: 0x8054D3B4, Size: 396
void C_MTXLookAt() {
}

// C_MTXLightFrustum
// Address: 0x8054D540, Size: 148
void C_MTXLightFrustum() {
}

// C_MTXLightPerspective
// Address: 0x8054D5D4, Size: 204
void C_MTXLightPerspective() {
}

// C_MTXLightOrtho
// Address: 0x8054D6A0, Size: 136
void C_MTXLightOrtho() {
}

// C_MTXMultVec
// Address: 0x8054D728, Size: 148
void C_MTXMultVec() {
}

// PSMTXMultVec
// Address: 0x8054D7BC, Size: 84
void PSMTXMultVec() {
}

// C_MTXMultVecArray
// Address: 0x8054D810, Size: 516
void C_MTXMultVecArray() {
}

// PSMTXMultVecArray
// Address: 0x8054DA14, Size: 140
void PSMTXMultVecArray() {
}

// C_MTXMultVecSR
// Address: 0x8054DAA0, Size: 124
void C_MTXMultVecSR() {
}

// PSMTXMultVecSR
// Address: 0x8054DB1C, Size: 84
void PSMTXMultVecSR() {
}

// C_MTXMultVecArraySR
// Address: 0x8054DB70, Size: 444
void C_MTXMultVecArraySR() {
}

// PSMTXMultVecArraySR
// Address: 0x8054DD2C, Size: 136
void PSMTXMultVecArraySR() {
}

// C_MTXFrustum
// Address: 0x8054DDB4, Size: 156
void C_MTXFrustum() {
}

// C_MTXPerspective
// Address: 0x8054DE50, Size: 208
void C_MTXPerspective() {
}

// C_MTXOrtho
// Address: 0x8054DF20, Size: 152
void C_MTXOrtho() {
}

// C_MTX44Identity
// Address: 0x8054DFB8, Size: 76
void C_MTX44Identity() {
}

// PSMTX44Identity
// Address: 0x8054E004, Size: 52
void PSMTX44Identity() {
}

// C_MTX44Copy
// Address: 0x8054E038, Size: 140
void C_MTX44Copy() {
}

// PSMTX44Copy
// Address: 0x8054E0C4, Size: 68
void PSMTX44Copy() {
}

// C_MTX44Concat
// Address: 0x8054E108, Size: 1104
void C_MTX44Concat() {
}

// PSMTX44Concat
// Address: 0x8054E558, Size: 260
void PSMTX44Concat() {
}

// C_MTX44Transpose
// Address: 0x8054E65C, Size: 196
void C_MTX44Transpose() {
}

// PSMTX44Transpose
// Address: 0x8054E720, Size: 100
void PSMTX44Transpose() {
}

// C_MTX44Inverse
// Address: 0x8054E784, Size: 1008
void C_MTX44Inverse() {
}

// C_MTX44Trans
// Address: 0x8054EB74, Size: 76
void C_MTX44Trans() {
}

// PSMTX44Trans
// Address: 0x8054EBC0, Size: 60
void PSMTX44Trans() {
}

// C_MTX44TransApply
// Address: 0x8054EBFC, Size: 152
void C_MTX44TransApply() {
}

// PSMTX44TransApply
// Address: 0x8054EC94, Size: 92
void PSMTX44TransApply() {
}

// C_MTX44Scale
// Address: 0x8054ECF0, Size: 76
void C_MTX44Scale() {
}

// PSMTX44Scale
// Address: 0x8054ED3C, Size: 52
void PSMTX44Scale() {
}

// C_MTX44ScaleApply
// Address: 0x8054ED70, Size: 180
void C_MTX44ScaleApply() {
}

// PSMTX44ScaleApply
// Address: 0x8054EE24, Size: 104
void PSMTX44ScaleApply() {
}

// C_MTX44RotRad
// Address: 0x8054EE8C, Size: 112
void C_MTX44RotRad() {
}

// PSMTX44RotRad
// Address: 0x8054EEFC, Size: 112
void PSMTX44RotRad() {
}

// C_MTX44RotTrig
// Address: 0x8054EF6C, Size: 284
void C_MTX44RotTrig() {
}

// PSMTX44RotTrig
// Address: 0x8054F088, Size: 212
void PSMTX44RotTrig() {
}

// C_MTX44RotAxisRad
// Address: 0x8054F15C, Size: 300
void C_MTX44RotAxisRad() {
}

// PSMTX44RotAxisRad
// Address: 0x8054F344, Size: 112
void PSMTX44RotAxisRad() {
}

// AXInit
// Address: 0x8055197C, Size: 36
void AXInit() {
}

// AXInitEx
// Address: 0x805519A0, Size: 76
void AXInitEx() {
}

// AXQuit
// Address: 0x805519EC, Size: 52
void AXQuit() {
}

// AXFreeVoice
// Address: 0x80552018, Size: 128
void AXFreeVoice() {
}

// AXAcquireVoice
// Address: 0x80552098, Size: 372
void AXAcquireVoice() {
}

// AXSetVoicePriority
// Address: 0x8055220C, Size: 168
void AXSetVoicePriority() {
}

// AXRegisterAuxACallback
// Address: 0x8055273C, Size: 12
void AXRegisterAuxACallback() {
}

// AXRegisterAuxBCallback
// Address: 0x80552748, Size: 12
void AXRegisterAuxBCallback() {
}

// AXSetMode
// Address: 0x80552E88, Size: 20
void AXSetMode() {
}

// AXGetMode
// Address: 0x80552E9C, Size: 8
void AXGetMode() {
}

// AXSetCompressor
// Address: 0x80552EA4, Size: 8
void AXSetCompressor() {
}

// AXSetStepMode
// Address: 0x8055312C, Size: 8
void AXSetStepMode() {
}

// AXRegisterCallback
// Address: 0x8055367C, Size: 68
void AXRegisterCallback() {
}

// AXSetVoiceSrcType
// Address: 0x805548A4, Size: 196
void AXSetVoiceSrcType() {
}

// AXSetVoiceState
// Address: 0x80554968, Size: 92
void AXSetVoiceState() {
}

// AXSetVoiceType
// Address: 0x805549C4, Size: 76
void AXSetVoiceType() {
}

// AXSetVoiceMix
// Address: 0x80554A10, Size: 596
void AXSetVoiceMix() {
}

// AXSetVoiceItdOn
// Address: 0x80554C64, Size: 100
void AXSetVoiceItdOn() {
}

// AXSetVoiceItdTarget
// Address: 0x80554CC8, Size: 92
void AXSetVoiceItdTarget() {
}

// AXSetVoiceUpdateIncrement
// Address: 0x80554D24, Size: 72
void AXSetVoiceUpdateIncrement() {
}

// AXSetVoiceUpdateWrite
// Address: 0x80554D6C, Size: 136
void AXSetVoiceUpdateWrite() {
}

// AXSetVoiceDpop
// Address: 0x80554DF4, Size: 156
void AXSetVoiceDpop() {
}

// AXSetVoiceVe
// Address: 0x80554E90, Size: 88
void AXSetVoiceVe() {
}

// AXSetVoiceVeDelta
// Address: 0x80554EE8, Size: 76
void AXSetVoiceVeDelta() {
}

// AXSetVoiceFir
// Address: 0x80554F34, Size: 96
void AXSetVoiceFir() {
}

// AXSetVoiceAddr
// Address: 0x80554F94, Size: 272
void AXSetVoiceAddr() {
}

// AXSetVoiceLoop
// Address: 0x805550A4, Size: 76
void AXSetVoiceLoop() {
}

// AXSetVoiceLoopAddr
// Address: 0x805550F0, Size: 84
void AXSetVoiceLoopAddr() {
}

// AXSetVoiceEndAddr
// Address: 0x80555144, Size: 84
void AXSetVoiceEndAddr() {
}

// AXSetVoiceCurrentAddr
// Address: 0x80555198, Size: 84
void AXSetVoiceCurrentAddr() {
}

// AXSetVoiceAdpcm
// Address: 0x805551EC, Size: 164
void AXSetVoiceAdpcm() {
}

// AXSetVoiceSrc
// Address: 0x80555290, Size: 152
void AXSetVoiceSrc() {
}

// AXSetVoiceSrcRatio
// Address: 0x80555328, Size: 152
void AXSetVoiceSrcRatio() {
}

// AXSetVoiceAdpcmLoop
// Address: 0x805553C0, Size: 108
void AXSetVoiceAdpcmLoop() {
}

// AXSetVoiceLpf
// Address: 0x8055542C, Size: 116
void AXSetVoiceLpf() {
}

// AXSetVoiceLpfCoefs
// Address: 0x805554A0, Size: 92
void AXSetVoiceLpfCoefs() {
}

// AXGetLpfCoefs
// Address: 0x805554FC, Size: 284
void AXGetLpfCoefs() {
}

// AXSetMaxDspCycles
// Address: 0x80555618, Size: 8
void AXSetMaxDspCycles() {
}

// AXGetMaxDspCycles
// Address: 0x80555620, Size: 8
void AXGetMaxDspCycles() {
}

// AXGetDspCycles
// Address: 0x80555628, Size: 8
void AXGetDspCycles() {
}

// AXInitProfile
// Address: 0x80555678, Size: 28
void AXInitProfile() {
}

// AXGetProfile
// Address: 0x80555694, Size: 76
void AXGetProfile() {
}

// MIXInit
// Address: 0x80555870, Size: 200
void MIXInit() {
}

// MIXQuit
// Address: 0x80555938, Size: 4
void MIXQuit() {
}

// MIXSetSoundMode
// Address: 0x8055593C, Size: 8
void MIXSetSoundMode() {
}

// MIXGetSoundMode
// Address: 0x80555944, Size: 8
void MIXGetSoundMode() {
}

// MIXInitChannel
// Address: 0x8055594C, Size: 3708
void MIXInitChannel() {
}

// MIXReleaseChannel
// Address: 0x805567C8, Size: 32
void MIXReleaseChannel() {
}

// MIXResetControls
// Address: 0x805567E8, Size: 140
void MIXResetControls() {
}

// MIXSetInput
// Address: 0x80556874, Size: 40
void MIXSetInput() {
}

// MIXAdjustInput
// Address: 0x8055689C, Size: 48
void MIXAdjustInput() {
}

// MIXGetInput
// Address: 0x805568CC, Size: 28
void MIXGetInput() {
}

// MIXAuxAPostFader
// Address: 0x805568E8, Size: 48
void MIXAuxAPostFader() {
}

// MIXAuxAPreFader
// Address: 0x80556918, Size: 40
void MIXAuxAPreFader() {
}

// MIXAuxAIsPostFader
// Address: 0x80556940, Size: 48
void MIXAuxAIsPostFader() {
}

// MIXSetAuxA
// Address: 0x80556970, Size: 40
void MIXSetAuxA() {
}

// MIXAdjustAuxA
// Address: 0x80556998, Size: 48
void MIXAdjustAuxA() {
}

// MIXGetAuxA
// Address: 0x805569C8, Size: 28
void MIXGetAuxA() {
}

// MIXAuxBPostFader
// Address: 0x805569E4, Size: 48
void MIXAuxBPostFader() {
}

// MIXAuxBPreFader
// Address: 0x80556A14, Size: 40
void MIXAuxBPreFader() {
}

// MIXAuxBIsPostFader
// Address: 0x80556A3C, Size: 48
void MIXAuxBIsPostFader() {
}

// MIXSetAuxB
// Address: 0x80556A6C, Size: 52
void MIXSetAuxB() {
}

// MIXAdjustAuxB
// Address: 0x80556AA0, Size: 60
void MIXAdjustAuxB() {
}

// MIXGetAuxB
// Address: 0x80556ADC, Size: 48
void MIXGetAuxB() {
}

// MIXSetPan
// Address: 0x80556B0C, Size: 108
void MIXSetPan() {
}

// MIXAdjustPan
// Address: 0x80556B78, Size: 116
void MIXAdjustPan() {
}

// MIXGetPan
// Address: 0x80556BEC, Size: 28
void MIXGetPan() {
}

// MIXSetSPan
// Address: 0x80556C08, Size: 108
void MIXSetSPan() {
}

// MIXAdjustSPan
// Address: 0x80556C74, Size: 116
void MIXAdjustSPan() {
}

// MIXGetSPan
// Address: 0x80556CE8, Size: 28
void MIXGetSPan() {
}

// MIXMute
// Address: 0x80556D04, Size: 40
void MIXMute() {
}

// MIXUnMute
// Address: 0x80556D2C, Size: 48
void MIXUnMute() {
}

// MIXIsMute
// Address: 0x80556D5C, Size: 48
void MIXIsMute() {
}

// MIXSetFader
// Address: 0x80556D8C, Size: 40
void MIXSetFader() {
}

// MIXAdjustFader
// Address: 0x80556DB4, Size: 48
void MIXAdjustFader() {
}

// MIXGetFader
// Address: 0x80556DE4, Size: 28
void MIXGetFader() {
}

// MIXSetDvdStreamFader
// Address: 0x80556E00, Size: 32
void MIXSetDvdStreamFader() {
}

// MIXGetDvdStreamFader
// Address: 0x80556E20, Size: 8
void MIXGetDvdStreamFader() {
}

// MIXUpdateSettings
// Address: 0x80556E28, Size: 4220
void MIXUpdateSettings() {
}

// TimeoutHandler
// Address: 0x805593A8, Size: 164
void TimeoutHandler() {
}

// SetupTimeoutAlarm
// Address: 0x8055944C, Size: 364
void SetupTimeoutAlarm() {
}

// Retry
// Address: 0x805595B8, Size: 672
void Retry() {
}

// UnlockedCallback
// Address: 0x80559858, Size: 272
void UnlockedCallback() {
}

// WriteCallback
// Address: 0x8055A7AC, Size: 212
void WriteCallback() {
}

// EraseCallback
// Address: 0x8055A880, Size: 200
void EraseCallback() {
}

// VerifyID
// Address: 0x8055AFBC, Size: 644
void VerifyID() {
}

// VerifyDir
// Address: 0x8055B240, Size: 576
void VerifyDir() {
}

// VerifyFAT
// Address: 0x8055B480, Size: 644
void VerifyFAT() {
}

// IsCard
// Address: 0x8055BDF8, Size: 204
void IsCard() {
}

// DoMount
// Address: 0x8055C0CC, Size: 1108
void DoMount() {
}

// DoUnmount
// Address: 0x8055C840, Size: 156
void DoUnmount() {
}

// FormatCallback
// Address: 0x8055C988, Size: 324
void FormatCallback() {
}

// CreateCallbackFat
// Address: 0x8055D8F8, Size: 304
void CreateCallbackFat() {
}

// ReadCallback
// Address: 0x8055DE48, Size: 304
void ReadCallback() {
}

// DeleteCallback
// Address: 0x8055E50C, Size: 164
void DeleteCallback() {
}

// UpdateIconOffsets
// Address: 0x8055E87C, Size: 504
void UpdateIconOffsets() {
}

// exnor_1st
// Address: 0x8055F11C, Size: 372
void exnor_1st() {
}

// exnor
// Address: 0x8055F290, Size: 372
void exnor() {
}

// bitrev
// Address: 0x8055F404, Size: 364
void bitrev() {
}

// ReadArrayUnlock
// Address: 0x8055F570, Size: 324
void ReadArrayUnlock() {
}

// GetInitVal
// Address: 0x8055F6B4, Size: 84
void GetInitVal() {
}

// DummyLen
// Address: 0x8055F708, Size: 196
void DummyLen() {
}

// InitCallback
// Address: 0x80560324, Size: 112
void InitCallback() {
}

// DoneCallback
// Address: 0x80560394, Size: 804
void DoneCallback() {
}

// BlockReadCallback
// Address: 0x805606B8, Size: 220
void BlockReadCallback() {
}

// BlockWriteCallback
// Address: 0x805607F8, Size: 232
void BlockWriteCallback() {
}

// ExtHandler
// Address: 0x80560CE8, Size: 60
void ExtHandler() {
}

// ExiHandler
// Address: 0x80560D24, Size: 48
void ExiHandler() {
}

// DbgHandler
// Address: 0x80560D54, Size: 108
void DbgHandler() {
}

// TxHandler
// Address: 0x80560DC0, Size: 64
void TxHandler() {
}

// RxHandler
// Address: 0x80560E00, Size: 64
void RxHandler() {
}

// HIOEnumDevices
// Address: 0x80560E40, Size: 200
void HIOEnumDevices() {
}

// HIOInit
// Address: 0x80560F08, Size: 796
void HIOInit() {
}

// HIOInitEx
// Address: 0x80561224, Size: 92
void HIOInitEx() {
}

// HIOReadMailbox
// Address: 0x80561280, Size: 388
void HIOReadMailbox() {
}

// HIOWriteMailbox
// Address: 0x80561404, Size: 328
void HIOWriteMailbox() {
}

// HIORead
// Address: 0x8056154C, Size: 408
void HIORead() {
}

// HIOWrite
// Address: 0x805616E4, Size: 408
void HIOWrite() {
}

// HIOReadAsync
// Address: 0x8056187C, Size: 380
void HIOReadAsync() {
}

// HIOWriteAsync
// Address: 0x805619F8, Size: 380
void HIOWriteAsync() {
}

// HIOReadStatus
// Address: 0x80561B74, Size: 388
void HIOReadStatus() {
}

// IsWriteGatherBufferEmpty
// Address: 0x80561CF8, Size: 16
void IsWriteGatherBufferEmpty() {
}

// EnableWriteGatherPipe
// Address: 0x80561D08, Size: 64
void EnableWriteGatherPipe() {
}

// WriteProjPS
// Address: 0x8056B418, Size: 28
void WriteProjPS() {
}

// Copy6Floats
// Address: 0x8056B434, Size: 28
void Copy6Floats() {
}

// WriteMTXPS4x3
// Address: 0x8056B610, Size: 52
void WriteMTXPS4x3() {
}

// WriteMTXPS3x3from3x4
// Address: 0x8056B644, Size: 52
void WriteMTXPS3x3from3x4() {
}

// WriteMTXPS3x3
// Address: 0x8056B678, Size: 44
void WriteMTXPS3x3() {
}

// WriteMTXPS4x2
// Address: 0x8056B6A4, Size: 36
void WriteMTXPS4x2() {
}

// VMInit
// Address: 0x8056CD98, Size: 156
void VMInit() {
}

// VMIsInitialized
// Address: 0x8056CE34, Size: 8
void VMIsInitialized() {
}

// VMQuit
// Address: 0x8056CE3C, Size: 104
void VMQuit() {
}

// VMResizeARAM
// Address: 0x8056CEA4, Size: 40
void VMResizeARAM() {
}

// VMSetLogStatsCallback
// Address: 0x8056CECC, Size: 8
void VMSetLogStatsCallback() {
}

// VMGetARAMSize
// Address: 0x8056CEEC, Size: 8
void VMGetARAMSize() {
}

// VMGetARAMBase
// Address: 0x8056CEF4, Size: 8
void VMGetARAMBase() {
}

// VMStoreAllPages
// Address: 0x8056D1E4, Size: 40
void VMStoreAllPages() {
}

// VMInvalidateAllPages
// Address: 0x8056D20C, Size: 48
void VMInvalidateAllPages() {
}

// VMInvalidateRange
// Address: 0x8056D23C, Size: 116
void VMInvalidateRange() {
}

// VMStoreOnePage
// Address: 0x8056D2B0, Size: 296
void VMStoreOnePage() {
}

// VMSetPageReplacementPolicy
// Address: 0x8056D3D8, Size: 8
void VMSetPageReplacementPolicy() {
}

// VMGetPageReplacementPolicy
// Address: 0x8056D3E0, Size: 8
void VMGetPageReplacementPolicy() {
}

// VMAlloc
// Address: 0x8056D70C, Size: 256
void VMAlloc() {
}

// VMFree
// Address: 0x8056D80C, Size: 264
void VMFree() {
}

// VMFreeAll
// Address: 0x8056D914, Size: 272
void VMFreeAll() {
}

// VMGetNumUnallocatedBytes
// Address: 0x8056DA24, Size: 40
void VMGetNumUnallocatedBytes() {
}

// THPVideoDecode
// Address: 0x8056DC58, Size: 580
void THPVideoDecode() {
}
