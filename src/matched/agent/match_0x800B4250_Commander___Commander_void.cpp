// 0x800B4250 Commander::~Commander(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; addi 11,13,-32076; addi 9,9,-5144; stw 9,0xc(3); b 2f; 0:; lwz 0,0x0(11); cmpw 0,3; bne 1f; lwz 0,0x0(3); stw 0,0x0(11); b 3f; 1:; mr 11,0; 2:; lwz 0,0x0(11); cmpwi 0,0; bne 0b; 3:; andi. 0,4,1; beq 4f; bl _s800B4250_0; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s800B4250_0();
extern "C" void f_800B4250() {}
