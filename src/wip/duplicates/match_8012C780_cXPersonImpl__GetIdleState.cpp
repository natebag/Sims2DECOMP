// 0x8012C780 (8 bytes)
class cXPersonImpl {
public:
    short GetIdleState();
};

short cXPersonImpl::GetIdleState() {
    return *(short*)((char*)this + 0x8);
}
