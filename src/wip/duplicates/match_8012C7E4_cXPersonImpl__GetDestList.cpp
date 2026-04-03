// 0x8012C7E4 (8 bytes)
class cXPersonImpl {
public:
    int GetDestList();
};

int cXPersonImpl::GetDestList() {
    return (int)((char*)this + 0x3F8);
}
