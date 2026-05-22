// 0x80197E60 CASGeneticsTarget::ShowGrandparentTexture(unsigned (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; cmplwi 31,3; ble 0f; li 31,3; 0:; cmpwi 5,-1; bne 1f; rlwinm 0,31,2,0,29; addi 9,30,156; lwzx 5,9,0; 1:; lwz 4,0x300(30); lwz 3,0x94(30); srw 4,4,31; rlwinm 4,4,0,31,31; bl _s80197E60_0; mr. 3,3; bne 3f; 2:; li 3,0; b 4f; 3:; lwz 4,0x4(3); cmpwi 4,0; beq 2b; rlwinm 0,31,2,0,29; addi 9,30,772; lwzx 3,9,0; cmpwi 3,0; beq 2b; li 5,0; bl _s80197E60_1; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80197E60_0();
extern "C" void _s80197E60_1();
extern "C" void f_80197E60() {}
