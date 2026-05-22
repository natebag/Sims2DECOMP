// 0x8015DA2C TreeTableEntryQuickData::~TreeTableEntryQuickData(void) (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lis 9,-32698; mr 29,3; addi 9,9,23688; li 0,0; lwz 28,0x8(29); addi 26,29,8; stw 9,0x0(29); mr 25,4; stw 0,0x4(29); lwz 30,0x4(26); mr 31,28; addi 27,29,8; cmpw 28,30; beq 2f; 0:; lwz 11,0x0(31); cmpwi 11,0; beq 1f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 1:; addi 31,31,4; cmpw 31,30; bne 0b; 2:; stw 28,0x4(26); lwz 30,0x4(27); lwz 31,0x8(29); cmpw 31,30; beq 5f; 3:; lwz 11,0x0(31); cmpwi 11,0; beq 4f; lwz 9,0x0(11); lha 3,0x18(9); lwz 0,0x1c(9); add 3,11,3; mtspr 8,0; blrl; 4:; addi 31,31,4; cmpw 31,30; bne 3b; 5:; lwz 3,0x0(27); cmpwi 3,0; beq 7f; lwz 0,0xc(27); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 6f; bl _s8015DA2C_0; b 7f; 6:; bl _s8015DA2C_1; 7:; andi. 0,25,1; beq 8f; mr 3,29; bl _s8015DA2C_2; 8:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s8015DA2C_0();
extern "C" void _s8015DA2C_1();
extern "C" void _s8015DA2C_2();
extern "C" void f_8015DA2C() {}
