/* EResourceManager::AddRefAsync at 0x80326D6C (72 bytes) */

struct EResourceManager;

unsigned int LookupResource(const char* name);
void EResourceManager_AddRef(EResourceManager* mgr, unsigned int id, int p1, int p2, int p3);

void EResourceManager_AddRefAsync(EResourceManager* mgr, const char* name)
{
    unsigned int id = LookupResource(name);
    EResourceManager_AddRef(mgr, id, 0, 0, 0);
}
