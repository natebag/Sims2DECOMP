// 0x800E1594 cXObjectImpl::UpdateWallAdjacency(void) (496 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 26,0x48(1); stw 0,0x64(1); mr 26,3; lwz 11,0x4(26); lwz 9,0x4(11); lwz 0,0x1cc(9); lha 3,0x1c8(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); li 4,6; lha 0,0x70(9); lwz 9,0x74(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; li 0,1; bne 0f; li 0,0; 0:; cmpwi 0,0; beq 7f; addi 3,26,40; lwz 28,-21488(13); li 4,5; mr 27,3; bl _s800E1594_0; lwz 11,0x4(26); lha 29,0x0(3); lwz 9,0x4(11); addi 3,1,8; rlwinm 29,29,0,0,25; lwz 0,0x35c(9); lha 4,0x358(9); mtspr 8,0; add 4,11,4; blrl; lwz 9,0x0(28); addi 4,1,8; lha 3,0x58(9); lwz 0,0x5c(9); add 3,28,3; mtspr 8,0; blrl; cmpwi 3,0; bne 5f; li 4,1; mr 3,27; bl _s800E1594_1; lwz 9,0x0(28); addi 31,1,16; lha 30,0x0(3); addi 5,1,8; lha 4,0xa8(9); mr 3,31; lwz 9,0xac(9); neg 30,30; add 4,28,4; rlwinm 0,30,1,31,31; mtspr 8,9; add 30,30,0; rlwinm 30,30,31,30,31; blrl; mr 4,30; mr 3,31; bl _s800E1594_2; mr 3,31; li 4,1; bl _s800E1594_3; cmpwi 3,0; beq 1f; ori 29,29,1; 1:; mr 3,31; li 4,2; bl _s800E1594_4; cmpwi 3,0; beq 2f; ori 29,29,4; 2:; mr 3,31; li 4,4; bl _s800E1594_5; cmpwi 3,0; beq 3f; ori 29,29,2; 3:; mr 3,31; li 4,8; bl _s800E1594_6; cmpwi 3,0; beq 4f; ori 29,29,8; 4:; mr 3,31; li 4,2; bl _s800E1594_7; 5:; mr 3,27; li 4,5; bl _s800E1594_8; lha 0,0x0(3); cmpw 29,0; beq 6f; mr 5,29; li 4,5; mr 3,27; bl _s800E1594_9; lwz 3,0x4(26); li 4,6; li 5,0; li 6,0; lwz 9,0x4(3); lha 0,0x100(9); lwz 9,0x104(9); add 3,3,0; mtspr 8,9; blrl; 6:; addi 3,1,8; li 4,2; bl _s800E1594_10; 7:; lwz 0,0x64(1); mtspr 8,0; lmw 26,0x48(1); addi 1,1,96"

extern "C" void _s800E1594_0();
extern "C" void _s800E1594_1();
extern "C" void _s800E1594_2();
extern "C" void _s800E1594_3();
extern "C" void _s800E1594_4();
extern "C" void _s800E1594_5();
extern "C" void _s800E1594_6();
extern "C" void _s800E1594_7();
extern "C" void _s800E1594_8();
extern "C" void _s800E1594_9();
extern "C" void _s800E1594_10();

struct cXObjectImpl {
    void UpdateWallAdjacency();
};

void cXObjectImpl::UpdateWallAdjacency() {
}
