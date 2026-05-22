// 0x8017EA1C UIReflow::Reflow_Id(char (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,4; mr 31,3; lis 4,-32706; mr 30,5; addi 4,4,14184; bl _s8017EA1C_0; lbz 9,0x0(29); addi 9,9,-48; cmplwi 9,1; ble 1f; cmpwi 30,0; beq 0f; lis 4,-32706; mr 3,31; addi 4,4,14192; bl _s8017EA1C_1; b 1f; 0:; lis 4,-32706; mr 3,31; addi 4,4,14196; bl _s8017EA1C_2; 1:; mr 4,29; mr 3,31; bl _s8017EA1C_3; lis 4,-32706; mr 3,31; addi 4,4,14200; bl _s8017EA1C_4; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8017EA1C_0();
extern "C" void _s8017EA1C_1();
extern "C" void _s8017EA1C_2();
extern "C" void _s8017EA1C_3();
extern "C" void _s8017EA1C_4();
extern "C" void f_8017EA1C() {}
