
## Instruções para compilação no VSCode

Caso tenha problemas para compilar, primeiro verifique:

 1. Instalou a extensão correta do C/C++;
 2. vá até `.vscode/c_cpp_properties.json` e coloque os segunintes caminhos dentro de `"includePath"`:
    - "C:\\MinGW\\include"
    - "C:\\MinGW\\lib\\gcc\\mingw32\\6.3.0"

            "includePath": [
                "${workspaceFolder}/**",
                "C:\\MinGW\\include",
                "C:\\MinGW\\lib\\gcc\\mingw32\\6.3.0"
            ],

3. Se ainda não deu certo, troque:
    - `"compilerPath"` para `"C:\\MinGW\\bin\\gcc.exe"`
    - `"intelliSenseMode"` para `"windows-gcc-x86"`

## Instruções para execução

Para compilar, primeiro se certique que está dentro da pasta src. Depois use o comando:

```
gcc indexador.c -o executavel
executavel ../data/input/teste.txt
```