// 0x8014BCB8 WantFearManager::~WantFearManager (76B)
// dtor: if (m_resource) m_resource->DelRef(); delete-flag check.

struct EResource {
    void DelRef();
};

struct WantFearManager {
    EResource* m_resource;
    ~WantFearManager();
};

WantFearManager::~WantFearManager() {
    if (m_resource != 0) m_resource->DelRef();
}
