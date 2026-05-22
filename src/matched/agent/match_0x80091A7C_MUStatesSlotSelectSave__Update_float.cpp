// 0x80091A7C MUStatesSlotSelectSave::Update(float) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,3; lwz 3,0x8(10); lwz 0,0x90(3); cmpwi 0,0; bne 0f; lis 9,-32696; li 4,2; stw 0,0x58d8(9); addi 11,9,22744; stw 0,0x8(11); lwz 3,0x8(10); bl _s80091A7C_0; b 2f; 0:; cmpwi 0,1; bne 1f; li 4,1; bl _s80091A7C_1; b 2f; 1:; cmpwi 0,2; bne 2f; li 4,2; bl _s80091A7C_2; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80091A7C_0();
extern "C" void _s80091A7C_1();
extern "C" void _s80091A7C_2();
extern "C" void f_80091A7C() {}
