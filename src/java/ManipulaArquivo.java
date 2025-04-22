import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class ManipulaArquivo {
  public void ler(String diretorio) {

    System.out.printf("\nConteúdo do arquivo texto:\n");

    try {
      FileReader arq = new FileReader(diretorio);
      BufferedReader lerArq = new BufferedReader(arq);

      //le a primeira linha e enquanto nao for vazio le as proximas
      String linha = lerArq.readLine();
      while (linha != null) {
        System.out.printf("%s\n", linha);
        linha = lerArq.readLine();
      }
      arq.close();
    } catch (IOException e) {
        System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
    }

    System.out.println();
  }
}