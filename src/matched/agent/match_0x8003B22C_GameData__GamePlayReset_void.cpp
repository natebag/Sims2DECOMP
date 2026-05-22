// 0x8003B22C GameData::GamePlayReset(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); li 0,0; mr 29,3; li 11,1; lis 9,-32697; stw 11,0xe4(29); addi 9,9,23428; stw 0,0xe8(29); li 30,0; stw 0,0xf0(29); addi 31,29,244; stw 0,0x84(29); stw 0,0xac(9); stw 0,0xb0(9); stw 0,0xb4(9); 0:; mr 3,31; mr 4,30; bl _s8003B22C_0; addi 30,30,1; addi 31,31,16; cmpwi 30,1; ble 0b; addi 3,29,4; bl _s8003B22C_1; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8003B22C_0();
extern "C" void _s8003B22C_1();
extern "C" void f_8003B22C() {}
