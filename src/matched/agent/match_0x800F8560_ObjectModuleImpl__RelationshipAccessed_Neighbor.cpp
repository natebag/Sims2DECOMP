// 0x800F8560 ObjectModuleImpl::RelationshipAccessed(Neighbor (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; mr 31,5; cmpwi 7,0; beq 0f; lwz 11,-21476(13); lwz 9,0x0(11); lwz 0,0xfc(9); lha 3,0xf8(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21476(13); mr 4,31; lwz 9,0x0(11); lwz 0,0xfc(9); lha 3,0xf8(9); mtspr 8,0; add 3,11,3; blrl; li 0,1; stw 0,0x18(30); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void f_800F8560() {}
