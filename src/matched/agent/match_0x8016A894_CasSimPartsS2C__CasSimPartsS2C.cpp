// 0x8016A894 CasSimPartsS2C::CasSimPartsS2C() (100B)

class EResourceManager;
class EFile;

class EResourceManager {
public:
    char data[3368];
    void* AddRef(unsigned int magic, EFile* file, int idx);
};

extern EResourceManager _quickdataman;

class CasSimPartsS2C {
public:
    void* m_0;
    int m_4;
    int m_8;
    int m_C;
    CasSimPartsS2C();
};

CasSimPartsS2C::CasSimPartsS2C() : m_0(0), m_4(0), m_8(1), m_C(0) {
    m_0 = _quickdataman.AddRef(0x2A2AF469, 0, 0);
}
