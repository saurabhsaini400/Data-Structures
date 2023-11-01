class Solution {
    public static void reverseArray(int[] arr, int start, int end) {
        while (start < end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    public void rotate(int[] arr, int K) {
        int length = arr.length;
        int effectiveRotations = K % length;

        reverseArray(arr, 0, length - 1);
        reverseArray(arr, 0, effectiveRotations - 1);
        reverseArray(arr, effectiveRotations, length - 1);
        
    }
}