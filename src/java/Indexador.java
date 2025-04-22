public class Indexador {
    public static void main(String[] args) {
        ManipulaArquivo manipulaArquivo = new ManipulaArquivo();

        if(args.length==1){
            manipulaArquivo.ler(args[0]);
            return;
        }
        if(args.length==2){
            manipulaArquivo.ler(args[0]);
            return;
        }
        System.out.println("Argumento inválido");
    }
}