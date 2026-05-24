// 0x800B39CC ChainResFile::AddExclusiveType(iResFile (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 27,0x1c(1); stw 0,0x34(1); stw 5,0x8(1); li 8,0; addi 11,3,20; li 10,0; 0:; addi 9,3,16; lwzx 0,9,10; cmpw 0,4; bne 13f; lwz 0,0x0(11); addi 3,3,36; lwz 9,0x4(11); subf 9,0,9; rlwinm. 0,9,30,2,31; beq 1f; lwzx 0,3,10; cmpwi 0,0; bne 14f; 1:; li 0,0; mr 28,11; stwx 0,3,10; addi 27,1,8; lwz 30,0x4(11); lwz 0,0xc(11); cmpw 30,0; beq 2f; lwz 0,0x8(1); stw 0,0x0(30); lwz 9,0x4(11); addi 9,9,4; stw 9,0x4(11); b 14f; 2:; lwz 0,0x0(11); li 9,1; stw 9,0x10(1); addi 10,1,16; subf 0,0,30; addi 11,1,12; srawi 9,0,2; stw 9,0xc(1); cmplwi 9,1; bge 3f; mr 11,10; 3:; lwz 0,0x0(11); add. 0,9,0; beq 5f; rlwinm 0,0,2,0,29; mr 29,0; cmplwi 0,128; ble 4f; mr 3,29; bl _s800B39CC_0; mr 31,3; b 6f; 4:; mr 3,29; bl _s800B39CC_1; mr 31,3; b 6f; 5:; li 31,0; li 29,0; 6:; lwz 4,0x0(28); cmpw 30,4; beq 7f; subf 30,4,30; mr 3,31; mr 5,30; bl _s800B39CC_2; add 0,3,30; b 8f; 7:; mr 0,31; 8:; lwz 9,0x10(1); mr 30,0; mtspr 9,9; cmpwi 9,0; beq 10f; 9:; lwz 0,0x0(27); stw 0,0x0(30); addi 30,30,4; bdnz 9b; 10:; lwz 3,0x0(28); lwz 0,0xc(28); cmpwi 3,0; subf 0,3,0; srawi 0,0,2; beq 12f; rlwinm 4,0,2,0,29; cmplwi 4,128; ble 11f; bl _s800B39CC_3; b 12f; 11:; bl _s800B39CC_4; 12:; add 0,29,31; stw 31,0x0(28); stw 0,0xc(28); stw 30,0x4(28); b 14f; 13:; addi 8,8,1; addi 11,11,24; addi 10,10,24; cmpwi 8,7; ble 0b; 14:; lwz 0,0x34(1); mtspr 8,0; lmw 27,0x1c(1); addi 1,1,48"

extern "C" void _s800B39CC_0();
extern "C" void _s800B39CC_1();
extern "C" void _s800B39CC_2();
extern "C" void _s800B39CC_3();
extern "C" void _s800B39CC_4();

struct ChainResFile {
    void AddExclusiveType_iResFile();
};

void ChainResFile::AddExclusiveType_iResFile() {
}
