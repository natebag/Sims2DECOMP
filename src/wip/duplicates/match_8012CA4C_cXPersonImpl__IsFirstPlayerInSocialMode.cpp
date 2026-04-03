// 0x8012CA4C (8 bytes)
class cXPersonImpl {
public:
    int IsFirstPlayerInSocialMode();
};

int cXPersonImpl::IsFirstPlayerInSocialMode() {
    return *(int*)((char*)this + 0x544);
}
