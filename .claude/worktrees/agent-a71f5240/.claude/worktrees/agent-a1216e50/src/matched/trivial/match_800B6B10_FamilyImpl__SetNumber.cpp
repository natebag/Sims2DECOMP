// 0x800B6B10 (8 bytes)
class FamilyImpl {
public:
    void SetNumber(int p);
};

void FamilyImpl::SetNumber(int p) {
    *(int*)((char*)this + 0x8) = p;
}
