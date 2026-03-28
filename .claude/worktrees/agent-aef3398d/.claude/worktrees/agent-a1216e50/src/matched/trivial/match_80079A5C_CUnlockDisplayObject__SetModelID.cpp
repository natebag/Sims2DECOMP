// 0x80079A5C (8 bytes)
class CUnlockDisplayObject {
public:
    void SetModelID(int p);
};

void CUnlockDisplayObject::SetModelID(int p) {
    *(int*)((char*)this + 0x2C) = p;
}
