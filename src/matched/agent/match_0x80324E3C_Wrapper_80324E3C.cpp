/* EFontManager::AddRef(unsigned int, EFile*, int) at 0x80324E3C (32B) */
// 0x80324E3C (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EFontManager : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EFontManager::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
