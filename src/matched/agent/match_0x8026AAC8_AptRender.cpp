// 0x8026AAC8 (32B) AptRender(void)
// Thunk to _AptInternalRender(void)

extern void _AptInternalRender(void);

void AptRender(void) {
    _AptInternalRender();
}
