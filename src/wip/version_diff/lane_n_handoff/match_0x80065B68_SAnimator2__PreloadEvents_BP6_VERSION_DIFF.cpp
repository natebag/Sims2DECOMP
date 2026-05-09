// FLAGS: -msdata=eabi -G 8
// 0x80065B68 (264B) SAnimator2::PreloadEvents(AnimRef *)
// SW2 Pack #3 Blueprint 6. VERSION_DIFF — Track-I wall (S13 2026-05-02).
//
// Body content MATCHES. Diff is isolated to switch-dispatch SHAPE in inner loop.
//
// SIZE: -12B / -3 instructions (264B DOL vs 252B compiled). DOL emits a balanced
// binary tree: cmpwi 9, ble check_low; (high) cmpwi 10, beq case_10; b skip;
// (check_low) cmpwi 6, bge skip; cmpwi 0, blt skip; cmpwi 4, ble skip;
// fall-through case_5. Total 11 dispatch instructions.
//
// cc1plus + my source produces sequential test (8 instr) regardless of switch
// shape tried:
//   v1 (case 5/10 only):      5 dispatch instr (-24B)
//   v2 (cases 0..10 + default): 8 dispatch instr (-12B)  ← current
//   v3 (if (type<=9) { if (a&&b&&c) }):  4 dispatch instr (collapsed to ==5; -20B)
//   v4 (if (type>9) { if==10 } else if ==5): 4 dispatch instr (-20B)
//
// v2's shape: cmpwi 5 beq case_5; ble skip; cmpwi 9 ble skip; cmpwi 10 beq case_10; b skip
// DOL's shape: cmpwi 9 ble check_low; cmpwi 10 beq case_10; b skip; check_low: cmpwi 6 bge skip; cmpwi 0 blt skip; cmpwi 4 ble skip
//
// Root cause: GCC 2.95.3 SN ProDG opts the case enumeration into condensed
// sequential rather than emitting the explicit per-bound binary-search range
// tests. The DOL's `cmpwi 0, blt skip` is redundant given `cmpwi 4, ble skip`
// (signed ble already catches negatives) — yet DOL emits it as part of the
// switch-statement range-prep. cc1plus folds this redundancy under -O2 in our
// reproduction.
//
// MutatorSmith candidate: switch_dispatch_expand mutator, or a Track-I rule
// that injects the missing 3-instr range-check at the binary-tree low fork.
// Pre-mutation anchor: `cmpwi 0,5` followed by sequential ble/cmpwi 9 chain.
// Post-mutation: insert cmpwi 6/0/4 chain replacing the ble compaction.
//
// Also minor: lis-lis-li ordering (DOL: 3f40 3f60 3ba0; mine: 3ba0 3f40 3f60)
// — register-allocator scheduling, not size-affecting.
//
// SDA singletons (sizeof 0xD20 → exceed -G 8 threshold → .data not .sdata):
//   _animman                0x804B2B38 (e_animman.obj)
//   g_soundeventman         0x804BC8FC (e_soundeventman.obj)
//   g_effectsAttachmentMan  0x804BF05C (effects_attachmentman.obj)

typedef unsigned char u8;

extern char _animman[];
extern char g_soundeventman[];
extern char g_effectsAttachmentMan[];

u8* EResourceManager__GetRef_unsigned_int(u8* mgr, unsigned int id);
void TArray_EAnimNote__ctor(u8* self);
void TArray_EAnimNote__assign(u8* self, u8* src);
void TArray_EAnimNote__dtor(u8* self, int mode);
void EResourceManager__PreloadResource_char_ptr(u8* mgr, char* name);
u8* EResourceManager__AddRef_char_ptr_EFile_ptr_int(u8* mgr, char* name, u8* efile, int flags);
void SAnimator2__PreloadBoneParticleEvent_REffectsAttachment_ptr(u8* self, u8* reff);
void EResource__DelRef_void(u8* res);

void SAnimator2__PreloadEvents_AnimRef_ptr(u8* self, u8* animRef) {
    u8 arr[12];

    u8* res = EResourceManager__GetRef_unsigned_int((u8*)_animman, *(unsigned int*)animRef);
    int count = 0;
    TArray_EAnimNote__ctor(arr);

    if (res) {
        u8* src = res + 0x88;
        count = *(int*)(src + 4);
        TArray_EAnimNote__assign(arr, src);
    }

    if (count > 0) {
        int byte_off = 0;
        do {
            u8* data = *(u8**)arr;
            u8* ep = data + byte_off;
            int event_type = *(int*)(ep + 4);

            switch (event_type) {
                case 0: case 1: case 2: case 3: case 4:
                    break;
                case 5:
                    EResourceManager__PreloadResource_char_ptr(
                        (u8*)g_soundeventman,
                        *(char**)(ep + 8));
                    break;
                case 6: case 7: case 8: case 9:
                    break;
                case 10: {
                    u8* reff = EResourceManager__AddRef_char_ptr_EFile_ptr_int(
                        (u8*)g_effectsAttachmentMan,
                        *(char**)(ep + 8), 0, 0);
                    if (reff) {
                        SAnimator2__PreloadBoneParticleEvent_REffectsAttachment_ptr(self, reff);
                        EResource__DelRef_void(reff);
                    }
                    break;
                }
                default:
                    break;
            }

            byte_off += 12;
        } while (--count);
    }

    TArray_EAnimNote__dtor(arr, 2);
}
