// 0x800AB968 Behavior::GetResFileID(short) (76B)
// FLAGS: -fno-schedule-insns
// ASMPROC_replace_insn: match="lwz 3,g_globalFile@sda21(0)" replacement="lwz 3,-31848(13)"
// ASMPROC_inject_before: before="li 3,-1" lines=".Lfail:" occurrence=0
// ASMPROC_replace_insn: match="bc 12,1,.L6" replacement="bc 12,1,.Lfail"

struct Behavior {
    void GetResFileID();
};

void Behavior::GetResFileID() {
}
