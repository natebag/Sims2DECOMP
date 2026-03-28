class ELevelDrawData;

class EIStaticModel {
public:
    void Draw(ELevelDrawData&);
};

class EIFenceWall : public EIStaticModel {
public:
    void Draw(ELevelDrawData&);
};

void EIFenceWall::Draw(ELevelDrawData& drawData)
{
    EIStaticModel::Draw(drawData);
}
