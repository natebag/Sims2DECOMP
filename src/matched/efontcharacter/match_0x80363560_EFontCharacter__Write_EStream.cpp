// 0x80363560 EFontCharacter::Write(EStream (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 30,4; mr 29,3; lwz 9,0x18(30); addi 4,1,24; li 5,4; lwz 0,0x4(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x18(1); mtspr 8,9; blrl; lwz 9,0x18(30); addi 4,1,28; li 5,4; lwz 0,0x8(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; stw 0,0x1c(1); mtspr 8,9; blrl; lwz 9,0x18(30); addi 4,1,8; li 5,2; lhz 0,0xc(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; sth 0,0x8(1); mtspr 8,9; blrl; lwz 9,0x18(30); addi 4,1,16; li 5,2; lhz 0,0xe(29); lha 3,0x38(9); lwz 9,0x3c(9); add 3,30,3; sth 0,0x10(1); mtspr 8,9; blrl; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"

struct EFontCharacter {
    void Write_EStream();
};

void EFontCharacter::Write_EStream() {
}
