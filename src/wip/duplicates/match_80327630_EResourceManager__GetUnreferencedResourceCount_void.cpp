class SomeContainer {
public:
    int GetCount();
};

class EResourceManager {
    char pad[88];
    SomeContainer m_container;
public:
    int GetUnreferencedResourceCount();
};

int EResourceManager::GetUnreferencedResourceCount() {
    return m_container.GetCount();
}
