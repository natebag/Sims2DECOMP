// 0x8025C37C stateReadingFST (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mfspr 0,8; lis 3,-32730; stw 0,0x4(1); addi 0,3,-15492; lis 3,-32694; stwu 1,-16(1); addi 3,3,-17248; stw 31,0xc(1); addi 31,3,8; stw 0,-23392(13); lwz 4,-23472(13); lwz 0,0x0(31); lwz 3,0x3c(4); cmplw 3,0; bge 0f; lis 3,-32700; crxor 6,6,6; addi 5,3,-14492; addi 3,13,-27780; li 4,661; bl _s8025C37C_0; 0:; lis 3,-32694; lwz 6,0x0(31); addi 5,3,-17248; lwz 7,-23472(13); lis 4,-32730; lwz 5,0x4(5); addi 0,6,31; lwz 3,0x38(7); addi 6,4,-15344; rlwinm 4,0,0,0,26; bl _s8025C37C_1; lwz 0,0x14(1); lwz 31,0xc(1); addi 1,1,16; mtspr 8,0"
extern "C" void _s8025C37C_0();
extern "C" void _s8025C37C_1();
extern "C" void f_8025C37C() {}
