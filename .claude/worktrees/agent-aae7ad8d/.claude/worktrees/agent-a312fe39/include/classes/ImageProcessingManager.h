#ifndef IMAGEPROCESSINGMANAGER_H
#define IMAGEPROCESSINGMANAGER_H

#include "types.h"

// ImageProcessingManager - struct layout extracted from assembly analysis
// Estimated minimum size: 0x74 (116 bytes)
// 21 known fields (6 named), 26 methods

class ImageProcessingManager {
public:
    // Methods
    void SetStageFilter(int, ImageProcessingManager::FilterDescriptor *);  // 0x8089D5B8 (308B)
    void Open(int);  // 0x8089D378 (460B)
    void Close(void);  // 0x8089D544 (116B)
    void Execute(ETexture *, ETexture *);  // 0x8089D864 (1516B)
    bool HasBaseColorParam(ImageProcessingManager::eFilter);  // 0x8089DE50 (68B)
    bool HasBlendParam(ImageProcessingManager::eFilter);  // 0x8089DF24 (72B)
    bool HasThreshParam(ImageProcessingManager::eFilter);  // 0x8089DEDC (72B)
    bool HasHSVParam(ImageProcessingManager::eFilter);  // 0x8089DE94 (72B)
    void SetStageCallback(int, void (*);  // 0x8089D6EC (200B)
    void ExecuteAsync(ETexture *, ETexture *, void (*);  // 0x8089D7B4 (176B)
    void LinkTexture(unsigned int, unsigned int);  // 0x8089F18C (296B)
    void DummyFree(void *);  // 0x8089F2B4 (32B)
    void CompositeEdges(short *, short *, int, int, ImageProcessingManager::BlendParams *);  // 0x8089F2D4 (2720B)

    // ---- Field Layout (from assembly analysis) ----
    u8 m_stageFilter;  // 0x000 [W] (FilterParams::Reset, Open, SetStageFilter)
    u8 m_field_001;  // 0x001 [W] (FilterParams::Reset)
    u8 m_field_002;  // 0x002 [W] (FilterParams::Reset)
    u8 _pad_003[1];  // 0x003
    u16 m_stageFilter_004;  // 0x004 [W] (CompositeEdges, Execute, FilterParams::Reset, ...)
    u8 _pad_006[2];  // 0x006
    u8 m_stageFilter_008;  // 0x008 [W] (CompositeEdges, Execute, FilterParams::Reset, ...)
    u8 m_field_009;  // 0x009 [W] (FilterParams::Reset)
    u8 m_field_00A;  // 0x00A [W] (FilterParams::Reset)
    u8 m_field_00B;  // 0x00B [W] (FilterParams::Reset)
    f32 m_stageFilter_00C;  // 0x00C [W] (FilterParams::Reset, SetStageFilter)
    f32 m_stageFilter_010;  // 0x010 [R/W] (CompositeEdges, Execute, FilterParams::Reset, ...)
    u16 m_field_012;  // 0x012 [R/W] (CompositeEdges, Execute)
    f32 m_stageFilter_014;  // 0x014 [W] (CompositeEdges, Execute, FilterParams::Reset, ...)
    u16 m_field_016;  // 0x016 [W] (CompositeEdges, Execute)
    f32 m_field_018;  // 0x018 [W] (CompositeEdges, Execute, FilterParams::Reset)
    u8 m_field_019;  // 0x019 [W] (CompositeEdges, Execute)
    u8 m_field_01A;  // 0x01A [W] (CompositeEdges, Execute)
    u8 m_field_01B;  // 0x01B [W] (CompositeEdges, Execute)
    u32 m_field_01C;  // 0x01C [W] (CompositeEdges, Execute)
    u32 m_field_020;  // 0x020 [R] (CompositeEdges)
    u32 m_field_024;  // 0x024 [R] (CompositeEdges, Execute)
    u8 _pad_028[0x48];  // 0x028
    u32 m_field_070;  // 0x070 [R] (CompositeEdges)
};

#endif // IMAGEPROCESSINGMANAGER_H
