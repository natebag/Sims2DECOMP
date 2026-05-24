// 0x800BD7AC IFFResMap::RemoveNode(IFFResNode (444 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 26,3; lwz 28,0x0(26); lwz 0,0x4(26); cmpw 28,0; beq 11f; 0:; lwz 0,0x4(28); lwz 3,0x0(28); mr 9,0; cmpw 3,0; beq 10f; lis 27,-17874; ori 27,27,35747; 1:; cmpw 3,4; bne 9f; addi 4,3,88; cmpw 4,9; beq 3f; mr 31,4; mr 30,3; subf 0,31,9; mullw 0,0,27; srawi. 29,0,3; ble 3f; 2:; lwz 9,0x0(31); addi 3,30,16; addi 4,31,16; stw 9,0x0(30); lwz 0,0x4(31); stw 0,0x4(30); lhz 9,0x8(31); sth 9,0x8(30); lhz 0,0xa(31); sth 0,0xa(30); lwz 9,0xc(31); addi 31,31,88; stw 9,0xc(30); bl _s800BD7AC_0; addi 30,30,88; addic. 29,29,-1; bgt 2b; 3:; lwz 9,0x4(28); lwz 0,0x0(28); addi 9,9,-88; subf 0,0,9; stw 9,0x4(28); mullw 0,0,27; rlwinm. 9,0,29,3,31; bne 11f; lwz 9,0x4(26); addi 4,28,24; cmpw 4,9; beq 5f; mr 30,4; lis 0,-21846; subf 9,30,9; ori 0,0,43691; mullw 9,9,0; mr 31,28; srawi. 29,9,3; ble 5f; 4:; mr 3,31; mr 4,30; bl _s800BD7AC_1; lwz 0,0x10(30); addic. 29,29,-1; stw 0,0x10(31); lwz 9,0x14(30); addi 30,30,24; stw 9,0x14(31); addi 31,31,24; bgt 4b; 5:; lwz 9,0x4(26); addi 11,9,-24; stw 11,0x4(26); lwz 0,0x4(11); lwz 9,-24(9); cmpw 9,0; beq 7f; 6:; addi 9,9,88; cmpw 9,0; bne 6b; 7:; lwz 3,0x0(11); cmpwi 3,0; beq 11f; lwz 0,0xc(11); subf 0,3,0; mullw 0,0,27; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 8f; bl _s800BD7AC_2; b 11f; 8:; bl _s800BD7AC_3; b 11f; 9:; addi 3,3,88; cmpw 3,9; bne 1b; 10:; lwz 0,0x4(26); addi 28,28,24; cmpw 28,0; bne 0b; 11:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s800BD7AC_0();
extern "C" void _s800BD7AC_1();
extern "C" void _s800BD7AC_2();
extern "C" void _s800BD7AC_3();

struct IFFResMap {
    void RemoveNode_IFFResNode();
};

void IFFResMap::RemoveNode_IFFResNode() {
}
