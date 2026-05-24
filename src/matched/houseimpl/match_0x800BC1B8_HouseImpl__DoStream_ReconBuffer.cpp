// 0x800BC1B8 HouseImpl::DoStream(ReconBuffer (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 31,4; mr 30,5; addi 4,3,24; mr 3,31; bl _s800BC1B8_0; cmpwi 30,89; bgt 1f; addi 28,1,8; li 30,5; mr 29,28; 0:; mr 3,31; mr 4,29; li 5,1; bl _s800BC1B8_1; mr 3,31; mr 4,29; li 5,1; bl _s800BC1B8_2; addic. 30,30,-1; bne 0b; mr 3,31; mr 4,28; li 5,1; bl _s800BC1B8_3; mr 3,31; mr 4,28; li 5,1; bl _s800BC1B8_4; 1:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s800BC1B8_0();
extern "C" void _s800BC1B8_1();
extern "C" void _s800BC1B8_2();
extern "C" void _s800BC1B8_3();
extern "C" void _s800BC1B8_4();

struct HouseImpl {
    void DoStream_ReconBuffer();
};

void HouseImpl::DoStream_ReconBuffer() {
}
