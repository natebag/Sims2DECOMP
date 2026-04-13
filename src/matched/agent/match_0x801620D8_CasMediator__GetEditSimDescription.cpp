// 0x801620D8 CasMediator::GetEditSimDescription (28B)

class CasMediator {
    char pad[0x10];
    void* m_editSim;

public:
    void* GetEditSimDescription(void);
};

void* CasMediator::GetEditSimDescription(void) {
    void* ptr = m_editSim;
    if (ptr != 0) {
        return (char*)ptr + 8;
    }
    return 0;
}
