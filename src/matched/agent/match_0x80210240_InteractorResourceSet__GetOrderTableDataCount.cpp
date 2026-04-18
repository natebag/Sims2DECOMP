/* InteractorModule::InteractorResourceSet::GetOrderTableDataCount(void) at 0x80210240 (32B) */

struct EOrderTableData { char data[56]; };

struct IRS_OTDCount {
    char pad[0x6C];
    EOrderTableData* m_orderTableBegin;
    EOrderTableData* m_orderTableEnd;
    int GetOrderTableDataCount();
};

int IRS_OTDCount::GetOrderTableDataCount() {
    return m_orderTableEnd - m_orderTableBegin;
}
