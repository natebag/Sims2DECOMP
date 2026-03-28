struct ERenderSurface {
    void DestroySubtextures();
};

struct EGraphics {
    void Destroy(ERenderSurface *surface);
};

struct ENgcGraphics : EGraphics {
    void Destroy(ERenderSurface *surface);
};

void ENgcGraphics::Destroy(ERenderSurface *surface) {
    surface->DestroySubtextures();
    EGraphics::Destroy(surface);
}
