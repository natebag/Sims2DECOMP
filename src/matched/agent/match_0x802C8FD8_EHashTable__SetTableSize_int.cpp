// 0x802C8FD8 EHashTable::SetTableSize(int) (144 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr 30,4; lwz 0,0xc(31); cmpw 0,30; beq 1f; bl _s802C8FD8_0; lwz 4,0x8(31); bl _s802C8FD8_1; mr 4,30; mr 3,31; bl _s802C8FD8_2; lwz 8,0x0(31); cmpwi 8,0; beq 1f; 0:; lwz 9,0xc(8); lwz 11,0xc(31); lwz 10,0x8(31); divwu 0,9,11; mullw 0,0,11; subf 9,0,9; rlwinm 9,9,2,0,29; lwzx 0,10,9; stw 0,0x8(8); stwx 8,10,9; lwz 8,0x4(8); cmpwi 8,0; bne 0b; 1:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s802C8FD8_0();
extern "C" void _s802C8FD8_1();
extern "C" void _s802C8FD8_2();
extern "C" void f_802C8FD8() {}
