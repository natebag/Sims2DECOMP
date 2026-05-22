// 0x8012B5A0 cXPersonImpl::InvalidateRoutes(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="addi 11,3,1036; lwz 9,0x40c(3); lwz 0,0x4(11); cmpw 9,0; beqlr; mr 3,11; li 11,0; 0:; stw 11,0x7c(9); addi 9,9,164; lwz 0,0x4(3); cmpw 9,0; bne 0b"
extern "C" void f_8012B5A0() {}
