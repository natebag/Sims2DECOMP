/* EEdithTreeSetMan::AddRef(char*, EFile*, int) at 0x80324B54 (32B) */
// 0x80324B54 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EEdithTreeSetMan : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EEdithTreeSetMan::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
