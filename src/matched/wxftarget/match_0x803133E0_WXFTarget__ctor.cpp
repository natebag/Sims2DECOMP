/* WXFTarget constructor at 0x803133E0 (68 bytes) */

extern int WXFTarget_vtable[];

void WXFBaseInit(void*);

struct WXFTarget {
    int* _vtable;
    char _pad_04[0x10];
    int m_field_14;

    WXFTarget();
};

WXFTarget::WXFTarget()
{
    WXFBaseInit(this);
    m_field_14 = 0;
    _vtable = WXFTarget_vtable;
}
