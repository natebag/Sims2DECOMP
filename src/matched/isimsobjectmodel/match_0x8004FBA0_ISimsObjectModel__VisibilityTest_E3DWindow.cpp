// 0x8004FBA0 ISimsObjectModel::VisibilityTest(E3DWindow (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 3,4; addi 4,31,60; bl _s8004FBA0_0; mr 30,3; xori 0,30,1; andi. 9,0,1; beq 3f; mr 3,31; bl _s8004FBA0_1; cmpwi 3,0; beq 2f; lwz 0,0x30(31); cmpwi 0,0; beq 0f; lwz 3,0x2c(31); mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; cmpwi 3,0; beq 3f; 2:; li 30,1; 3:; mr 3,30; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s8004FBA0_0();
extern "C" void _s8004FBA0_1();

struct ISimsObjectModel {
    void VisibilityTest_E3DWindow();
};

void ISimsObjectModel::VisibilityTest_E3DWindow() {
}
