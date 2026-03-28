/* EResourceMap::~EResourceMap(void) - 0x80327A5C (64 bytes) */

struct EResourceMap {
    void Cleanup();
    ~EResourceMap();
};

EResourceMap::~EResourceMap()
{
    Cleanup();
}
