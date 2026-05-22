// 0x80177F4C GetVariableCommandTable::RemoveRecord(GetVariableCommandTable::GetVariableCommandTableRecord (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(4); cmpwi 9,0; beq 0f; lwz 0,0x4(4); stw 0,0x4(9); 0:; lwz 9,0x4(4); cmpwi 9,0; beq 1f; lwz 0,0x0(4); stw 0,0x0(9); 1:; lwz 0,0x0(3); cmpw 0,4; bne 2f; lwz 0,0x4(4); stw 0,0x0(3); 2:; lwz 0,0x4(3); cmpw 0,4; bne 3f; lwz 0,0x0(4); stw 0,0x4(3); 3:; li 0,0; stw 0,0x4(4); stw 0,0x0(4); lwz 0,0x8(3); cmpwi 0,0; beq 4f; stw 0,0x4(4); lwz 9,0x8(3); stw 4,0x0(9); 4:; stw 4,0x8(3); lwz 9,0x8(3); li 0,0; stw 0,0x8(9); lwz 11,0x8(3); stw 0,0xc(11)"
extern "C" void f_80177F4C() {}
