// 0x80078FDC (8 bytes)
class CUnlockDisplay {
public:
    int IsDone();
};

int CUnlockDisplay::IsDone() {
    return *(int*)((char*)this + 0x45C);
}
