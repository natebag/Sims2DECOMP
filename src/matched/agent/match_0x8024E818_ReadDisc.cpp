// 0x8024E818 ReadDisc (108 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-72(1); mr 0,4; mr 6,5; mr 4,3; mr 5,0; addi 3,1,20; li 7,0; li 8,0; bl _s8024E818_0; b 0f; 0:; b 1f; 1:; b 3f; 2:; bl _s8024E818_1; cmpwi 3,0; bne 3f; li 3,0; bl _s8024E818_2; 3:; addi 3,1,20; bl _s8024E818_3; cmpwi 3,0; bne 2b; lwz 0,0x4c(1); addi 1,1,72; mtspr 8,0"
extern "C" void _s8024E818_0();
extern "C" void _s8024E818_1();
extern "C" void _s8024E818_2();
extern "C" void _s8024E818_3();
extern "C" void f_8024E818() {}
