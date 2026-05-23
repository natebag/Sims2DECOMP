// 0x80204f24 (24B) InteractorModule::DirectInteractor::ClearCancelTimer(void)
// Scheduling: DOL hoists lis before li; then stw after lfs. Two swap_adj fixes it.
// ASMPROC_swap_adj: a=li b=lis
// ASMPROC_swap_adj: a=stw b=lfs
namespace InteractorModule {
extern char kTimerClearedValue[];
struct DirectInteractor {
    char _[0x84]; int m_cancelTimerActive; float m_cancelTimerValue;
    void ClearCancelTimer();
};
void DirectInteractor::ClearCancelTimer() {
    m_cancelTimerActive = 0;
    m_cancelTimerValue = *(float*)kTimerClearedValue;
}
}
