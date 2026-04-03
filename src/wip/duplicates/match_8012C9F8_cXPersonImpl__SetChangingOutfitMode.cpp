// 0x8012C9F8 (8 bytes)
class cXPersonImpl {
public:
    void SetChangingOutfitMode(int p);
};

void cXPersonImpl::SetChangingOutfitMode(int p) {
    *(int*)((char*)this + 0x530) = p;
}
