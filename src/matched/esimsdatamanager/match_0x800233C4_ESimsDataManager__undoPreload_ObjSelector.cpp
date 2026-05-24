// 0x800233C4 ESimsDataManager::undoPreload(ObjSelector (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 29,0x24(1); stw 0,0x34(1); mr 29,4; lwz 0,0xa0(29); cmpwi 0,0; beq 1f; li 30,0; addi 31,1,8; stw 30,0x8(1); addi 9,31,8; stw 30,0x4(31); mr 3,29; stw 30,0x4(9); mr 4,31; li 5,0; bl _s800233C4_0; mr 3,31; bl _s800233C4_1; lwz 3,0x8(1); stw 30,0xa0(29); cmpwi 3,0; beq 1f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s800233C4_2; b 1f; 0:; bl _s800233C4_3; 1:; lwz 0,0x34(1); mtspr 8,0; lmw 29,0x24(1); addi 1,1,48"

extern "C" void _s800233C4_0();
extern "C" void _s800233C4_1();
extern "C" void _s800233C4_2();
extern "C" void _s800233C4_3();

struct ESimsDataManager {
    void undoPreload_ObjSelector();
};

void ESimsDataManager::undoPreload_ObjSelector() {
}
