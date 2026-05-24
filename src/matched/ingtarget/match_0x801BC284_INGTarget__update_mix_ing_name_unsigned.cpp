// 0x801BC284 INGTarget::update_mix_ing_name(unsigned (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stw 0,0x2c(1); mr 5,4; cmplwi 5,3; bgt 0f; lis 4,-32705; addi 5,5,1; addi 4,4,-8800; addi 3,1,8; crxor 6,6,6; bl _s801BC284_0; lwz 3,-25136(13); lis 4,-32705; addi 4,4,6616; li 5,0; li 6,0; li 7,1; addi 8,1,8; crxor 6,6,6; bl _s801BC284_1; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x2c(1); mtspr 8,0; addi 1,1,40"

extern "C" void _s801BC284_0();
extern "C" void _s801BC284_1();

struct INGTarget {
    void update_mix_ing_name();
};

void INGTarget::update_mix_ing_name() {
}
