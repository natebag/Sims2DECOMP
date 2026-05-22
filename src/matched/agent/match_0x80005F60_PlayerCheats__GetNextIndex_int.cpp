// 0x80005F60 PlayerCheats::GetNextIndex(int (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,0x0(4); addi 9,9,1; cmpwi 9,5; stw 9,0x0(4); ble 0f; li 0,0; stw 0,0x0(4); 0:; lwz 3,0x0(4)"
extern "C" void f_80005F60() {}
