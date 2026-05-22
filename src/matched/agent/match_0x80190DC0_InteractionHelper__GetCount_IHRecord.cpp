// 0x80190DC0 InteractionHelper::GetCount(IHRecord (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,0; mr. 4,4; beqlr; 0:; lwz 0,0x8(4); addi 3,3,1; cmpwi 0,0; bne 1f; lwz 4,0x4(4); b 2f; 1:; lwz 4,0xc(4); 2:; cmpwi 4,0; bne 0b"
extern "C" int f_80190DC0() {}
