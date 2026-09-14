public class ArrayOperations {

    public void arraSort(int arr[]) {

        for (int itemp = 0; itemp < arr.length; itemp++) {

            for (int jtemp = itemp + 1; jtemp < arr.length; jtemp++) {

                if (arr[itemp] > arr[jtemp]) {

                    int temp = arr[itemp];
                    arr[itemp] = arr[jtemp];
                    arr[jtemp] = temp;
                }
            }
        }
    }

    public int arraySum(int arr[]) {

        int sum = 0;

        for (int itemp = 0; itemp < arr.length; itemp++) {
            sum = sum + arr[itemp];
        }

        return sum;
    }

    public void display(int arr[]) {

        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }

        System.out.println();
    }

    public double calculateAvgArray(int arr[]) {

        double avg = (double) arraySum(arr) / arr.length;

        return avg;
    }

    public int[] copyArray(int arr[]) {

        int copy[] = new int[arr.length];

        for (int temp = 0; temp < copy.length; temp++) {
            copy[temp] = arr[temp];
        }

        return copy;
    }

    public int findMax(int arr[]) {

        int max = arr[0];

        for (int temp = 0; temp < arr.length; temp++) {

            if (max < arr[temp])
                max = arr[temp];
        }

        return max;
    }

    public int findMin(int arr[]) {

        int min = arr[0];

        for (int temp = 0; temp < arr.length; temp++) {

            if (min > arr[temp])
                min = arr[temp];
        }

        return min;
    }

    public int[] reverseArray(int arr[]) {

        for (int i = 0; i < arr.length / 2; i++) {

            int temp = arr[i];
            arr[i] = arr[arr.length - 1 - i];
            arr[arr.length - 1 - i] = temp;
        }

        return arr;
    }

    public void findDuplicate(int arr[]) {

        for (int i = 0; i < arr.length; i++) {

            for (int j = i + 1; j < arr.length; j++) {

                if (arr[i] == arr[j]) {
                    System.out.println("Duplicate : " + arr[i]);
                }
            }
        }
    }

    public void findCommon(int arr1[], int arr2[]) {

        for (int i = 0; i < arr1.length; i++) {

            for (int j = 0; j < arr2.length; j++) {

                if (arr1[i] == arr2[j]) {
                    System.out.println("Common : " + arr1[i]);
                }
            }
        }
    }
}