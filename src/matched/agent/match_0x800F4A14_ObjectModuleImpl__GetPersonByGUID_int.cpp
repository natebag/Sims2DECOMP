// 0x800F4A14 ObjectModuleImpl::GetPersonByGUID(int) (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); addi 9,3,8280; lwz 31,0x2058(3); lwz 0,0x4(9); mr 29,4; cmpw 31,0; beq 2f; mr 30,9; 0:; lwz 9,0x0(31); lwz 11,0x0(9); lwz 10,0x4(11); lwz 9,0x4(10); lha 3,0x368(9); lwz 0,0x36c(9); add 3,10,3; mtspr 8,0; blrl; bl _s800F4A14_0; cmpw 3,29; bne 1f; lwz 9,0x0(31); li 3,0; cmpwi 9,0; beq 3f; lwz 3,0x4(9); b 3f; 1:; lwz 0,0x4(30); addi 31,31,4; cmpw 31,0; bne 0b; 2:; li 3,0; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s800F4A14_0();
extern "C" void f_800F4A14() {}
