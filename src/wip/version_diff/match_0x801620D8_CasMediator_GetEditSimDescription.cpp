// 0x801620D8 CasMediator::GetEditSimDescription(void) (28b)

class CasMediator {
    void *m_editSim;
    
public:
    void* GetEditSimDescription(void);
};

void* CasMediator::GetEditSimDescription(void) {
    char *ptr = (char*)m_editSim;
    if (ptr != 0) {
        ptr = ptr + 8;
    }
    return ptr;
}
