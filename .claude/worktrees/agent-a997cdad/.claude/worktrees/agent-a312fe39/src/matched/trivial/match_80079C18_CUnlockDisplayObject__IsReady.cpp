// 0x80079C18 (8 bytes)
class CUnlockDisplayObject {
public:
    int IsReady();
};

int CUnlockDisplayObject::IsReady() {
    return *(int*)((char*)this + 0x74);
}
