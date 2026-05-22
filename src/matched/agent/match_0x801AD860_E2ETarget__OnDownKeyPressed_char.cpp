// 0x801AD860 E2ETarget::OnDownKeyPressed(char (64 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 9,0xa8(3); addi 9,9,-1; cmpwi 9,0; stw 9,0xa8(3); bge 0f; lwz 9,0xac(3); addi 9,9,-1; stw 9,0xa8(3); 0:; bl _s801AD860_0; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s801AD860_0();
extern "C" void f_801AD860() {}
