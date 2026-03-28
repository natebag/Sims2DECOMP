// 0x8012C980 (8 bytes)
class cXPersonImpl {
public:
    int GetMotives();
};

int cXPersonImpl::GetMotives() {
    return (int)((char*)this + 0xA8);
}
