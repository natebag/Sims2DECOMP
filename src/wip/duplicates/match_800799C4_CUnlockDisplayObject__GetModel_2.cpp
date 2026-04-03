// 0x800799C4 (8 bytes)
class CUnlockDisplayObject {
public:
    int GetModel();
};

int CUnlockDisplayObject::GetModel() {
    return *(int*)((char*)this + 0x14);
}
