// 0x802A98CC AptNativeHash::~AptNativeHash(void) (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,3; mr 26,4; lwz 0,0x4(30); cmpwi 0,0; beq 6f; lwz 0,0x0(30); li 28,0; mr 5,0; cmpw 28,0; bge 5f; li 27,0; li 29,0; 0:; lwz 9,0x4(30); li 10,1; lwzx 0,29,9; add 11,29,9; cmpwi 0,0; bne 1f; li 10,0; 1:; cmpwi 10,0; beq 4f; lwz 0,0x4(11); cmpwi 0,0; beq 2f; stw 27,0x4(11); 2:; lwz 31,0x4(30); lwzx 4,29,31; lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 3f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s802A98CC_0; 3:; stwx 27,29,31; 4:; lwz 0,0x0(30); addi 28,28,1; addi 29,29,8; mr 5,0; cmpw 28,0; blt 0b; 5:; lwz 3,-23020(13); rlwinm 5,5,3,0,28; lwz 4,0x4(30); bl _s802A98CC_1; li 0,0; stw 0,0x4(30); 6:; andi. 0,26,1; beq 7f; lwz 3,-23020(13); mr 4,30; li 5,20; bl _s802A98CC_2; 7:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s802A98CC_0();
extern "C" void _s802A98CC_1();
extern "C" void _s802A98CC_2();
extern "C" void f_802A98CC() {}
