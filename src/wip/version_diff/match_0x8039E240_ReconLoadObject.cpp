// VERSION_DIFF: compiled 96B vs DOL 100B — stack struct construction differs
/* int ReconLoadObject<ObjectSaveTypeTable2>(...) at 0x8039E240 (100B) */
// FLAGS: -fno-elide-constructors

struct RCtx { void *vtable; void *obj; int param; };

extern void *g_recon_vt[4];
extern int ReconInner(void *, RCtx *, int);
extern void ReconCleanup(RCtx *, int);

int ReconLoadObj(void *obj, int resFile, int param) {
    RCtx ctx;
    ctx.vtable = g_recon_vt;
    ctx.obj = obj;
    ctx.param = param;
    char buf[8];
    int result = ReconInner(buf, &ctx, resFile);
    ReconCleanup(&ctx, 2);
    return result;
}
