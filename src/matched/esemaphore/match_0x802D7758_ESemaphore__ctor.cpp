// 0x802D7758 ESemaphore::ESemaphore(void) (72B)

extern void EObj_ctor(void* self);
extern char vt_ESemaphore[];

class ESemaphore {
public:
    void* m_vt;       // 0x00
    int m_field_4;    // 0x04
    int m_field_8;    // 0x08
    ESemaphore();
};

ESemaphore::ESemaphore() {
    EObj_ctor(this);
    m_vt = vt_ESemaphore;
    m_field_4 = 0;
    m_field_8 = 0;
}
