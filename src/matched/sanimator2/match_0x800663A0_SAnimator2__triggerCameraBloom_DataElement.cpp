// 0x800663A0 SAnimator2::triggerCameraBloom(CameraBloomDataElement *) (72B)
// Pattern: SDA-resident bloom-target singleton vcall via vt+424/+428 slot (slot 53, this-adjust).
// Caller's `this` (r3) is unused; SDA pointer holds the dispatcher. 4 floats from data element
// are loaded with insn-scheduled order (f4 first then f1/f2/f3) and passed to the slot fn.

typedef void (*BloomTriggerFn)(void* adjThis, float a, float b, float c, float d);

extern void* g_bloomTarget;   // SDA-resident pointer at r13-26392

struct CameraBloomDataElement { float a, b, c, d; };

class SAnimator2 {
public:
    void triggerCameraBloom(CameraBloomDataElement* p);
};

void SAnimator2::triggerCameraBloom(CameraBloomDataElement* p) {
    char* obj = (char*)g_bloomTarget;
    char* vt = *(char**)obj;
    short adj = *(short*)(vt + 424);
    BloomTriggerFn fn = *(BloomTriggerFn*)(vt + 428);
    fn(obj + adj, p->a, p->b, p->c, p->d);
}
