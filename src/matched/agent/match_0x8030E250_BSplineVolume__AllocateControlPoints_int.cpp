// 0x8030E250 BSplineVolume::AllocateControlPoints(int, (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 20,0x8(1); stw 0,0x3c(1); mr 23,4; mr 24,5; rlwinm 30,23,2,0,29; lis 3,-32692; mr 20,6; mr 21,7; mr 4,30; li 5,16; addi 3,3,-27556; li 29,0; bl _s8030E250_0; lis 22,-32692; mr 27,3; mr 5,30; li 4,0; bl _s8030E250_1; cmpw 29,23; bge 3f; rlwinm 25,24,2,0,29; 0:; mr 4,25; li 5,16; addi 3,22,-27556; rlwinm 31,29,2,0,29; bl _s8030E250_2; addi 26,29,1; mr 0,3; li 4,0; stwx 0,31,27; mr 5,25; bl _s8030E250_3; cmpwi 24,0; ble 2f; mullw 29,20,21; li 28,0; mr 30,24; 1:; mr 4,29; li 5,16; addi 3,22,-27556; bl _s8030E250_4; lwzx 11,31,27; li 4,0; mr 5,29; stwx 3,28,11; lwzx 9,31,27; lwzx 3,28,9; addi 28,28,4; bl _s8030E250_5; addic. 30,30,-1; bne 1b; 2:; mr 29,26; cmpw 29,23; blt 0b; 3:; mr 3,27; lwz 0,0x3c(1); mtspr 8,0; lmw 20,0x8(1); addi 1,1,56"
extern "C" void _s8030E250_0();
extern "C" void _s8030E250_1();
extern "C" void _s8030E250_2();
extern "C" void _s8030E250_3();
extern "C" void _s8030E250_4();
extern "C" void _s8030E250_5();
extern "C" void f_8030E250() {}
