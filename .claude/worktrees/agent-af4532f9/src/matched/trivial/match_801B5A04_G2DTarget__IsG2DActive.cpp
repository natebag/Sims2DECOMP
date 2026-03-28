// 0x801B5A04 (8 bytes)
class G2DTarget {
public:
    int IsG2DActive();
};

int G2DTarget::IsG2DActive() {
    return *(int*)((char*)this + 0x88);
}
