// 0x80280E48 (372B) AptActionInterpreter::isObjectOfType(AptValue*, AptValue*)
// FLAGS: -fno-schedule-insns
//
// ActionScript `o instanceof T`-style runtime type test over two APT values.
//
//   - If BOTH values are objects (the v5 / vt+0x28 "IsObject" virtual returns
//     nonzero on each): take `target = b->GetTypeChain()->m_0C` (b's type
//     identity). If `a` is itself a class/function-typed value (low-7 type tag
//     in [12,19] with the 0x08000000 flag bit set), walk a's superclass chain
//     (the v4 / vt+0x20 "GetTypeChain" virtual, following ->m_08) and report a
//     match if any link equals `target`. Otherwise delegate to
//     AptObject::DoesImplementObject(a, target).
//   - If either value is NOT an object: fall back to primitive type-tag
//     equality — equal low-7 tags match, except the special tags [43,45] (when
//     flagged) and 27 (when flagged) never match.
//
// AptValueObj is the polymorphic value-box (head { u32 m_flags@0; u32 @4 },
// vptr@0x08). GCC 2.95 8-byte vtable entries place virtual N at table+0x08*N:
// the 4th virtual = GetTypeChain (vt+0x20), the 5th = IsObject (vt+0x28).
// See include/types/AptValue.h. The 0x08000000 "is class type" flag bit is read
// as (m_flags >> 27) & 1. No ASMPROC, no inline asm — clean structural C++.

struct AptValueObjHead {
    unsigned int m_flags;    // 0x00  low 7 bits = type tag; bit 0x08000000 = class-type
    unsigned int m_field04;  // 0x04
};

struct AptValueObj;

struct AptObjThing {         // result of GetTypeChain (vt+0x20)
    char         _pad[8];    // 0x00..0x07
    AptValueObj* m_08;       // 0x08  next link in the superclass chain
    AptValueObj* m_0C;       // 0x0C  type identity
};

struct AptValueObj : public AptValueObjHead {
    virtual void         slot1();        // vt+0x08
    virtual void         slot2();        // vt+0x10
    virtual void         slot3();        // vt+0x18
    virtual AptObjThing* GetTypeChain(); // vt+0x20
    virtual int          IsObject();     // vt+0x28
};

struct AptValue;

struct AptObject {
    int DoesImplementObject(AptValue*);
};

struct AptActionInterpreter {
    static int isObjectOfType(AptValueObj* a, AptValueObj* b);
};

int AptActionInterpreter::isObjectOfType(AptValueObj* a, AptValueObj* b) {
    int result = 0;
    if (a->IsObject() && b->IsObject()) {
        AptObjThing* pb = b->GetTypeChain();
        unsigned int af = a->m_flags;
        int aIsClass = 0;
        AptValueObj* target = pb->m_0C;
        unsigned int t = af & 0x7F;
        if (t - 12 <= 7)
            aIsClass = (af >> 27) & 1;
        if (aIsClass != 0) {
            AptValueObj* node = a->GetTypeChain()->m_08;
            while (node != 0) {
                if (node == target)
                    result = 1;
                node = node->GetTypeChain()->m_08;
            }
        } else {
            if (((AptObject*)a)->DoesImplementObject((AptValue*)target))
                result = 1;
        }
    } else {
        unsigned int af = a->m_flags;
        unsigned int low7 = af & 0x7F;
        int e = 0;
        if (low7 - 43 <= 2)
            e = (af >> 27) & 1;
        if (e == 0) {
            int f = 0;
            if (low7 == 27)
                f = (af >> 27) & 1;
            if (f == 0 && low7 == (b->m_flags & 0x7F))
                result = 1;
        }
    }
    return result;
}
