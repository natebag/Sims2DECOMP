/* operator>>(EStream &, EFontCharacter *&) - 64 bytes at 0x803634E0 */

class EStorable;
class EStream;
class EFontCharacter;

EStream& operator>>(EStream&, EStorable *&);

EStream& operator>>(EStream& stream, EFontCharacter *& ptr) {
    EStorable *storable;
    operator>>(stream, storable);
    ptr = (EFontCharacter *)storable;
    return stream;
}
