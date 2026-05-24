// 0x80023458 ESimsDataManager::preload(ObjSelector (156 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 30,4; lwz 0,0xa0(30); cmpwi 0,1; beq 1f; li 0,0; addi 31,1,8; stw 0,0x8(1); addi 9,31,8; stw 0,0x4(31); mr 3,30; stw 0,0x4(9); mr 4,31; li 5,0; bl _s80023458_0; mr 3,31; li 4,0; bl _s80023458_1; lwz 3,0x8(1); li 0,1; stw 0,0xa0(30); cmpwi 3,0; beq 1f; lwz 0,0xc(31); subf 0,3,0; rlwinm 4,0,0,0,29; cmplwi 4,128; ble 0f; bl _s80023458_2; b 1f; 0:; bl _s80023458_3; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"

extern "C" void _s80023458_0();
extern "C" void _s80023458_1();
extern "C" void _s80023458_2();
extern "C" void _s80023458_3();

struct ESimsDataManager {
    void preload_ObjSelector();
};

void ESimsDataManager::preload_ObjSelector() {
}
