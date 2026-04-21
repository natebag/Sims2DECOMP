// 0x800E22F8 (108B) cXObjectImpl::SetWasPlacedFromInventory(bool)

extern short* helper_0x800E4040(void* p, int idx);
extern void helper_0x800E4558(void* p, int idx, int val);

struct cXObjectImpl {
    int SetWasPlacedFromInventory(bool flag);
};

int cXObjectImpl::SetWasPlacedFromInventory(bool flag) {
    void* p = (char*)this + 40;
    int val = (int)*helper_0x800E4040(p, 8);
    if (flag) {
        val |= 0x4000;
        helper_0x800E4558(p, 8, val);
    } else {
        val &= ~0x4000;
        helper_0x800E4558(p, 8, val);
    }
    return 1;
}
