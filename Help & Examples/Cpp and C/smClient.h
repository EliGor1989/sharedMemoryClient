#define EXPORT __declspec(dllexport)


EXPORT int abrirMemoria(char *nombre, int tipo);
EXPORT int abrirMemoriaString(char *nombre, int cantPalabras);

EXPORT int readIntValue(char *nomMemoria, int posicion);
EXPORT void writeIntValue(char *nomMemoria, int posicion,int valor);
EXPORT void writeFloatValue(char *nomMemoria, int posicion, float valor);
EXPORT float readFloatValue(char *nomMemoria, int posicion);
EXPORT void writeDoubleValue(char *nomMemoria, int posicion, double valor);
EXPORT double readDoubleValue(char *nomMemoria, int posicion);
EXPORT void writeStringValue(char *nomMemoria, int posicion, char *str);
EXPORT void readStringValue(char *nomMemoria, int posicion, char *str);
EXPORT void rStringValMatlab(char *nomMemoria, int posicion, char **str);

EXPORT int gestMemoria(int cantidad);
EXPORT int crearMemoria(char *nombre, int cantidad, int tipo);
EXPORT void liberarMemorias();


