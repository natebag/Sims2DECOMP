// 0x8015F078 (92B) CasClothingUnlocks::ClearUnlocks()

extern "C" void* memset(void*, int, unsigned int);

class CasClothingUnlocks {
public:
    void ClearUnlocks();
    void UnlockGroup(unsigned int, bool);
};

void CasClothingUnlocks::ClearUnlocks() {
    unsigned char val = 2;
    unsigned char* pval = &val;
    memset(this, *pval, 2560);
    memset((char*)this + 2560, *pval, 480);
    UnlockGroup(0, false);
}
