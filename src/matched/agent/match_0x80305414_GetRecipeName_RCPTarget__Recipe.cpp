// 0x80305414 GetRecipeName(RCPTarget::Recipe (280 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplw 9,0; blt 1f; add 6,10,8; 0:; mulli 9,3,12; mr 3,11; add 9,9,31; lwz 7,0x18(9); addi 11,9,24; lwz 0,0x8(11); addi 10,9,12; lwz 8,0x4(11); stw 7,0xc(9); stw 0,0x8(10); stw 8,0x4(10); lwz 0,0x8(31); cmpw 3,0; bge 1f; lwz 9,0xc(1); addi 11,3,1; lwzu 0,0xc(6); cmplw 9,0; bge 0b; 1:; mulli 9,3,12; lwz 0,0x8(1); lwz 11,0x8(5); lwz 10,0x4(5); add 9,9,31; stw 0,0xc(9); addi 9,9,12; stw 11,0x8(9); stw 10,0x4(9); lwz 0,0x24(1); mtspr 8,0; lwz 31,0x1c(1); addi 1,1,32; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,5; bl _s80305414_0; mr. 3,3; blt 2f; mulli 0,3,12; addi 9,31,20; stwx 30,9,0; 2:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 4,5; bl _s80305414_1; mr 5,3; mr 4,29; mr 3,30; bl _s80305414_2; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80305414_0();
extern "C" void _s80305414_1();
extern "C" void _s80305414_2();
extern "C" void f_80305414() {}
