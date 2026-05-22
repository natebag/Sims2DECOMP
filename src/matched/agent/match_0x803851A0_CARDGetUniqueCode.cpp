// 0x803851A0 CARDGetUniqueCode (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; stw 0,0x4(1); stwu 1,-32(1); stw 31,0x1c(1); addi 31,4,0; stw 30,0x18(1); mr. 30,3; blt 0f; cmpwi 30,2; blt 1f; 0:; li 3,-128; b 3f; 1:; addi 3,30,0; addi 4,1,16; bl _s803851A0_0; cmpwi 3,0; bge 2f; b 3f; 2:; bl _s803851A0_1; mulli 4,30,12; addi 0,3,0; addi 4,4,4; addi 3,31,0; add 4,0,4; li 5,8; bl _s803851A0_2; li 3,0; bl _s803851A0_3; lwz 3,0x10(1); li 4,0; bl _s803851A0_4; 3:; lwz 0,0x24(1); lwz 31,0x1c(1); lwz 30,0x18(1); addi 1,1,32; mtspr 8,0"
extern "C" void _s803851A0_0();
extern "C" void _s803851A0_1();
extern "C" void _s803851A0_2();
extern "C" void _s803851A0_3();
extern "C" void _s803851A0_4();
extern "C" void f_803851A0() {}
