// 0x803239E8 EControllerManager::MapControllerCommands(EBtnToCmdAssoc*, int) (100B)
//
// 4-iteration loop calling GetController + SetCommandMap + UnmapPlayer
// for each controller index. DOL emits the loop test as `cmpwi r31, 4;
// blt loop` (i < 4 form). GCC canonicalizes to `cmpwi r31, 3; ble loop`
// (i <= 3 form). Same control flow, different encoding.
//
// Recipe: 2-directive replace_insn to undo GCC's `<` canonicalization.
//
// ASMPROC_replace_insn: match="cmpwi 0,31,3" replacement="cmpwi 0,31,4"
// ASMPROC_replace_insn: match="bc 4,1" replacement="bc 12,0"

class EBtnToCmdAssoc;

class EController {
public:
    void SetCommandMap(EBtnToCmdAssoc* assoc, int val);
};

class EControllerManager {
public:
    EController* GetController(unsigned int idx);
    void UnmapPlayer(unsigned int idx);
    void MapControllerCommands(EBtnToCmdAssoc* assoc, int val);
};

void EControllerManager::MapControllerCommands(EBtnToCmdAssoc* assoc, int val) {
    int i = 0;
loop:
    EController* ctrl = GetController(i);
    ctrl->SetCommandMap(assoc, val);
    UnmapPlayer(i);
    i++;
    if (i < 4) goto loop;
}
