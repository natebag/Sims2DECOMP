// 0x8026BA9C CasTweakTool::GetMixinInfo(char (12 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="blr; stw 3,-27572(13)"

struct CasTweakTool {
    void GetMixinInfo();
};

void CasTweakTool::GetMixinInfo() {
}
