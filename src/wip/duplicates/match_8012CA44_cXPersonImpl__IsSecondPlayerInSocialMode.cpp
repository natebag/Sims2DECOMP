// 0x8012CA44 (8 bytes)
class cXPersonImpl {
public:
    int IsSecondPlayerInSocialMode();
};

int cXPersonImpl::IsSecondPlayerInSocialMode() {
    return *(int*)((char*)this + 0x548);
}
