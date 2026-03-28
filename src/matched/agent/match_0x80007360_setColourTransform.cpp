/* setColourTransform(AptCXForm *) at 0x80007360 (88B) */

struct CXFormHalf {
    int a;
    int b;
    int c;
    int d;
};

struct AptCXForm {
    CXFormHalf mul;
    CXFormHalf add;
};

extern CXFormHalf g_colourMul;
extern CXFormHalf g_colourAdd;

void setColourTransform(AptCXForm *xform) {
    g_colourMul = xform->mul;
    g_colourAdd = xform->add;
}
