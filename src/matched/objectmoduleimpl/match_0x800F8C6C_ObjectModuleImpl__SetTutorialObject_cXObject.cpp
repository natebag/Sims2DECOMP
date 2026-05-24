// 0x800F8C6C ObjectModuleImpl::SetTutorialObject(cXObject (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr. 4,4; beq 0f; lwz 9,0x4(4); lha 3,0x520(9); lwz 0,0x524(9); add 3,4,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; lwz 0,0x2088(31); mr 9,0; cmpwi 0,0; beq 2f; cmpwi 3,0; beq 2f; li 3,0; b 4f; 2:; cmpw 9,3; beq 3f; stw 3,0x2088(31); li 4,0; li 3,259; bl _s800F8C6C_0; 3:; li 3,1; 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s800F8C6C_0();

struct ObjectModuleImpl {
    void SetTutorialObject_cXObject();
};

void ObjectModuleImpl::SetTutorialObject_cXObject() {
}
