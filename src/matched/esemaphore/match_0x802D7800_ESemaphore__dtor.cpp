// 0x802D7800 ESemaphore::~ESemaphore(void) (84B)

class EObj {
public:
    EObj();
    virtual ~EObj();
};

extern char vt_ESemaphore[];

class ESemaphore : public EObj {
public:
    int m_field_4;
    int m_field_8;
    ESemaphore();
    virtual ~ESemaphore();
    void Release();
};

ESemaphore::~ESemaphore() {
    if (m_field_4 != 0) Release();
}
