// 0x80149294 (8 bytes)
class TreeSimImpl {
public:
    int GetIterations();
};

int TreeSimImpl::GetIterations() {
    return *(int*)((char*)this + 0x4);
}
