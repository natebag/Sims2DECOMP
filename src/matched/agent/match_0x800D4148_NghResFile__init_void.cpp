// 0x800D4148 NghResFile::init(void) (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); mr 29,3; li 3,16; bl _s800D4148_0; li 9,4; stw 3,0x138(29); mtspr 9,9; li 0,0; li 11,0; 0:; lwz 9,0x138(29); stwx 0,11,9; addi 11,11,4; bdnz 0b; addi 31,29,316; addi 26,29,16; addi 25,29,404; li 28,0; mr 30,31; addi 27,29,376; 1:; li 3,24; bl _s800D4148_1; li 0,6; stw 3,0x0(30); mtspr 9,0; li 11,0; 2:; lwz 9,0x0(31); stwx 28,11,9; addi 11,11,4; bdnz 2b; addi 31,31,4; addi 30,30,4; cmpw 31,27; ble 1b; li 3,8; bl _s800D4148_2; li 9,2; stw 3,0x17c(29); mtspr 9,9; li 0,0; li 11,0; 3:; lwz 9,0x17c(29); stwx 0,11,9; addi 11,11,4; bdnz 3b; lwz 3,0x10(29); lwz 0,0x4(26); mr 9,3; cmpw 3,0; beq 5f; 4:; addi 9,9,16; cmpw 9,0; bne 4b; 5:; li 11,36; stw 3,0x4(26); mtspr 9,11; addi 9,25,140; li 0,0; 6:; stw 0,0x0(9); addi 9,9,-4; bdnz 6b; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"
extern "C" void _s800D4148_0();
extern "C" void _s800D4148_1();
extern "C" void _s800D4148_2();
extern "C" void f_800D4148() {}
