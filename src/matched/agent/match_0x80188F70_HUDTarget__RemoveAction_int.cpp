// 0x80188F70 HUDTarget::RemoveAction(int, (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mulli 9,4,796; mr 10,3; li 11,1; add 9,9,10; lwz 0,0x10c(9); cmpwi 0,0; bne 0f; li 11,0; 0:; cmpwi 11,0; beq 1f; mulli 3,4,796; mr 4,5; addi 3,3,264; add 3,10,3; bl _s80188F70_0; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80188F70_0();
extern "C" void f_80188F70() {}
