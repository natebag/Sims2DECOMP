// 0x8012AC7C cXPersonImpl::CompleteCurrentAction(void) (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 0,0x534(31); cmpwi 0,0; beq 2f; addi 11,31,304; lis 0,-13108; lwz 9,0x2a8(11); ori 0,0,52429; mr 30,11; mulhwu 0,9,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 9,0,9; mulli 9,9,68; add 11,11,9; lwz 0,0x3c(11); rlwinm 0,0,17,31,31; cmpwi 0,0; beq 0f; li 0,1; 0:; stw 0,0x534(31); mr 3,30; li 4,0; bl _s8012AC7C_0; lwz 9,0x2a8(30); lwz 0,0x2ac(30); subf. 9,9,0; bne 1f; lwz 0,0x534(31); cmpwi 0,0; beq 1f; stw 9,0x534(31); 1:; mr 3,31; bl _s8012AC7C_1; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8012AC7C_0();
extern "C" void _s8012AC7C_1();

struct cXPersonImpl {
    void CompleteCurrentAction();
};

void cXPersonImpl::CompleteCurrentAction() {
}
