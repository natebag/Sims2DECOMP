class ETexture;
class EGraphics {
public:
    int NeedFlushToDestroy(ETexture *);
};
int EGraphics::NeedFlushToDestroy(ETexture *) { return 1; }
