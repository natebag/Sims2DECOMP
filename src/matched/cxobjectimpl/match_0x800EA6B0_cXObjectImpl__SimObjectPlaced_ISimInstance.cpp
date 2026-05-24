// 0x800EA6B0 cXObjectImpl::SimObjectPlaced(ISimInstance (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr. 26,3; beq 2f; mr 3,26; bl _s800EA6B0_0; mr 28,3; mr 3,26; bl _s800EA6B0_1; cmpwi 3,0; bne 2f; lwz 9,0x320(26); addi 31,26,800; lwz 11,0x24(9); addi 29,9,24; lha 3,0x20(9); mtspr 8,11; lha 30,0x18(9); add 3,31,3; add 30,31,30; blrl; lwz 0,0x4(29); rlwinm 4,3,0,26,23; mr 3,30; mtspr 8,0; blrl; lwz 9,0x320(26); lwz 0,0x14(9); lha 3,0x10(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(28); li 4,0; lha 3,0x2c0(9); lwz 0,0x2c4(9); add 3,28,3; mtspr 8,0; blrl; mr. 27,3; beq 2f; mr 25,31; 0:; lwz 3,0x0(27); lwz 9,0x18(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 1f; lwz 9,0x320(26); addi 28,31,800; lwz 11,0x320(31); lwz 0,0x24(9); lha 3,0x20(9); addi 29,11,24; mtspr 8,0; lha 30,0x18(11); add 3,25,3; add 30,28,30; blrl; lwz 0,0x4(29); rlwinm 4,3,0,26,23; mr 3,30; mtspr 8,0; blrl; lwz 9,0x320(31); lha 3,0x10(9); lwz 0,0x14(9); add 3,28,3; mtspr 8,0; blrl; 1:; lwz 9,0x4(27); li 4,0; lha 3,0x2c0(9); lwz 0,0x2c4(9); add 3,27,3; mtspr 8,0; blrl; mr. 27,3; bne 0b; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s800EA6B0_0();
extern "C" void _s800EA6B0_1();

struct cXObjectImpl {
    void SimObjectPlaced_ISimInstance();
};

void cXObjectImpl::SimObjectPlaced_ISimInstance() {
}
