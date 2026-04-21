// 0x802F12B0 EGraphics::GetScissorRect(TRect<float>*, TRect<float>&, TRect<float>&) (36B)
// Pure 4-float copy: *out = src1. (src2 unused at this address.)

template<class T> struct TRect { T a, b, c, d; };

struct EGraphics {
    void GetScissorRect(TRect<float>* out, TRect<float>& src1, TRect<float>& src2);
};

void EGraphics::GetScissorRect(TRect<float>* out, TRect<float>& src1, TRect<float>& src2) {
    out->a = src1.a;
    out->b = src1.b;
    out->c = src1.c;
    out->d = src1.d;
}
