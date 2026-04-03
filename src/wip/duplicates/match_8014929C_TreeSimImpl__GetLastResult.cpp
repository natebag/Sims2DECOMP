// 0x8014929C (8 bytes)
class TreeSimImpl {
public:
    int GetLastResult();
};

int TreeSimImpl::GetLastResult() {
    return *(int*)((char*)this + 0x2C);
}
