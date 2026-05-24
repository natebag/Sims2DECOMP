// 0x800F3A5C ObjectModuleImpl::SelectPlayerSims(void) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32697; li 31,0; addi 9,9,23428; lis 27,-32697; addi 28,9,208; 0:; lwz 0,0x0(28); li 30,0; addi 28,28,4; mr 4,0; cmpwi 0,0; beq 1f; lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0xb8(9); lwz 0,0xbc(9); add 3,11,3; mtspr 8,0; blrl; mr. 3,3; beq 1f; lwz 29,-21484(13); lwz 30,0x0(29); lha 0,0xe8(30); addi 30,30,232; add 29,29,0; bl _s800F3A5C_0; lwz 0,0x4(30); mr 4,3; mr 3,29; mtspr 8,0; blrl; mr 30,3; 1:; mr 4,31; mr 5,30; addi 3,27,24012; addi 31,31,1; bl _s800F3A5C_1; cmpwi 31,2; blt 0b; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800F3A5C_0();
extern "C" void _s800F3A5C_1();

struct ObjectModuleImpl {
    void SelectPlayerSims();
};

void ObjectModuleImpl::SelectPlayerSims() {
}
