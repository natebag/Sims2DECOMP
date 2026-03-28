class EResourceManager {
public:
    void Detach(void*);
};

class EResource {
    char pad[4];
    EResourceManager* m_pManager;
public:
    void Detach();
};

void EResource::Detach() {
    m_pManager->Detach(this);
}
