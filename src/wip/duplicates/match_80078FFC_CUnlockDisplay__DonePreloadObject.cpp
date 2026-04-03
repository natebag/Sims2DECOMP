// 0x80078FFC (8 bytes)
class CUnlockDisplay {
public:
    int DonePreloadObject();
};

int CUnlockDisplay::DonePreloadObject() {
    return *(int*)((char*)this + 0x450);
}
