// 0x8036362C EFontCharacter::Read(EStream (188 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32688; mr 30,3; lhz 0,-10542(9); mr 31,4; cmpwi 0,0; bne 0f; lwz 9,0x18(31); addi 4,30,4; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,30,8; li 5,4; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,30,12; li 5,2; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x18(31); addi 4,30,14; li 5,2; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_8036362C() {}
