// 0x801A0810 (8 bytes)
class CASTarget {
public:
    int GetCurrentSimNumber();
};

int CASTarget::GetCurrentSimNumber() {
    return *(int*)((char*)this + 0x134C);
}
