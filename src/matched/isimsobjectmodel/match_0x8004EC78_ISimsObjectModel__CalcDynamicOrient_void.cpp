// 0x8004EC78 ISimsObjectModel::CalcDynamicOrient(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 30,0x58(1); stw 0,0x64(1); mr 31,3; lwz 0,0x44c(31); cmpwi 0,0; beq 0f; cmpw 0,31; beq 0f; lwz 9,0x0(31); addi 4,1,8; mr 30,4; lwz 0,0x114(9); lha 3,0x110(9); mtspr 8,0; add 3,31,3; blrl; lis 11,-32707; lis 10,-32707; lfs f0,0x3218(11); addi 9,1,72; lfs f13,0x321c(10); mr 4,9; stfs f0,0x48(1); mr 3,30; stfs f0,0x4(9); stfs f13,0x8(9); bl _s8004EC78_0; lwz 11,0x44c(31); mr 4,30; lwz 9,0x0(11); lha 3,0x98(9); lwz 0,0x9c(9); add 3,11,3; mtspr 8,0; blrl; 0:; lwz 0,0x64(1); mtspr 8,0; lmw 30,0x58(1); addi 1,1,96"

extern "C" void _s8004EC78_0();

struct ISimsObjectModel {
    void CalcDynamicOrient();
};

void ISimsObjectModel::CalcDynamicOrient() {
}
