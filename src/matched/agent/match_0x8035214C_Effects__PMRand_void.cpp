// 0x8035214C Effects::PMRand(void) (68 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22460(13); rlwinm 9,0,16,16,31; mulli 9,9,16807; rlwinm 0,0,0,16,31; mulli 0,0,16807; rlwinm 11,9,16,1,15; rlwinm 9,9,17,15,31; add 0,0,11; add 9,0,9; stw 9,-22460(13); cmpwi 9,0; bge 0f; addis 9,9,-32768; addi 9,9,1; stw 9,-22460(13); 0:; lwz 3,-22460(13)"
extern "C" void f_8035214C() {}
