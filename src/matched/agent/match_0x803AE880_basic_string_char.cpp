// 0x803AE880 basic_string<char, (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; li 29,0; addi 9,30,8; stw 29,0x0(30); stw 29,0x4(30); li 3,8; stw 29,0x4(9); bl _s803AE880_0; mr 9,3; addi 0,9,8; stw 9,0x0(30); stw 0,0xc(30); mr 3,30; stw 9,0x4(30); stb 29,0x0(9); lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s803AE880_0();
extern "C" void f_803AE880() {}
