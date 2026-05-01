// 0x802D7A08 ESemaphore::operator++(void) (72B)

class ESemaphoreVt {
public:
    char pad[0x10];
    short m_off;                       // 0x10
    char _p[2];
    void (*m_fn)(void*, int);          // 0x14
};

class ESemaphore {
public:
    ESemaphoreVt* m_vt;                // 0x00
    ESemaphore& operator++();
};

ESemaphore& ESemaphore::operator++() {
    ESemaphoreVt* vt = m_vt;
    short off = vt->m_off;
    void (*fn)(void*, int) = vt->m_fn;
    fn((char*)this + off, -1);
    return *this;
}
