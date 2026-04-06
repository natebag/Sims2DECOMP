extern "C" void doStreamImpl(void* buf, void* self, int mode);
void FamilyMember_DoStream(void* self, void* buf) {
    doStreamImpl(buf, self, 1);
}
