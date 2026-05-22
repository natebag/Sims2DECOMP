// 0x8012C6E4 cXPersonImpl::CountActions(bool) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 10,3; cmplwi 4,0; addi 9,10,304; lwz 11,0x2a8(9); lwz 0,0x2ac(9); subf 3,11,0; bnelr; lwz 0,0x534(10); cmplwi 0,0; beqlr; addi 3,3,-1"
extern "C" int f_8012C6E4() {}
