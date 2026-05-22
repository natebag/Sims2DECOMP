// 0x80013960 AwarenessManager::MemoryAwarenessCheck(unsigned (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; bl _s80013960_0; cmpwi 3,0; beq 5f; mr 3,31; bl _s80013960_1; mr 30,3; cmpwi 30,-1; beq 5f; mr 4,30; mr 3,31; bl _s80013960_2; lwz 0,0x0(31); mr 4,3; stw 3,0x1c(31); rlwinm 0,0,0,21,19; mr 3,31; stw 0,0x0(31); bl _s80013960_3; lwz 0,0x18(31); cmpwi 0,0; beq 2f; lwz 4,0x1c(31); mr 3,31; bl _s80013960_4; cmpwi 3,0; beq 4f; lis 9,-32697; rlwinm 0,30,2,0,29; addi 9,9,24012; lwz 8,0x34(31); addi 9,9,188; li 4,0; lwzx 11,9,0; cmpwi 8,0; lwz 9,0x4(11); lha 0,0x2f0(9); addi 10,9,752; add 3,11,0; beq 0f; lwz 4,0x0(8); 0:; lwz 9,0x4(10); mtspr 8,9; blrl; lwz 0,0x18(31); cmpwi 0,2; bne 1f; mr 3,31; li 4,2; lwz 5,0x14(3); bl _s80013960_5; b 5f; 1:; cmpwi 0,3; bne 3f; lwz 5,0x14(31); mr 3,31; li 4,3; bl _s80013960_6; cmpwi 3,0; beq 2f; lfs f1,0x20(31); lwz 3,0x4(31); bl _s80013960_7; b 5f; 2:; mr 3,31; bl _s80013960_8; b 5f; 3:; cmpwi 0,1; bne 5f; mr 3,31; bl _s80013960_9; b 5f; 4:; mr 3,31; bl _s80013960_10; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80013960_0();
extern "C" void _s80013960_1();
extern "C" void _s80013960_2();
extern "C" void _s80013960_3();
extern "C" void _s80013960_4();
extern "C" void _s80013960_5();
extern "C" void _s80013960_6();
extern "C" void _s80013960_7();
extern "C" void _s80013960_8();
extern "C" void _s80013960_9();
extern "C" void _s80013960_10();
extern "C" void f_80013960() {}
