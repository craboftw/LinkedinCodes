🎯 **¿Sabías que puedes introducir cualquier función —sin importar su firma— en un `std::function<void()>` (o en `auto`, si no eres *hater* de C++11) usando `std::bind`?**

En Refactoring Guru, el patrón **Command** se muestra con el enfoque orientado a objetos: una interfaz `Command` y una clase derivada por cada acción.
Funciona, sí… pero añade una capa de herencia a cada clase y eso es una mochila extra, incluso cuando no necesitas esa característica.

💡 Con **`std::bind`** puedes meter cualquier función en un objeto apilable dentro de una colección:

* **Sin herencia**
* **Sin clases extra**
* Envolviendo cualquier lógica (funciones libres, métodos con parámetros, funciones globales…)

🔗 **Código completo en GitHub:**
👉 [https://github.com/craboftw/LinkedinCodes/blob/main/CommandPatternWithBind/main.cpp](https://github.com/craboftw/LinkedinCodes/blob/main/CommandPatternWithBind/main.cpp)

📌 En mi ejemplo apilo en una colección:

* Funciones libres con parámetros
* Métodos de instancia
* Funciones globales con estado externo

✅ **Ventaja:** cero modificaciones en tus clases y cero acoplamiento. Súper adaptable a cualquier problema.

⚠️ **¿Te lo preguntarán en una entrevista?** Probablemente no.
Aunque forma parte del estándar desde C++11, rara vez se habla de todo su potencial. Pero cuando construyes sistemas reales, lo agradeces.
