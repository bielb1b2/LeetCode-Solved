public class IsPalindrome {

    public static void main(String args[]) {
        isPalindrome(121);
        isPalindrome(1221);
    }   

    public static boolean isPalindrome(int x) {
        String convertInt = String.valueOf(x);
        String invert = "";

        for (int i = convertInt.length() - 1; i >= 0; i--) {
            invert += convertInt.charAt(i);
        }
        
        if(convertInt.equals(invert)) {
            return true;
        }
        
        return false;
    }
}
