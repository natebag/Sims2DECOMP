// 0x8036EAF0 strlwr (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lbz 0,0x0(3); mr 10,3; cmpwi 0,0; beqlr; lis 9,-32704; addi 8,9,-935; 0:; lbz 0,0x0(10); extsb 11,0; lbzx 9,11,8; andi. 0,9,1; beq 1f; addi 0,11,32; stb 0,0x0(10); 1:; lbzu 0,0x1(10); cmpwi 0,0; bne 0b"
extern "C" void f_8036EAF0() {}
