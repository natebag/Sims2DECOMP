// 0x80151C30 (8 bytes)
class cFixedWorldImpl {
public:
    int GetXSize();
};

int cFixedWorldImpl::GetXSize() {
    return *(int*)((char*)this + 0x14);
}
