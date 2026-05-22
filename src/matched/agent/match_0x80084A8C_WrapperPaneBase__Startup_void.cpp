// 0x80084A8C WrapperPaneBase::Startup(void) (40 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 0,0x8(3); li 10,7; mtspr 9,10; li 11,0; stw 0,0xc(3); addi 9,3,88; 0:; stw 11,0x0(9); addi 9,9,-4; bdnz 0b"
extern "C" void f_80084A8C() {}
