// 0x800937E8 (52B) MUStateMachine::MURequest(MUStateMachine::eMURequest)
// If no current request and request in [1..8], clear result slots and set current request.
// Single-exit accumulator pattern: r9=0 early; r9=req in success path; final mr r3,r9.

extern int g_muCurrentRequest;  // SDA @ -21368
extern int g_muRequestType;      // SDA @ -21364
extern int g_muResult;           // SDA @ -21372

struct MUStateMachine {
    static int MURequest(int req);
};

int MUStateMachine::MURequest(int req)
{
    int result = 0;
    if (g_muCurrentRequest == 0 && (unsigned int)(req - 1) <= 7) {
        g_muRequestType = 0;
        g_muResult = 0;
        g_muCurrentRequest = req;
        result = req;
    }
    return result;
}
