class EResourceManager {
public:
    void Refresh(void*);
};

class EResource {
    char pad[4];
    EResourceManager* m_pManager;
public:
    void Refresh();
};

void EResource::Refresh() {
    if (m_pManager) {
        m_pManager->Refresh(this);
    }
}
