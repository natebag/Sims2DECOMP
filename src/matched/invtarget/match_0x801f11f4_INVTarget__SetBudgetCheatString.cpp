// 0x801F11F4 INVTarget::SetBudgetCheatString(int) (52B)

extern int Sprintf(char* dest, const char* fmt, ...);

struct INVTarget {
    char pad[0x298B];
    char m_budgetCheatString[32];
    void SetBudgetCheatString(int value);
};

void INVTarget::SetBudgetCheatString(int value) {
    Sprintf(m_budgetCheatString, "%d", value);
}
