// 0x80038518 EyeToyClient::Init(void) (284 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); lis 9,-32702; li 11,0; addi 27,9,15808; addi 26,27,4; 0:; mulli 0,11,12; addi 31,11,1; lwzx 9,26,0; lwzx 4,27,0; cmpwi 9,0; ble 2f; mr 30,4; mr 29,9; lis 28,-32692; 1:; lwz 4,0x0(30); addi 3,28,-17444; li 5,0; li 6,0; bl _s80038518_0; stw 3,0x4(30); addic. 29,29,-1; addi 30,30,8; bne 1b; 2:; mr 11,31; cmpwi 11,4; ble 0b; li 29,-1; li 3,5; stw 29,-32560(13); li 28,0; bl _s80038518_1; lis 11,-32697; lis 9,-32765; addi 30,11,23136; addi 9,9,32032; li 0,13; stw 9,0x4(30); stw 0,0x5a60(11); addi 3,30,8; bl _s80038518_2; lis 9,-32707; lis 11,-32707; lfs f13,0x1678(9); mr 4,30; lfs f0,0x1674(11); li 3,0; stfs f13,0x20(30); stfs f0,0x18(30); stfs f13,0x1c(30); bl _s80038518_3; lwz 3,-32056(13); lis 4,17785; lis 5,-32765; lis 6,-32765; lis 7,-32765; stw 29,-32544(13); addi 5,5,30112; addi 6,6,30772; addi 7,7,30288; ori 4,4,25938; bl _s80038518_4; addi 9,13,-25040; stw 28,0x0(9); lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80038518_0();
extern "C" void _s80038518_1();
extern "C" void _s80038518_2();
extern "C" void _s80038518_3();
extern "C" void _s80038518_4();

struct EyeToyClient {
    void Init();
};

void EyeToyClient::Init() {
}
