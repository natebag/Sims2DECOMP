// 0x8026507C PADDisable (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); stw 30,0x18(1); stw 29,0x14(1); mr 29,3; bl _s8026507C_0; lis 0,-32768; srw 30,0,29; addi 31,3,0; addi 3,30,0; bl _s8026507C_1; lwz 0,-23180(13); not 9,30; lwz 6,-23168(13); mr 3,29; lwz 5,-23164(13); lwz 4,-23160(13); and 8,0,9; lwz 0,-23156(13); and 7,6,9; and 6,5,9; and 5,4,9; stw 8,-23180(13); and 0,0,9; stw 7,-23168(13); li 4,0; stw 6,-23164(13); stw 5,-23160(13); stw 0,-23156(13); bl _s8026507C_2; mr 3,31; bl _s8026507C_3; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); lwz 29,0x14(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s8026507C_0();
extern "C" void _s8026507C_1();
extern "C" void _s8026507C_2();
extern "C" void _s8026507C_3();
extern "C" void f_8026507C() {}
