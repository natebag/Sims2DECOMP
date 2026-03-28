// 0x801A08A8 (8 bytes)
class CASTarget {
public:
    int GetGeneticsTarget();
};

int CASTarget::GetGeneticsTarget() {
    return *(int*)((char*)this + 0x1370);
}
