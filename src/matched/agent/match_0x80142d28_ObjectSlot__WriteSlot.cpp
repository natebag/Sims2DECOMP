// 0x80142D28 ObjectSlot::WriteSlot(SlotDescriptor *) (60B)

struct SlotDescriptor {
    short m_type;
    float m_field4;
    float m_field8;
    float m_fieldC;
    int m_field10;
    int m_field14;
    int m_field18;
};

struct ObjectSlot {
    char pad[8];
    int m_field8;
    int m_fieldC;
    int m_field10;
    float m_field14;
    float m_field18;
    float m_field1C;
    void WriteSlot(SlotDescriptor* dest);
};

void ObjectSlot::WriteSlot(SlotDescriptor* dest) {
    dest->m_type = 0;
    dest->m_field10 = m_fieldC;
    dest->m_field14 = m_field10;
    dest->m_field18 = m_field8;
    dest->m_field4 = m_field14;
    dest->m_field8 = m_field18;
    dest->m_fieldC = m_field1C;
}
