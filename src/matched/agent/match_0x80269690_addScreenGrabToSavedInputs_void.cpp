// 0x80269690 _addScreenGrabToSavedInputs(void) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); lwz 0,-27608(13); cmpwi 0,0; beq 0f; lwz 5,-23012(13); lis 4,-32704; addi 4,4,3432; addi 3,1,8; crxor 6,6,6; bl _s80269690_0; lis 30,-32694; addi 3,1,8; addi 30,30,-16288; lwz 9,0x1c(30); mtspr 8,9; blrl; lwz 10,0x18(30); addi 11,1,24; lwz 9,-23012(13); mr 3,11; li 4,5; mtspr 8,10; li 0,3; stw 9,0x18(1); stw 0,0x4(11); blrl; 0:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s80269690_0();
extern "C" void f_80269690() {}
