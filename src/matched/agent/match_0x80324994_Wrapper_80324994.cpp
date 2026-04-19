/* EDatasetManager::PreloadResource(unsigned int) at 0x80324994 (32B) */
// 0x80324994 (32 bytes)
class EResourceManager {
public:
    void PreloadResource(unsigned int id);
};
class EDatasetManager : public EResourceManager {
public:
    void PreloadResource(unsigned int id);
};
void EDatasetManager::PreloadResource(unsigned int id) {
    EResourceManager::PreloadResource(id);
}
