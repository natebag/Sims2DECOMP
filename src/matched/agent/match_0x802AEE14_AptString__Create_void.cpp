// 0x802AEE14 AptString::Create(void) (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 31,-26892(13); cmpwi 31,0; beq 3f; lwz 0,0x0(31); lwz 9,0x10(31); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(31); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 0f; rlwinm 0,11,0,3,1; stw 0,0x0(31); b 1f; 0:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 31,11,9; stw 0,0x4(8); 1:; addi 30,31,12; mr 3,30; bl _s802AEE14_0; cmpwi 3,0; bne 2f; mr 3,30; li 4,0; bl _s802AEE14_1; 2:; mr 3,31; b 4f; 3:; lwz 3,-23020(13); li 4,20; bl _s802AEE14_2; bl _s802AEE14_3; 4:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802AEE14_0();
extern "C" void _s802AEE14_1();
extern "C" void _s802AEE14_2();
extern "C" void _s802AEE14_3();
extern "C" void f_802AEE14() {}
