typedef unsigned char u8;

class CUnlockDisplay {
    u8 _pad0[0x45C];
    int m_bDone;
public:
    int IsDone();
};

int CUnlockDisplay::IsDone() {
    return m_bDone;
}
