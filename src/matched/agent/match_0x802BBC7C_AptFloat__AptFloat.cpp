// AptFloat::AptFloat(float) @ 0x802BBC7C (80B)
// FLAGS: -fno-schedule-insns
// DOL uses -32 stack frame; compiled uses -24. Adjust all frame offsets +8.
// ASMPROC_replace_insn: match="stwu 1,-24(1)" replacement="stwu 1,-32(1)"
// ASMPROC_replace_insn: match="stfd 31,16(1)" replacement="stfd 31,24(1)"
// ASMPROC_replace_insn: match="stmw 30,8(1)" replacement="stmw 30,16(1)"
// ASMPROC_replace_insn: match="stw 0,28(1)" replacement="stw 0,36(1)"
// ASMPROC_replace_insn: match="lwz 0,28(1)" replacement="lwz 0,36(1)"
// ASMPROC_replace_insn: match="lmw 30,8(1)" replacement="lmw 30,16(1)"
// ASMPROC_replace_insn: match="lfd 31,16(1)" replacement="lfd 31,24(1)"
// ASMPROC_replace_insn: match="la 1,24(1)" replacement="la 1,32(1)"

extern char AptFloat_vtable[];
extern void AptValue_ctor(void *, int);

struct AptFloat {
    char pad[0x10];
    float m_val;
    AptFloat(float val);
};

AptFloat::AptFloat(float val)
{
    AptValue_ctor(this, 6);
    *(float*)((char*)this + 0x0C) = val;
    *(int**)((char*)this + 0x08) = (int*)AptFloat_vtable;
}
