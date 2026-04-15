// MotiveConstantsClient::MotiveConstantsClient(void) at 0x800C2D1C (64B)

class GlobalConstantsClient {
public:
    GlobalConstantsClient(short n);
};

extern char MotiveConstantsClient_vtable[16];  // at 0x8045F740, 40 bytes

class MotiveConstantsClient : public GlobalConstantsClient {
public:
    MotiveConstantsClient();
};

MotiveConstantsClient::MotiveConstantsClient() : GlobalConstantsClient(1) {
    *(void**)this = (void*)MotiveConstantsClient_vtable;
}
