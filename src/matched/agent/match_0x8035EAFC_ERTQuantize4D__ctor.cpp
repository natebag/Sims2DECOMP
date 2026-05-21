// 0x8035EAFC ERTQuantize4D::ERTQuantize4D(void) (56B)
//
// Sister of ERTQuantize ctor — identical recipe (offsets 4102/4104/4108
// instead of 4234/4236/4240).
//
// ASMPROC_swap_adj: a=stw b=stw which=last

extern char ERTQuantize4D_vt[];

class ERTQuantize4D {
public:
    ERTQuantize4D();
};

ERTQuantize4D::ERTQuantize4D() {
    *(int*)((char*)this + 0) = (int)ERTQuantize4D_vt;
    int i;
    for (i = 0; i < 256; i++) ;
    *(short*)((char*)this + 4102) = 1;
    *(int*)((char*)this + 4104) = 0;
    *(int*)((char*)this + 4108) = 0;
}
