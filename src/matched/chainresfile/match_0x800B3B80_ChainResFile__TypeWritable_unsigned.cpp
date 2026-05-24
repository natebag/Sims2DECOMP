// 0x800B3B80 ChainResFile::TypeWritable(unsigned (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; mfcr 12; stmw 29,0xc(1); stw 0,0x1c(1); stw 12,0x8(1); lwz 0,0x10(3); mr 30,4; li 29,0; cmpwi 0,0; beq 8f; addi 31,3,16; 0:; lwz 9,0x4(31); li 8,0; lwz 0,0x8(31); lwz 10,0x14(31); cmpw 9,0; beq 3f; mr 11,0; 1:; lwz 0,0x0(9); cmpw 0,30; bne 2f; li 8,1; 2:; addi 9,9,4; cmpw 9,11; bne 1b; 3:; cmpwi 4,8,0; beq cr4,5f; cmpwi 10,0; bne 4f; lwz 3,0x0(31); lwz 9,0xc(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 6f; 4:; bne cr4,7f; 5:; lwz 0,0x14(31); cmpwi 0,0; beq 7f; lwz 3,0x0(31); lwz 9,0xc(3); lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 7f; 6:; li 3,1; b 9f; 7:; addi 29,29,1; addi 31,31,24; cmpwi 29,7; bgt 8f; lwz 0,0x0(31); cmpwi 0,0; bne 0b; 8:; li 3,0; 9:; lwz 0,0x1c(1); lwz 12,0x8(1); mtspr 8,0; lmw 29,0xc(1); mtcrf 8,12; addi 1,1,24"

struct ChainResFile {
    void TypeWritable();
};

void ChainResFile::TypeWritable() {
}
