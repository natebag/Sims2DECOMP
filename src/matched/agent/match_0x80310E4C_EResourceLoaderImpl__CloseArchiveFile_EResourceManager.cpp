// 0x80310E4C EResourceLoaderImpl::CloseArchiveFile(EResourceManager (232 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,4; mr 31,3; lwz 0,0x54(30); cmpwi 0,0; bne 1f; lwz 9,0x0(31); lha 3,0x28(9); lwz 0,0x2c(9); add 3,31,3; mtspr 8,0; blrl; mr. 29,3; beq 0f; addi 0,31,860; lwz 9,0x35c(31); stw 0,0x8(1); li 4,-1; lha 3,0x10(9); lwz 9,0x14(9); add 3,0,3; mtspr 8,9; blrl; mr 3,30; bl _s80310E4C_0; lwz 11,0x8(1); lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; li 3,40; bl _s80310E4C_1; bl _s80310E4C_2; mr 9,3; li 0,7; stw 0,0x0(9); mr 3,31; mr 4,9; stw 30,0x4(9); stw 29,0x20(9); bl _s80310E4C_3; lwz 9,0x0(31); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s80310E4C_0();
extern "C" void _s80310E4C_1();
extern "C" void _s80310E4C_2();
extern "C" void _s80310E4C_3();
extern "C" void f_80310E4C() {}
