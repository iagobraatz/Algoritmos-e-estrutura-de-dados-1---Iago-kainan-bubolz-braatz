int reverseBits(int n) {
    unsigned int numero = (unsigned int)n;
    unsigned int resultado = 0;
    
    for (int i = 0; i < 32; i++) {
        resultado <<= 1;
        resultado |= (numero & 1);
        numero >>= 1;
    }
    
    return (int)resultado;
}
