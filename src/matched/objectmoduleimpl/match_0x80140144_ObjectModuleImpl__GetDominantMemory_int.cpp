// 0x80140144 ObjectModuleImpl::GetDominantMemory(int, (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 3,4; li 0,0; mr 4,5; mr 28,6; addi 5,1,8; stw 0,0x8(1); addi 6,1,12; li 29,-1; bl _s80140144_0; li 31,0; lwz 11,0x8(1); li 5,2; lwz 4,0xc(1); lwz 9,0x0(11); lha 3,0x40(9); lwz 0,0x44(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; b 1f; 0:; addi 31,31,1; 1:; cmpwi 31,7; bgt 2f; mr 3,30; mr 4,31; bl _s80140144_1; cmpw 3,28; blt 0b; mr 29,31; 2:; mr 3,29; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s80140144_0();
extern "C" void _s80140144_1();

struct ObjectModuleImpl {
    void GetDominantMemory();
};

void ObjectModuleImpl::GetDominantMemory() {
}
