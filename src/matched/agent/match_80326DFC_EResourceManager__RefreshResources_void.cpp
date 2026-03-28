class SomeContainer {
public:
    void Refresh();
};

class EResourceManager {
    char pad[3336];
    SomeContainer m_container;
public:
    void RefreshResources();
};

void EResourceManager::RefreshResources() {
    m_container.Refresh();
}
