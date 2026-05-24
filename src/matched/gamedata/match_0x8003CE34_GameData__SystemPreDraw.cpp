// 0x8003CE34 (68B) GameData::SystemPreDraw(ERC*)
// ASMPROC: GCC emits cmpwi 0,3,3; bc 4,1 (ble 3) for status<4 — DOL uses cmpwi 0,3,4; bc 12,0 (blt 4).
// ASMPROC_replace_insn: match="cmpwi 0,3,3" replacement="cmpwi 0,3,4"
// ASMPROC_replace_insn: match="bc 4,1,.L4" replacement="bc 12,0,.L4"

struct GameData {
    void SystemPreDraw();
};

void GameData::SystemPreDraw() {
}
