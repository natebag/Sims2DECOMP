#ifndef ENGCSCHEDULER_H
#define ENGCSCHEDULER_H

#include "types.h"

// ENgcScheduler - struct layout extracted from assembly analysis
// Estimated minimum size: 0x3A4 (932 bytes)
// 5 known fields (0 named), 32 methods

class ENgcScheduler {
public:
    // Constructors / Destructors
    ENgcScheduler(void)  // 0x808DC528
    ~ENgcScheduler(void);  // 0x808DC5A0

    // Methods
    void Init(void);  // 0x808DC61C (188B)
    void QueueSetupFrameBuffer(int);  // 0x808DC6D8 (180B)
    void QueueDisplayList(EDL *, bool);  // 0x808DC78C (76B)
    void QueueCompletionEvent(EEvent &);  // 0x808DC7D8 (68B)
    void QueueSwapBuffer(int, int);  // 0x808DC81C (76B)
    void Flush(void);  // 0x808DC868 (60B)
    void TextureLoadsComplete(ESchedCommand *);  // 0x808DC8A4 (136B)
    void RenderingComplete(ESchedCommand *);  // 0x808DC92C (136B)
    /* ? */ GetLastRetraceCount(void);  // 0x808DC9B4 (40B)
    void Main(void);  // 0x808DC9DC (100B)
    void FreeSchedCommand(ESchedCommand *);  // 0x808DCBD4 (100B)
    void SendCommand(ESchedCommand *);  // 0x808DCA40 (292B)
    void AllocSchedCommand(void);  // 0x808DCB64 (112B)
    void RendFrameComplete(ESchedCommand *);  // 0x808DCDD8 (36B)

    // ---- Field Layout (from assembly analysis) ----
    u32 m_field_000;  // 0x000 [R] (AllocSchedCommand)
    u8 _pad_004[0x328];  // 0x004
    u32 m_field_32C;  // 0x32C [W] (Init)
    u8 _pad_330[8];  // 0x330
    u32 m_field_338;  // 0x338 [W] (ENgcScheduler, ~ENgcScheduler)
    u8 _pad_33C[0x58];  // 0x33C
    u32 m_field_394;  // 0x394 [R/W] (AllocSchedCommand, FreeSchedCommand)
    u8 _pad_398[8];  // 0x398
    u32 m_field_3A0;  // 0x3A0 [R] (AllocSchedCommand, FreeSchedCommand)
};

#endif // ENGCSCHEDULER_H
