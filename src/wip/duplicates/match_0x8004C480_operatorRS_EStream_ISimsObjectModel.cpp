struct EStorable;
struct EStream;
struct ISimsObjectModel;

EStream& operator>>(EStream&, EStorable*&);

EStream& operator>>(EStream& stream, ISimsObjectModel*& obj) {
    EStorable* storable;
    operator>>(stream, storable);
    obj = (ISimsObjectModel*)storable;
    return stream;
}
