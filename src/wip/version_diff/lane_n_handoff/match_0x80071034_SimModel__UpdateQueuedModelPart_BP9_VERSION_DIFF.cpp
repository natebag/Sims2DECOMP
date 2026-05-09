// FLAGS: -msdata=eabi -G 8
// 0x80071034 (296B) SimModel::UpdateQueuedModelPart(eBodyPartS2C, bool, bool)
// SW2 Pack #3 Blueprint 9. VERSION_DIFF — Track-I wall @ 30min (S13 2026-05-02).
//
// SIZE: matches (296B/296B compiled and DOL).
// BYTES: MISMATCH at register-allocation boundary.
//
// Divergence (mine vs DOL):
//   Mine:  9421ffd0 stwu r1,-48     bee1000c stmw r23,12(r1)   (9 regs saved)
//   DOL:   9421ffd8 stwu r1,-40     bf010008 stmw r24,8(r1)    (8 regs saved)
//
// Root cause: mine introduces r23 as a separate NULL-marker (`li r23,0`)
// after AddRef-fallback, while DOL reuses r27 (singleton-hi half from
// `lis r27,-32692`) dual-purpose as the NULL marker. DOL also reuses r29
// to save the resource-id index (`mr r29,r30`) instead of holding a fresh
// pointer. cc1plus + my source consistently allocates a 9th saved reg.
//
// Source-coercion attempts (v1/v2/v3 — all hit register-alloc wall):
//   v1: early-return fast path → SIZE_MISMATCH (-12B/-3 instr; compiler
//       placed fast-path block at head with reordered arg-mr's).
//   v2: inverted condition (slow body inline; fast path falls through at
//       tail) + explicit `EResource* resBase` → SIZE matched (296B/296B)
//       but byte mismatch (9 saved regs vs DOL's 8).
//   v3 (CURRENT): removed `resBase` intermediate; direct member access
//       via `m_resourceIDs[part]` / `m_models[part]` throughout. Same
//       size match, same byte mismatch at stmw boundary.
//
// MutatorSmith candidate: register-rename mutator coercing the `lis` at
// the singleton load to land in a register reused as NULL marker (DOL's
// r27 dual-purpose pattern), or `gpr_relabel`-style remapping at stmw
// boundary to drop r23 from the saved-reg span (r23..r31 → r24..r31).
//
// Pattern: m_partFlags[part] bit-0x20 gate; on hit: GetRef→AddRef-fallback against
//          g_modelman singleton (EResourceManager sizeof>8 SDA-threshold lever);
//          sibling UpdateModelPart bl; post-update diamond branch on
//          m_models[part]->m_field_120 / m_field_C → (a) clear models slot + mask 0x1E,
//          (b) EResource::DelRef + mask 0x40.

class EFile;

struct EResource {
    char pad_0[12];        // +0..+11
    short m_field_C;       // +12 (lha)
    void DelRef();
};

class EResourceManager {
public:
    char m_pad[16];        // pad sizeof past -G 8 threshold so g_modelman lands in .data not .sdata
    EResource* GetRef(unsigned int id);
    EResource* AddRef(unsigned int id, EFile* file, int unk);
};

extern EResourceManager g_modelman;     // 0x804B945C (_modelman / e_modelman.obj)

struct Model {
    char pad_0[288];        // +0..+287
    EResource* m_field_120; // +288
};

enum eBodyPartS2C { eBodyPart_DUMMY };

class SimModel {
public:
    int m_partFlags[26];              // +0
    Model* m_models[26];              // +104 (0x68)
    unsigned int m_resourceIDs[26];   // +208 (0xD0)

    int UpdateQueuedModelPart(eBodyPartS2C part, bool b1, bool b2);
    int UpdateModelPart(eBodyPartS2C part, bool b1, bool b2);
};

int SimModel::UpdateQueuedModelPart(eBodyPartS2C part, bool b1, bool b2) {
    if (m_partFlags[part] & 0x20) {
        if (m_resourceIDs[part] == 0) return 0;
        EResource* res = g_modelman.GetRef(m_resourceIDs[part]);
        if (res == 0) {
            res = g_modelman.AddRef(m_resourceIDs[part], 0, 0);
            if (res == 0) return 0;
        }
        m_resourceIDs[part] = 0;
        m_partFlags[part] = (m_partFlags[part] & ~0x20) | 0x40;
        int retval = UpdateModelPart(part, b1, b2);
        if (m_models[part]->m_field_120 != 0 && m_models[part]->m_field_120->m_field_C <= 1) {
            m_models[part] = 0;
            m_partFlags[part] &= ~0x1E;
            return 0;
        }
        res->DelRef();
        m_partFlags[part] &= ~0x40;
        return retval;
    }
    return UpdateModelPart(part, b1, b2);
}
