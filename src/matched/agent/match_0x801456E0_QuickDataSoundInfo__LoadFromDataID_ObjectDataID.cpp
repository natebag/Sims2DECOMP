// 0x801456E0 QuickDataSoundInfo::LoadFromDataID(ObjectDataID (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,4; addi 3,30,80; bl _s801456E0_0; addi 3,30,4; bl _s801456E0_1; lwz 3,-21508(13); lwz 4,0x0(31); lwz 9,0x0(3); lha 0,0x38(9); lwz 9,0x3c(9); add 3,3,0; mtspr 8,9; blrl; lwz 3,0x8(3); cmpwi 3,0; bne 0f; li 3,0; b 3f; 0:; lwz 3,0x18(3); li 4,0; cmpwi 3,0; beq 1f; lwz 4,-4(3); 1:; rlwinm 4,4,3,0,28; lhz 5,0x4(31); add 4,3,4; bl _s801456E0_2; mr. 3,3; bne 2f; stw 3,0x4c(30); li 3,0; b 3f; 2:; lwz 0,0x4(3); li 3,1; stw 0,0x4c(30); 3:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801456E0_0();
extern "C" void _s801456E0_1();
extern "C" void _s801456E0_2();
extern "C" void f_801456E0() {}
