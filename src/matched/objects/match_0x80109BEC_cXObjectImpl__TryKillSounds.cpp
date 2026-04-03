// 0x80109BEC (68 bytes) — VERIFIED MATCH
// cXObjectImpl::TryKillSounds(StackElem *, KillSoundsParam *)
// Kills sounds by source ID. Uses param field or object's own sourceID.

struct StackElem;
struct KillSoundsParam;

extern void *g_soundPlayer;

void QuietBySourceID_fn(void *player, int id);

struct TKS {
    long long TryKillSounds(StackElem *elem, KillSoundsParam *param);
};

long long TKS::TryKillSounds(StackElem *elem, KillSoundsParam *param) {
    int id;
    if (*(short *)param != 0) {
        id = *(short *)((char *)elem + 4);
    } else {
        id = *(short *)((char *)this + 100);
    }
    QuietBySourceID_fn(g_soundPlayer, id);
    return 1;
}
