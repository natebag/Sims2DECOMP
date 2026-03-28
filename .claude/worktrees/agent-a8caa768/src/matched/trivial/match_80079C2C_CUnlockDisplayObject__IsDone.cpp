// 0x80079C2C (8 bytes)
class CUnlockDisplayObject {
public:
    int IsDone();
};

int CUnlockDisplayObject::IsDone() {
    return *(int*)((char*)this + 0x78);
}
