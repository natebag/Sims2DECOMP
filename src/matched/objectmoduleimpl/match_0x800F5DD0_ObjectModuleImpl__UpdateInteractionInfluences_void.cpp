// 0x800F5DD0 ObjectModuleImpl::UpdateInteractionInfluences(void) (168 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 11,-21488(13); mr 30,3; lwz 9,0x0(11); lwz 0,0xdc(9); lha 3,0xd8(9); mtspr 8,0; add 3,11,3; blrl; mr 31,3; bl _s800F5DD0_0; lwz 9,0x0(30); lha 3,0x98(9); lwz 0,0x9c(9); b 2f; 0:; lwz 9,0x4(30); lha 3,0x4a8(9); lwz 0,0x4ac(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; bne 1f; mr 3,31; mr 4,30; bl _s800F5DD0_1; 1:; lwz 9,0x4(30); lha 3,0x490(9); lwz 0,0x494(9); 2:; add 3,30,3; mtspr 8,0; blrl; mr. 30,3; bne 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800F5DD0_0();
extern "C" void _s800F5DD0_1();

struct ObjectModuleImpl {
    void UpdateInteractionInfluences();
};

void ObjectModuleImpl::UpdateInteractionInfluences() {
}
