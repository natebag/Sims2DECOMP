// 0x80151C38 (8 bytes)
class cFixedWorldImpl {
public:
    int GetYSize();
};

int cFixedWorldImpl::GetYSize() {
    return *(int*)((char*)this + 0x18);
}
