// 0x80048714 ObjectList::RemoveObject(cXObject (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 3,0x0(31); lwz 0,0x4(31); cmpw 3,0; beq 3f; 0:; lwz 0,0x0(3); cmpw 0,4; bne 2f; lwz 5,0x4(31); addi 4,3,4; cmpw 4,5; beq 1f; cmpw 5,4; beq 1f; subf 5,4,5; bl _s80048714_0; 1:; lwz 9,0x4(31); addi 9,9,-4; stw 9,0x4(31); b 3f; 2:; lwz 0,0x4(31); addi 3,3,4; cmpw 3,0; bne 0b; 3:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80048714_0();
extern "C" void f_80048714() {}
