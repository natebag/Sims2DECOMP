// 0x803129D8 EResPrefetch::Main(void) (152 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; addi 30,1,8; 0:; lwz 5,0x414(31); li 4,0; stw 4,0x8(1); addi 3,31,908; xori 5,5,1; mr 4,30; bl _s803129D8_0; cmpwi 3,0; beq 5f; lwz 4,0x8(1); lwz 0,0x0(4); cmpwi 0,1; beq 3f; bgt 1f; cmpwi 0,0; beq 2f; b 0b; 1:; cmpwi 0,2; beq 4f; b 0b; 2:; mr 3,31; bl _s803129D8_1; b 0b; 3:; mr 3,31; bl _s803129D8_2; b 0b; 4:; mr 3,31; bl _s803129D8_3; b 0b; 5:; mr 3,31; bl _s803129D8_4; b 0b"

extern "C" void _s803129D8_0();
extern "C" void _s803129D8_1();
extern "C" void _s803129D8_2();
extern "C" void _s803129D8_3();
extern "C" void _s803129D8_4();

struct EResPrefetch {
    void Main();
};

void EResPrefetch::Main() {
}
