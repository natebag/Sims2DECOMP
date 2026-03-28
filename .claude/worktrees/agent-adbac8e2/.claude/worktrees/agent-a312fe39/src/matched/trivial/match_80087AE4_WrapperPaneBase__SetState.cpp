// 0x80087AE4 (8 bytes)
class WrapperPaneBase {
public:
    void SetState(int p);
};

void WrapperPaneBase::SetState(int p) {
    *(int*)((char*)this + 0x34) = p;
}
