// 0x80079B80 (8 bytes)
class CUnlockDisplayObject {
public:
    void SetAnimationLoops(int p);
};

void CUnlockDisplayObject::SetAnimationLoops(int p) {
    *(int*)((char*)this + 0x38) = p;
}
