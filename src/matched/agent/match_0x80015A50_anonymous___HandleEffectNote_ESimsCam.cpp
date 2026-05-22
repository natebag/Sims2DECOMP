// 0x80015A50 {anonymous}::HandleEffectNote(ESimsCam (408 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 26,4; mr 28,5; mr. 3,3; beq 5f; lwz 30,0x4(3); cmpwi 30,0; blt 5f; lis 9,-32697; rlwinm 11,30,2,0,29; addi 10,9,24012; mr 31,11; addi 9,10,188; lwzx 0,9,11; cmpwi 0,0; beq 2f; cmpwi 28,13; bne 0f; addi 9,10,280; lwzx 3,9,31; bl _s80015A50_0; mr 4,3; mr 3,26; bl _s80015A50_1; b 2f; 0:; cmpwi 28,14; bne 1f; addi 9,10,280; lwzx 3,9,31; bl _s80015A50_2; mr 4,3; mr 3,26; bl _s80015A50_3; b 2f; 1:; cmpwi 28,15; bne 2f; addi 9,10,280; lwzx 3,9,31; bl _s80015A50_4; mr 4,3; mr 3,26; bl _s80015A50_5; 2:; lis 9,-32697; lwz 0,0x5c70(9); cmpwi 0,0; beq 5f; lis 9,-32697; addi 30,30,1; addi 27,9,24012; rlwinm 0,30,1,31,31; addi 29,27,188; add 0,30,0; lwzx 11,29,31; rlwinm 0,0,0,0,30; subf 30,0,30; lwz 9,0x4(11); lwz 0,0x36c(9); lha 3,0x368(9); mtspr 8,0; add 3,11,3; blrl; mr 9,3; rlwinm 3,30,2,0,29; lwzx 0,29,3; cmpw 9,0; bne 5f; cmpwi 9,0; beq 5f; cmpwi 28,13; bne 3f; addi 9,27,280; lwzx 3,9,3; bl _s80015A50_6; mr 4,3; mr 3,26; bl _s80015A50_7; b 5f; 3:; cmpwi 28,14; bne 4f; addi 9,27,280; lwzx 3,9,3; bl _s80015A50_8; mr 4,3; mr 3,26; bl _s80015A50_9; b 5f; 4:; cmpwi 28,15; bne 5f; addi 9,27,280; lwzx 3,9,3; bl _s80015A50_10; mr 4,3; mr 3,26; bl _s80015A50_11; 5:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"
extern "C" void _s80015A50_0();
extern "C" void _s80015A50_1();
extern "C" void _s80015A50_2();
extern "C" void _s80015A50_3();
extern "C" void _s80015A50_4();
extern "C" void _s80015A50_5();
extern "C" void _s80015A50_6();
extern "C" void _s80015A50_7();
extern "C" void _s80015A50_8();
extern "C" void _s80015A50_9();
extern "C" void _s80015A50_10();
extern "C" void _s80015A50_11();
extern "C" void f_80015A50() {}
