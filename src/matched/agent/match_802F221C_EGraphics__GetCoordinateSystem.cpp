typedef int ECoordinateSystem;
class EGraphics {
public:
    char m_pad[152];
    ECoordinateSystem m_coordinateSystem;
    ECoordinateSystem GetCoordinateSystem();
};
ECoordinateSystem EGraphics::GetCoordinateSystem() { return m_coordinateSystem; }
