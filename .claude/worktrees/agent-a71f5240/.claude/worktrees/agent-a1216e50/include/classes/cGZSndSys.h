#ifndef CGZSNDSYS_H
#define CGZSNDSYS_H

#include "types.h"

// cGZSndSys - struct layout extracted from assembly analysis
// Estimated minimum size: 0x41C (1052 bytes)
// 22 known fields (1 named), 30 methods

class cGZSndSys {
public:
    // Constructors / Destructors
    cGZSndSys(void)  // 0x8023F5E8
    ~cGZSndSys(void);  // 0x8023F670

    // Methods
    void FreeUnusedSounds(void);  // 0x8023FC20 (88B)
    void killDeadSounds(void);  // 0x8023FC78 (372B)
    void unloadMusic(void);  // 0x80240B04 (32B)
    void Update(void);  // 0x802400B4 (2608B)
    void Initialize(void);  // 0x8023F808 (64B)
    void preloadMusic(void);  // 0x80240AE4 (32B)
    void CreateSoundEffect(unsigned int, float);  // 0x8023F848 (116B)
    void CreateAudioStream(unsigned int, bool, float);  // 0x8023F8BC (228B)
    void addToList(cGZSnd *);  // 0x8023F9A0 (56B)
    void removeFromList(cGZSnd *);  // 0x8023F9D8 (252B)
    void addToList(cGZMusic *);  // 0x8023FAD4 (56B)
    void removeFromList(cGZMusic *);  // 0x8023FB0C (276B)
    void ProcessCache(unsigned int);  // 0x8023FDEC (712B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (ProcessCache, Update, cGZSndSys, ...)
    u8 m_field_003;  // 0x003 [R] (ProcessCache)
    u32 m_field_004;  // 0x004 [R/W] (Update)
    u32 m_field_008;  // 0x008 [R] (Update)
    u32 m_field_00C;  // 0x00C [W] (CreateAudioStream)
    u32 m_field_010;  // 0x010 [R/W] (CreateAudioStream, ProcessCache)
    u32 m_field_014;  // 0x014 [R/W] (CreateSoundEffect, Update)
    u32 m_field_018;  // 0x018 [R] (ProcessCache)
    f32 m_field_01C;  // 0x01C [R/W] (CreateAudioStream, Update)
    u32 m_field_020;  // 0x020 [R/W] (Update)
    u32 m_field_024;  // 0x024 [R] (Update)
    u8 _pad_028[8];  // 0x028
    f32 m_field_030;  // 0x030 [W] (CreateSoundEffect)
    u32 m_field_034;  // 0x034 [R/W] (Update)
    u32 m_field_038;  // 0x038 [R] (Update)
    u8 _pad_03C[0x74];  // 0x03C
    s16 m_field_0B0;  // 0x0B0 [R] (Update)
    u8 _pad_0B2[2];  // 0x0B2
    u32 m_field_0B4;  // 0x0B4 [R] (Update)
    u8 _pad_0B8[0x34C];  // 0x0B8
    u32 m_field_404;  // 0x404 [R/W] (Update, cGZSndSys, killDeadSounds, ...)
    u32 m_field_408;  // 0x408 [R/W] (Update, cGZSndSys, removeFromList, ...)
    u32 m_field_40C;  // 0x40C [R/W] (Update, cGZSndSys, removeFromList)
    u32 m_field_410;  // 0x410 [R/W] (Update, cGZSndSys)
    u32 m_field_414;  // 0x414 [R/W] (Update, cGZSndSys)
    u32 m_field_418;  // 0x418 [R/W] (Update, cGZSndSys)
};

#endif // CGZSNDSYS_H
