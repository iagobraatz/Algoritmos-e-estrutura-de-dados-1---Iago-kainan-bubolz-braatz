int majorityElement(int* nums, int numsSize) {
    int candidato = 0;
    int contador = 0;

    for (int i = 0; i < numsSize; i++) {
        if (contador == 0) {
            candidato = nums[i];
        }

        if (nums[i] == candidato) {
            contador++;
        } else {
            contador--;
        }
    }

    return candidato;
}
