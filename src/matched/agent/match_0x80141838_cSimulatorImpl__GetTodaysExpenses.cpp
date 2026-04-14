// 0x80141838 cSimulatorImpl::GetTodaysExpenses(ExpenseReport*) (92B)
struct ExpenseReport {
    int data[8];
};

struct cSimulatorImpl {
    char pad[340];
    ExpenseReport m_today;
};

void cSimulatorImpl__GetTodaysExpenses(cSimulatorImpl* self, ExpenseReport* report) {
    *report = self->m_today;
}
