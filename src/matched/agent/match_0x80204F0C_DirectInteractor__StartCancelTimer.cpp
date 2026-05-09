// 0x80204f0c (24B) InteractorModule::DirectInteractor::StartCancelTimer(void)
// Scheduling: DOL hoists lis before li; then stw after lfs. Two swap_adj fixes it.
// ASMPROC_swap_adj: a=li b=lis
// ASMPROC_swap_adj: a=stw b=lfs
namespace InteractorModule {
extern char kTimerStartValue[];
struct DirectInteractor {
    char _[0x84]; int m_cancelTimerActive; float m_cancelTimerValue;
    void StartCancelTimer();
};
void DirectInteractor::StartCancelTimer() {
    m_cancelTimerActive = 1;
    m_cancelTimerValue = *(float*)kTimerStartValue;
}
}
