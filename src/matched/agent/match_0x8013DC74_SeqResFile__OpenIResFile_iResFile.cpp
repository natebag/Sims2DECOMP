// 0x8013DC74 SeqResFile::OpenIResFile(iResFile (308 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 24,0x118(1); stw 0,0x13c(1); mr 26,3; mr 29,5; mr 28,6; mr 25,7; li 24,-250; mr. 30,4; beq 5f; addi 31,1,8; li 5,260; addi 4,31,8; mr 3,31; bl _s8013DC74_0; li 27,-250; mr 4,29; mr 3,31; bl _s8013DC74_1; mulli 4,28,20; mr 3,31; addi 4,4,208; add 4,26,4; bl _s8013DC74_2; cmpwi 3,0; beq 0f; lwz 9,0xc(30); mr 4,31; lha 3,0x28(9); lwz 0,0x2c(9); add 3,30,3; mtspr 8,0; blrl; mr 27,3; 0:; cmpwi 27,0; mfcr 31; beq 1f; lwz 9,0xc(30); lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; b 3f; 1:; lwz 9,0xc(30); lha 3,0x60(9); lwz 0,0x64(9); add 3,30,3; mtspr 8,0; blrl; 2:; mtcrf 128,31; beq 4f; 3:; mr 24,27; cmpwi 30,0; beq 5f; lwz 9,0xc(30); li 4,3; lha 3,0x8(9); lwz 0,0xc(9); add 3,30,3; mtspr 8,0; blrl; b 5f; 4:; mr 3,26; mr 4,30; bl _s8013DC74_3; li 0,1; stw 0,0x0(25); 5:; mr 3,24; lwz 0,0x13c(1); mtspr 8,0; lmw 24,0x118(1); addi 1,1,312"
extern "C" void _s8013DC74_0();
extern "C" void _s8013DC74_1();
extern "C" void _s8013DC74_2();
extern "C" void _s8013DC74_3();
extern "C" void f_8013DC74() {}
