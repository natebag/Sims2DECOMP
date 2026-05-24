// 0x800BDCB0 IFFResMap::GetHighestID(unsigned (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,5; li 5,0; bl _s800BDCB0_0; lwz 0,0x4(30); cmpw 3,0; beq 2f; lwz 0,0x4(3); lwz 3,0x0(3); cmpw 3,0; beq 2f; mr 9,0; 0:; lwz 0,0x4(3); cmpw 0,31; ble 1f; lha 31,0x6(3); 1:; addi 3,3,88; cmpw 3,9; bne 0b; 2:; mr 3,31; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800BDCB0_0();

struct IFFResMap {
    void GetHighestID();
};

void IFFResMap::GetHighestID() {
}
