// 0x800F9E6C cXObjectImpl::AllowIdleOptimization(void) (180B)
//
// Semantic recovery from ASMPROC inject_before stub (src/matched/agent/
// match_0x800F9E6C_cXObjectImpl__AllowIdleOptimization_void.cpp). Real C++,
// no inject_before. objectsim TU canonical destination.
//
// Behavior:
//   1. Iterate this->m_actionArray[m_actionBegin..m_actionEnd), stride 108.
//      Set local `hasNonZero` if any entry has m_field10 != 0.
//   2. Dispatch m_inner virtual slot 0x318 (GetObjectType per
//      include/types/cXObjectImpl.h). If returns 2 → return 0.
//   3. Call helper_0x800E4040(&m_edithVariableSet, 25); if first short of
//      returned blob != 0 → return 0.
//   4. Otherwise return hasNonZero ? 1 : 0.

extern "C" short* helper_0x800E4040(void* p, int idx);

struct AIOEntry {
    char pad0[0x10];
    int m_field10;
    char tail[108 - 0x14];
};

struct AIOInnerVt {
    char pad[0x318];
    short m_off;
    char _p2[2];
    int (*m_fn)(void*);
};

struct AIOInner {
    char pad[0x04];
    AIOInnerVt* m_vt;
};

struct cXObjImplAIO {
    char pad1[0x04];
    AIOInner* m_inner;             // +0x04
    char pad2[0x28 - 0x08];
    char m_edithVariableSet[0xB0 - 0x28];  // EdithVariableSet at +0x28
    AIOEntry* m_actionBegin;        // +0xB0
    AIOEntry* m_actionEnd;          // +0xB4

    int AllowIdleOptimization();
};

int cXObjImplAIO::AllowIdleOptimization() {
    int hasNonZero = 0;
    AIOEntry* p = m_actionBegin;
    AIOEntry* end = m_actionEnd;
    while (p != end) {
        int isActive = (p->m_field10 != 0);
        if (isActive) {
            hasNonZero = 1;
            break;
        }
        ++p;
    }

    AIOInner* inner = m_inner;
    AIOInnerVt* vt = inner->m_vt;
    short adj = vt->m_off;
    int (*fn)(void*) = vt->m_fn;
    int objType = fn((char*)inner + adj);

    if (objType == 2) goto ret_zero;
    {
        short* edith = helper_0x800E4040(m_edithVariableSet, 25);
        if (*edith != 0) goto ret_zero;
    }
    if (hasNonZero == 0) goto ret_one;
ret_zero:
    return 0;
ret_one:
    return 1;
}
