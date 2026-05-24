// FLAGS: -fno-schedule-insns
// 0x802093F0 (100B) — InteractorModule::Interactor::GetSelectionRadius()
// ASMPROC_force_reg: match="lis 11,k_radiusInner@ha" from_reg=11 to_reg=30
// ASMPROC_force_reg: match="lfs 13,k_radiusInner@l(11)" from_reg=11 to_reg=30

struct Interactor {
    void GetSelectionRadius();
};

void Interactor::GetSelectionRadius() {
}
