// 0x801D63B8 PCTTarget::CreateGrabObjectMenu(TNodeList<ISimInstance (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 28,0x18(1); stw 0,0x2c(1); mr 31,4; mr 29,3; lwz 0,0x0(31); cmpwi 0,0; bne 0f; li 3,0; b 4f; 0:; lwz 0,0xe4(29); li 3,0; cmpwi 0,0; beq 4f; addi 3,1,8; bl _s801D63B8_0; lwz 31,0x0(31); li 0,0; stw 0,0x10(1); cmpwi 31,0; beq 3f; li 28,0; 1:; lwz 3,0x0(31); bl _s801D63B8_1; mr 30,3; bl _s801D63B8_2; mr 4,3; addi 3,1,8; bl _s801D63B8_3; addi 4,1,16; mr 3,30; bl _s801D63B8_4; mr 7,3; lwz 8,0x10(1); lwz 3,0xe4(29); mr 4,30; li 5,0; addi 6,1,8; li 9,0; bl _s801D63B8_5; lwz 3,0x10(1); cmpwi 3,0; beq 2f; bl _s801D63B8_6; stw 28,0x10(1); 2:; lwz 31,0x8(31); cmpwi 31,0; bne 1b; 3:; lwz 3,0xe4(29); bl _s801D63B8_7; addi 3,1,8; li 4,2; bl _s801D63B8_8; li 3,1; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 28,0x18(1); addi 1,1,40"

extern "C" void _s801D63B8_0();
extern "C" void _s801D63B8_1();
extern "C" void _s801D63B8_2();
extern "C" void _s801D63B8_3();
extern "C" void _s801D63B8_4();
extern "C" void _s801D63B8_5();
extern "C" void _s801D63B8_6();
extern "C" void _s801D63B8_7();
extern "C" void _s801D63B8_8();

struct PCTTarget {
    void CreateGrabObjectMenu_TNodeList_ISimInstance();
};

void PCTTarget::CreateGrabObjectMenu_TNodeList_ISimInstance() {
}
