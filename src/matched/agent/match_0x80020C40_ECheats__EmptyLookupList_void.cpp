// 0x80020C40 ECheats::EmptyLookupList(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,3; li 9,0; li 28,0; 0:; rlwinm 0,9,2,0,29; addi 30,9,1; lwzx 31,29,0; cmpwi 31,0; beq 2f; stwx 28,29,0; 1:; mr 3,31; lwz 31,0x0(31); bl _s80020C40_0; cmpwi 31,0; bne 1b; 2:; mr 9,30; cmpwi 9,63; ble 0b; li 0,0; stw 0,0x100(29); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s80020C40_0();
extern "C" void f_80020C40() {}
