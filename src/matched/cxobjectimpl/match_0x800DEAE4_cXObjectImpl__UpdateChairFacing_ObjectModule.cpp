// 0x800DEAE4 cXObjectImpl::UpdateChairFacing(ObjectModule (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 31,3; addi 3,1,8; bl _s800DEAE4_0; lwz 3,-21488(13); addi 4,1,8; lwz 9,0x0(3); lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 9,0x0(31); addi 4,1,8; lwz 11,0x254(9); addi 29,9,144; lha 3,0x250(9); mtspr 8,11; lha 30,0x90(9); add 3,31,3; add 30,31,30; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; mr. 11,3; bne 1f; 0:; addi 3,1,8; li 4,2; bl _s800DEAE4_1; b 2f; 1:; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; bl _s800DEAE4_2; addi 3,1,8; li 4,2; bl _s800DEAE4_3; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800DEAE4_0();
extern "C" void _s800DEAE4_1();
extern "C" void _s800DEAE4_2();
extern "C" void _s800DEAE4_3();

struct cXObjectImpl {
    void UpdateChairFacing_ObjectModule();
};

void cXObjectImpl::UpdateChairFacing_ObjectModule() {
}
