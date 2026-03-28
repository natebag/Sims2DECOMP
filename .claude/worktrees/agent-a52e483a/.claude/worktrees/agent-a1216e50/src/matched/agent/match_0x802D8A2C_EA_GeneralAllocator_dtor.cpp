/* GeneralAllocator::~GeneralAllocator(void) - 0x802D8A2C (64 bytes) */

struct GeneralAllocator {
    void Cleanup();
    ~GeneralAllocator();
};

GeneralAllocator::~GeneralAllocator()
{
    Cleanup();
}
