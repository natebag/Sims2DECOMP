// 0x80149EE0 cGZSnd::operator (60 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="cmpwi 0,0; bne 0f; addi 3,13,-23964; bl _s80149EE0_0; li 0,1; lis 3,-32747; stw 0,-23960(13); addi 3,3,-27964; bl _s80149EE0_1; 0:; addi 3,13,-23964; bl _s80149EE0_2; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"

extern "C" void _s80149EE0_0();
extern "C" void _s80149EE0_1();
extern "C" void _s80149EE0_2();

struct cGZSnd {
    void operator();
};

void cGZSnd::operator() {
}
