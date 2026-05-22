// 0x8030A5A0 GetChar(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-26688(13); lwz 0,-26684(13); cmpw 9,0; beq 0f; addi 9,13,-26688; lwz 11,0x0(9); lbz 3,0x0(11); addi 11,11,1; stw 11,0x0(9); blr; 0:; li 3,-1"
extern "C" void f_8030A5A0() {}
