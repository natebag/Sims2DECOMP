struct AptContext;
extern AptContext* gAptContext;
extern "C" void AptDeallocStringList(void* list);

void AptDeallocateAllStrings() {
    if (gAptContext) {
        AptDeallocStringList((char*)gAptContext + 0x28);
    }
}
