// 0x8031BE28 ERQuickdata::FindTableName(void (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,5; lwz 9,0x14(31); mr 6,4; li 4,0; lwz 5,0x8(9); addi 5,5,-1; bl _s8031BE28_0; mr. 3,3; bge 0f; li 0,0; li 3,0; stw 0,0x0(30); b 1f; 0:; mulli 0,3,20; lwz 9,0x14(31); li 3,1; addi 9,9,24; lwzx 11,9,0; stw 11,0x0(30); 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8031BE28_0();
extern "C" void f_8031BE28() {}
