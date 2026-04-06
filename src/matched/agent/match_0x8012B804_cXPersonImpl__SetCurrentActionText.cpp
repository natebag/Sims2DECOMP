extern "C" void BString2_assign(void* self, void* src, int flags);

void cXPersonImpl_SetCurrentActionText(void* self, void* str) {
    BString2_assign((char*)self + 0x130, str, 0);
}
