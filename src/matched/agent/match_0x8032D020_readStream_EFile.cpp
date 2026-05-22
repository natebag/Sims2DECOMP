// 0x8032D020 readStream(EFile (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 28,5; bl _s8032D020_0; li 6,0; li 7,0; mr 4,30; li 5,32; bl _s8032D020_1; lwz 9,0x28(29); mr 31,3; mr 5,30; mr 4,31; lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,29,3; blrl; mr 5,30; andi. 0,5,31; beq 0f; addi 5,5,32; rlwinm 5,5,0,0,26; 0:; mr 4,28; mr 3,31; bl _s8032D020_2; bl _s8032D020_3; mr 4,31; bl _s8032D020_4; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8032D020_0();
extern "C" void _s8032D020_1();
extern "C" void _s8032D020_2();
extern "C" void _s8032D020_3();
extern "C" void _s8032D020_4();
extern "C" void f_8032D020() {}
