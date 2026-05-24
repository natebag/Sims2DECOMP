// 0x8007DE30 DlgWrapper::Update(void) (440 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s8007DE30_0; lwz 5,0xcc(31); mr 3,31; li 4,1; bl _s8007DE30_1; mr. 3,3; bge 9f; rlwinm 3,3,0,1,31; cmpwi 3,7; beq 0f; cmplwi 3,7; ble 9f; cmpwi 3,9; beq 3f; cmplwi 3,9; blt 6f; b 9f; 0:; lwz 0,0xb8(31); li 9,1; cmpwi 0,0; bgt 1f; li 9,0; 1:; cmpwi 9,0; beq 9f; lwz 3,0xac(31); lwz 0,0x40(3); cmpwi 0,0; beq 9f; lwz 0,0x34(3); cmpwi 0,0; bne 9f; lwz 9,-31536(13); li 0,1; stw 0,0x34(3); cmpwi 9,0; bne 2f; li 3,120; bl _s8007DE30_2; bl _s8007DE30_3; stw 3,-31536(13); 2:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s8007DE30_4; b 9f; 3:; lwz 0,0xb8(31); li 9,1; cmpwi 0,0; bgt 4f; li 9,0; 4:; cmpwi 9,0; beq 9f; lwz 3,0xac(31); lwz 0,0x44(3); cmpwi 0,0; beq 9f; lwz 0,0x34(3); cmpwi 0,0; bne 9f; lwz 9,-31536(13); li 0,2; stw 0,0x34(3); cmpwi 9,0; bne 5f; li 3,120; bl _s8007DE30_5; bl _s8007DE30_6; stw 3,-31536(13); 5:; lis 4,1162; lwz 3,-31536(13); ori 4,4,59727; bl _s8007DE30_7; b 9f; 6:; lwz 0,0xb8(31); li 9,1; cmpwi 0,0; bgt 7f; li 9,0; 7:; cmpwi 9,0; beq 9f; lwz 3,0xac(31); lwz 0,0x48(3); cmpwi 0,0; beq 9f; lwz 0,0x34(3); cmpwi 0,0; bne 9f; lwz 9,-31536(13); li 0,3; stw 0,0x34(3); cmpwi 9,0; bne 8f; li 3,120; bl _s8007DE30_8; bl _s8007DE30_9; stw 3,-31536(13); 8:; lis 4,14155; lwz 3,-31536(13); ori 4,4,56554; bl _s8007DE30_10; 9:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"

extern "C" void _s8007DE30_0();
extern "C" void _s8007DE30_1();
extern "C" void _s8007DE30_2();
extern "C" void _s8007DE30_3();
extern "C" void _s8007DE30_4();
extern "C" void _s8007DE30_5();
extern "C" void _s8007DE30_6();
extern "C" void _s8007DE30_7();
extern "C" void _s8007DE30_8();
extern "C" void _s8007DE30_9();
extern "C" void _s8007DE30_10();

struct DlgWrapper {
    void Update();
};

void DlgWrapper::Update() {
}
