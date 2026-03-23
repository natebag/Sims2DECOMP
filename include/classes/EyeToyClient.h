#ifndef EYETOYCLIENT_H
#define EYETOYCLIENT_H

#include "types.h"

// EyeToyClient - struct layout extracted from assembly analysis
// Estimated minimum size: 0x5EB8 (24248 bytes)
// 25 known fields (11 named), 100 methods

class EyeToyClient {
public:
    // Methods
    void Shutdown(void);  // 0x8009AA24 (460B)
    void Init(void);  // 0x8009A760 (708B)
    /* ? */ GetBrightness(void);  // 0x8009CE34 (60B)
    /* ? */ GetExposure(void);  // 0x8009C9EC (168B)
    /* ? */ GetHue(void);  // 0x8009CC68 (128B)
    /* ? */ GetSaturation(void);  // 0x8009CB48 (60B)
    void SetBrightness(float);  // 0x8009CE70 (228B)
    void SetExposure(float);  // 0x8009CA94 (180B)
    void SetHue(float);  // 0x8009CCE8 (332B)
    void SetSaturation(float);  // 0x8009CB84 (228B)
    void loadTexture_alloc(unsigned int, unsigned int);  // 0x80098A30 (52B)
    void loadTexture_dealloc(void *);  // 0x80098A64 (32B)
    void WriteTextureToRepSlot(int, ETexture *, EyeToyClient::SlotImageType);  // 0x8009BD30 (344B)
    void LoadDefaultSettings(void);  // 0x80098D68 (100B)
    void FindFirstConnectedEyeToy(void);  // 0x80098EA0 (148B)
    void SetUnplugCallback(void (*);  // 0x8009A6C8 (52B)
    void UnpluggedCallback(int);  // 0x8009A6FC (100B)
    void CloseSession(void);  // 0x8009BA80 (284B)
    void Update(float);  // 0x8009ABF0 (272B)
    void Render(void);  // 0x8009AD54 (2332B)
    /* ? */ GetFunframeCount(void);  // 0x8009B670 (36B)
    /* ? */ GetFilterCount(void);  // 0x8009B694 (36B)
    /* ? */ GetTargetSlotCount(void);  // 0x8009B6B8 (36B)
    void OpenSession(void);  // 0x8009B6DC (932B)
    void ApplyPresetFilter(int);  // 0x8009BB9C (208B)
    void ApplyFunFrame(int);  // 0x8009BC6C (196B)
    void SaveSessionToSlot(int);  // 0x8009BE88 (104B)
    /* ? */ GetSessionTexture(void);  // 0x8009BEF0 (44B)
    void StartStream(void);  // 0x8009BF1C (96B)
    void StopStream(void);  // 0x8009BF7C (96B)
    bool IsEyeToyHardwarePresent(void);  // 0x8009BFDC (80B)
    bool IsSessionEyeToyDisconnected(void);  // 0x8009C02C (96B)
    /* ? */ GetRepSlotUnLockedBits(int);  // 0x8009C08C (804B)
    /* ? */ GetFunFrameUnLockedBits(int);  // 0x8009C3B0 (252B)
    void DoesRepSlotHaveEyetoyImage(int);  // 0x8009C4AC (204B)
    /* ? */ GetRepShaderGUID(int);  // 0x8009C578 (192B)
    bool IsSlotOpenForCASImage(int, int);  // 0x8009C638 (220B)
    void SetRepTexture(int, ETexture *);  // 0x8009C714 (68B)
    /* ? */ GetRepTexture(int);  // 0x8009C758 (336B)
    /* ? */ GetRepShaderERTextureID(EyeToyClient::RepShaderMapping);  // 0x8009C8A8 (244B)
    void RestoreDefaults(void);  // 0x8009C99C (80B)
    void saveHeader(NghResFile::SaveRecord &);  // 0x800571B0 (172B)
    void saveTexture(int, NghResFile::SaveRecord &);  // 0x8005725C (244B)
    void Save(NghResFile::SectionID, NghResFile::SaveRecord &);  // 0x80057350 (240B)
    void SaveComplete(NghResFile::SectionID, NghResFile::SaveRecord &);  // 0x80057440 (4B)
    void loadHeader(NghResFile::SaveRecord &);  // 0x80057444 (180B)
    void loadTexture(int, NghResFile::SaveRecord &);  // 0x80057504 (288B)
    void Load(NghResFile::SectionID, NghResFile::SaveRecord &);  // 0x80057624 (240B)
    void FrameReadyCallback(char *, int);  // 0x80057760 (128B)
    void AcquireTexture(int, int, int);  // 0x80057840 (212B)
    void ReleaseTexture(ETexture *);  // 0x80057914 (64B)
    void AcquireRenderSurface(int, int, int);  // 0x80057954 (304B)
    void ReleaseRenderSurface(ERenderSurface *);  // 0x80057A84 (64B)
    void CopyTextureToShader(ERShader *, ETexture *);  // 0x80057AC4 (1020B)
    void CompositeFF_callback(ETexture *);  // 0x80057EC0 (1220B)
    void UpdateFunFrameLoading(void);  // 0x80058384 (124B)
    void SetFilterPipeline(int);  // 0x80058400 (900B)
    void MacroBlockDummyAllocator(unsigned int, unsigned int);  // 0x80058B10 (8B)
    void MacroBlockDummyFree(void *);  // 0x80058B18 (4B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (Render, loadTexture, saveHeader)
    f32 m_repSlotUnLockedBits;  // 0x004 [R/W] (GetExposure, GetRepSlotUnLockedBits, SetFilterPipeline, ...)
    u16 m_repSlotUnLockedBits_006;  // 0x006 [R] (GetRepSlotUnLockedBits)
    u8 _pad_008[8];  // 0x008
    u16 m_field_010;  // 0x010 [R] (CompositeFF_callback, Debug::WriteTGAToHost)
    u16 m_field_012;  // 0x012 [R] (CompositeFF_callback, Debug::WriteTGAToHost)
    u32 m_field_014;  // 0x014 [R] (CopyTextureToShader, saveTexture)
    u32 m_field_018;  // 0x018 [R] (CopyTextureToShader, saveTexture)
    u8 _pad_01C[4];  // 0x01C
    u32 m_field_020;  // 0x020 [R] (CompositeFF_callback, Render)
    u32 m_field_024;  // 0x024 [R] (CompositeFF_callback, CopyTextureToShader, Debug::WriteTGAToHost, ...)
    u8 _pad_028[8];  // 0x028
    s16 m_field_030;  // 0x030 [R] (CopyTextureToShader)
    u8 _pad_032[2];  // 0x032
    u32 m_field_034;  // 0x034 [R] (CopyTextureToShader)
    s16 m_field_038;  // 0x038 [R] (CopyTextureToShader)
    u8 _pad_03A[2];  // 0x03A
    u32 m_field_03C;  // 0x03C [R] (CopyTextureToShader)
    s16 m_field_040;  // 0x040 [R] (CopyTextureToShader)
    u8 _pad_042[2];  // 0x042
    u32 m_field_044;  // 0x044 [R] (CopyTextureToShader)
    u8 _pad_048[0x28];  // 0x048
    s16 m_field_070;  // 0x070 [R] (CompositeFF_callback, CopyTextureToShader, Render)
    u8 _pad_072[2];  // 0x072
    u32 m_field_074;  // 0x074 [R] (CopyTextureToShader)
    u8 _pad_078[0xA8];  // 0x078
    s16 m_repSlotUnLockedBits_120;  // 0x120 [R] (GetRepSlotUnLockedBits)
    u8 _pad_122[2];  // 0x122
    u32 m_repSlotUnLockedBits_124;  // 0x124 [R] (GetRepSlotUnLockedBits)
    u8 _pad_128[0x20];  // 0x128
    s16 m_repSlotUnLockedBits_148;  // 0x148 [R] (GetRepSlotUnLockedBits)
    u8 _pad_14A[2];  // 0x14A
    u32 m_repSlotUnLockedBits_14C;  // 0x14C [R] (GetRepSlotUnLockedBits)
    u8 _pad_150[0x1514];  // 0x150
    f32 m_filterPipeline;  // 0x1664 [R] (SetFilterPipeline)
    f32 m_filterPipeline_1668;  // 0x1668 [R] (SetFilterPipeline)
    u8 _pad_166C[4];  // 0x166C
    f32 m_filterPipeline_1670;  // 0x1670 [R] (SetFilterPipeline)
    u8 _pad_1674[0x4840];  // 0x1674
    u32 m_repSlotUnLockedBits_5EB4;  // 0x5EB4 [R] (GetRepSlotUnLockedBits)
};

#endif // EYETOYCLIENT_H
