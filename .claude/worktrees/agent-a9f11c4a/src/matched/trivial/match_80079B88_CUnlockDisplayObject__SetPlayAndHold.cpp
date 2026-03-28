// 0x80079B88 (8 bytes)
class CUnlockDisplayObject {
public:
    void SetPlayAndHold(int p);
};

void CUnlockDisplayObject::SetPlayAndHold(int p) {
    *(int*)((char*)this + 0x6C) = p;
}
