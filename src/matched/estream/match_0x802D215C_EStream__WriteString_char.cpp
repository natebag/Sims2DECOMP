// 0x802D215C EStream::WriteString(char (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 29,4; li 30,0; lbzx 0,29,30; mr 31,3; cmpwi 0,0; beq 1f; 0:; stb 0,0x8(1); addi 4,1,8; li 5,1; addi 30,30,1; lwz 9,0x18(31); lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lbzx 0,29,30; cmpwi 0,0; bne 0b; 1:; lwz 9,0x18(31); li 0,0; stb 0,0x8(1); addi 4,1,8; li 5,1; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; addi 3,30,1; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

struct EStream {
    void WriteString();
};

void EStream::WriteString() {
}
