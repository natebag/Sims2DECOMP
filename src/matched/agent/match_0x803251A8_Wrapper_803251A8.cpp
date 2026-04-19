/* EMovieMan::AddRef(char*, EFile*, int) at 0x803251A8 (32B) */
// 0x803251A8 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(char*, EFile*, int);
};
class EMovieMan : public EResourceManager {
public:
    void AddRef(char* name, EFile* file, int flag);
};
void EMovieMan::AddRef(char* name, EFile* file, int flag) {
    EResourceManager::AddRef(name, file, flag);
}
