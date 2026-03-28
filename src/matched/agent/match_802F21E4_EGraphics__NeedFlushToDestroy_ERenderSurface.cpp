class ERenderSurface;
class EGraphics {
public:
    int NeedFlushToDestroy(ERenderSurface *);
};
int EGraphics::NeedFlushToDestroy(ERenderSurface *) { return 1; }
