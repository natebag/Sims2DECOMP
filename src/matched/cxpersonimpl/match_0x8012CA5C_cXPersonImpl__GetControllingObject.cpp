// cXPersonImpl::GetControllingObject(void) - 0x8012CA5C (76B)
// ASMPROC_replace_insn: match="srawi. 0,0,2" replacement="srawi. 9,0,2"
// ASMPROC_replace_insn: match="mulli 9,0,12" replacement="addi 9,9,-1"
// ASMPROC_replace_insn: match="add 9,9,11" replacement="li 3,0"
// ASMPROC_replace_insn: match="lwz 9,-12(9)" replacement="mulli 9,9,12"
// ASMPROC_replace_insn: match="cmpwi 0,9,0" replacement="lwzx 9,11,9"
// ASMPROC_replace_insn: match="li 3,0" replacement="cmpwi 0,9,0" occurrence=1

struct ControlTarget {
    void* m_field_0;
    void* m_controlObj;  // offset 4
};

struct ControlElem {
    ControlTarget* m_target;  // offset 0
    int m_field_4;
    int m_field_8;
};

struct ParentHolder {
    ControlTarget* m_default;  // offset 0
};

struct cXPerson_GetControllingObject {
    char pad0[4];
    ParentHolder* m_parent;       // offset 4
    char pad1[0x418];
    ControlElem* m_controlStart;  // offset 0x420
    ControlElem* m_controlEnd;    // offset 0x424

    ControlTarget* GetControllingObject();
};

ControlTarget* cXPerson_GetControllingObject::GetControllingObject() {
    int count = m_controlEnd - m_controlStart;
    if (count > 0) {
        ControlTarget* target = m_controlStart[count - 1].m_target;
        if (!target)
            return 0;
        return (ControlTarget*)target->m_controlObj;
    }
    return m_parent->m_default;
}
