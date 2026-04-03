// 0x80079C68 (8 bytes)
class CUnlockDisplayObject {
public:
    int GetType();
};

int CUnlockDisplayObject::GetType() {
    return *(int*)((char*)this + 0x4);
}
