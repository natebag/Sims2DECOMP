// 0x801CF704 O2TTarget::OnXKeyPressed(char (124 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lwz 0,0x88(3); cmpwi 0,0; bne 2f; lwz 3,0x9c(3); cmpwi 3,0; beq 0f; cmpwi 3,1; beq 1f; b 2f; 0:; lis 3,-32705; li 4,4; addi 3,3,-2032; bl _s801CF704_0; lis 3,-32705; addi 3,3,-2020; bl _s801CF704_1; b 2f; 1:; lis 3,-32705; li 4,7; addi 3,3,-2032; bl _s801CF704_2; lis 3,-32705; addi 3,3,-2020; bl _s801CF704_3; 2:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s801CF704_0();
extern "C" void _s801CF704_1();
extern "C" void _s801CF704_2();
extern "C" void _s801CF704_3();

struct O2TTarget {
    void OnXKeyPressed();
};

void O2TTarget::OnXKeyPressed() {
}
