import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();

        String name = input.split(" ")[0];
        int M1 = Integer.parseInt(input.split(" ")[1]);
        int M2 = Integer.parseInt(input.split(" ")[2]);

        DigitalNumber digitalNumber = new DigitalNumber(name, M1, M2);

        digitalNumber.drawCanvas();

        digitalNumber.printCanvas();
    }
}
