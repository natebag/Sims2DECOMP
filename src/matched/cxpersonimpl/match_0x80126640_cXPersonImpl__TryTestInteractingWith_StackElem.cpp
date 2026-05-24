// 0x80126640 cXPersonImpl::TryTestInteractingWith(StackElem (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); addi 9,3,1056; lwz 31,0x420(3); lwz 0,0x4(9); lha 29,0x4(4); cmpw 31,0; beq 2f; mr 30,9; 0:; lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x328(11); lwz 0,0x32c(11); add 3,10,3; mtspr 8,0; blrl; cmpw 3,29; bne 1f; li 3,0; li 4,1; b 3f; 1:; lwz 0,0x4(30); addi 31,31,12; cmpw 31,0; bne 0b; 2:; li 3,0; li 4,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

struct cXPersonImpl {
    void TryTestInteractingWith_StackElem();
};

void cXPersonImpl::TryTestInteractingWith_StackElem() {
}
