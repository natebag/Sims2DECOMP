// 0x800F9384 ObjectModuleImpl::IsValidPerson(cXPerson (176 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lwz 9,0x0(3); mr 30,4; lha 0,0x98(9); lwz 9,0x9c(9); add 3,3,0; mtspr 8,9; b 4f; 0:; lwz 9,0x4(31); lha 3,0x4a8(9); lwz 0,0x4ac(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 3f; cmpwi 31,0; beq 1f; lwz 3,0x0(31); li 4,2; bl _s800F9384_0; b 2f; 1:; li 3,0; 2:; cmpw 3,30; bne 3f; li 3,1; b 5f; 3:; lwz 9,0x4(31); lha 3,0x490(9); lwz 0,0x494(9); add 3,31,3; mtspr 8,0; 4:; blrl; mr. 31,3; bne 0b; li 3,0; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s800F9384_0();

struct ObjectModuleImpl {
    void IsValidPerson();
};

void ObjectModuleImpl::IsValidPerson() {
}
