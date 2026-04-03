// 0x8012C7EC (8 bytes)
class cXPersonImpl {
public:
    int GetSAnimator();
};

int cXPersonImpl::GetSAnimator() {
    return *(int*)((char*)this + 0x3F4);
}
