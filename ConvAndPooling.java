import java.util.Random;

public class ConvAndPooling {
    public static int imageLenght = 227;
    public static int stride = 4;
    public static int matrixLenght = 11;
    public static int[][] image = new int[imageLenght][imageLenght];
    public static int[][] matrix = new int[matrixLenght][matrixLenght];
    public static int[][] results = new int[55][55];
    public static int [][]pooling = new int[55 / matrixLenght][55 / matrixLenght];
    public static void Conv(){
        Random random = new Random();
        int i, j;
        for(i = 0; i < imageLenght; i++) {
            for(j = 0; j < imageLenght; j++) {
                image[i][j] = random.nextInt(255);
            }
        }

        for(i = 0; i < matrixLenght; i++) {
            for(j = 0; j < matrixLenght; j++) {
                matrix[i][j] = random.nextInt(2);
            }
        }


        int x = 0, y = 0;

        for(i = 0; i < imageLenght - matrixLenght + 1; i += stride) {
            for(j = 0; j < imageLenght - matrixLenght + 1; j += stride) {
                for(int k = 0; k < matrixLenght; k++) {
                    for(int m = 0; m < matrixLenght; m++) {
                        results[x][y] = results[x][y] + image[m + i][k + j] * matrix[m][k];
                    }
                }
                y++;
            }
            y = 0;
            x++;
        }
    }

    public static void Pooling(){
        int i, j;
        int a = 0, b = 0;
        for(i = 0; i < 55; i += matrixLenght) {
            for(j = 0; j < 55; j += matrixLenght) {
                int max = results[i][j];
                for(int k = 0; k < matrixLenght; k++){
                    for(int m = 0; m < matrixLenght; m++){
                        if(results[i + k][j + m] > max)
                            max = results[i + k][j + m];
                    }
                }
                pooling[a][b++] = max;
            }
            a++;
            b = 0;
        }
    }

    public static void Print(){
        int i, j;
        for(i = 0; i < 55 / matrixLenght; i++){
            for(j = 0; j < 55 / matrixLenght; j++){
                System.out.printf("%d ", pooling[i][j]);
            }
            System.out.println();
        }
    }


    public static void main(String[] args) {

        int i, j;
        Conv();
        Pooling();
        Print();
    }
}