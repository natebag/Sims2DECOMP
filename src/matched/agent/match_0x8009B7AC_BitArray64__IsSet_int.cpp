// 0x8009B7AC BitArray64::IsSet(int) (80 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 5,4; lwz 4,0x4(3); lwz 3,0x0(3); crxor 6,6,6; bl _s8009B7AC_0; mr 11,3; mr 12,4; li 9,0; rlwinm 10,12,0,31,31; li 3,0; or. 0,9,10; beq 0f; li 3,1; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8009B7AC_0();
extern "C" void f_8009B7AC() {}
