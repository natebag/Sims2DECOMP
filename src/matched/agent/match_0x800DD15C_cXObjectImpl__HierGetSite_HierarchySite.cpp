// 0x800DD15C cXObjectImpl::HierGetSite(HierarchySite (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,3; mr 28,4; lwz 29,0x4(31); li 4,26; addi 3,31,40; lwz 30,0x4(29); lha 0,0x488(30); addi 30,30,1160; add 29,29,0; bl _s800DD15C_0; lwz 0,0x4(30); lha 4,0x0(3); mr 3,29; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; stw 3,0xc(28); addi 3,1,8; lwz 11,0x4(31); lwz 9,0x4(11); lwz 0,0x35c(9); lha 4,0x358(9); mtspr 8,0; add 4,11,4; blrl; lwz 11,-21488(13); addi 4,1,8; lwz 9,0x0(11); lwz 0,0x5c(9); lha 3,0x58(9); mtspr 8,0; add 3,11,3; blrl; xori 3,3,1; li 4,14; stw 3,0x0(28); addi 3,31,40; bl _s800DD15C_1; lha 0,0x0(3); li 4,2; addi 3,1,8; stw 0,0x10(28); lwz 9,0x68(31); lwz 10,0x6c(31); stw 9,0x4(28); stw 10,0x8(28); lwz 0,0x80(31); stw 0,0x14(28); bl _s800DD15C_2; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"
extern "C" void _s800DD15C_0();
extern "C" void _s800DD15C_1();
extern "C" void _s800DD15C_2();
extern "C" void f_800DD15C() {}
