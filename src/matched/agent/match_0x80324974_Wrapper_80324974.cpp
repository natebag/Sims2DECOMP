/* EDatasetManager::AddRefAsync(unsigned int) at 0x80324974 (32B) */
// 0x80324974 (32 bytes)
class EResourceManager {
public:
    void AddRefAsync(unsigned int id);
};
class EDatasetManager : public EResourceManager {
public:
    void AddRefAsync(unsigned int id);
};
void EDatasetManager::AddRefAsync(unsigned int id) {
    EResourceManager::AddRefAsync(id);
}
