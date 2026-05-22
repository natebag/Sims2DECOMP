// 0x8037B9B0 __AXGetCurrentProfile (72 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-22076(13); cmplwi 0,0; beq 0f; lwz 3,-22080(13); lwz 4,-22084(13); addi 0,3,1; lwz 6,-22088(13); stw 0,-22080(13); mulli 0,3,56; lwz 5,-22080(13); add 3,6,0; divwu 0,5,4; mullw 0,0,4; subf 0,0,5; stw 0,-22080(13); blr; 0:; li 3,0"
extern "C" void f_8037B9B0() {}
