// 0x80079C60 (8 bytes)
class CUnlockDisplayObject {
public:
    int HasDrawn();
};

int CUnlockDisplayObject::HasDrawn() {
    return *(int*)((char*)this + 0x7C);
}
