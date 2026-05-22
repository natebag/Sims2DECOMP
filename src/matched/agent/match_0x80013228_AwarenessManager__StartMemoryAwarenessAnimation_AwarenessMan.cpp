// 0x80013228 AwarenessManager::StartMemoryAwarenessAnimation(AwarenessManager::eAwarenessAction, (400 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; mr 29,4; addi 6,1,8; bl _s80013228_0; lwz 4,0x8(1); cmpwi 4,0; beq 3f; lwz 4,0x0(4); lis 30,-32693; addi 3,30,11064; bl _s80013228_1; cmpwi 3,0; beq 2f; lwz 0,0x0(31); andi. 9,0,16; beq 0f; lwz 9,0x8(1); addi 3,30,11064; li 5,1; lwz 4,0x0(9); bl _s80013228_2; 0:; mr 3,31; bl _s80013228_3; lwz 0,0x0(31); cmpwi 29,3; rlwinm 0,0,0,28,26; stw 0,0x0(31); bne 1f; lwz 9,0x8(1); li 4,128; lfs f1,-32300(13); li 6,2; lwz 5,0x0(9); li 7,0; lwz 3,0x8(31); bl _s80013228_4; mr 30,3; lfs f1,0x2c(31); lwz 3,0x8(31); mr 4,30; bl _s80013228_5; li 0,1; stb 0,0xd(30); b 3f; 1:; cmpwi 29,2; lwz 11,0x8(1); lis 9,-32707; lfs f1,-8984(9); li 6,-1; lwz 5,0x0(11); li 7,0; lwz 3,0x8(31); li 4,1024; bl _s80013228_6; mr 30,3; lfs f1,0x2c(31); lwz 3,0x8(31); mr 4,30; bl _s80013228_7; li 0,1; lis 9,-32707; stb 0,0xd(30); li 5,1; lfs f1,-8980(9); mr 4,30; lwz 3,0x8(31); bl _s80013228_8; lis 9,-32707; lis 11,-32707; lwz 3,0x8(31); mr 4,30; lfs f1,-8976(9); lfs f3,-8972(11); lfs f2,-32300(13); bl _s80013228_9; lis 5,-32688; lwz 3,0x8(31); mr 4,30; addi 5,5,-20000; bl _s80013228_10; b 3f; 2:; lwz 0,0x0(31); andi. 9,0,16; bne 3f; lwz 9,0x8(1); addi 3,30,11064; lwz 4,0x0(9); bl _s80013228_11; lwz 0,0x0(31); ori 0,0,16; stw 0,0x0(31); 3:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80013228_0();
extern "C" void _s80013228_1();
extern "C" void _s80013228_2();
extern "C" void _s80013228_3();
extern "C" void _s80013228_4();
extern "C" void _s80013228_5();
extern "C" void _s80013228_6();
extern "C" void _s80013228_7();
extern "C" void _s80013228_8();
extern "C" void _s80013228_9();
extern "C" void _s80013228_10();
extern "C" void _s80013228_11();
extern "C" void f_80013228() {}
