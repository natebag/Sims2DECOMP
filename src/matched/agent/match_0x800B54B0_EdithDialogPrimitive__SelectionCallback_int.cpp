// 0x800B54B0 EdithDialogPrimitive::SelectionCallback(int) (36 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 4,-1; stw 4,0x88(3); bne 0f; lwz 9,0x0(3); addi 9,9,-1; stw 9,0x88(3); 0:; li 0,1; sth 0,-31828(13)"
extern "C" void f_800B54B0() {}
