/* EEdithTreeSetMan::AddRef(unsigned int, EFile*, int) at 0x80324B34 (32B) */
// 0x80324B34 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EEdithTreeSetMan : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EEdithTreeSetMan::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
