// 0x802CE6E4 ERTQuantize::ERTQuantize(void) (56B)
//
// vtable store + 256-iter empty-bdnz-loop + 3 field stores + swap_adj for stw order.
//
// ASMPROC_swap_adj: a=stw b=stw which=last

extern char ERTQuantize_vt[];

class ERTQuantize {
public:
    ERTQuantize();
};

ERTQuantize::ERTQuantize() {
    *(int*)((char*)this + 0) = (int)ERTQuantize_vt;
    int i;
    for (i = 0; i < 256; i++) ;
    *(short*)((char*)this + 4234) = 1;
    *(int*)((char*)this + 4236) = 0;
    *(int*)((char*)this + 4240) = 0;
}
