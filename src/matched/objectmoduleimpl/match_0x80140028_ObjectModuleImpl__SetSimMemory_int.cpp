// 0x80140028 ObjectModuleImpl::SetSimMemory(int, (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 26,0x18(1); stw 0,0x34(1); mr 26,3; mr 28,4; mr 27,5; mr 29,6; li 0,0; mr 30,7; stw 0,0x8(1); addi 6,1,12; addi 5,1,8; mr 3,28; mr 4,27; bl _s80140028_0; lwz 11,0x8(1); li 5,2; lwz 4,0xc(1); lwz 9,0x0(11); lwz 0,0x44(9); lha 3,0x40(9); mtspr 8,0; add 3,11,3; blrl; stw 3,0x10(1); mr 4,29; addi 3,1,16; mr 5,30; bl _s80140028_1; lwz 11,0x8(1); li 5,2; lwz 6,0x10(1); lwz 9,0x0(11); lwz 4,0xc(1); lwz 0,0x4c(9); lha 3,0x48(9); mtspr 8,0; add 3,11,3; blrl; lwz 30,-21476(13); mr 4,28; lwz 9,0x0(30); lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(30); mr 29,3; mr 4,27; lwz 0,0xbc(9); lha 3,0xb8(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(26); mr 5,3; mr 4,29; li 6,2; lha 3,0x1a8(9); li 7,1; lwz 0,0x1ac(9); add 3,26,3; mtspr 8,0; blrl; lwz 0,0x34(1); mtspr 8,0; lmw 26,0x18(1); addi 1,1,48"

extern "C" void _s80140028_0();
extern "C" void _s80140028_1();

struct ObjectModuleImpl {
    void SetSimMemory();
};

void ObjectModuleImpl::SetSimMemory() {
}
