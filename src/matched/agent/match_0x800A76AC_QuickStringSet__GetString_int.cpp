// 0x800A76AC QuickStringSet::GetString(int, (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x8(3); cmpwi 9,0; beq 3f; cmpwi 4,0; ble 1f; lwz 11,0x0(9); li 0,0; cmpwi 11,0; beq 0f; lwz 0,-4(11); 0:; cmpw 4,0; ble 2f; 1:; li 3,0; blr; 2:; addi 9,4,-1; rlwinm 9,9,2,0,29; lwzx 3,11,9; blr; 3:; li 3,0"
extern "C" int f_800A76AC() {}
