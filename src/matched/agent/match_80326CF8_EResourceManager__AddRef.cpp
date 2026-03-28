class EFile;

class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
    void AddRef(unsigned int, EFile*, int, int);
};

void EResourceManager::AddRef(unsigned int id, EFile* f, int x) {
    AddRef(id, f, x, 1);
}
