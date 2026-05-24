// 0x80112BA8 ObjTestSim::RunMenuCheckTree(InteractionList (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 31,5; mr 30,3; stw 31,-21344(13); mr 3,29; bl _s80112BA8_0; mr 28,3; li 5,0; li 6,0; li 7,1; li 8,0; mr 3,30; mr 4,31; bl _s80112BA8_1; mr 3,29; bl _s80112BA8_2; cmpw 28,3; bne 0f; lwz 0,0x3c(31); andi. 9,0,16; bne 0f; andi. 9,0,8; beq 0f; mr 4,31; mr 3,29; bl _s80112BA8_3; 0:; mr 3,29; bl _s80112BA8_4; subf 3,28,3; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s80112BA8_0();
extern "C" void _s80112BA8_1();
extern "C" void _s80112BA8_2();
extern "C" void _s80112BA8_3();
extern "C" void _s80112BA8_4();

struct ObjTestSim {
    void RunMenuCheckTree_InteractionList();
};

void ObjTestSim::RunMenuCheckTree_InteractionList() {
}
