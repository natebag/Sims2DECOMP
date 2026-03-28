class EStream;
class EStorable { };
class ISimsWallObjectModel : public EStorable { };

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, ISimsWallObjectModel* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
