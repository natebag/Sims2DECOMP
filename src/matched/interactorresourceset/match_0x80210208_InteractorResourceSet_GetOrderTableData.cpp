// 0x80210208 InteractorModule::InteractorResourceSet::GetOrderTableData(unsigned int) (56B)

struct OrderTableData;

struct InteractorResourceSet {
    char pad[108];
    char* m_begin;
    char* m_end;
    OrderTableData* GetOrderTableData(unsigned int idx);
};

OrderTableData* InteractorResourceSet::GetOrderTableData(unsigned int idx) {
    int diff = m_end - m_begin;
    int count = (diff * (int)0xB6DB6DB7) >> 3;
    if (idx >= count) {
        return 0;
    }
    return (OrderTableData*)(m_begin + idx * 56);
}
