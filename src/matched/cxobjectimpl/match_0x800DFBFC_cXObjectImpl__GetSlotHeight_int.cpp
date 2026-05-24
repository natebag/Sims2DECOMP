// 0x800DFBFC cXObjectImpl::GetSlotHeight(int) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stmw 30,0x8(1); stw 0,0x1c(1); mr 31,3; mr. 30,4; blt 0f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x2b0(9); lwz 9,0x2b4(9); add 3,3,0; mtspr 8,9; blrl; cmpw 30,3; blt 1f; 0:; lis 9,-32706; lfs f1,-20896(9); b 5f; 1:; lwz 31,0x4(31); lis 9,-32706; lfs f31,-20896(9); cmpwi 31,0; beq 4f; 2:; lwz 9,0x4(31); mr 4,30; lha 3,0x2b8(9); lwz 0,0x2bc(9); add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 3f; lfs f0,0x1c(3); fadds f31,f31,f0; 3:; mr 30,31; lwz 9,0x4(30); lwz 0,0x2d4(9); lha 3,0x2d0(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x4(30); mr 31,3; lha 3,0x2e8(9); lwz 0,0x2ec(9); add 3,30,3; mtspr 8,0; blrl; mr 30,3; cmpwi 31,0; bne 2b; 4:; fmr f1,f31; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x8(1); lfd f31,0x10(1); addi 1,1,24"

struct cXObjectImpl {
    void GetSlotHeight();
};

void cXObjectImpl::GetSlotHeight() {
}
