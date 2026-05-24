// 0x800F3BF0 ObjectModuleImpl::DoReconPerson(ReconBuffer (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,5; mr 11,3; lwz 9,0x0(31); mr 30,4; cmpwi 9,0; beq 0f; lwz 0,0x0(9); stw 0,0x8(1); b 1f; 0:; stw 9,0x8(1); 1:; lwz 9,0x0(11); mr 4,30; addi 5,1,8; lwz 0,0x1dc(9); lha 3,0x1d8(9); mtspr 8,0; add 3,11,3; blrl; lwz 0,0xc(30); cmpwi 0,0; bne 3f; lwz 9,0x8(1); cmpwi 9,0; beq 2f; lwz 9,0x4(9); li 4,7; lwz 3,0x0(9); bl _s800F3BF0_0; stw 3,0x0(31); b 3f; 2:; stw 9,0x0(31); 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s800F3BF0_0();

struct ObjectModuleImpl {
    void DoReconPerson();
};

void ObjectModuleImpl::DoReconPerson() {
}
