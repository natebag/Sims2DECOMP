// 0x800E04CC cXObjectImpl::ReconHeader(ReconBuffer (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,3; mr 31,4; mr 29,5; mr 3,31; addi 4,30,120; li 5,1; bl _s800E04CC_0; mr 3,31; addi 4,30,124; li 5,1; bl _s800E04CC_1; mr 3,31; addi 4,30,112; li 5,1; bl _s800E04CC_2; mr 3,31; addi 4,30,116; li 5,1; bl _s800E04CC_3; mr 3,31; addi 4,30,108; li 5,1; bl _s800E04CC_4; mr 3,31; addi 4,30,104; li 5,1; bl _s800E04CC_5; cmpwi 29,24; ble 0f; mr 3,31; addi 4,30,128; li 5,1; bl _s800E04CC_6; 0:; cmpwi 29,46; bgt 1f; mr 3,31; addi 4,30,100; li 5,1; bl _s800E04CC_7; 1:; li 0,1; mr 3,31; sth 0,0x8(1); addi 4,1,8; li 5,1; bl _s800E04CC_8; cmpwi 29,55; bne 2f; mr 3,31; addi 4,30,132; li 5,1; bl _s800E04CC_9; 2:; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"

extern "C" void _s800E04CC_0();
extern "C" void _s800E04CC_1();
extern "C" void _s800E04CC_2();
extern "C" void _s800E04CC_3();
extern "C" void _s800E04CC_4();
extern "C" void _s800E04CC_5();
extern "C" void _s800E04CC_6();
extern "C" void _s800E04CC_7();
extern "C" void _s800E04CC_8();
extern "C" void _s800E04CC_9();

struct cXObjectImpl {
    void ReconHeader_ReconBuffer();
};

void cXObjectImpl::ReconHeader_ReconBuffer() {
}
