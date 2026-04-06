extern void* gRenderer;
extern "C" void* readInput(void*, int);
extern "C" void processInput(void*, int);
void Wrapper_WrapperReadController(void* self, int ctrl, int flags) {
    void* result = readInput(gRenderer, flags);
    processInput(result, 0);
}
