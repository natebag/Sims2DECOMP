// 0x8012B82C (8 bytes)
class cXPersonImpl {
public:
    void SetFirstPlayerInSocialMode(int p);
};

void cXPersonImpl::SetFirstPlayerInSocialMode(int p) {
    *(int*)((char*)this + 0x544) = p;
}
