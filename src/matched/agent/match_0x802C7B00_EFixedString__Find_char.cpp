// 0x802C7B00 EFixedString::Find(char (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; mr 3,30; bl _s802C7B00_0; mr 31,3; mr 3,29; bl _s802C7B00_1; subf 6,31,3; li 3,0; cmpw 3,6; bgt 4f; 0:; li 10,0; li 7,1; cmpw 10,31; bge 3f; lwz 9,0x0(29); lbz 11,0x0(30); lbzx 0,9,3; mr 8,9; b 2f; 1:; addi 10,10,1; cmpw 10,31; bge 3f; add 9,3,10; lbzx 11,30,10; lbzx 0,8,9; 2:; cmpw 0,11; beq 1b; li 7,0; 3:; cmpwi 7,0; bne 5f; addi 3,3,1; cmpw 3,6; ble 0b; 4:; li 3,-1; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s802C7B00_0();
extern "C" void _s802C7B00_1();
extern "C" void f_802C7B00() {}
