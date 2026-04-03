// 0x8012B8C4 (8 bytes)
class cXPersonImpl {
public:
    void SetWaitingForSocialMode(int p);
};

void cXPersonImpl::SetWaitingForSocialMode(int p) {
    *(int*)((char*)this + 0x54C) = p;
}
