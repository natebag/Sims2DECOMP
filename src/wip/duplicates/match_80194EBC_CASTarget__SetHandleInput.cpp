// 0x80194EBC (8 bytes)
class CASTarget {
public:
    void SetHandleInput(int p);
};

void CASTarget::SetHandleInput(int p) {
    *(int*)((char*)this + 0x8C) = p;
}
