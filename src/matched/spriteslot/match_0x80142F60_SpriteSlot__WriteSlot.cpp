// SpriteSlot::WriteSlot(SlotDescriptor *) - 0x80142F60 (44B)
// Two writes to desc.m_a: first from m_extra (this+0x4c), then overwritten by m_a (this+0xc).

struct SlotDescriptor {
    short m_type;          // +0x00
    char _pad[2];
    float m_b;             // +0x04
    float m_c;             // +0x08
    float m_a;             // +0x0c
};

class SpriteSlot {
public:
    char _pad0[4];
    float m_b;             // +0x04
    float m_c;             // +0x08
    float m_a;             // +0x0c
    char _pad1[0x3c];
    float m_extra;         // +0x4c
    void WriteSlot(SlotDescriptor* desc);
};

void SpriteSlot::WriteSlot(SlotDescriptor* desc)
{
    desc->m_a = m_extra;
    desc->m_type = 1;
    desc->m_b = m_b;
    desc->m_c = m_c;
    desc->m_a = m_a;
}
