// 0x8012C988 (8 bytes)
class cXPersonImpl {
public:
    int GetMotiveEffects();
};

int cXPersonImpl::GetMotiveEffects() {
    return *(int*)((char*)this + 0x408);
}
