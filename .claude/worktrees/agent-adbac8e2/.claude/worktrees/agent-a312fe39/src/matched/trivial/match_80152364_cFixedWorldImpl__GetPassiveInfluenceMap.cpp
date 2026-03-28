// 0x80152364 (8 bytes)
class cFixedWorldImpl {
public:
    int GetPassiveInfluenceMap();
};

int cFixedWorldImpl::GetPassiveInfluenceMap() {
    return *(int*)((char*)this + 0x40);
}
