// 0x8026D7C8 UI2D::UI2DRecord::~UI2DRecord(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="sth 9,0x0(4); cmpwi 0,0; bne 0f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026D7C8_0; 0:; li 3,0; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s8026D7C8_0();
extern "C" void f_8026D7C8() {}
