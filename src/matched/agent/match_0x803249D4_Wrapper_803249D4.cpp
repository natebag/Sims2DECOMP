/* EDatasetManager::DelRef(char*, EResourceManager::DelRefMode) at 0x803249D4 (32B) */
// 0x803249D4 (32 bytes)
class EResourceManager {
public:
    enum DelRefMode { kDelRefDefault };
    void DelRef(char* name, DelRefMode mode);
};
class EDatasetManager : public EResourceManager {
public:
    void DelRef(char* name, DelRefMode mode);
};
void EDatasetManager::DelRef(char* name, EResourceManager::DelRefMode mode) {
    EResourceManager::DelRef(name, mode);
}
