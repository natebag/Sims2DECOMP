// 0x800F9820 ObjectModuleImpl::GetNumObjects(void) (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 0,16; li 11,0; mtspr 9,0; addi 9,3,8352; 0:; lwz 0,0x0(9); addi 9,9,4; cmpwi 0,0; beq 1f; addi 11,11,1; 1:; bdnz 0b; lwz 0,0x2090(3); lwz 3,0x2094(3); subf 3,0,3; srawi 3,3,2; add 3,3,11"
extern "C" int f_800F9820() {}
