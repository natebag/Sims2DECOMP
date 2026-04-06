// 0x800C2D1C MotiveConstantsClient::MotiveConstantsClient (64b)
extern int g_vtable_MotiveConstantsClient[8];
void ConstantsClient2_ctor(void*, int);

void* MotiveConstantsClient_ctor(void* self) {
    ConstantsClient2_ctor(self, 1);
    *(void**)self = (void*)g_vtable_MotiveConstantsClient;
    return self;
}
