// 0x80203D68 (8 bytes)
class INVTarget {
public:
    int GetSelectedShoppingCategoryListIdx();
};

int INVTarget::GetSelectedShoppingCategoryListIdx() {
    return *(unsigned char*)((char*)this + 0x3250);
}
