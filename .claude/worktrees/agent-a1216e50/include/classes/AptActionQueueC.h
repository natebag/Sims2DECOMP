#ifndef APTACTIONQUEUEC_H
#define APTACTIONQUEUEC_H

#include "types.h"

// AptActionQueueC - struct layout extracted from assembly analysis
// Estimated minimum size: 0x14 (20 bytes)
// 5 known fields (3 named), 30 methods

class AptActionQueueC {
public:
    // Constructors / Destructors
    AptActionQueueC(unsigned int)  // 0x806C4C08
    ~AptActionQueueC(void);  // 0x806C4CB4

    // Methods
    /* ? */ GetFirstItem(void);  // 0x806C4D18 (72B)
    bool IsLastItem(AptActionQueueC::AptActionPool *);  // 0x806C4DAC (60B)
    void SetCurItem(AptActionQueueC::AptActionPool *);  // 0x806C4E90 (40B)
    bool IsLastItemOrBeyond(AptActionQueueC::AptActionPool *);  // 0x806C4DE8 (124B)
    /* ? */ GetNextItem(AptActionQueueC::AptActionPool *);  // 0x806C4D60 (76B)
    void ClearActions(void);  // 0x806C39D4 (480B)
    void RegisterReferences(void);  // 0x806C46A0 (348B)
    void AddActionBack(AptActionBlock *, AptCIH *, int, unsigned int);  // 0x806C3BB4 (372B)
    void IncrementDequeLocation(AptActionQueueC::AptActionPool *);  // 0x806C4F08 (120B)
    void AddActionFront(AptActionBlock *, AptCIH *, int, unsigned int);  // 0x806C3D28 (372B)
    void DecrementDequeLocation(AptActionQueueC::AptActionPool *);  // 0x806C4F80 (124B)
    void AddFunctionBack(AptCIH *, AptValue *, int, int, unsigned int);  // 0x806C3E9C (448B)
    void AddFunctionFront(AptCIH *, AptValue *, int, int, unsigned int);  // 0x806C405C (448B)
    void RemoveActionFor(AptCIH *);  // 0x806C421C (656B)
    /* ? */ GetCurItem(void);  // 0x806C4E64 (44B)
    /* ? */ GetDequeSize(void);  // 0x806C44AC (204B)
    /* ? */ GetDequeLocation(int);  // 0x806C4578 (296B)
    void CheckDequeueBounds(AptActionQueueC::AptActionPool *);  // 0x806C627C (208B)
    void AddActionBack(AptActionBlock *, AptCIH *, unsigned int);  // 0x80403AA8 (196B)
    void AddActionFront(AptActionBlock *, AptCIH *, unsigned int);  // 0x80403B6C (196B)
    void AddFunctionBack(AptCIH *, AptValue *, int, unsigned int);  // 0x80403C30 (240B)
    void AddFunctionFront(AptCIH *, AptValue *, int, unsigned int);  // 0x80403D20 (240B)

    // ---- Field Layout (from assembly analysis) ----
    void** _vtable;  // 0x000 [R/W] - vtable pointer (AddActionBack, AddActionFront, AddFunctionBack, ...)
    u32 m_dequeLocation_004;  // 0x004 [R/W] (AddActionBack, AddActionFront, AddFunctionBack, ...)
    u32 m_field_008;  // 0x008 [R/W] (AddActionBack, AddActionFront, AddFunctionBack, ...)
    u32 m_field_00C;  // 0x00C [R] (ClearActions, RegisterReferences, RemoveActionFor)
    u32 m_dequeLocation_010;  // 0x010 [R] (AddActionBack, AddActionFront, AddFunctionBack, ...)
};

#endif // APTACTIONQUEUEC_H
