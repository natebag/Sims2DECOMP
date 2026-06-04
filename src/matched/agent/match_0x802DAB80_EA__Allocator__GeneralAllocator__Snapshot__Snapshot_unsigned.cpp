// 0x802DAB80 EA::Allocator::GeneralAllocator::Snapshot::Snapshot(unsigned int, unsigned int) (120 B)
// Zero `size` bytes of the snapshot, then stamp the 'SNAP' magic, record the
// size and the second argument, and clear the remaining header words.
extern "C" void* memset(void* dst, int val, unsigned int n);

namespace EA { namespace Allocator {

struct GeneralAllocator {
    struct Snapshot {
        unsigned int magic;       // 0x00
        unsigned int m_size;      // 0x04
        unsigned int m_arg2;      // 0x08
        unsigned int field_0C;    // 0x0C
        unsigned int field_10;    // 0x10
        unsigned int field_14;    // 0x14
        unsigned int field_18;    // 0x18
        unsigned int field_1C;    // 0x1C
        unsigned int field_20;    // 0x20
        unsigned int field_24;    // 0x24
        unsigned int field_28;    // 0x28
        Snapshot(unsigned int size, unsigned int arg2);
    };
};

GeneralAllocator::Snapshot::Snapshot(unsigned int size, unsigned int arg2)
{
    memset(this, 0, size);
    magic = 0x534E4150;
    m_size = size;
    m_arg2 = arg2;
    field_0C = 0;
    field_10 = 0;
    field_14 = 0;
    field_18 = 0;
    field_1C = 0;
    field_20 = 0;
    field_24 = 0;
    field_28 = 0;
}

}}
