// 0x80149D74 __node_alloc<false, (172 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sth 0,0x110(3); blr; lha 0,0x114(3); cmpwi 7,0,99; mfcr 3; rlwinm 3,3,30,31,31; blr; li 3,16; blr; rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4; addi 3,3,8; blr; rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4; addi 3,3,6; blr; rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4; addi 3,3,4; blr; rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4; addi 3,3,8; blr; rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4; addi 3,3,6; blr; rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4; addi 3,3,4; blr; rlwinm 4,4,4,0,27; addi 4,4,8; add 3,3,4"
extern "C" void f_80149D74() {}
