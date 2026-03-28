// 0x8012C7DC (8 bytes)
class cXPersonImpl {
public:
    void SetIdleLoopCount(int p);
};

void cXPersonImpl::SetIdleLoopCount(int p) {
    *(short*)((char*)this + 0x540) = (short)p;
}
