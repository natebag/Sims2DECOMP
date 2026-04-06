// MATCH: 0x800755DC SimsMemCardWrap::PreservePrefs (40 bytes)
// Pattern: load global address from SDA, call function with it

extern "C" void fn_80058E5C(void*);

// SDA global - accessed via r13 relative
extern void* gSimsMemCardWrap;

extern "C" void SimsMemCardWrap_PreservePrefs() {
    fn_80058E5C(gSimsMemCardWrap);
}
