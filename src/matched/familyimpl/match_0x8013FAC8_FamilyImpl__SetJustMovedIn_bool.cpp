// 0x8013FAC8 FamilyImpl::SetJustMovedIn(bool) (32 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x64(1); mtspr 8,0; lmw 20,0x30(1); addi 1,1,96; blr; li 0,1; stw 0,0x0(3)"

struct FamilyImpl {
    void SetJustMovedIn();
};

void FamilyImpl::SetJustMovedIn() {
}
