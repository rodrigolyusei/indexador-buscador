#include <stdio.h>
#include <wchar.h>
#include <locale.h>

void removerAcentos(wchar_t *str) {
    wchar_t comAcento[] = L"áàâãéèêíìîóòôõúùûç";
    wchar_t semAcento[] = L"aaaaeeeiiioooouuuc";

    for (size_t i = 0; i < wcslen(str); i++) {
        for (size_t j = 0; j < wcslen(comAcento); j++) {
            if (str[i] == comAcento[j]) {
                str[i] = semAcento[j];
                break;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");  // Configuração da localidade para suporte a caracteres especiais
    wchar_t palavra[] = L"árvóres";

    wprintf(L"Palavra original: %ls\n", palavra);

    removerAcentos(palavra);

    wprintf(L"Palavra sem acentos: %ls\n", palavra);

    return 0;
}