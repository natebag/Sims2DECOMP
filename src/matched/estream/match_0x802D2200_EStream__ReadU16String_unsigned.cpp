// 0x802D2200 EStream::ReadU16String(unsigned (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 26,0x10(1); stw 0,0x2c(1); mr 26,4; mr 28,3; mr 29,5; li 30,0; addi 27,1,8; mr 31,26; 0:; lwz 9,0x18(28); mr 4,27; li 5,2; lha 3,0x30(9); lwz 0,0x34(9); add 3,28,3; mtspr 8,0; blrl; cmpw 30,29; bge 1f; lhz 0,0x8(1); sth 0,0x0(31); 1:; lhz 0,0x8(1); addi 31,31,2; addi 30,30,1; cmpwi 0,0; bne 0b; cmpw 30,29; ble 2f; add 9,29,29; add 9,9,26; sth 0,-2(9); 2:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 26,0x10(1); addi 1,1,40"

struct EStream {
    void ReadU16String();
};

void EStream::ReadU16String() {
}
