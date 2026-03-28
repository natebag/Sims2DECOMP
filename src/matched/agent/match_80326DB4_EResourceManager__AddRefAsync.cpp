class EFile;

class EResourceManager {
public:
    void AddRefAsync(unsigned int);
    void AddRefImpl(unsigned int, EFile*, int, int);
};

void EResourceManager::AddRefAsync(unsigned int id) {
    AddRefImpl(id, 0, 0, 0);
}
