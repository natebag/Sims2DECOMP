class G2DTarget {
public:
    char _pad[0x88];
    int m_isActive;

    int IsG2DActive();
};

int G2DTarget::IsG2DActive() {
    return m_isActive;
}
