// 0x802871F8 AptArray::sMethod_shift(AptValue (164 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; lwz 30,-22936(13); lwz 9,0x0(31); li 11,0; rlwinm 0,9,0,25,31; cmpwi 0,22; bne 0f; rlwinm 11,9,5,31,31; 0:; cmpwi 11,0; beq 2f; lwz 0,0x2c(31); cmpwi 0,0; ble 2f; mr 3,31; li 4,0; bl _s802871F8_0; lwz 9,0x2c(31); mr 30,3; addi 5,9,-1; stw 5,0x2c(31); cmpwi 5,0; beq 1f; lwz 3,0x24(31); rlwinm 5,5,2,0,29; addi 4,3,4; bl _s802871F8_1; 1:; lwz 9,0x2c(31); li 0,0; lwz 11,0x24(31); rlwinm 9,9,2,0,29; stwx 0,9,11; 2:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802871F8_0();
extern "C" void _s802871F8_1();
extern "C" void f_802871F8() {}
