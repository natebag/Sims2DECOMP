// 0x8012CA54 (8 bytes)
class cXPersonImpl {
public:
    int IsWaitingForSocialMode();
};

int cXPersonImpl::IsWaitingForSocialMode() {
    return *(int*)((char*)this + 0x54C);
}
