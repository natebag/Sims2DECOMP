// 0x803239E8 EControllerManager::MapControllerCommands(EBtnToCmdAssoc *, int) (100B)
// ASMPROC_replace_insn: match="cmpwi 0,31,3" replacement="cmpwi 0,31,4"
// ASMPROC_replace_insn: match="bc 4,1" replacement="bc 12,0"

struct EControllerManager {
    void MapControllerCommands();
};

void EControllerManager::MapControllerCommands() {
}
