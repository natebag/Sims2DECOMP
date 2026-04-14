// 0x80141B60 cSimulatorImpl::SetObjectsValue(int) (48B)
struct cSimulatorImpl {
    char pad[86];
    short m_objectsCents;   // 86
    short m_objectsDollars; // 88
    char pad2[46];
    int m_rawObjects;       // 136
};

void cSimulatorImpl__SetObjectsValue(cSimulatorImpl* self, int value) {
    self->m_rawObjects = value;
    self->m_objectsDollars = value / 10000;
    self->m_objectsCents = value % 10000;
}
