/* EResourceManager::LookupId(EResourceManager*, unsigned int, unsigned int&, unsigned int&) at 0x80327F10 (32B) */
// 0x80327F10 (32 bytes)
class EResourceManager {
public:
    void LookupId(unsigned int id, unsigned int& outA, unsigned int& outB);
    static void LookupId(EResourceManager* mgr, unsigned int id, unsigned int& outA, unsigned int& outB);
};
void EResourceManager::LookupId(EResourceManager* mgr, unsigned int id, unsigned int& outA, unsigned int& outB) {
    mgr->LookupId(id, outA, outB);
}
