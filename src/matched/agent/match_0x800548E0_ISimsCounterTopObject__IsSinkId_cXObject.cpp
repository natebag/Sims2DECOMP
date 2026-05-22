// 0x800548E0 ISimsCounterTopObject::IsSinkId(cXObject (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); li 30,0; mr. 31,3; beq 0f; lwz 9,0x4(31); lha 3,0x310(9); lwz 0,0x314(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0f; lwz 9,0x4(31); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0xc0(3); cmpwi 0,0; beq 0f; lwz 9,0x4(31); lwz 0,0x314(9); lha 3,0x310(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0xc0(3); lbz 0,0x7(9); cmpwi 0,0; beq 0f; li 30,1; 0:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_800548E0() {}
