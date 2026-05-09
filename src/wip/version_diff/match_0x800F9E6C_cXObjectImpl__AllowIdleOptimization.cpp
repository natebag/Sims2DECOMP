// cXObjectImpl::AllowIdleOptimization() at 0x800F9E6C (180B)
// VERSION_DIFF: tail !hasActive lowers to xori vs DOL branch-style
//   cmpwi r30,0; beq +N; li r3,0; b end; +N: li r3,1.
// Loop body matches (boolean materialization li r11,1; cmpwi; bne; li r11,0).
// 1 vcall (vt[792/796]), 1 EdithVariableSet[25] check.
// Variants tried: !hasActive, hasActive ? 0 : 1, separate-if returns.
// Compiler always optimizes to xori. Track-I mutator needed (replace_insn xori→branch
// or force_alias_base on r30). Park for MutatorSmith.

struct cXObject;
struct EdithVariableEntry { short m_value; char _p[6]; };

struct AIVt { char pad[792]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct AIInner { char pad[4]; AIVt *m_vt; };

struct EdithVariableSet {
    EdithVariableEntry *operator[](int);
};

struct SpriteSlot {
    char pad[16];
    int m_field16;
    char pad2[88];  // total 108
};

struct cXObjectImpl {
    char pad[4];
    AIInner *m_obj;            // offset 4
    char pad2[0x20];           // through 0x28
    EdithVariableSet m_vars;   // offset 0x28
    char pad3[0xB0 - 0x28 - sizeof(EdithVariableSet)];
    SpriteSlot *m_spritesBegin;  // offset 0xB0 (176)
    SpriteSlot *m_spritesEnd;    // offset 0xB4 (180)

    int AllowIdleOptimization();
};

int cXObjectImpl::AllowIdleOptimization() {
    int hasActive = 0;
    SpriteSlot *p = this->m_spritesBegin;
    SpriteSlot *end = this->m_spritesEnd;
    for (; p != end; p++) {
        int b = (p->m_field16 != 0);
        if (b) { hasActive = 1; break; }
    }

    AIInner *obj = this->m_obj;
    int ret = obj->m_vt->m_fn((char *)obj + obj->m_vt->m_off);
    if (ret == 2) return 0;

    if (this->m_vars[25]->m_value != 0) return 0;
    return hasActive ? 0 : 1;
}
