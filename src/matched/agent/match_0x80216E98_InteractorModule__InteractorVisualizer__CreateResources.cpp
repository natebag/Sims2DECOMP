// 0x80216E98 InteractorModule::InteractorVisualizer::CreateResources(SimInteractor&) (64B)

extern void* GetSomething();
extern void DoSomething(void* p, unsigned int magic);

struct SimInteractor;

int IM_CreateResources(SimInteractor& si) {
    void* p = GetSomething();
    if (!p) return 0;
    DoSomething(p, 0x13187659);
    return 1;
}
