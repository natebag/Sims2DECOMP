typedef unsigned char u8;

class CUnlockDisplay {
    u8 _pad0[0x450];
    int m_bDonePreloadObject;
public:
    int DonePreloadObject();
};

int CUnlockDisplay::DonePreloadObject() {
    return m_bDonePreloadObject;
}
