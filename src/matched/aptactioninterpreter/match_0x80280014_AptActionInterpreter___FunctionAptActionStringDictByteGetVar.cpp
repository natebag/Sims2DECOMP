// 0x80280014 AptActionInterpreter::_FunctionAptActionStringDictByteGetVar(
//                 AptActionInterpreter*, AptActionInterpreter::LocalContextT*) (192 B)
//
// Byte-index "get variable" opcode. Reads a single-byte dictionary id, fetches the
// 348-byte AptValue from m_stringDict, derives the variable-name C-string pointer,
// calls GetVariable to resolve it to a boxed value, pushes the box onto working
// stack A0, and dispatches a per-type method on it.
//
//   name = ((entry->m_typeFlags & 0x7F) == 1)   // inline-string variant
//             ? (char*)entry        + 0x0C       // text lives in the entry
//             : (char*)entry->m_ref + 0x0C;      // else in the backing AptValue
//
// AptValue 348B layout + AptValueObj box: see include/types/AptValue.h.
// apt-opcode-handler recipe (default scheduling, single-read stack top, vptr@0x8
// polymorphic box dispatch). The ctx fields are read into early locals so the
// scheduler hoists them (producing the `mr r4,r8`), and the dict entry is held in
// a distinct `entry0` with the selected pointer in `entry` (ternary) — that keeps
// the name pointer out of the entry's register, which is what makes GCC 2.95 color
// the field04 scratch the way the DOL does. No post-compile surgery.
struct AptGlobal { char _r[16]; };

struct AptValueObjHead {
    unsigned int m_flags;    // 0x00
    unsigned int m_field04;  // 0x04
};

struct AptValueObj : public AptValueObjHead {
    virtual void Dispatch(AptGlobal*, AptGlobal*, int) = 0;  // vtable+0x08
};

struct AptValue {                       // 348-byte by-value operand (dict entry)
    unsigned int m_typeFlags;           // 0x00  low 7 bits = type tag
    unsigned int m_field04;             // 0x04
    void*        m_vtable;              // 0x08
    char         m_payload[0x24 - 0x0C];// 0x0C  inline text when type tag == 1
    AptValue*    m_ref;                 // 0x24  backing value otherwise
    char         _body[0x15C - 0x28];   // -> sizeof 0x15C (348)
};

struct AptInterpStack {
    int           top;   // 0x00
    int           cap;   // 0x04
    AptValueObj** data;  // 0x08
};

struct LocalContextT {
    unsigned char* cursor;     // 0x00
    void*          m_field04;  // 0x04
    void*          m_field08;  // 0x08
};

extern AptGlobal gAptGVByteGlobalA;
extern AptGlobal gAptGVByteGlobalB;

struct AptActionInterpreter {
    AptInterpStack m_stackA0;          // 0x00
    char           _pad[0x38 - 0x0C];  // 0x0C .. 0x38
    AptValue**     m_stringDict;       // 0x38
    static void _FunctionAptActionStringDictByteGetVar(AptActionInterpreter* interp,
                                                       LocalContextT* ctx);
    static AptValueObj* GetVariable(AptActionInterpreter*, void*, void*, char*, int, int, int);
};

void AptActionInterpreter::_FunctionAptActionStringDictByteGetVar(AptActionInterpreter* interp,
                                                                  LocalContextT* ctx) {
    unsigned char* cur = ctx->cursor;
    void* f08 = ctx->m_field08;
    unsigned int idx = *cur++;
    void* f04 = ctx->m_field04;
    ctx->cursor = cur;

    AptValue* entry0 = interp->m_stringDict[idx];
    AptValue* entry = ((entry0->m_typeFlags & 0x7F) != 1) ? entry0->m_ref : entry0;
    char* name = (char*)entry + 0x0C;

    AptValueObj* box = GetVariable(interp, f04, f08, name, 1, 1, 0);

    int top = interp->m_stackA0.top;
    interp->m_stackA0.data[top] = box;
    interp->m_stackA0.top = top + 1;

    box->Dispatch(&gAptGVByteGlobalA, &gAptGVByteGlobalB, 138);
}
