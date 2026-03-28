class G2DTarget {
public:
    char _pad[0x84];
    int m_isSpawned;

    int IsG2DSpawned();
};

int G2DTarget::IsG2DSpawned() {
    return m_isSpawned;
}
