import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

// Precisa tentar o metodo inteligente

public class RemoveLetterToEqualizeFrequency {

    public static void main(String args[]) {
        // System.out.println(equalFrequency("abcc"));
        // System.out.println(equalFrequency("aazz"));
        // System.out.println(equalFrequency("aabbccc"));
        // System.out.println(equalFrequency("bac"));
        System.out.println(metodoIgenuo("ddaccb"));
    }   


    public static boolean metodoIgenuo(String word) {
        
        for (int i = 0; i < word.length(); i++)
        {
            Map<String, Integer> lista = new HashMap<>();
            

            String newString = removeCharAtIndex(i, word);

            for (int j = 0; j < newString.length(); j++) {
                String letra = String.valueOf(newString.charAt(j));
    
                if(!lista.containsKey(letra)) {
                    lista.put(letra, 1);
                } else {
                    lista.compute(letra, (k, v) -> v+1);
                }
            }

            System.out.println(newString);

            Set<Integer> teste = new HashSet<>();
            teste.addAll(lista.values());

            if(teste.size() == 1) {
                return true;
            }
        }

        return false;
    }

    public static String removeCharAtIndex(int index, String word) {
        return word.substring(0, index) + word.substring(index+1, word.length());
    }

    public static boolean equalFrequency(String word) {
        Map<String, Integer> lista = new HashMap<>();

        // 1. Maior quantidade de letras precisa ser unico, se n for unico = False
        // 2. Se possuir > 2 quantidades de letras diferentes = False
        // 3. Se todas as letras possuirem a mesma quantidade = False

        for (int i = 0; i < word.length(); i++) {
            String letra = String.valueOf(word.charAt(i));

            if(!lista.containsKey(letra)) {
                lista.put(letra, 1);
            } else {
                lista.compute(letra, (k, v) -> v+1);
            }
        }

        
        

        Set<Integer> teste = new HashSet<>();
        teste.addAll(lista.values());

        if(teste.size() == 1 && teste.contains(1)) {
            return true;
        }

        if(teste.size() > 2 || teste.size() == 1) {
            return false;
        }

        return true;
    }

}


