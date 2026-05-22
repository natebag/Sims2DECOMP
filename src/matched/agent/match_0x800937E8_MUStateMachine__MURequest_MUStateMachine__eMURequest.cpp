// 0x800937E8 MUStateMachine::MURequest(MUStateMachine::eMURequest) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,-21368(13); li 9,0; cmpwi 0,0; bne 0f; addi 0,3,-1; cmplwi 0,7; bgt 0f; stw 9,-21364(13); stw 9,-21372(13); stw 3,-21368(13); mr 9,3; 0:; mr 3,9"
extern "C" void f_800937E8() {}
