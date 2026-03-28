#ifndef ERESPREFETCH_H
#define ERESPREFETCH_H

#include "types.h"

// EResPrefetch - struct layout extracted from assembly analysis
// Estimated minimum size: 0x418 (1048 bytes)
// 22 known fields (5 named), 42 methods

class EResPrefetch {
public:
    // Constructors / Destructors
    EResPrefetch(void)  // 0x8084A44C
    ~EResPrefetch(void);  // 0x8084A4FC

    // Methods
    void Init(void);  // 0x8084A5A8 (420B)
    void Shutdown(void);  // 0x8084A74C (88B)
    void ResetState(void);  // 0x8084C2BC (188B)
    void Flush(void);  // 0x8084B628 (276B)
    void AcquireBuffer(void *, unsigned int);  // 0x8084A7A4 (184B)
    void ReleasedBuffer(EScratchBuffUser *);  // 0x8084A85C (256B)
    void DoCancel(EPrefetchMsg *);  // 0x8084A95C (72B)
    void DoBegin(EPrefetchMsg *);  // 0x8084A9A4 (840B)
    void LoadAnotherBlock(void);  // 0x8084ACEC (1716B)
    void DoFlush(EPrefetchMsg *);  // 0x8084B3A0 (108B)
    void Main(void);  // 0x8084B40C (540B)
    bool Cancel(void);  // 0x8084B73C (260B)
    void BeginPreFetch(char *, char *);  // 0x8084B840 (96B)
    void BeginPreFetch(char *, unsigned int);  // 0x8084B8A0 (324B)
    void AddRef(char *, char *);  // 0x8084B9E4 (212B)
    void AddRef(char *, unsigned int);  // 0x8084BAB8 (872B)
    bool CanAddRef(void);  // 0x8084BE20 (232B)
    bool CanReleaseBuffer(void);  // 0x8084C214 (100B)
    /* ? */ GetLoadProgress(void);  // 0x8084C278 (68B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [W] - vtable pointer (BeginPreFetch, EResPrefetch, ~EResPrefetch)
    u32 m_field_004;  // 0x004 [W] (BeginPreFetch)
    u32 m_field_008;  // 0x008 [R] (DoCancel, ReleasedBuffer, ResetState)
    u32 m_field_00C;  // 0x00C [W] (BeginPreFetch)
    u32 m_field_010;  // 0x010 [W] (BeginPreFetch)
    u8 _pad_014[0x32C];  // 0x014
    u32 m_field_340;  // 0x340 [W] (EResPrefetch, ~EResPrefetch)
    u8 _pad_344[0x94];  // 0x344
    u32 m_field_3D8;  // 0x3D8 [R/W] (EResPrefetch, Init, Shutdown, ...)
    u32 m_field_3DC;  // 0x3DC [R/W] (AddRef, DoBegin, DoCancel, ...)
    u32 m_field_3E0;  // 0x3E0 [R/W] (AddRef, DoBegin, DoCancel, ...)
    u32 m_field_3E4;  // 0x3E4 [R/W] (DoBegin, DoCancel, LoadAnotherBlock, ...)
    u32 m_field_3E8;  // 0x3E8 [R/W] (DoBegin, DoCancel, LoadAnotherBlock, ...)
    u32 m_field_3EC;  // 0x3EC [R/W] (AddRef, DoBegin, DoCancel, ...)
    u32 m_bCanAddRef;  // 0x3F0 [R/W] (CanAddRef, DoBegin, DoCancel, ...)
    u32 m_field_3F4;  // 0x3F4 [R/W] (DoBegin, DoCancel, LoadAnotherBlock, ...)
    u32 m_field_3F8;  // 0x3F8 [R/W] (DoBegin, EResPrefetch, Init, ...)
    u32 m_field_3FC;  // 0x3FC [R/W] (AddRef, DoBegin, EResPrefetch, ...)
    u32 m_bCanAddRef_400;  // 0x400 [R/W] (CanAddRef, EResPrefetch, Init, ...)
    u32 m_bCanAddRef_404;  // 0x404 [R/W] (CanAddRef, DoCancel, LoadAnotherBlock, ...)
    u32 m_field_408;  // 0x408 [R/W] (DoCancel, LoadAnotherBlock, ReleasedBuffer, ...)
    u32 m_field_40C;  // 0x40C [R/W] (AddRef, DoCancel, ReleasedBuffer, ...)
    f32 m_field_410;  // 0x410 [W] (DoBegin, DoCancel, LoadAnotherBlock, ...)
    u32 m_bCanReleaseBuffer;  // 0x414 [R/W] (CanAddRef, CanReleaseBuffer, DoBegin, ...)
};

#endif // ERESPREFETCH_H
