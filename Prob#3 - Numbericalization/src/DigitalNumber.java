public class DigitalNumber {
    public static int defaultScale = 5;
    private String number;
    private int verScale;
    private int horScale;
    private char canvas[][];

    DigitalNumber(String number, int verScale, int horScale) {
        setNumber(number);
        setHorScale(horScale);
        setVerScale(verScale);

        int numberLength = number.length();
        int verticalLength = defaultScale * verScale;
        int horizontalLength = defaultScale * horScale * numberLength + ((numberLength - 1) * horScale);
        canvas = new char[verticalLength][horizontalLength];
    }

    void drawCanvas() {
        for (int i = 0; i < canvas.length; i++) {
            for (int j = 0; j < canvas[i].length; j++) {
                int posI = i / verScale;
                int posJ = j / horScale;
                int currentNumber = Character.getNumericValue(number.charAt(j / (defaultScale * horScale + horScale)));
                if (posJ % (defaultScale + 1) < defaultScale) {
                    canvas[i][j] = NumberTemplate.NUMBER_TEMPLATE[currentNumber][posI][posJ % (defaultScale + 1)];
                } else {
                    canvas[i][j] = ' ';
                }
            }
        }
    }

    void printCanvas() {
        for (char[] ver : canvas) {
            for (char c : ver) {
                System.out.print(c);
            }
            System.out.println();
        }
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public void setVerScale(int verScale) {
        this.verScale = verScale;
    }

    public void setHorScale(int horScale) {
        this.horScale = horScale;
    }
}
