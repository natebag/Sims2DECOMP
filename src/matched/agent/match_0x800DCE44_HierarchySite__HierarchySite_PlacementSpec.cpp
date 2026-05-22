// 0x800DCE44 HierarchySite::HierarchySite(PlacementSpec (76 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x0(4); mr 11,3; stw 0,0x0(11); lwz 9,0x10(4); stw 9,0x10(11); cmpwi 9,-1; beq 0f; addi 0,9,1; stw 0,0x10(11); 0:; lwz 9,0x4(4); lwz 10,0x8(4); mr 3,11; stw 9,0x4(11); stw 10,0x8(11); lwz 0,0x14(4); stw 0,0x14(11); lwz 9,0xc(4); stw 9,0xc(11)"
extern "C" void f_800DCE44() {}
