// 0x8012CA08 (8 bytes)
class cXPersonImpl {
public:
    void SetLastMotiveUpdateTick(int p);
};

void cXPersonImpl::SetLastMotiveUpdateTick(int p) {
    *(int*)((char*)this + 0x538) = p;
}
