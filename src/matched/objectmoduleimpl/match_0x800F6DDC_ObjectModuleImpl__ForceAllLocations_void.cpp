// 0x800F6DDC ObjectModuleImpl::ForceAllLocations(void) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x0(3); lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; b 1f; 0:; lwz 9,0x4(31); lwz 0,0x1c4(9); lha 3,0x1c0(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x4(31); lha 3,0x490(9); lwz 0,0x494(9); add 3,31,3; mtspr 8,0; 1:; blrl; mr. 31,3; bne 0b; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

struct ObjectModuleImpl {
    void ForceAllLocations();
};

void ObjectModuleImpl::ForceAllLocations() {
}
