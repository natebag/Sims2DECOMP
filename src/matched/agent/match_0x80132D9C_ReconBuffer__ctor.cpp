// 0x80132D9C ReconBuffer::ReconBuffer(void *, int, ReconBuffer::Mode, bool) (60B)
//
// 4-arg ctor with uniform-volatile-int + 1 swap_adj for li/stw order.
//
// ASMPROC_swap_adj: a=stw b=li which=first

class ReconBuffer {
public:
    enum Mode {};
    ReconBuffer(void* p, int n, Mode m, bool b);
};

ReconBuffer::ReconBuffer(void* p, int n, Mode m, bool b) {
    *(volatile int*)((char*)this + 0)  = (int)p;
    *(volatile int*)((char*)this + 4)  = n;
    *(volatile int*)((char*)this + 12) = (int)m;
    *(volatile int*)((char*)this + 44) = 0;
    *(volatile int*)((char*)this + 16) = 1;
    *(volatile int*)((char*)this + 8)  = 0;
    *(volatile int*)((char*)this + 20) = 0;
    *(volatile int*)((char*)this + 24) = 0;
    *(volatile int*)((char*)this + 28) = 0;
    *(volatile int*)((char*)this + 32) = 0;
    *(volatile int*)((char*)this + 40) = 0;
}
