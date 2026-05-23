// 0x801E70FC EYETarget::EyeToyUnplugCallback(int) (24B) — semantic conversion of auto-stub
//
// Original disasm:
//   lwz   r9, -0x7028(r13)   ; s_eyeTargetSingleton (SDA)
//   cmpwi r9, 0
//   beqlr                    ; if (!p) return;
//   li    r0, 1
//   stw   r0, 0xB0(r9)       ; p->m_pendingUnplugEvent = 1;
//   blr
//
// Static callback registered with EyeToy SDK — int arg is the event code and is
// ignored (callback merely sets a pending-event flag for the next Update() to
// process). Declared static to match the signature without requiring a `this`.

class EYETarget {
public:
    char pad[0xB0];
    int m_pendingUnplugEvent;
    static void EyeToyUnplugCallback(int code);
};

extern EYETarget* s_eyeTargetSingleton;

void EYETarget::EyeToyUnplugCallback(int /*code*/) {
    EYETarget* p = s_eyeTargetSingleton;
    if (!p) return;
    p->m_pendingUnplugEvent = 1;
}
