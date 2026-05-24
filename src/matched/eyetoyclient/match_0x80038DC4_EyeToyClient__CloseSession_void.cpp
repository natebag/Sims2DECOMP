// 0x80038DC4 EyeToyClient::CloseSession(void) (112 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); bl _s80038DC4_0; li 0,1; lwz 3,-32576(13); stw 0,-25040(13); stfs f1,-25036(13); bl _s80038DC4_1; lwz 9,-32548(13); li 0,-1; stw 0,-32576(13); cmpwi 9,0; beq 0f; lwz 3,-25044(13); li 30,0; bl _s80038DC4_2; lwz 3,-32536(13); stw 30,-25044(13); bl _s80038DC4_3; stw 30,-32548(13); stw 30,-32536(13); 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"

extern "C" void _s80038DC4_0();
extern "C" void _s80038DC4_1();
extern "C" void _s80038DC4_2();
extern "C" void _s80038DC4_3();

struct EyeToyClient {
    void CloseSession();
};

void EyeToyClient::CloseSession() {
}
