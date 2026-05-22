// 0x800C58CC cXMTObjectImpl::SetLeader(cXMTObject (140 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; mr. 4,4; beq 0f; lwz 9,0x4(4); lha 3,0x58(9); lwz 0,0x5c(9); add 3,4,3; mtspr 8,0; blrl; b 1f; 0:; li 3,0; 1:; li 0,0; stw 3,0xc(31); stw 0,0x8(31); cmpwi 3,0; beq 4f; lwz 0,0x8(3); addi 3,3,8; cmpwi 0,0; beq 3f; 2:; lwz 9,0x0(3); lwz 0,0x8(9); addi 3,9,8; cmpwi 0,0; bne 2b; 3:; stw 31,0x0(3); 4:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void f_800C58CC() {}
