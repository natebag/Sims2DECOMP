class EStream;
class EStorable { };
class ISimsMultiTileObjectModel : public EStorable { };

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, ISimsMultiTileObjectModel* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
