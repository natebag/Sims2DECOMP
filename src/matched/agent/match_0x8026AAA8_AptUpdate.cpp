// 0x8026AAA8 (32B) AptUpdate(unsigned int)
// Thunk to _AptInternalUpdate(unsigned int)

extern void _AptInternalUpdate(unsigned int a0);

void AptUpdate(unsigned int a0) {
    _AptInternalUpdate(a0);
}
