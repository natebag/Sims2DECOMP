// 0x80147434 (8 bytes)
class TreeSimImpl {
public:
    void SetError(int p);
};

void TreeSimImpl::SetError(int p) {
    *(short*)((char*)this + 0x34) = (short)p;
}
