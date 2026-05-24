// 0x803A1E68 ERLevel::GetRoomIndex(EInstance (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="mr 7,30; mr 3,29; li 5,0; mr 8,6; bl _s803A1E68_0; b 2f; mr 5,10; mr 4,31; mr 7,30; mr 3,29; mr 6,5; li 8,0; bl _s803A1E68_1; b 2f; cmpw 27,11; bne 0f; lwz 0,0x0(28); b 1f; 0:; mr 4,31; mr 5,30; addi 3,1,24; bl _s803A1E68_2; lwz 0,0x18(1); 1:; stw 0,0x0(29); 2:; mr 3,29; lwz 0,0x3c(1); mtspr 8,0; lmw 27,0x24(1); addi 1,1,56"

extern "C" void _s803A1E68_0();
extern "C" void _s803A1E68_1();
extern "C" void _s803A1E68_2();

struct ERLevel {
    void GetRoomIndex_EInstance();
};

void ERLevel::GetRoomIndex_EInstance() {
}
