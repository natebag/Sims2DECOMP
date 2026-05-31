// 0x802DB0E8 EA::Allocator::GeneralAllocator::SetAutoHeapValidation(int, int) (36 B)
// FLAGS:
//
// Configure periodic automatic heap validation. The validation level is stored
// and clamped to a minimum of 1, the validation frequency is recorded, and the
// running counter is reset to 0.

struct GeneralAllocator {
    char _pad[0x488];
    int m_autoValFrequency;  // 0x488
    int m_autoValLevel;      // 0x48C
    int m_autoValCounter;    // 0x490
    void SetAutoHeapValidation(int frequency, int level);
};

void GeneralAllocator::SetAutoHeapValidation(int frequency, int level)
{
    m_autoValLevel = level;
    if (level == 0)
        m_autoValLevel = 1;
    m_autoValFrequency = frequency;
    m_autoValCounter = 0;
}
