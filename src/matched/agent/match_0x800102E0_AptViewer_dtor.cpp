// 0x800102E0 (120B) AptViewer::~AptViewer(void)
extern void closeFunc();
extern void _delete(void*);

class EMutex {
public:
    void dtor(int);
};

class EWindow {
public:
    void dtor(int);
};

class EAHeap;
extern EAHeap* MainHeap();
extern void EAHeap_Free(EAHeap*, void*);

struct AptViewer {
    char pad[0x358];
    EMutex m_mutex;
    char pad2[0x18];
    void* m_buf;
    void UnLoad();
    void dtor(int del);
};

void AptViewer::dtor(int del) {
    UnLoad();
    closeFunc();
    if (m_buf) {
        _delete(m_buf);
        m_buf = 0;
    }
    m_mutex.dtor(2);
    ((EWindow*)this)->dtor(0);
    if (del & 1) {
        EAHeap_Free(MainHeap(), this);
    }
}
