// 0x8038BF04 __GXGetNumXfbLines (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 0,3,-1; rlwinm 0,0,8,0,23; divwu 5,0,4; cmplwi 4,128; addi 5,5,1; ble 2f; cmplwi 4,256; bge 2f; b 1f; 0:; rlwinm 4,4,31,1,31; 1:; rlwinm. 0,4,0,31,31; beq 0b; divwu 0,3,4; mullw 0,0,4; subf. 0,0,3; bne 2f; addi 5,5,1; 2:; cmplwi 5,1024; ble 3f; li 5,1024; 3:; mr 3,5"
extern "C" int f_8038BF04() {}
