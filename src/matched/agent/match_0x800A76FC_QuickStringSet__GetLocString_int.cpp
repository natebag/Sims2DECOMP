// 0x800A76FC QuickStringSet::GetLocString(int) (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x4(4); cmpwi 9,0; beq 3f; cmpwi 5,0; ble 1f; lwz 11,0x0(9); li 0,0; cmpwi 11,0; beq 0f; lwz 0,-4(11); 0:; cmpw 5,0; ble 2f; 1:; lwz 0,0xc(4); stw 0,0x0(3); blr; 2:; addi 9,5,-1; rlwinm 9,9,2,0,29; lwzx 0,11,9; stw 0,0x0(3); blr; 3:; lwz 0,0xc(4); stw 0,0x0(3)"
extern "C" void f_800A76FC() {}
