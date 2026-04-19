/* ESoundTrackDataManager::AddRef(unsigned int, EFile*, int) at 0x803285B8 (32B) */
// 0x803285B8 (32 bytes)

class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class ESoundTrackDataManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};

void ESoundTrackDataManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
