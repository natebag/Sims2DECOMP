// 0x802D4F44 EString2::Find(unsigned (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 3,30; bl _s802D4F44_0; mr 31,3; mr 3,29; bl _s802D4F44_1; subf 5,31,3; li 3,0; cmpw 3,5; bgt 4f; 0:; li 8,0; li 6,1; cmpw 8,31; bge 3f; lwz 9,0x0(29); add 11,3,3; lhz 10,0x0(30); lhzx 0,11,9; mr 7,9; b 2f; 1:; addi 8,8,1; cmpw 8,31; bge 3f; add 9,3,8; add 11,8,8; add 9,9,9; lhzx 10,11,30; lhzx 0,9,7; 2:; cmpw 0,10; beq 1b; li 6,0; 3:; cmpwi 6,0; bne 5f; addi 3,3,1; cmpw 3,5; ble 0b; 4:; li 3,-1; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802D4F44_0();
extern "C" void _s802D4F44_1();
extern "C" void f_802D4F44() {}
