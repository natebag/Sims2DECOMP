// 0x800DD338 cXObjectImpl::HierGetObject(HierarchySite (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); lwz 0,0x0(4); mr 30,3; cmpwi 0,0; li 3,0; beq 2f; lwz 3,0xc(4); cmpwi 3,0; beq 0f; lwz 4,0x10(4); bl _s800DD338_0; b 2f; 0:; lwz 5,0x14(4); addi 0,5,-1; cmplwi 0,2; bgt 1f; addi 3,1,8; addi 4,4,4; bl _s800DD338_1; lwz 10,-21484(13); addi 4,1,8; lwz 30,0x4(30); lwz 9,0x0(10); lwz 11,0x4(30); lha 3,0x250(9); lwz 9,0x254(9); addi 29,11,1160; add 3,10,3; lha 0,0x488(11); mtspr 8,9; add 30,30,0; blrl; lwz 0,0x4(29); mr 4,3; mr 3,30; mtspr 8,0; blrl; mr 30,3; li 4,2; addi 3,1,8; bl _s800DD338_2; mr 3,30; b 2f; 1:; li 3,0; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800DD338_0();
extern "C" void _s800DD338_1();
extern "C" void _s800DD338_2();

struct cXObjectImpl {
    void HierGetObject_HierarchySite();
};

void cXObjectImpl::HierGetObject_HierarchySite() {
}
