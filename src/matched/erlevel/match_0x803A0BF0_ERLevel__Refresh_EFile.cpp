// 0x803A0BF0 ERLevel::Refresh(EFile (464 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stw 11,0x20(1); stw 8,0x24(1); stw 30,0x28(1); stw 5,0x2c(1); stw 6,0x30(1); stw 7,0x34(1); stw 10,0x38(1); stw 11,0x40(1); stw 8,0x44(1); bl _s803A0BF0_0; andi. 0,29,1; beq 0f; mr 3,31; bl _s803A0BF0_1; 0:; lwz 0,0x7c(1); mtspr 8,0; lmw 29,0x6c(1); addi 1,1,120; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-13880; stw 9,0x18(3); beq 1f; bl _s803A0BF0_2; 1:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-13880; stw 9,0x18(3); beq 2f; bl _s803A0BF0_3; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-13880; stw 9,0x18(3); beq 3f; bl _s803A0BF0_4; 3:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-13880; stw 9,0x18(3); beq 4f; bl _s803A0BF0_5; 4:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-112(1); stw 4,0xc(1); stw 5,0x10(1); stw 6,0x14(1); stw 7,0x18(1); stw 8,0x1c(1); stw 9,0x20(1); stw 10,0x24(1); bne cr1,5f; stfd f1,0x28(1); stfd f2,0x30(1); stfd f3,0x38(1); stfd f4,0x40(1); stfd f5,0x48(1); stfd f6,0x50(1); stfd f7,0x58(1); stfd f8,0x60(1); 5:; addi 1,1,112; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-13880; stw 9,0x18(3); beq 6f; bl _s803A0BF0_6; 6:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8; blr; stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 9,-32698; andi. 0,4,1; addi 9,9,-13880; stw 9,0x18(3); beq 7f; bl _s803A0BF0_7; 7:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s803A0BF0_0();
extern "C" void _s803A0BF0_1();
extern "C" void _s803A0BF0_2();
extern "C" void _s803A0BF0_3();
extern "C" void _s803A0BF0_4();
extern "C" void _s803A0BF0_5();
extern "C" void _s803A0BF0_6();
extern "C" void _s803A0BF0_7();

struct ERLevel {
    void Refresh_EFile();
};

void ERLevel::Refresh_EFile() {
}
