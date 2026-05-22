// 0x8034E174 ENGCAudioStreamer::Update(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32690; li 30,0; addi 31,9,-14064; 0:; lwz 9,0x74(31); andis. 0,9,32; bne 1f; lwz 0,0x0(31); cmpwi 0,5; bne 5f; andis. 0,9,64; bne 5f; lbz 0,0x75(31); andi. 9,0,16; bne 5f; 1:; lwz 9,0x1c(31); li 4,0; li 6,0; cmpwi 9,0; beq 4f; lwz 11,0x1b2(9); lwz 10,0x20(31); cmplw 11,10; bge 2f; lwz 0,0x70(31); rlwinm 6,0,31,1,31; 2:; lwz 0,0x18(31); lwz 9,0x6c(31); add 0,0,0; add 0,0,9; cmplw 11,0; blt 3f; cmplw 10,0; bge 3f; lwz 0,0x70(31); rlwinm 4,0,31,1,31; 3:; stw 11,0x20(31); 4:; li 3,0; li 5,0; mr 7,31; bl _s8034E174_0; 5:; addi 30,30,1; addi 31,31,120; cmplwi 30,1; ble 0b; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8034E174_0();
extern "C" void f_8034E174() {}
