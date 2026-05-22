// 0x80371CF4 OSUTF32to16 (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmplwi 3,55296; blt 0f; cmplwi 3,57343; bgt 0f; li 3,0; blr; 0:; lis 6,1; cmplw 3,6; bge 1f; sth 3,0x0(4); addi 3,4,2; blr; 1:; lis 5,17; addi 0,5,-1; cmplw 3,0; bgt 2f; addis 3,3,-1; addi 5,6,-10240; rlwinm 0,3,22,10,31; or 5,5,0; sth 5,0x0(4); addi 5,6,-9216; rlwinm 0,3,0,22,31; or 5,5,0; addi 3,4,2; sth 5,0x2(4); addi 3,3,2; blr; 2:; li 3,0"
extern "C" void f_80371CF4() {}
