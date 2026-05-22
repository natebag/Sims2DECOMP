// 0x800714CC SimModel::WeldAllSharedVertices(void) (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 26,0x28(1); stw 0,0x44(1); mr 28,3; li 30,0; addi 26,1,8; addi 27,1,32; 0:; lwz 3,0x138(28); mr 4,30; addi 5,1,8; li 6,7; bl _s800714CC_0; addi 29,30,1; mr 31,26; 1:; lwz 5,0x0(31); addi 31,31,4; cmpwi 5,26; beq 2f; cmpw 5,30; ble 2f; mr 3,28; mr 4,30; li 6,0; bl _s800714CC_1; 2:; cmplw 31,27; ble 1b; mr 30,29; cmplwi 30,25; ble 0b; lwz 0,0x44(1); mtspr 8,0; lmw 26,0x28(1); addi 1,1,64"
extern "C" void _s800714CC_0();
extern "C" void _s800714CC_1();
extern "C" void f_800714CC() {}
