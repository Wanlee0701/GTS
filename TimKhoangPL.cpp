//pp tiep tuyen nghiem cua pt

#include<stdio.h>
#include<math.h>

/*
Pt: 21x^5 - 12x^4 + 3x^2 - 15 = 0
f'(x) = 
*/



float tinh_da_thuc(float he_so[], int bac, float x) {
    float ket_qua = 0.0;
    for (int i = bac; i >= 0; --i) {
        ket_qua += he_so[i] * pow(x, i);
    }
    return ket_qua;
}

void tim_khoang_phan_ly_nghiem(float he_so[], int bac, float gioi_han_duoi, float gioi_han_tren, float buoc) {
    float x1, x2, y1, y2;
    
    printf("Cac khoang phan ly nghiem:\n");
    
    x1 = gioi_han_duoi;
    y1 = tinh_da_thuc(he_so, bac, x1);
    
    while (x1 < gioi_han_tren) {
        x2 = x1 + buoc;
        y2 = tinh_da_thuc(he_so, bac, x2);
        
        if (y1 * y2 < 0) {
            printf("[%f, %f]\n", x1, x2);
        }
        
        x1 = x2;
        y1 = y2;
    }
}

int main() {
    float he_so[4]; // M?ng d? luu tr? các h? s? c?a da th?c b?c 5
    int bac = 3;
    float gioi_han_duoi, gioi_han_tren, buoc;
    
    // Nh?p các h? s? c?a da th?c
    printf("Nhap cac he so cua da thuc bac 5 (he so tu bac 5 den bac 0):\n");
    for (int i = bac; i >= 0; --i) {
        printf("Nhap he so tu bac %d: ", i);
        scanf("%f", &he_so[i]);
    }
    
    // Nh?p gi?i h?n du?i và gi?i h?n trên c?a mi?n giá tr? x
    printf("Nhap gioi han duoi cua mien gia tri x: ");
    scanf("%f", &gioi_han_duoi);
    printf("Nhap gioi han tren cua mien gia tri x: ");
    scanf("%f", &gioi_han_tren);
    
    //Nhap do dai cac khoang
    printf("Nhap do dai cua cac khoang: ");
    scanf("%f", &buoc);
    
    // Tìm và hi?n th? các kho?ng phân ly nghi?m
    tim_khoang_phan_ly_nghiem(he_so, bac, gioi_han_duoi, gioi_han_tren, buoc);
    
    return 0;
}

