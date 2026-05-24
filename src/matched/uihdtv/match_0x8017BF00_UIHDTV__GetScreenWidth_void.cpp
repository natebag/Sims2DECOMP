// 0x8017BF00 UIHDTV::GetScreenWidth(void) (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 9,-26392(13); lwz 3,0x18(9)"

struct UIHDTV {
    void GetScreenWidth();
};

void UIHDTV::GetScreenWidth() {
}
