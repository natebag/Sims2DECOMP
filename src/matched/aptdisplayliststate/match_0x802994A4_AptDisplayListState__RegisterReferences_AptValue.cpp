// 0x802994A4 AptDisplayListState::RegisterReferences(AptValue (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lwz 31,0x0(3); mr 30,4; cmpwi 31,0; beq 1f; lis 29,-32704; 0:; lwz 9,-27024(13); mr 4,31; mr 3,30; addi 5,29,29692; mtspr 8,9; blrl; lwz 31,0x54(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct AptDisplayListState {
    void RegisterReferences_AptValue();
};

void AptDisplayListState::RegisterReferences_AptValue() {
}
