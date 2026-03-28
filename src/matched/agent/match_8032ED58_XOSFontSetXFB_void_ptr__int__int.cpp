static void *s_xfb;
static int s_xfb_w;
static int s_xfb_h;
void XOSFontSetXFB(void *xfb, int w, int h) { s_xfb = xfb; s_xfb_w = w; s_xfb_h = h; }
