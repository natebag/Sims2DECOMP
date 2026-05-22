// 0x80193174 CASTarget::SetVariable(char (448 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 31,4; lis 3,-32705; mr 28,5; addi 3,3,-16432; bl _s80193174_0; cmpwi 3,0; bne 0f; mr 3,30; mr 4,28; bl _s80193174_1; b 8f; 0:; lis 3,-32705; mr 4,31; addi 3,3,-16424; bl _s80193174_2; cmpwi 3,0; bne 1f; mr 3,30; mr 4,28; bl _s80193174_3; b 8f; 1:; lis 9,-32705; mr 4,31; addi 29,9,-16412; mr 3,29; bl _s80193174_4; cmpwi 3,0; bne 5f; mr 3,29; li 31,1; bl _s80193174_5; cmpwi 3,1; bne 2f; li 31,0; 2:; cmpwi 31,0; beq 3f; lwz 0,0x1348(30); ori 0,0,128; b 4f; 3:; lwz 0,0x1348(30); rlwinm 0,0,0,25,23; 4:; stw 0,0x1348(30); lwz 9,0x1348(30); li 0,2; lwz 11,-26532(13); lis 4,-32693; ori 9,9,256; stw 0,0x1364(30); stw 9,0x1348(30); addi 4,4,-11760; addi 30,30,4968; lwz 9,0x0(11); lha 3,0x28(9); lwz 0,0x2c(9); add 3,11,3; mtspr 8,0; blrl; lis 3,-32705; stfs f1,0x4(30); addi 3,3,-16412; mr 4,31; bl _s80193174_6; b 8f; 5:; lis 3,-32705; mr 4,31; addi 3,3,-16380; bl _s80193174_7; cmpwi 3,0; beq 8f; lis 3,-32705; mr 4,31; addi 3,3,-16364; bl _s80193174_8; cmpwi 3,0; bne 8f; mr 3,28; bl _s80193174_9; lwz 30,0x84(30); mr 11,3; lwz 0,0x2c(30); cmpwi 0,0; bne 6f; lwz 0,0x28(30); cmpwi 0,0; bne 6f; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; bne 8f; 6:; cmpwi 11,0; bne 7f; lis 9,-32697; li 0,-1; stw 0,0x6230(9); li 3,4; stw 11,-28408(13); bl _s80193174_10; b 8f; 7:; li 0,0; li 3,4; stw 0,-28408(13); bl _s80193174_11; 8:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80193174_0();
extern "C" void _s80193174_1();
extern "C" void _s80193174_2();
extern "C" void _s80193174_3();
extern "C" void _s80193174_4();
extern "C" void _s80193174_5();
extern "C" void _s80193174_6();
extern "C" void _s80193174_7();
extern "C" void _s80193174_8();
extern "C" void _s80193174_9();
extern "C" void _s80193174_10();
extern "C" void _s80193174_11();
extern "C" void f_80193174() {}
