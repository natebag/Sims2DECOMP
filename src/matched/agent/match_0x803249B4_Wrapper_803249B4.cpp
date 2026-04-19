/* EDatasetManager::DelRef(unsigned int, EResourceManager::DelRefMode) at 0x803249B4 (32B) */
// 0x803249B4 (32 bytes)
class EResourceManager {
public:
    enum DelRefMode { kDelRefDefault };
    void DelRef(unsigned int id, DelRefMode mode);
};
class EDatasetManager : public EResourceManager {
public:
    void DelRef(unsigned int id, DelRefMode mode);
};
void EDatasetManager::DelRef(unsigned int id, EResourceManager::DelRefMode mode) {
    EResourceManager::DelRef(id, mode);
}
