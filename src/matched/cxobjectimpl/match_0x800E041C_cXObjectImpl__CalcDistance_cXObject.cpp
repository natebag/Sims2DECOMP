// 0x800E041C cXObjectImpl::CalcDistance(cXObject (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 29,3; mr. 31,4; beq 0f; lwz 9,0x4(31); lha 3,0x520(9); lwz 0,0x524(9); add 3,31,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; li 4,29; addi 3,3,40; bl _s800E041C_0; mr 30,3; li 4,29; addi 3,29,40; bl _s800E041C_1; lha 9,0x0(30); lha 0,0x0(3); cmpw 9,0; beq 2f; lwz 4,0x4(29); mr 5,31; lwz 3,0x58(29); bl _s800E041C_2; b 3f; 2:; lwz 3,0x4(29); mr 4,31; lwz 9,0x4(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"

extern "C" void _s800E041C_0();
extern "C" void _s800E041C_1();
extern "C" void _s800E041C_2();

struct cXObjectImpl {
    void CalcDistance_cXObject();
};

void cXObjectImpl::CalcDistance_cXObject() {
}
