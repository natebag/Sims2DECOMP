class EResource;
void EResource_DelRef(EResource* res);

class REffectsEmitter {
public:
    char pad[0x1C];
    EResource* m_subResource;

    void DelRefSubResources();
};

void REffectsEmitter::DelRefSubResources()
{
    if (m_subResource != 0) {
        EResource_DelRef(m_subResource);
        m_subResource = 0;
    }
}
