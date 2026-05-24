// 0x802D20C0 EStream::ReadString(char (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 27,0x14(1); stw 0,0x2c(1); mr 29,3; mr 28,4; mr 30,5; li 31,0; addi 27,1,8; 0:; lwz 9,0x18(29); mr 4,27; li 5,1; lha 3,0x30(9); lwz 0,0x34(9); add 3,29,3; mtspr 8,0; blrl; cmpw 31,30; bge 1f; lbz 0,0x8(1); stbx 0,28,31; 1:; lbz 0,0x8(1); addi 31,31,1; extsb 0,0; cmpwi 0,0; bne 0b; cmpw 31,30; ble 3f; cmpwi 30,80; ble 2f; li 30,80; 2:; add 9,30,28; stb 0,-1(9); 3:; mr 3,31; lwz 0,0x2c(1); mtspr 8,0; lmw 27,0x14(1); addi 1,1,40"

struct EStream {
    void ReadString();
};

void EStream::ReadString() {
}
