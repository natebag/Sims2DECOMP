class EResource;

class EResourceManager {
public:
    void AddResource(EResource*, unsigned int);
    void AddResource(EResource*, unsigned int, int);
};

void EResourceManager::AddResource(EResource* res, unsigned int id) {
    AddResource(res, id, 0);
}
