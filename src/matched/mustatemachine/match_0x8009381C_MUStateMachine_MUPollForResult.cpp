// 0x8009381C MUStateMachine::MUPollForResult(MUStateMachine::eMURequest) (28B)

extern int g_muRequestType;   // SDA @ -21364
extern int g_muResult;         // SDA @ -21372

struct MUStateMachine {
    static int MUPollForResult(int req);
};

int MUStateMachine::MUPollForResult(int req) {
    int result = 0;
    if (g_muRequestType == req) {
        result = g_muResult;
    }
    return result;
}
