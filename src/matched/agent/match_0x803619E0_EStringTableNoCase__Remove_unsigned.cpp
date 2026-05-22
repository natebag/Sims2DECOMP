// 0x803619E0 EStringTableNoCase::Remove(unsigned (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lwz 0,0x8(30); mr 29,5; cmpwi 0,0; bne 0f; lwz 4,0xc(30); bl _s803619E0_0; 0:; lwz 11,0x8(30); rlwinm 9,31,2,0,29; lwzx 31,11,9; add 4,11,9; b 2f; 1:; addi 4,31,8; lwz 31,0x8(31); 2:; cmpwi 31,0; beq 3f; cmpw 31,29; bne 1b; 3:; lwz 0,0x8(31); stw 0,0x0(4); lwz 9,0x0(30); cmpw 9,31; bne 4f; lwz 0,0x4(31); stw 0,0x0(30); b 5f; 4:; lwz 9,0x0(31); lwz 0,0x4(31); stw 0,0x4(9); 5:; lwz 0,0x4(30); cmpw 0,31; bne 6f; lwz 0,0x0(31); stw 0,0x4(30); b 7f; 6:; lwz 9,0x4(31); lwz 0,0x0(31); stw 0,0x0(9); 7:; cmpwi 31,0; beq 8f; lwz 4,0xc(31); addi 3,31,12; bl _s803619E0_1; mr 3,31; bl _s803619E0_2; 8:; lwz 9,0x14(30); addi 9,9,-1; stw 9,0x14(30); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803619E0_0();
extern "C" void _s803619E0_1();
extern "C" void _s803619E0_2();
extern "C" void f_803619E0() {}
