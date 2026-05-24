// 0x8004DD1C ISimsObjectModel::SetSOMModel(unsigned (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 28,0x48(1); stw 0,0x5c(1); mr 31,3; mr 30,4; lwz 11,0x328(31); addi 28,31,820; lwz 29,0x110(31); lwz 9,0x4(11); lha 3,0x2a8(9); lwz 0,0x2ac(9); add 3,11,3; mtspr 8,0; blrl; mr 5,3; mr 4,30; mr 3,31; li 6,0; li 7,0; bl _s8004DD1C_0; lwz 9,0x120(31); cmpw 29,30; lfs f0,0x88(9); stfs f0,0x58(28); beq 0f; lwz 0,0x3e8(31); cmpwi 0,0; beq 0f; lwz 0,0x3cc(31); cmpwi 0,0; bge 0f; lwz 9,0x0(31); addi 4,1,8; lha 3,0x110(9); lwz 0,0x114(9); add 3,31,3; mtspr 8,0; blrl; mr 3,28; li 4,1; addi 5,1,8; bl _s8004DD1C_1; mr 3,28; li 4,0; addi 5,1,8; bl _s8004DD1C_2; 0:; lwz 0,0x5c(1); mtspr 8,0; lmw 28,0x48(1); addi 1,1,88"

extern "C" void _s8004DD1C_0();
extern "C" void _s8004DD1C_1();
extern "C" void _s8004DD1C_2();

struct ISimsObjectModel {
    void SetSOMModel();
};

void ISimsObjectModel::SetSOMModel() {
}
