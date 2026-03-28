struct TypeInfoData { int name; int key; unsigned short version; unsigned short readVer; };
TypeInfoData s_REffectsAttachment_tid = { 1, 2, 3, 4 };
class REffectsAttachment { public: unsigned short GetTypeVersion() const; };
unsigned short REffectsAttachment::GetTypeVersion() const { return s_REffectsAttachment_tid.version; }
