extern void AptActionInterpreter_unresolveStream_inner(void* a, void* b, int c, void* d);

void AptActionInterpreter_unresolveStream(void* self, void* a, void* c) {
    AptActionInterpreter_unresolveStream_inner(self, a, 0, c);
}
