// 0x802D87EC EA::Allocator::MemoryFillCheck(unsigned (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="rlwinm 0,4,0,0,29; add 8,3,4; add 10,3,0; cmplwi 4,3; ble 4f; andi. 0,3,3; bne 4f; rlwinm 9,5,16,0,15; rlwinm 0,5,24,0,7; or 0,0,9; rlwinm 11,5,8,0,23; or 0,0,11; cmplw 3,10; or 9,0,5; bge 4f; 0:; lwz 0,0x0(3); addi 3,3,4; cmpw 0,9; beq 2f; 1:; li 3,0; blr; 2:; cmplw 3,10; blt 0b; b 4f; 3:; lbz 0,0x0(3); addi 3,3,1; cmpw 0,5; bne 1b; 4:; cmplw 3,8; blt 3b; li 3,1"
extern "C" int f_802D87EC() {}
