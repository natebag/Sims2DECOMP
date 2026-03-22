// image_processing.cpp - Image processing filters
// Part of the Sims 2 GC decompilation
// Auto-generated stub implementations - 19 functions
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

// calcWeightSum(int *, int)
// Address: 0x8050226C, Size: 52
void calcWeightSum() {
}

// ApplyConvolution(short *, short *, int, int, int *, int, int, int, ImageProcessingManager::BaseColor)
// Address: 0x805022A0, Size: 836
void ApplyConvolution() {
}

// Sharpen(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x805025E4, Size: 132
void Sharpen() {
}

// Sharpen_MeanRemoval(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x80502668, Size: 132
void Sharpen_MeanRemoval() {
}

// GaussianBlur(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x805026EC, Size: 236
void GaussianBlur() {
}

// Emboss(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x805027D8, Size: 232
void Emboss() {
}

// Emboss2(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x805028C0, Size: 360
void Emboss2() {
}

// Laplacian(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x80502A28, Size: 232
void Laplacian() {
}

// MergeEdges_Color(short *, short *, short *, int)
// Address: 0x80502B10, Size: 388
void MergeEdges_Color() {
}

// EdgeDetect_Prewitt(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x80503208, Size: 612
void EdgeDetect_Prewitt() {
}

// EdgeDetect_Sobel(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x8050346C, Size: 536
void EdgeDetect_Sobel() {
}

// EdgeDetect_OnePass(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x80503684, Size: 232
void EdgeDetect_OnePass() {
}

// EdgeDetect_NonConvolved(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x8050376C, Size: 344
void EdgeDetect_NonConvolved() {
}

// Posterize(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x805038C4, Size: 216
void Posterize() {
}

// Solarize(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x8050399C, Size: 108
void Solarize() {
}

// InverseSolarize(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x80503A08, Size: 108
void InverseSolarize() {
}

// sort3IntPtrs(int **)
// Address: 0x80503A74, Size: 100
void sort3IntPtrs() {
}

// Saturate(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x80503AD8, Size: 1152
void Saturate() {
}

// CustomConvolution(short *, short *, int, int, ImageProcessingManager::FilterParams *)
// Address: 0x80503F58, Size: 132
void CustomConvolution() {
}
