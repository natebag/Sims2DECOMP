// 0x8014BC6C WantFearManager::WantFearManager() (76B)

class WantFearManager {
public:
    int m_0;
    int m_4;
    int m_8;
    int m_C;
    int m_10;
    char pad14[4];
    int m_18;
    WantFearManager();
    void LoadWants();
};

WantFearManager::WantFearManager() : m_0(0), m_4(0), m_8(0), m_C(0), m_10(0), m_18(0) {
    LoadWants();
}
