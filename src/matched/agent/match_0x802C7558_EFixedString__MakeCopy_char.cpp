// 0x802C7558 EFixedString::MakeCopy(char (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr. 31,4; bne 0f; lwz 31,-26884(13); 0:; mr 3,31; bl _s802C7558_0; lwz 5,0x4(30); addi 0,3,1; cmpw 0,5; bgt 1f; lwz 3,0x0(30); mr 4,31; mr 5,0; crxor 6,6,6; bl _s802C7558_1; b 2f; 1:; lwz 3,0x0(30); mr 4,31; addi 5,5,-1; crxor 6,6,6; bl _s802C7558_2; lwz 9,0x4(30); li 11,0; lwz 0,0x0(30); add 9,9,0; stb 11,-1(9); 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C7558_0();
extern "C" void _s802C7558_1();
extern "C" void _s802C7558_2();
extern "C" void f_802C7558() {}
