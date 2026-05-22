// 0x8023FB9C PCreadAsyncInit (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 30,4; mr 26,3; mr 31,5; mr 27,6; mr 28,7; mr 29,8; andi. 0,30,31; bne 0f; andi. 0,31,31; bne 0f; bl _s8023FB9C_0; lis 9,-32694; lis 11,-32700; stw 29,-26476(9); mr 3,26; stw 27,-23468(11); mr 6,28; mr 4,30; mr 5,31; bl _s8023FB9C_1; lis 9,-32694; lis 11,-32694; stw 31,-26480(9); lis 10,-32694; lis 9,-32700; li 0,1; stw 26,-26496(11); li 3,0; stw 30,-26492(10); stw 0,-23472(9); b 1f; 0:; li 3,-1; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s8023FB9C_0();
extern "C" void _s8023FB9C_1();
extern "C" void f_8023FB9C() {}
