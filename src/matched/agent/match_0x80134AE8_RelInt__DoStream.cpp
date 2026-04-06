extern "C" void doStreamImpl(void* buf, void* self, int mode);
void RelInt_DoStream(void* self, void* buf) {
    doStreamImpl(buf, self, 1);
}
