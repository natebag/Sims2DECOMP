// 0x8020377C (8 bytes)
class EYETarget {
public:
    void SetState(int p);
};

void EYETarget::SetState(int p) {
    *(int*)((char*)this + 0xAC) = p;
}
