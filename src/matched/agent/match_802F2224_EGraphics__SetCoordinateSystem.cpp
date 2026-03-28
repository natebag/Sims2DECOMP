typedef int ECoordinateSystem;
class EGraphics {
public:
    char m_pad[152];
    ECoordinateSystem m_coordinateSystem;
    void SetCoordinateSystem(ECoordinateSystem);
};
void EGraphics::SetCoordinateSystem(ECoordinateSystem cs) { m_coordinateSystem = cs; }
