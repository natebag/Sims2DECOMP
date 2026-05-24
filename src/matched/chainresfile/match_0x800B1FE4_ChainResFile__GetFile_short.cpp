// 0x800B1FE4 ChainResFile::GetFile(short) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 8,3; li 10,0; lwz 0,0x10(8); li 11,0; li 3,0; cmpwi 0,0; beqlr; cmpw 3,4; bne 0f; mr 3,0; blr; 0:; addi 11,11,1; addi 10,10,1; cmpwi 11,7; bgtlr; mulli 0,11,24; addi 9,8,16; lwzx 0,9,0; cmpwi 0,0; beqlr; cmpw 10,4; bne 0b; mr 3,0"

struct ChainResFile {
    void GetFile();
};

void ChainResFile::GetFile() {
}
