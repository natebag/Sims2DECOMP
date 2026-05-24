// 0x80034C38 ESim::UpdateGhostParticleEffect(void) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 27,3; lwz 3,0x3d0(27); lwz 9,0x4(3); lha 0,0x218(9); lwz 9,0x21c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; lwz 0,0x404(27); cmpwi 0,0; bne 4f; lis 3,-32692; lis 4,20543; addi 3,3,-4004; ori 4,4,57884; li 5,0; li 6,0; bl _s80034C38_0; stw 3,0x404(27); cmpwi 3,0; beq 4f; lwz 9,0x14(3); lwz 0,0x18(3); subf 0,9,0; srawi. 9,0,3; mtspr 9,9; ble 4f; mfspr 28,9; li 31,0; 0:; lwz 10,0x3d0(27); lwz 9,0x404(27); lwz 11,0x4(10); lwz 30,0x14(9); lwz 0,0x18c(11); lha 3,0x188(11); add 29,30,31; mtspr 8,0; add 3,10,3; blrl; lwz 9,0x0(3); lbzx 6,30,31; lha 0,0xf8(9); addi 31,31,8; lbz 4,0x1(29); extsb 6,6; lwz 9,0xfc(9); add 3,3,0; extsb 4,4; lwz 5,0x4(29); mtspr 8,9; blrl; addic. 28,28,-1; bne 0b; b 4f; 1:; lwz 11,0x404(27); cmpwi 11,0; beq 4f; lwz 9,0x14(11); lwz 0,0x18(11); subf 0,9,0; srawi. 9,0,3; mtspr 9,9; ble 3f; mfspr 28,9; li 31,0; 2:; lwz 10,0x3d0(27); lwz 9,0x404(27); lwz 11,0x4(10); lwz 30,0x14(9); lwz 0,0x18c(11); lha 3,0x188(11); add 29,30,31; mtspr 8,0; add 3,10,3; blrl; lwz 9,0x0(3); lbzx 6,30,31; lha 0,0x100(9); addi 31,31,8; lbz 4,0x1(29); extsb 6,6; lwz 9,0x104(9); add 3,3,0; extsb 4,4; lwz 5,0x4(29); mtspr 8,9; blrl; addic. 28,28,-1; bne 2b; 3:; lis 3,-32692; lwz 4,0x404(27); addi 3,3,-4004; li 5,1; bl _s80034C38_1; li 0,0; stw 0,0x404(27); 4:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s80034C38_0();
extern "C" void _s80034C38_1();

struct ESim {
    void UpdateGhostParticleEffect();
};

void ESim::UpdateGhostParticleEffect() {
}
