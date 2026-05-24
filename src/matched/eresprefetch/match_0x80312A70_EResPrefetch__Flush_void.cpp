// 0x80312A70 EResPrefetch::Flush(void) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-64(1); mfspr 0,8; stmw 30,0x38(1); stw 0,0x44(1); mr 31,3; lwz 0,0x414(31); cmpwi 0,0; beq 0f; addi 30,1,8; mr 3,30; bl _s80312A70_0; li 4,1; li 5,0; mr 3,30; bl _s80312A70_1; li 11,0; li 0,2; li 9,-1; addi 4,1,32; stw 0,0x20(1); li 5,1; stw 11,0x28(1); addi 3,31,908; stw 9,0x24(1); stw 30,0x30(1); stw 11,0x2c(1); bl _s80312A70_2; li 4,-1; mr 3,30; bl _s80312A70_3; mr 3,30; bl _s80312A70_4; mr 3,30; li 4,2; bl _s80312A70_5; 0:; lwz 0,0x44(1); mtspr 8,0; lmw 30,0x38(1); addi 1,1,64"

extern "C" void _s80312A70_0();
extern "C" void _s80312A70_1();
extern "C" void _s80312A70_2();
extern "C" void _s80312A70_3();
extern "C" void _s80312A70_4();
extern "C" void _s80312A70_5();

struct EResPrefetch {
    void Flush();
};

void EResPrefetch::Flush() {
}
