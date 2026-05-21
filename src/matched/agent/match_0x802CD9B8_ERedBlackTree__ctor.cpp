// 0x802CD9B8 ERedBlackTree::ERedBlackTree(void) (32B)
//
// Simple 3-field ctor: zero m_0 + set m_8 to vtable + zero m_4. DOL aliases
// this to r11 (mr r11, r3) and uses r9 for vtable. GCC chose r9 for the
// alias and r11 for vtable — the opposite. Plus the prologue insn order
// differs (DOL: lis-mr-li-addi; GCC: mr-li-lis).
//
// Recipe: 1 gpr_relabel + 3 swap_adj.
//   - gpr_relabel swap=9:11 swaps the register roles bidirectionally.
//   - 2 swap_adj's shift the lis-load to the head of the prologue.
//   - 1 swap_adj a=stw b=la swaps the la (extended-mnemonic for addi) with
//     the preceding stw r0,0 so the addi/la lands BEFORE the first store
//     (matching DOL's addi-then-stores order).
//
// NOTE: the la mnemonic is what SN emits for `addi rt, ra, label@l(ra)` —
// the opcode in .s is `la`, not `addi`. Mutator authors targeting the
// vtable LO-half should match `la` (not `addi`).
//
// ASMPROC_gpr_relabel: swap=9:11
// ASMPROC_swap_adj: a=li b=lis which=first
// ASMPROC_swap_adj: a=mr b=lis which=first
// ASMPROC_swap_adj: a=stw b=la which=first

extern char ERedBlackTree_vt[];

class ERedBlackTree {
public:
    int m_0;
    int m_4;
    void* m_8;
    ERedBlackTree();
};

ERedBlackTree::ERedBlackTree() {
    *(volatile int*)((char*)this + 0) = 0;
    *(volatile int*)((char*)this + 8) = (int)ERedBlackTree_vt;
    *(volatile int*)((char*)this + 4) = 0;
}
