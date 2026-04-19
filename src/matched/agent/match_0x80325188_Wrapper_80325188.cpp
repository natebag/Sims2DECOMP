/* EMovieMan::AddRef(unsigned int, EFile*, int) at 0x80325188 (32B) */
// 0x80325188 (32 bytes)
class EFile;
class EResourceManager {
public:
    void AddRef(unsigned int, EFile*, int);
};
class EMovieMan : public EResourceManager {
public:
    void AddRef(unsigned int id, EFile* file, int flag);
};
void EMovieMan::AddRef(unsigned int id, EFile* file, int flag) {
    EResourceManager::AddRef(id, file, flag);
}
