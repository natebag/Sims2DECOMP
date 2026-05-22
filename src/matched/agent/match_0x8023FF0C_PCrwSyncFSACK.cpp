// 0x8023FF0C PCrwSyncFSACK (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32694; lis 11,-32694; lwz 0,-26476(9); addi 31,11,-26464; cmpwi 0,0; beq 1f; 0:; bl _s8023FF0C_0; mr. 3,3; beq 0b; mr 4,3; lis 30,-32694; mr 3,31; bl _s8023FF0C_1; lwz 9,0x8(31); li 0,0; sth 0,0x2(31); mr 3,31; stw 9,-26472(30); li 4,8; bl _s8023FF0C_2; li 31,0; lis 9,-32700; lis 11,-32700; lwz 0,-23468(9); stw 31,-23472(11); cmpwi 0,0; beq 1f; lwz 3,-26472(30); mtspr 8,0; blrl; lis 9,-32700; stw 31,-23468(9); 1:; li 10,0; lis 9,-32700; lis 11,-13312; stw 10,-23468(9); ori 11,11,26664; li 0,8; stw 0,0x0(11); lis 9,-13312; ori 9,9,12288; li 0,4096; stw 0,0x0(9); lis 11,-32700; stw 10,-23472(11); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023FF0C_0();
extern "C" void _s8023FF0C_1();
extern "C" void _s8023FF0C_2();
extern "C" void f_8023FF0C() {}
