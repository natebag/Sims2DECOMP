// 0x8012AD28 cXPersonImpl::DeleteTopAction(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x534(3); li 11,0; cmpwi 0,0; beq 0f; li 11,1; 0:; addi 9,3,304; lwz 4,0x2a8(9); lwz 0,0x2ac(9); subf 0,4,0; cmplw 0,11; ble 1f; lis 0,-13108; add 4,4,11; ori 0,0,52429; mulhwu 0,4,0; rlwinm 0,0,29,3,31; mulli 0,0,10; subf 4,0,4; mulli 4,4,68; add 4,9,4; bl _s8012AD28_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8012AD28_0();
extern "C" void f_8012AD28() {}
