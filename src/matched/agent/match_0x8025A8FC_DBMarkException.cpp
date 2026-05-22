// 0x8025A8FC __DBMarkException (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,0; rlwinm 0,3,0,24,31; li 3,1; slw 4,3,0; beq 0f; lwz 3,-23520(13); addi 3,3,4; lwz 0,0x0(3); or 0,0,4; stw 0,0x0(3); b 1f; 0:; lwz 3,-23520(13); addi 3,3,4; lwz 0,0x0(3); andc 0,0,4; stw 0,0x0(3); 1:"
extern "C" void f_8025A8FC() {}
