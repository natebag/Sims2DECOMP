// 0x80036EA0 ESpriteRenderMan::ESpriteRenderMan (28b)

struct ESpriteRenderMan {
    int f0;
    int f4;
    int f8;
    ESpriteRenderMan();
};

ESpriteRenderMan::ESpriteRenderMan() {
    ESpriteRenderMan* p = this;
    p->f4 = 0;
    p->f0 = 0;
    p->f8 = 1;
}
