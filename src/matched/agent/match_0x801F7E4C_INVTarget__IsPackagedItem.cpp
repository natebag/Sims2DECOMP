// 0x801F7E4C INVTarget::IsPackagedItem(BBI::InventoryItem *) (100B)
// ASMPROC_replace_insn: match="cmpwi 7,3,1" replacement="cmpwi 7,3,2"
// ASMPROC_inject_before: before="mfcr 30" lines="cror 4*cr7+so,4*cr7+eq,4*cr7+gt"
// ASMPROC_replace_insn: match="rlwinm 30,30,30,1" replacement="rlwinm 30,30,0,1"

namespace BBI {
    class InventoryItem {
    public:
        int GetItemCategory() const;
        int GetItemSubcategory() const;
    };
}

class INVTarget {
public:
    static int IsPackagedItem(BBI::InventoryItem* item);
};

int INVTarget::IsPackagedItem(BBI::InventoryItem* item) {
    int result = 0;
    if (item != 0) {
        if (item->GetItemCategory() == 2) {
            int sub = item->GetItemSubcategory();
            if (sub <= 5) {
                result = (sub == 2 || sub > 2);
            }
        }
    }
    return result;
}
