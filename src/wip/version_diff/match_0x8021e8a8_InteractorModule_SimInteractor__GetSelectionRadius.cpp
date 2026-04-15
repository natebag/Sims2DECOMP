// 0x8021E8A8 InteractorModule::SimInteractor::GetSelectionRadius(void) (64B)

struct InteractorModule_Interactor;
extern float GetSelectionRadius__26InteractorModule_Interactor(void);

struct InteractorModule_SimInteractor {
    char pad[0x214];
    int m_hasSelectionRadius;
    float GetSelectionRadius(void);
};

float InteractorModule_SimInteractor::GetSelectionRadius(void) {
    float result = GetSelectionRadius__26InteractorModule_Interactor();
    if (!m_hasSelectionRadius) {
        result = *(float*)0x8040DD1C;
    }
    return result;
}
