// 0x8014743C (8 bytes)
class TreeSimImpl {
public:
    short GetError();
};

short TreeSimImpl::GetError() {
    return *(short*)((char*)this + 0x34);
}
