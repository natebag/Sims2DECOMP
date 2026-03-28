class EResource;

class EResourceManager {
public:
    EResource* FindResource(unsigned int);
    bool IsValid(unsigned int);
};

bool EResourceManager::IsValid(unsigned int id) {
    EResource* r = FindResource(id);
    if (r != 0) return true;
    return false;
}
