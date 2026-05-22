// 0x8023FE64 PCrwAsyncFSACK (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32694; addi 31,9,-26464; 0:; bl _s8023FE64_0; mr. 3,3; beq 0b; mr 4,3; li 30,0; mr 3,31; bl _s8023FE64_1; lwz 11,0x8(31); li 0,0; lis 9,-32694; sth 0,0x2(31); stw 11,-26472(9); mr 3,31; li 4,8; bl _s8023FE64_2; lis 9,-32700; lis 11,-32700; lwz 0,-23468(9); stw 30,-23472(11); cmpwi 0,0; beq 1f; lis 9,-32694; mtspr 8,0; lwz 3,-26472(9); blrl; lis 9,-32700; stw 30,-23468(9); 1:; lis 9,-13312; li 0,4096; ori 9,9,12288; stw 0,0x0(9); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8023FE64_0();
extern "C" void _s8023FE64_1();
extern "C" void _s8023FE64_2();
extern "C" void f_8023FE64() {}
