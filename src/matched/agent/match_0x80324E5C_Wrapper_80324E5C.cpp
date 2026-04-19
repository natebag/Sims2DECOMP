/* EFontManager::AddRef(char*, EFile*, int) at 0x80324E5C (32B) */
// 0x80324E5C (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EFontManager : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EFontManager::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
