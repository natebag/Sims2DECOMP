// 0x800BA824 cGZSnd::SetPan(int) (184 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 31,3; lwz 0,0x24(31); cmpw 4,0; beq 0f; lwz 0,0x1c(31); stw 4,0x24(31); cmpwi 0,0; beq 0f; lwz 0,0x34(31); cmpwi 0,0; bne 0f; lwz 4,0x20(31); addi 30,1,8; stw 0,0x8(1); addi 5,1,32; addi 6,1,36; bl _s800BA824_0; lfs f0,0x20(1); mr 5,30; lwz 11,-26564(13); stfs f0,0x4(30); lwz 0,0x8(1); lwz 4,0x1c(31); ori 0,0,1; lfs f0,0x24(1); stw 0,0x8(1); stfs f0,0x8(30); lwz 0,0x8(1); ori 0,0,2; stw 0,0x8(1); lwz 9,0x0(11); lha 3,0xb0(9); lwz 0,0xb4(9); add 3,11,3; mtspr 8,0; blrl; 0:; li 3,1; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"

extern "C" void _s800BA824_0();

struct cGZSnd {
    void SetPan();
};

void cGZSnd::SetPan() {
}
