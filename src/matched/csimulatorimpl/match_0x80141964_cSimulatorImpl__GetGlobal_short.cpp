// 0x80141964 cSimulatorImpl::GetGlobal(short) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,4; mr 30,3; cmpwi 31,46; beq 0f; cmpwi 31,47; beq 1f; b 2f; 0:; lis 3,-32697; addi 3,3,24012; bl _s80141964_0; sth 3,0x70(30); b 2f; 1:; lis 3,-32697; addi 3,3,24012; bl _s80141964_1; sth 3,0x72(30); 2:; add 0,31,31; addi 9,30,20; lhax 3,9,0; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80141964_0();
extern "C" void _s80141964_1();

struct cSimulatorImpl {
    void GetGlobal();
};

void cSimulatorImpl::GetGlobal() {
}
