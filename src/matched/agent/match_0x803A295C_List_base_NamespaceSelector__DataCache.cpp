// 0x803A295C _List_base<NamespaceSelector::DataCache, (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; lwz 9,0x4(29); lwz 30,0x0(9); cmpw 30,9; beq 3f; 0:; mr 31,30; lwz 11,0xc(31); lwz 30,0x0(30); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; cmpwi 31,0; beq 2f; mr 3,31; li 4,20; bl _s803A295C_0; 2:; lwz 0,0x4(29); cmpw 30,0; bne 0b; 3:; lwz 9,0x4(29); stw 9,0x0(9); lwz 11,0x4(29); stw 11,0x4(11); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s803A295C_0();
extern "C" void f_803A295C() {}
