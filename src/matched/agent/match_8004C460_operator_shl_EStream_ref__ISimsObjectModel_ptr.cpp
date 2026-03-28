class EStream;
class EStorable { };
class ISimsObjectModel : public EStorable { };

extern EStream& operator<<(EStream&, EStorable*);

EStream& operator<<(EStream& stream, ISimsObjectModel* obj)
{
    return operator<<(stream, (EStorable*)obj);
}
