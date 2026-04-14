// 0x8014513C QuickDataSlotDescList::GetNumSlots (24B)
struct QuickDataSlotDescList {
    char pad[0x54];
    void* m_data;
};
int QuickDataSlotDescList_GetNumSlots(QuickDataSlotDescList* self) {
    void* data = self->m_data;
    int result = 0;
    if (data != 0) {
        result = ((int*)data)[-1];
    }
    return result;
}
