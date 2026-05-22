// 0x80181F80 UIUserDrawCBTable::RemoveRecord(UIUserDrawCBTable::UserDrawCBTableRecord (204 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 9,0x0(4); mr 31,3; cmpwi 9,0; beq 0f; lwz 0,0x4(4); stw 0,0x4(9); 0:; lwz 9,0x4(4); cmpwi 9,0; beq 1f; lwz 0,0x0(4); stw 0,0x0(9); 1:; lwz 0,0x0(31); cmpw 0,4; bne 2f; lwz 0,0x4(4); stw 0,0x0(31); 2:; lwz 0,0x4(31); cmpw 0,4; bne 3f; lwz 0,0x0(4); stw 0,0x4(31); 3:; li 0,0; stw 0,0x4(4); stw 0,0x0(4); lwz 0,0x8(31); cmpwi 0,0; beq 4f; stw 0,0x4(4); lwz 9,0x8(31); stw 4,0x0(9); 4:; stw 4,0x8(31); lwz 9,0x8(31); lwz 3,0xc(9); cmpwi 3,0; beq 5f; bl _s80181F80_0; lwz 9,0x8(31); li 0,0; stw 0,0xc(9); 5:; lwz 9,0x8(31); li 0,0; stw 0,0x10(9); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80181F80_0();
extern "C" void f_80181F80() {}
