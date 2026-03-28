#ifndef EMSGQUEUE_H
#define EMSGQUEUE_H

#include "types.h"

// EMsgQueue - struct layout extracted from assembly analysis
// Estimated minimum size: 0x4C (76 bytes)
// 7 known fields (3 named), 26 methods

class EMsgQueue {
public:
    // Constructors / Destructors
    EMsgQueue(void)  // 0x808FD998
    EMsgQueue(int)  // 0x808FDA04
    ~EMsgQueue(void);  // 0x808FDAE0

    // Methods
    bool IsFull(void);  // 0x80799EB4 (84B)
    bool IsEmpty(void);  // 0x8084C378 (84B)
    void Destroy(void);  // 0x808FDD6C (212B)
    void Create(int);  // 0x808FDB60 (524B)
    void Send(unsigned int, bool);  // 0x808FDE40 (356B)
    void Receive(unsigned int *, bool);  // 0x808FDFA4 (320B)
    /* ? */ GetCount(void);  // 0x808FE304 (212B)
    /* ? */ GetStats(int &, int &, int &, int &);  // 0x808FE3D8 (120B)
    void iSend(unsigned int);  // 0x808FE0E4 (264B)
    void iReceive(unsigned int *);  // 0x808FE1EC (280B)
    void Empty(void);  // 0x808FE450 (84B)

    // ---- Field Layout (from assembly analysis) ----
    u8 _pad_000[0x30];  // 0x000
    u32 m_field_030;  // 0x030 [R/W] (Create, Send, iSend)
    u32 m_field_034;  // 0x034 [R/W] (Create, Receive, iReceive)
    u32 m_stats;  // 0x038 [R/W] (Create, Destroy, EMsgQueue, ...)
    u32 m_field_03C;  // 0x03C [R/W] (Create, Destroy, Receive, ...)
    u32 m_field_040;  // 0x040 [R/W] (Create, Destroy, EMsgQueue)
    u32 m_stats_044;  // 0x044 [R/W] (EMsgQueue, GetStats, Send)
    u32 m_stats_048;  // 0x048 [R/W] (EMsgQueue, GetStats, Send)
};

#endif // EMSGQUEUE_H
