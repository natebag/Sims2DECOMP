class EShader;
class EGraphics {
public:
    int NeedFlushToDestroy(EShader *);
};
int EGraphics::NeedFlushToDestroy(EShader *) { return 1; }
