/* InteractorModule::DirectInteractor::ExitDirectControl(void) at 0x80206120 (12B) */
/* li r0, 1; stw r0, 0x6C(r3); blr */

namespace InteractorModule {
struct DirectInteractor {
    char _pad[0x6C];
    int m_exitDirectControl;
    void ExitDirectControl(void);
};
}

void InteractorModule::DirectInteractor::ExitDirectControl(void) {
    m_exitDirectControl = 1;
}
