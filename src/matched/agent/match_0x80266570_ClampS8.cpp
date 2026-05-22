// 0x80266570 ClampS8 (84 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="extsb. 0,4; ble 0f; extsb 5,4; addi 0,5,-128; extsb 5,0; extsb 0,3; cmpw 0,5; bge 1f; mr 3,5; b 1f; 0:; extsb. 0,4; bge 1f; extsb 5,4; addi 0,5,127; extsb 5,0; extsb 0,3; cmpw 5,0; bge 1f; mr 3,5; 1:; subf 3,4,3"
extern "C" int f_80266570() {}
