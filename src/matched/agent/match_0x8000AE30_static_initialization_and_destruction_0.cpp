// 0x8000AE30 __static_initialization_and_destruction_0 (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); li 0,0; ori 0,0,65535; cmpw 4,0; bne 8f; cmpwi 3,0; beq 2f; li 11,48; lis 9,-32697; mtspr 9,11; li 0,0; addi 9,9,-6160; 0:; stw 0,0xc(9); stw 0,0x10(9); stw 0,0x18(9); stw 0,0x0(9); stw 0,0x8(9); stw 0,0x1c(9); stw 0,0x4(9); addi 9,9,32; bdnz 0b; li 0,350; mtspr 9,0; 1:; bdnz 1b; b 8f; 2:; lis 9,-32697; addi 9,9,-6160; cmpwi 9,0; beq 8f; addi 30,9,1536; cmpw 30,9; beq 8f; mr 29,9; addi 31,29,1548; 3:; lwzu 0,-32(31); addi 30,30,-32; lwz 11,0x4(31); mr 9,0; cmpw 9,11; beq 5f; 4:; addi 9,9,8; cmpw 9,11; bne 4b; 5:; lwz 3,0x0(31); cmpwi 3,0; beq 7f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,28; cmplwi 4,128; ble 6f; bl _s8000AE30_0; b 7f; 6:; bl _s8000AE30_1; 7:; cmpw 30,29; bne 3b; 8:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s8000AE30_0();
extern "C" void _s8000AE30_1();
extern "C" void f_8000AE30() {}
