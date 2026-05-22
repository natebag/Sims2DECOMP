// 0x80199E9C CASSelectionTarget::InitScreen(void) (344 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 3,0x84(31); cmpwi 3,0; beq 5f; lwz 3,0x1c(3); cmpwi 3,0; beq 5f; bl _s80199E9C_0; stw 3,0x54c(31); lis 3,-32705; addi 3,3,-16412; bl _s80199E9C_1; xori 3,3,1; subfic 0,3,0; adde 3,0,3; lis 9,-32705; li 0,1; stw 3,0x550(31); stw 0,0x548(31); addi 10,9,-14256; li 8,0; lwz 4,0x54c(31); lhz 11,-14256(9); mr 3,31; lbz 0,0x2(10); addi 5,1,8; sth 11,0x5d8(31); stb 0,0x5da(31); stw 8,0x8c(31); bl _s80199E9C_2; cmpwi 3,0; beq 0f; lwz 3,0x84(31); addi 5,31,148; lwz 4,0x8(1); addi 6,31,748; bl _s80199E9C_3; b 1f; 0:; lwz 4,0x54c(31); mr 3,31; addi 5,1,12; bl _s80199E9C_4; cmpwi 3,0; beq 2f; lwz 3,0x84(31); addi 5,31,148; lwz 4,0xc(1); addi 6,31,748; bl _s80199E9C_5; 1:; stw 3,0x8c(31); 2:; lwz 11,0x8c(31); li 0,1; stw 0,0x544(31); cmpwi 11,0; ble 4f; srawi 9,11,2; rlwinm 0,9,2,0,29; stw 9,0x544(31); subf. 0,0,11; ble 3f; addi 9,9,1; cmpwi 0,4; stw 9,0x544(31); ble 3f; addi 0,9,1; stw 0,0x544(31); 3:; lwz 0,0x8c(31); cmpwi 0,4; ble 4f; lwz 9,0x544(31); addi 9,9,-1; stw 9,0x544(31); 4:; lwz 4,0x54c(31); mr 3,31; bl _s80199E9C_6; mr 3,31; bl _s80199E9C_7; 5:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24"
extern "C" void _s80199E9C_0();
extern "C" void _s80199E9C_1();
extern "C" void _s80199E9C_2();
extern "C" void _s80199E9C_3();
extern "C" void _s80199E9C_4();
extern "C" void _s80199E9C_5();
extern "C" void _s80199E9C_6();
extern "C" void _s80199E9C_7();
extern "C" void f_80199E9C() {}
