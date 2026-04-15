// 0x80210208 InteractorModule::InteractorResourceSet::GetOrderTableData(unsigned int) (56B)

struct OrderTableData;

struct InteractorResourceSet {
    char* m_begin;
    char* m_end;
    OrderTableData* GetOrderTableData(unsigned int idx);
};

OrderTableData* InteractorResourceSet::GetOrderTableData(unsigned int idx) {
    int count = (m_end - m_begin) / 7;
    if (idx >= count) {
        return 0;
    }
    return (OrderTableData*)(m_begin + idx * 56);
}
