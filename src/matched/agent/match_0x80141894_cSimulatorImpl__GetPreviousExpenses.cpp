// 0x80141894 cSimulatorImpl::GetPreviousExpenses(int, ExpenseReport*) (100B)
struct ExpenseReport {
    int data[8];
};

struct cSimulatorImpl {
    char pad[180];
    ExpenseReport m_history[5];
};

void cSimulatorImpl__GetPreviousExpenses(cSimulatorImpl* self, int index, ExpenseReport* report) {
    *report = self->m_history[index];
}
