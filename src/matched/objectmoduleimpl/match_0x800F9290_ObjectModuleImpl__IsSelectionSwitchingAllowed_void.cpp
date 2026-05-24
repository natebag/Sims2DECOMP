// 0x800F9290 ObjectModuleImpl::IsSelectionSwitchingAllowed(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-21476(13); cmpwi 0,0; beq 0f; lis 9,-32697; addi 9,9,23428; lwz 0,0xe8(9); cmpwi 0,0; bne 1f; lwz 0,0xf0(9); cmpwi 0,0; bne 1f; lwz 11,-21496(13); cmpwi 11,0; beq 0f; lwz 9,0x0(11); lha 3,0xe8(9); lwz 0,0xec(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,91; bgt 1f; 0:; li 3,0; b 2f; 1:; li 3,1; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

struct ObjectModuleImpl {
    void IsSelectionSwitchingAllowed();
};

void ObjectModuleImpl::IsSelectionSwitchingAllowed() {
}
