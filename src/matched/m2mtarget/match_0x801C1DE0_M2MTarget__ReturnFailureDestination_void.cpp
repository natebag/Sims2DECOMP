// 0x801C1DE0 M2MTarget::ReturnFailureDestination(void) (228 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lwz 0,0x11c(31); cmpwi 0,15; bne 3f; lis 3,-32705; li 4,0; addi 3,3,8428; bl _s801C1DE0_0; lis 3,-32705; addi 3,3,-2032; bl _s801C1DE0_1; cmpwi 3,4; beq 2f; bgt 0f; cmpwi 3,2; beq 1f; b 6f; 0:; cmpwi 3,7; beq 2f; b 6f; 1:; lis 3,-32705; li 4,10; b 4f; 2:; lis 3,-32705; li 4,11; b 4f; 3:; lis 9,-32697; lwz 9,0x5bec(9); cmpwi 9,0; beq 5f; lwz 0,0xa4(9); cmpwi 0,2; bne 5f; lis 3,-32705; li 4,8; 4:; addi 3,3,8412; bl _s801C1DE0_2; b 6f; 5:; lwz 3,-32056(13); bl _s801C1DE0_3; lis 3,-32705; li 4,6; addi 3,3,8412; bl _s801C1DE0_4; 6:; mr 3,31; bl _s801C1DE0_5; li 0,3; stw 0,0x168(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s801C1DE0_0();
extern "C" void _s801C1DE0_1();
extern "C" void _s801C1DE0_2();
extern "C" void _s801C1DE0_3();
extern "C" void _s801C1DE0_4();
extern "C" void _s801C1DE0_5();

struct M2MTarget {
    void ReturnFailureDestination();
};

void M2MTarget::ReturnFailureDestination() {
}
