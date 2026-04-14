// 0x8036723C ERAmbientScore::GetTypeKey (12B) const
extern int g_ERAmbientScore_TypeKey[3];
struct ERAmbientScore_GTK { int GetTypeKey() const; };
int ERAmbientScore_GTK::GetTypeKey() const { return g_ERAmbientScore_TypeKey[0]; }
