// 0x8015235C (8 bytes)
class cFixedWorldImpl {
public:
    int GetInfluenceMap();
};

int cFixedWorldImpl::GetInfluenceMap() {
    return *(int*)((char*)this + 0x3C);
}
