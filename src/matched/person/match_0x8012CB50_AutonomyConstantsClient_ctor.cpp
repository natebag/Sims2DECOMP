// 0x8012CB50 AutonomyConstantsClient::AutonomyConstantsClient (64b)
extern int g_vtable_AutonomyConstantsClient[8];
void ConstantsClient_ctor(void*, int);

void* AutonomyConstantsClient_ctor(void* self) {
    ConstantsClient_ctor(self, 2);
    *(void**)self = (void*)g_vtable_AutonomyConstantsClient;
    return self;
}
