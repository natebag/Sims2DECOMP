// FLAGS: -fno-elide-constructors
// 0x80285740 match_80285740_AptActionQueueC__IncrementDequeLocation_AptActionPool_ptr_ (40B)
struct AptActionPool {
    int data[5];
};

struct AptActionQueueC {
    AptActionPool* m_base;
    char pad1[0x0C];
    int m_capacity;

    AptActionPool* IncrementDequeLocation(AptActionPool* loc);
};

AptActionPool* AptActionQueueC::IncrementDequeLocation(AptActionPool* loc) {
    loc++;
    if (loc == m_base + m_capacity)
        loc = m_base;
    return loc;
}
