// 0x801491B4 (8 bytes)
class StackElem {
public:
    void SetIgnoreDataBreakPoint(int p);
};

void StackElem::SetIgnoreDataBreakPoint(int p) {
    *(int*)((char*)this + 0xC) = p;
}
