// 0x802D7A50 ESemaphore::operator++(int) (72B)

class ESemaphoreVt {
public:
    char pad[0x10];
    short m_off;
    char _p[2];
    void (*m_fn)(void*, int);
};

class ESemaphore {
public:
    ESemaphoreVt* m_vt;
    ESemaphore& operator++(int);
};

ESemaphore& ESemaphore::operator++(int) {
    ESemaphoreVt* vt = m_vt;
    short off = vt->m_off;
    void (*fn)(void*, int) = vt->m_fn;
    fn((char*)this + off, -1);
    return *this;
}
