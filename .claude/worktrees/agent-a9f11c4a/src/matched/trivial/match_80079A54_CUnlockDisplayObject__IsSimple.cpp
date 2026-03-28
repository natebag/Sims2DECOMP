// 0x80079A54 (8 bytes)
class CUnlockDisplayObject {
public:
    int IsSimple();
};

int CUnlockDisplayObject::IsSimple() {
    return *(int*)((char*)this + 0x80);
}
