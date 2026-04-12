// 0x8032F8C4 ENgcGraphics::AllocRenderSurface (40b)

typedef unsigned int uint;
void *operator_new_fn(unsigned long);
void *ctor_fn(void *);

void *AllocRenderSurface() {
    void *mem = operator_new_fn(44);
    return ctor_fn(mem);
}
