#ifndef ERESLOADERMSGQUEUE_H
#define ERESLOADERMSGQUEUE_H

#include "types.h"

// EResLoaderMsgQueue - struct layout extracted from assembly analysis
// Estimated minimum size: 0x50 (80 bytes)
// 7 known fields (5 named), 11 methods

class EResLoaderMsgQueue {
public:
    // Constructors / Destructors
    EResLoaderMsgQueue(void)  // 0x80841B38
    ~EResLoaderMsgQueue(void);  // 0x80847CC8

    // Methods
    bool IsInQueue(EResourceManager *, unsigned int);  // 0x80841B84 (396B)
    void CollapseDelRef(EResourceManager *, unsigned int);  // 0x80841D10 (480B)
    void Send(unsigned int, bool);  // 0x80841EF0 (380B)
    void Receive(unsigned int *, bool);  // 0x8084206C (344B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x30];  // 0x000
    u32 m_bIsInQueue;  // 0x030 [R/W] (CollapseDelRef, IsInQueue, Send)
    u32 m_bIsInQueue_034;  // 0x034 [R/W] (CollapseDelRef, IsInQueue, Receive)
    u32 m_bIsInQueue_038;  // 0x038 [R] (CollapseDelRef, IsInQueue, Receive, ...)
    u32 m_bIsInQueue_03C;  // 0x03C [R] (CollapseDelRef, IsInQueue, Receive, ...)
    u8 _pad_040[4];  // 0x040
    u32 m_field_044;  // 0x044 [R/W] (Send)
    u32 m_field_048;  // 0x048 [R/W] (Send)
    u32 m_bIsInQueue_04C;  // 0x04C [R] (CollapseDelRef, IsInQueue, Receive, ...)
};

#endif // ERESLOADERMSGQUEUE_H
