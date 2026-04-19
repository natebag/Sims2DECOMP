/* ESoundTrackDataManager::AddRef(char*, EFile*, int) at 0x803285D8 (32B) */
// 0x803285D8 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class ESoundTrackDataManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};

void ESoundTrackDataManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
