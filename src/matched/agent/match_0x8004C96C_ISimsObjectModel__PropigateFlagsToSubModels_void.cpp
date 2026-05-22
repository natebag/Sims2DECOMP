// 0x8004C96C ISimsObjectModel::PropigateFlagsToSubModels(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; lwz 31,0x450(30); cmpwi 31,0; beq 1f; 0:; lwz 3,0x0(31); lwz 4,0x32c(30); lwz 9,0x320(3); addi 3,3,800; lha 0,0x18(9); lwz 9,0x1c(9); add 3,3,0; mtspr 8,9; blrl; lwz 31,0x8(31); cmpwi 31,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8004C96C() {}
