// 0x800F9E6C cXObjectImpl::AllowIdleOptimization(void) (180 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; li 30,0; lwz 10,0xb4(31); lwz 9,0xb0(31); b 1f; 0:; addi 9,9,108; 1:; cmpw 9,10; beq 3f; lwz 0,0x10(9); li 11,1; cmpwi 0,0; bne 2f; li 11,0; 2:; cmpwi 11,0; beq 0b; li 30,1; 3:; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x318(9); lwz 9,0x31c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,2; beq 4f; addi 3,31,40; li 4,25; bl _s800F9E6C_0; lha 0,0x0(3); cmpwi 0,0; bne 4f; cmpwi 30,0; beq 5f; 4:; li 3,0; b 6f; 5:; li 3,1; 6:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800F9E6C_0();
extern "C" void f_800F9E6C() {}
