// 0x800F5A98 ObjectModuleImpl::DayChanged(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x0(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; b 1f; 0:; lwz 9,0x4(31); lwz 0,0x524(9); lha 3,0x520(9); mtspr 8,0; add 3,31,3; blrl; bl _s800F5A98_0; lwz 9,0x4(31); lha 3,0x490(9); lwz 0,0x494(9); add 3,31,3; mtspr 8,0; 1:; blrl; mr. 31,3; bne 0b; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s800F5A98_0();

struct ObjectModuleImpl {
    void DayChanged();
};

void ObjectModuleImpl::DayChanged() {
}
