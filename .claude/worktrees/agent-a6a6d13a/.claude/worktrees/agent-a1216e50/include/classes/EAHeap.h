#ifndef EAHEAP_H
#define EAHEAP_H

#include "types.h"

// EAHeap - struct layout extracted from assembly analysis
// Estimated minimum size: 0x538 (1336 bytes)
// 6 known fields (0 named), 68 methods

class EAHeap {
public:
    // Static members (from map file)
    // static ??? EA_HEAP_NUM_SMALL_COUNTERS;

    // Constructors / Destructors
    EAHeap(char *, void *, unsigned int, EAHeap *, EAHeap *)  // 0x807647D8
    ~EAHeap(void);  // 0x80767074

    // Methods
    bool IsInitialized(void);  // 0x80019968 (44B)
    void Free(void *);  // 0x8076502C (372B)
    void Compact(void);  // 0x807651A0 (100B)
    void SetNextCheckPoint(void);  // 0x80764764 (72B)
    /* ? */ GetCurrentCheckPoint(void);  // 0x807647AC (44B)
    void Malloc(unsigned int, int);  // 0x80764900 (560B)
    void MallocAligned(unsigned int, unsigned int, unsigned int, int);  // 0x80764B30 (668B)
    void Calloc(unsigned int, unsigned int, int);  // 0x80764DCC (608B)
    void FindHeapForAddress(void *);  // 0x807655E4 (208B)
    void InitializeHeapStatics(void);  // 0x807644BC (460B)
    void Clear(void);  // 0x807654C0 (180B)
    void Init(void *, unsigned int);  // 0x80764874 (140B)
    void CountAlloc(unsigned int);  // 0x80767414 (240B)
    void CountOverflowAlloc(unsigned int);  // 0x80767504 (240B)
    void AllocTest(void);  // 0x80765204 (700B)
    void ValidateHeap(EA::Allocator::GeneralAllocator::HeapValidationLevel);  // 0x80765574 (112B)
    void ValidatePools(void);  // 0x807656B4 (160B)
    void UpdateHeapMemoryStats(void);  // 0x80767EA8 (472B)
    /* ? */ GetUsageInfo(HeapUseInfo &);  // 0x80768080 (184B)
    void PrintSizes(void);  // 0x807684AC (128B)
    void PrintUsedByCheckPoint(int, int);  // 0x8076852C (40B)
    /* ? */ GetGlobalSmallAllocCount(int);  // 0x80767A04 (648B)
    /* ? */ GetSmallAllocCount(unsigned int, int &);  // 0x80768E58 (168B)
    /* ? */ GetGlobalAllocCounter(void);  // 0x80767C8C (540B)
    /* ? */ GetHeapAllocCount(int &);  // 0x80768F00 (44B)
    /* ? */ GetName(void);  // 0x80768DA8 (44B)
    /* ? */ GetFree(void);  // 0x80768E00 (44B)
    /* ? */ GetLargestFree(void);  // 0x80768E2C (44B)
    /* ? */ GetNumUsed(void);  // 0x80768DD4 (44B)
    void ValidateLinks(void);  // 0x80768138 (884B)
    /* ? */ GetCoreCount(void);  // 0x807687AC (108B)
    /* ? */ GetCoreAddress(int);  // 0x80768818 (136B)
    /* ? */ GetCoreSize(int);  // 0x807688A0 (140B)
    void FillBlockUsage(char *, int, int, int, int);  // 0x8076892C (732B)
    void DumpBlockAllocs(int, int);  // 0x80768C08 (72B)
    /* ? */ GetSmallActiveAllocCount(unsigned int, int &);  // 0x80819D34 (168B)
    /* ? */ GetSmallOverflowAllocCount(unsigned int, int &);  // 0x80819C8C (168B)
    /* ? */ GetHeapActiveAllocCount(int &);  // 0x80819DDC (44B)
    /* ? */ GetHeapOverflowAllocCount(int &);  // 0x80819E34 (44B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[4];  // 0x000
    u32 m_field_004;  // 0x004 [R] (Compact)
    u8 _pad_008[0x4F4];  // 0x008
    u32 m_field_4FC;  // 0x4FC [R] (Compact)
    u8 _pad_500[0x28];  // 0x500
    u32 m_field_528;  // 0x528 [W] (EAHeap)
    u32 m_field_52C;  // 0x52C [R/W] (Calloc, EAHeap, FindHeapForAddress, ...)
    u32 m_field_530;  // 0x530 [R/W] (Calloc, EAHeap, FindHeapForAddress, ...)
    u32 m_field_534;  // 0x534 [W] (Clear)
};

#endif // EAHEAP_H
