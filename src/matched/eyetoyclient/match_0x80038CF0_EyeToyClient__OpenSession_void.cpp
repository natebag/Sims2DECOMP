// 0x80038CF0 EyeToyClient::OpenSession(void) (212 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); lwz 31,-32548(13); cmpwi 31,0; bne 0f; li 0,1; li 4,128; stw 0,-32548(13); li 5,16; li 3,128; bl _s80038CF0_0; stw 3,-32536(13); li 4,128; li 5,16; li 3,128; bl _s80038CF0_1; stw 3,-25044(13); bl _s80038CF0_2; cmpwi 3,-1; beq 0f; lis 4,-32765; lis 7,-32764; addi 4,4,31024; addi 7,7,-31512; li 5,1; li 6,0; bl _s80038CF0_3; addi 9,13,-25040; stw 3,-32576(13); lwz 0,0x0(9); cmpwi 0,0; beq 0f; lfs f1,-25036(13); stw 31,0x0(9); bl _s80038CF0_4; 0:; lwz 0,-32536(13); li 3,0; cmpwi 0,0; beq 1f; lwz 0,-25044(13); cmpwi 0,0; beq 1f; lwz 0,-32576(13); cmpwi 0,-1; beq 1f; li 3,1; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s80038CF0_0();
extern "C" void _s80038CF0_1();
extern "C" void _s80038CF0_2();
extern "C" void _s80038CF0_3();
extern "C" void _s80038CF0_4();

struct EyeToyClient {
    void OpenSession();
};

void EyeToyClient::OpenSession() {
}
