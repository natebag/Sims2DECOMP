// 0x8026AAEC AptAddToInputQueue(AptInputType, (92 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,-22988(13); mr 11,3; mr 10,4; mr 6,5; cmpwi 0,0; beq 0f; lis 9,-32694; lwz 0,-16052(9); cmpwi 0,0; bne 0f; lwz 3,-23008(13); cmpwi 3,0; beq 0f; mr 4,11; mr 5,10; bl _s8026AAEC_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8026AAEC_0();
extern "C" void f_8026AAEC() {}
