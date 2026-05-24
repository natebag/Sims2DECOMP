// 0x800F59B4 ObjectModuleImpl::PostSim(bool) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; cmpwi 4,0; bne 0f; bl _s800F59B4_0; lwz 0,0x18(31); cmpwi 0,0; beq 0f; lwz 11,-21496(13); lwz 9,0x0(11); lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,11,3; blrl; lis 0,26214; srawi 9,3,31; ori 0,0,26215; mulhw 0,3,0; srawi 0,0,4; subf 0,9,0; mulli 0,0,40; subf. 30,0,3; bne 0f; lwz 3,-21476(13); lwz 9,0x0(3); lha 0,0x108(9); lwz 9,0x10c(9); add 3,3,0; mtspr 8,9; blrl; stw 30,0x18(31); 0:; lwz 9,0x0(31); li 4,0; lha 3,0x118(9); lwz 0,0x11c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; lwz 9,0x0(31); li 4,0; lha 3,0x120(9); lwz 0,0x124(9); add 3,31,3; mtspr 8,0; blrl; 1:; li 3,0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800F59B4_0();

struct ObjectModuleImpl {
    void PostSim();
};

void ObjectModuleImpl::PostSim() {
}
