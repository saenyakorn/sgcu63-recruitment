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
        int horizontalLength = defaultScale * horScale * numberLength + (numberLength * horScale);
        canvas = new char[verticalLength][horizontalLength];
    }

    void drawCanvas() {
        for (int i = 0; i < canvas.length; i++) {
            for (int j = 0; i < canvas[i].length; j++) {
                int currentNumber = Character.getNumericValue(number.charAt(j % (defaultScale * horScale + horScale)));
                int posI = i / verScale;
                int posJ = j / horScale;
                canvas[i][j] = posJ >= 5 ? ' ' : NumberTemplate.NUMBER_TEMPLATE[currentNumber][posI][posJ];
            }
        }
    }

    void printCanvas() {
        for (char[] ver : canvas) {
            for (char c : ver) {
                System.out.println(c);
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
