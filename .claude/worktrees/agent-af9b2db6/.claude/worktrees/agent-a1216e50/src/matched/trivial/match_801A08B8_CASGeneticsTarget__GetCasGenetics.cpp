// 0x801A08B8 (8 bytes)
class CASGeneticsTarget {
public:
    int GetCasGenetics();
};

int CASGeneticsTarget::GetCasGenetics() {
    return *(int*)((char*)this + 0x94);
}
