// 0x8014BCB8 WantFearManager::~WantFearManager() (76B)

class EResource {
public:
    void DelRef();
};

class WantFearManager {
public:
    EResource* m_0;
    int m_4, m_8, m_C, m_10;
    char pad14[4];
    int m_18;
    ~WantFearManager();
};

WantFearManager::~WantFearManager() {
    if (m_0 != 0) {
        m_0->DelRef();
    }
}
