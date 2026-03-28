// 0x8014CDCC (8 bytes)
class cFixedWorldImpl {
public:
    int GetWalls();
};

int cFixedWorldImpl::GetWalls() {
    return *(int*)((char*)this + 0x38);
}
