// 0x8012C978 (8 bytes)
class cXPersonImpl {
public:
    short GetVisibility();
};

short cXPersonImpl::GetVisibility() {
    return *(short*)((char*)this + 0x9C);
}
