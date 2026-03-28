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
