// 0x800BCB70 IconGroupImpl::GetIconLabel(int, (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; mr 29,4; mr 31,5; bl _s800BCB70_0; lwz 11,0x8(30); cmpwi 11,0; beq 0f; lwz 9,0x0(11); addi 4,29,1; li 5,-1; lha 3,0x80(9); lwz 0,0x84(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,31; bl _s800BCB70_1; 0:; mr 3,31; bl _s800BCB70_2; cmpwi 3,0; bne 1f; lis 4,-32706; mr 3,31; addi 4,4,-25032; li 5,-1; bl _s800BCB70_3; mr 3,31; mr 4,29; bl _s800BCB70_4; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800BCB70_0();
extern "C" void _s800BCB70_1();
extern "C" void _s800BCB70_2();
extern "C" void _s800BCB70_3();
extern "C" void _s800BCB70_4();
extern "C" void f_800BCB70() {}
