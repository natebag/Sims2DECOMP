// 0x8003CE34 (68B) GameData::SystemPreDraw(ERC*)
// Returns true unless DVD drive is in busy/seeking state (status 4-6 or 11).
// goto-shared-label: blt(status<4) → ret1, ble(status<=6) → ret0, beq(status==11) → ret0.
// ASMPROC: GCC emits cmpwi 0,3,3; bc 4,1 (ble 3) for status<4 — DOL uses cmpwi 0,3,4; bc 12,0 (blt 4).
// ASMPROC_replace_insn: match="cmpwi 0,3,3" replacement="cmpwi 0,3,4"
// ASMPROC_replace_insn: match="bc 4,1,.L4" replacement="bc 12,0,.L4"

int DVDGetDriveStatus();

struct ERC {};

class GameData_SPD {
public:
    bool SystemPreDraw(ERC* erc);
};

bool GameData_SPD::SystemPreDraw(ERC* erc) {
    int status = DVDGetDriveStatus();
    if (status < 4) goto ret1;
    if (status <= 6) goto ret0;
    if (status == 11) goto ret0;
ret1:
    return true;
ret0:
    return false;
}
