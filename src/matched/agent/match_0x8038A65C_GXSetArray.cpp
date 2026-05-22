// 0x8038A65C GXSetArray (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 3,25; bne 0f; li 3,10; 0:; li 7,8; addi 3,3,-9; lis 6,-13311; stb 7,-32768(6); ori 0,3,160; rlwinm 4,4,0,2,31; stb 0,-32768(6); ori 3,3,176; rlwinm 0,5,0,24,31; stw 4,-32768(6); stb 7,-32768(6); stb 3,-32768(6); stw 0,-32768(6)"
extern "C" void f_8038A65C() {}
