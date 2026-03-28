// 0x801491AC (8 bytes)
class StackElem {
public:
    int GetIgnoreDataBreakPoint();
};

int StackElem::GetIgnoreDataBreakPoint() {
    return *(int*)((char*)this + 0xC);
}
