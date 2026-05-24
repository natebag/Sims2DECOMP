// 0x800BDB70 IFFResMap::RemoveAllNodesOfType(unsigned (248 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 28,3; li 5,0; bl _s800BDB70_0; lwz 9,0x4(28); cmpw 3,9; beq 5f; addi 4,3,24; cmpw 4,9; beq 1f; mr 30,4; lis 0,-21846; subf 9,30,9; ori 0,0,43691; mullw 9,9,0; mr 31,3; srawi. 29,9,3; ble 1f; 0:; mr 3,31; mr 4,30; bl _s800BDB70_1; lwz 0,0x10(30); addic. 29,29,-1; stw 0,0x10(31); lwz 9,0x14(30); addi 30,30,24; stw 9,0x14(31); addi 31,31,24; bgt 0b; 1:; lwz 9,0x4(28); addi 11,9,-24; stw 11,0x4(28); lwz 0,0x4(11); lwz 9,-24(9); cmpw 9,0; beq 3f; 2:; addi 9,9,88; cmpw 9,0; bne 2b; 3:; lwz 3,0x0(11); cmpwi 3,0; beq 5f; lwz 0,0xc(11); lis 9,-17874; ori 9,9,35747; subf 0,3,0; mullw 0,0,9; srawi 0,0,3; mulli 4,0,88; cmplwi 4,128; ble 4f; bl _s800BDB70_2; b 5f; 4:; bl _s800BDB70_3; 5:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800BDB70_0();
extern "C" void _s800BDB70_1();
extern "C" void _s800BDB70_2();
extern "C" void _s800BDB70_3();

struct IFFResMap {
    void RemoveAllNodesOfType();
};

void IFFResMap::RemoveAllNodesOfType() {
}
