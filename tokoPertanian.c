#include <stdio.h>
#include <stdlib.h>

#define merah "\x1b[31m"
#define ijo "\x1b[32m"
#define kuning "\x1b[33m"
#define biru "\x1b[34m"
#define reset "\x1b[0m"

struct barang
{
    char jenis[20];
    int stok;
    float harga;
};
void clear(){
    system("clear");
}
void load(struct barang tabbarang[]){
    
    int i = 0;
    FILE *stokBarang = fopen("DataStok.csv", "r");
    if(stokBarang!=NULL){
        while (fscanf(stokBarang, "%49[^,],%d,%f\n", tabbarang[i].jenis, &tabbarang[i].stok, &tabbarang[i].harga) == 3) {
            i++;
        }
    }
    fclose(stokBarang);
}
void save(struct barang tabbarang[]){
    
    FILE *stokBarang = fopen("DataStok.csv", "w");

    for (int i=0;i<3;i++){
        fprintf(stokBarang, "%s,%d,%2f\n",tabbarang[i].jenis,tabbarang[i].stok,tabbarang[i].harga);
    }
    fclose(stokBarang);
}

void tStok(int pilb,struct barang tabarang[]){
    
    do{
        int jum;
        clear();
        printf("\n====================== TAMBAH STOK ========================\n");
        printf("===========================================================\n");
        printf("|| "biru"No."reset"|| "biru"PILIH BARANG"reset" ||  "biru"STOK"reset"  ||        "biru"HARGA"reset"          ||\n");
        printf("===========================================================\n");
        printf("|| "ijo"1."reset" || "ijo"PUPUK"reset"        || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[0].stok,tabarang[0].harga);
        printf("|| "ijo"2."reset" || "ijo"BENIH"reset"        || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[1].stok,tabarang[1].harga);
        printf("|| "ijo"3."reset" || "ijo"PESTISIDA"reset"    || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[2].stok,tabarang[2].harga);
        printf("|| "merah"0."reset" || "merah"KEMBALI"reset"                                         ||\n");
        printf("===========================================================\n");

        printf(biru);
        printf("Masukkan Pilihan : ");
        scanf("%d", &pilb);
        
        switch (pilb){
            case 1:
                printf("Masukkan Jumlah Stok Yang Ingin Anda Tambahkan : ");
                scanf("%d", &jum);
                tabarang[0].stok = tabarang[0].stok + jum ;
                printf("\n"ijo"%d "biru"STOK TELAH DITAMBAHKAN KE "ijo"PUPUK\n", jum);
                break;
            case 2:
                printf("Masukkan Jumlah Stok Yang Ingin Anda Tambahkan : ");
                scanf("%d", &jum);
                tabarang[1].stok = tabarang[1].stok + jum ;
                printf("\n"ijo"%d "biru"STOK TELAH DITAMBAHKAN KE "ijo"BENIH\n", jum);
                break;
            case 3:
                printf("Masukkan Jumlah Stok Yang Ingin Anda Tambahkan : ");
                scanf("%d", &jum);
                tabarang[2].stok = tabarang[2].stok + jum ;
                printf("\n"ijo"%d "biru"STOK TELAH DITAMBAHKAN KE "ijo"PESTISIDA\n", jum);
                break;
            case 0:
                printf(merah"\nKembali Ke Menu Sebelumnya..."reset);
                break;
            default:
                printf(merah"Input Angka Sesuai Menu Yang Tertera(1/2/3/0)"reset);
                break;
            }
            save(tabarang);
        if (pilb != 0){
                printf(merah"\nTekan"reset" "ijo"Enter"reset" "merah"Untuk Kembali Ke Menu Sebelumnya..."reset);
                getchar();
                getchar();
                clear();
            }
    }while(pilb!=0);
}
void kStok(int pilb,struct barang tabarang[]){
    
    do{
        int jum;
        clear();
        printf("\n====================== KURANGI STOK =======================\n");
        printf("===========================================================\n");
        printf("|| "biru"No."reset"|| "biru"PILIH BARANG"reset" ||  "biru"STOK"reset"  ||        "biru"HARGA"reset"          ||\n");
        printf("===========================================================\n");
        printf("|| "ijo"1."reset" || "ijo"PUPUK"reset"        || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[0].stok,tabarang[0].harga);
        printf("|| "ijo"2."reset" || "ijo"BENIH"reset"        || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[1].stok,tabarang[1].harga);
        printf("|| "ijo"3."reset" || "ijo"PESTISIDA"reset"    || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[2].stok,tabarang[2].harga);
        printf("|| "merah"0."reset" || "merah"KEMBALI"reset"                                         ||\n");
        printf("===========================================================\n");

        printf(biru);
        printf("Masukkan Pilihan : ");
        scanf("%d", &pilb);

        switch (pilb){
            case 1:
                printf("Masukkan Jumlah Stok Yang Ingin Anda Kurangi : ");
                scanf("%d", &jum);
                tabarang[0].stok = tabarang[0].stok - jum ;
                printf("\n"ijo"%d "biru"STOK TELAH DIKURANGI DARI "ijo"PUPUK\n", jum);
                break;
            case 2:
                printf("Masukkan Jumlah Stok Yang Ingin Anda Kurangi : ");
                scanf("%d", &jum);
                tabarang[1].stok = tabarang[1].stok - jum ;
                printf("\n"ijo"%d "biru"STOK TELAH DIKURANGI DARI "ijo"BENIH\n", jum);
                break;
            case 3:
                printf("Masukkan Jumlah Stok Yang Ingin Anda Kurangi : ");
                scanf("%d", &jum);
                tabarang[2].stok = tabarang[2].stok - jum ;
                printf("\n"ijo"%d "biru"STOK TELAH DIKURANGI DARI "ijo"PESTISIDA\n", jum);
                break;
            case 0:
                printf(merah"\nKembali Ke Menu Sebelumnya..."reset);
                break;
            default:
                printf(merah"Input Angka Sesuai Menu Yang Tertera(1/2/3/0)"reset);
                break;
            }
            save(tabarang);
        if (pilb != 0){
                printf(merah"\nTekan"reset" "ijo"Enter"reset" "merah"Untuk Kembali Ke Menu Sebelumnya..."reset);
                getchar();
                getchar();
                clear();
            }
    }while(pilb!=0);
}
void uHarga(int pilb, struct barang tabarang[]){

    do{
        float hbaru; 
        clear();
        printf("\n===================== PERBARUI HARGA ======================\n");
        printf("===========================================================\n");
        printf("|| "biru"No."reset"|| "biru"PILIH BARANG"reset" ||  "biru"STOK"reset"  ||        "biru"HARGA"reset"          ||\n");
        printf("===========================================================\n");
        printf("|| "ijo"1."reset" || "ijo"PUPUK"reset"        || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[0].stok,tabarang[0].harga);
        printf("|| "ijo"2."reset" || "ijo"BENIH"reset"        || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[1].stok,tabarang[1].harga);
        printf("|| "ijo"3."reset" || "ijo"PESTISIDA"reset"    || "ijo"%d\t"reset"||"ijo" Rp.%.2f\t\t"reset" ||\n",tabarang[2].stok,tabarang[2].harga);
        printf("|| "merah"0."reset" || "merah"KEMBALI"reset"                                         ||\n");
        printf("===========================================================\n");

        printf(biru);
        printf("Masukkan Pilihan : ");
        scanf("%d", &pilb);
        printf(biru);

        switch (pilb){
            case 1:
                printf(biru);
                printf("MASUKKAN HARGA BARU UNTUK "ijo"%s"reset" "biru":"reset" "ijo"Rp.",tabarang[0].jenis);
                scanf("%f", &hbaru);
                tabarang[0].harga = hbaru ;
                printf("\n"biru"HARGA"ijo" %s "biru"TELAH DIUBAH MENJADI "ijo"Rp.%.2f\n", tabarang[0].jenis,hbaru);
                break;
            case 2:
                printf(biru);
                printf("MASUKKAN HARGA BARU UNTUK "ijo"%s"reset" "biru":"reset" "ijo"Rp.",tabarang[1].jenis);
                scanf("%f", &hbaru);
                tabarang[1].harga = hbaru ;
                printf("\n"biru"HARGA"ijo" %s "biru"TELAH DIUBAH MENJADI "ijo"Rp.%.2f\n", tabarang[1].jenis,hbaru);
                break;
            case 3:
                printf(biru);
                printf("MASUKKAN HARGA BARU UNTUK "ijo"%s"reset" "biru":"reset" "ijo"Rp.",tabarang[2].jenis);
                scanf("%f", &hbaru);
                tabarang[2].harga = hbaru ;
                printf("\n"biru"HARGA"ijo" %s "biru"TELAH DIUBAH MENJADI "ijo"Rp.%.2f\n", tabarang[2].jenis,hbaru);
                break;
            case 0:
                printf(merah"\nKembali Ke Menu Sebelumnya..."reset);
                break;
            default:
                printf(merah"Input Angka Sesuai Menu Yang Tertera(1/2/3/0)"reset);
                break;
            }
            save(tabarang);
        if (pilb != 0){
                printf(merah"\nTekan"reset" "ijo"Enter"reset" "merah"Untuk Kembali Ke Menu Sebelumnya..."reset);
                getchar();
                getchar();
                clear();
            }
    }while(pilb!=0);
}
void tampil(struct barang tabbarang[]){
    
    clear();
    
    printf("\n");
    printf("========================================= INVENTARIS ==============================================\n");
    printf("===================================================================================================\n");
    printf("|| "biru"No.BARANG"reset"            ||              "biru"STOK"reset"             ||                 "biru"HARGA"reset"                ||\n");
    printf("||======================||===============================||======================================||\n");
    for (int i = 0 ; i < 3; i++)
    {
        int j=1+i;
        printf("|| "kuning"%d. %s"reset"\t\t||\t\t"kuning"%d"reset"\t\t ||\t\t"kuning"Rp.%.2f"reset"\t\t ||\n",j,tabbarang[i].jenis,tabbarang[i].stok,tabbarang[i].harga);
    }
    printf("===================================================================================================\n");
    
}
void menuStok(int pilb, struct barang barang[]){
    do {
        int subpil;
        clear();
        printf("\n========================================================\n");
        printf("|| "biru"No."reset"||          "biru"PILIH MENU STOK BARANG"reset"              ||\n");
        printf("========================================================\n");
        printf("|| "ijo"1."reset" || "ijo"TAMBAH STOK BARANG"reset"                           ||\n");
        printf("|| "ijo"2."reset" || "ijo"KURANGI STOK BARANG"reset"                          ||\n");
        printf("|| "ijo"3."reset" || "ijo"UBAH HARGA BARANG"reset"                            ||\n");
        printf("|| "merah"0."reset" || "merah"KEMBALI"reset"                                      ||\n");
        printf("========================================================\n");
        
        printf(biru);
        printf("Masukkan Pilihan : ");
        scanf("%d", &pilb);
        printf(reset);

        switch(pilb){
            case 1 : 
                tStok(subpil,barang);
                break;
            case 2 :
                kStok(subpil,barang);
                break;
            case 3 :
                uHarga(subpil,barang);
                break;
            case 0 :
                printf(merah"\nKembali Ke Menu Utama..."reset);
                break;
            default : 
                printf(merah"Input Angka Sesuai Menu Yang Tertera(1/2/3/0)"reset);
                break;
        }
        if (pilb != 0){
            printf(merah"\nTekan"reset" "ijo"Enter"reset" "merah"Untuk Kembali Ke Menu Sebelumnya..."reset);
            getchar();
            getchar();
            clear();
        }
    }while(pilb!=0);
}

void banyak(struct barang tabbarang[]){

    int pass,i,max;
    struct barang tmp;

    for(pass = 0; pass < 3 - 1; pass++){
        max = pass;
        for(i = max +1; i < 3; i++){
            if(tabbarang[i].stok > tabbarang[max].stok){
            max = i;    
            }
        }
        tmp = tabbarang[pass];
        tabbarang[pass] = tabbarang[max];
        tabbarang[max] = tmp;
    }
    clear();
    tampil(tabbarang);
}
void kecil(struct barang tabbarang[]){

    int pass,i,max;
    struct barang tmp;

    for(pass = 0; pass < 3 - 1; pass++){
        max = pass;
        for(i = max +1; i < 3; i++){
            if(tabbarang[i].stok < tabbarang[max].stok){
            max = i;    
            }
        }
        tmp = tabbarang[pass];
        tabbarang[pass] = tabbarang[max];
        tabbarang[max] = tmp;
    }
    clear();
    tampil(tabbarang);
}
int csBanyak(struct barang tabbarang[]){
    
    int imax=0;
    int stokmax=tabbarang[0].stok;

    for (int i = 0; i < 3; i++)
    {
        if(tabbarang[i].stok > stokmax){
            stokmax = tabbarang[i].stok;
            imax = i;
        }
    }
    return imax;

}
int csKecil(struct barang tabbarang[]){
    
    int imin=0;
    int stokmin=tabbarang[0].stok;

    for (int i = 0; i < 3; i++)
    {
        if(tabbarang[i].stok < stokmin){
            stokmin = tabbarang[i].stok;
            imin = i;
        }
    }
    return imin;

}
int chTinggi(struct barang tabbarang[]){
    
    int himax=0;
    float harting=tabbarang[0].harga;

    for (int i = 0; i < 3; i++)
    {
        if(tabbarang[i].harga > harting){
            harting = tabbarang[i].harga;
            himax = i;
        }
    }
    return himax;
}
int chRendah(struct barang tabbarang[]){
    
    int himin=0;
    float haren=tabbarang[0].harga;

    for (int i = 0; i < 3; i++)
    {
        if(tabbarang[i].harga < haren){
            haren = tabbarang[i].harga;
            himin = i;
        }
    }
    return himin;
}
void hTinggi(struct barang tabbarang[]){

    int pass,i,max;
    struct barang tmp;

    for(pass = 0; pass < 3 - 1; pass++){
        max = pass;
        for(i = max +1; i < 3; i++){
            if(tabbarang[i].harga > tabbarang[max].harga){
            max = i;    
            }
        }
        tmp = tabbarang[pass];
        tabbarang[pass] = tabbarang[max];
        tabbarang[max] = tmp;
    }
    clear();
    tampil(tabbarang);
}
void hRendah(struct barang tabbarang[]){

    int pass,i,min;
    struct barang tmp;

    for(pass = 0; pass < 3 - 1; pass++){
        min = pass;
        for(i = min +1; i < 3; i++){
            if(tabbarang[i].harga < tabbarang[min].harga){
            min = i;    
            }
        }
        tmp = tabbarang[pass];
        tabbarang[pass] = tabbarang[min];
        tabbarang[min] = tmp;
    }
    clear();
    tampil(tabbarang);
}
void menucData(int pilb, struct barang tabbarang[]){
    
    do {
        int imax=csBanyak(tabbarang);
        int imin=csKecil(tabbarang);
        int himax=chTinggi(tabbarang);
        int himin=chRendah(tabbarang);
        clear();
        printf("\n========================================================\n");
        printf("|| "biru"No."reset"||          "biru"PILIH MENU CARI DATA BARANG"reset"         ||\n");
        printf("========================================================\n");
        printf("|| "ijo"1."reset" || "ijo"CARI BARANG DENGAN STOK PALING BANYAK"reset"        ||\n");
        printf("|| "ijo"2."reset" || "ijo"CARI BARANG DENGAN STOK PALING SEDIKIT"reset"       ||\n");
        printf("|| "ijo"3."reset" || "ijo"URUTKAN BARANG DARI STOK PALING BANYAK"reset"       ||\n");
        printf("|| "ijo"4."reset" || "ijo"URUTKAN BARANG DARI STOK PALING SEDIKIT"reset"      ||\n");
        printf("|| "ijo"5."reset" || "ijo"CARI BARANG DENGAN HARGA PALING TINGGI"reset"       ||\n");
        printf("|| "ijo"6."reset" || "ijo"CARI BARANG DENGAN HARGA PALING RENDAH"reset"       ||\n");
        printf("|| "ijo"7."reset" || "ijo"URUTKAN BARANG DARI HARGA PALING BANYAK"reset"      ||\n");
        printf("|| "ijo"8."reset" || "ijo"URUTKAN BARANG DARI HARGA PALING RENDAH"reset"      ||\n");
        printf("|| "merah"0."reset" || "merah"KEMBALI"reset"                                      ||\n");
        printf("========================================================\n");

        printf(biru);
        printf("Masukkan Pilihan : ");
        scanf("%d", &pilb);
        printf(reset);

        switch(pilb){
            case 1 :
                printf("\n======= "biru"BARANG DENGAN STOK PALING BANYAK"reset" =======\n");
                printf(""ijo"%s"reset" ADALAH BARANG DENGAN STOK PALING BANYAK, DENGAN JUMLAH STOK SEBANYAK "ijo"%d"reset" DAN HARGA SENILAI "ijo"Rp.%.2f"reset"\n", tabbarang[imax].jenis,tabbarang[imax].stok,tabbarang[imax].harga);
                break;
            case 2 :
                printf("\n======= "biru"BARANG DENGAN STOK PALING SEDIKIT"reset" =======\n");
                printf(""ijo"%s"reset" ADALAH BARANG DENGAN STOK PALING SEDIKIT, DENGAN JUMLAH STOK SEBANYAK "ijo"%d"reset" DAN HARGA SENILAI "ijo"Rp.%.2f"reset"\n", tabbarang[imin].jenis,tabbarang[imin].stok,tabbarang[imin].harga);
                break;
            case 3 :
                banyak(tabbarang);
                printf(biru"URUTAN BARANG BERDASARKAN STOK PALING BANYAK\n"reset);
                break;
            case 4 :
                kecil(tabbarang);
                printf(biru"URUTAN BARANG BERDASARKAN STOK PALING SEDIKIT\n"reset);
                break;
            case 5 :
                printf("\n======= "biru"BARANG DENGAN HARGA PALING TINGGI"reset" =======\n");
                printf(""ijo"%s"reset" ADALAH BARANG DENGAN HARGA PALING TINGGI, DENGAN HARGA SENILAI "ijo"Rp.%.2f"reset" DAN JUMLAH STOK SEBANYAK "ijo"%d"reset"\n", tabbarang[himax].jenis,tabbarang[himax].harga,tabbarang[himax].stok);
                break;
            case 6 :
                printf("\n======= "biru"BARANG DENGAN HARGA PALING RENDAH"reset" =======\n");
                printf(""ijo"%s"reset" ADALAH BARANG DENGAN HARGA PALING RENDAH, DENGAN HARGA SENILAI "ijo"Rp.%.2f"reset" DAN JUMLAH STOK SEBANYAK "ijo"%d"reset"\n", tabbarang[himin].jenis,tabbarang[himin].harga,tabbarang[himin].stok);
                break;
            case 7 :
                hTinggi(tabbarang);
                printf(biru"URUTAN BARANG BERDASARKAN HARGA PALING TINGGI\n"reset);
                break;
            case 8 :
                hRendah(tabbarang);
                printf(biru"URUTAN BARANG BERDASARKAN HARGA PALING RENDAH\n"reset);
                break;
            case 0 : 
                printf(merah"\nKembali Ke Menu Utama..."reset);
                break;
            default :
                printf(merah"Input Angka Sesuai Menu Yang Tertera(1/2/3/4/5/6/7/8/0)"reset);
                break;
        }
        if (pilb != 0){
            printf(merah"\nTekan"reset" "ijo"Enter"reset" "merah"Untuk Kembali Ke Menu Sebelumnya..."reset);
            getchar();
            getchar();
            clear();
        }
    }while(pilb!=0);
}


int main(){

    int pil,subpil;
    struct barang tabbarang[3];
    clear();

    printf(kuning);
    printf(" ##::::'##::::'###::::'##::: ##::::'###::::::::::'##:'########:'##::::'##:'########:'##::: ##:\n");
    printf(" ###::'###:::'## ##::: ###:: ##:::'## ##::::::::: ##: ##.....:: ###::'###: ##.....:: ###:: ##:\n");
    printf(" ####'####::'##:. ##:: ####: ##::'##:. ##:::::::: ##: ##::::::: ####'####: ##::::::: ####: ##:\n");
    printf(" ## ### ##:'##:::. ##: ## ## ##:'##:::. ##::::::: ##: ######::: ## ### ##: ######::: ## ## ##:\n");
    printf(" ##. #: ##: #########: ##. ####: #########:'##::: ##: ##...:::: ##. #: ##: ##...:::: ##. ####:\n");
    printf(" ##:.:: ##: ##.... ##: ##:. ###: ##.... ##: ##::: ##: ##::::::: ##:.:: ##: ##::::::: ##:. ###:\n");
    printf(" ##:::: ##: ##:::: ##: ##::. ##: ##:::: ##:. ######:: ########: ##:::: ##: ########: ##::. ##:\n");
    printf("..:::::..::..:::::..::..::::..::..:::::..:::......:::........::..:::::..::........::..::::..::\n");
    printf("::::::::::::'####:'##::: ##:'##::::'##:'########:'##::: ##:'########::::'###::::'########::'####::'######::\n");
    printf("::::::::::::. ##:: ###:: ##: ##:::: ##: ##.....:: ###:: ##::... ##..::::'## ##::: ##.... ##:. ##::'##... ##:\n");
    printf("::::::::::::: ##:: ####: ##: ##:::: ##: ##::::::: ####: ##:::: ##:::::'##:. ##:: ##:::: ##:: ##:: ##:::..::\n");
    printf("::::::::::::: ##:: ## ## ##: ##:::: ##: ######::: ## ## ##:::: ##::::'##:::. ##: ########::: ##::. ######::\n");
    printf("::::::::::::: ##:: ##. ####:. ##:: ##:: ##...:::: ##. ####:::: ##:::: #########: ##.. ##:::: ##:::..... ##:\n");
    printf("::::::::::::: ##:: ##:. ###::. ## ##::: ##::::::: ##:. ###:::: ##:::: ##.... ##: ##::. ##::: ##::'##::: ##:\n");
    printf("::::::::::::'####: ##::. ##:::. ###:::: ########: ##:::. ##:::: ##:::: ##:::: ##: ##:::. ##:'####:. ######::\n");
    printf("::::::::::::....::..::::..:::::...:::::........::..:::::..:::::..:::::..::..::::..:::::..::....:::......:::\n");
    printf("::::::::::::::::::::::::'########::'########:'########::'########::::'###::::'##::: ##:'####::::'###::::'##::: ##:\n");
    printf(":::::::::::::::::::::::: ##.... ##: ##.....:: ##.... ##:... ##..::::'## ##::: ###:: ##:. ##::::'## ##::: ###:: ##:\n");
    printf(":::::::::::::::::::::::: ##:::: ##: ##::::::: ##:::: ##:::: ##:::::'##:. ##:: ####: ##:: ##:::'##:. ##:: ####: ##:\n");
    printf(":::::::::::::::::::::::: ########:: ######::: ########::::: ##::::'##:::. ##: ## ## ##:: ##::'##:::. ##: ## ## ##:\n");
    printf(":::::::::::::::::::::::: ##.....::: ##...:::: ##.. ##:::::: ##:::: #########: ##. ####:: ##:: #########: ##. ####:\n");
    printf(":::::::::::::::::::::::: ##:::::::: ##::::::: ##::. ##::::: ##:::: ##.... ##: ##:. ###:: ##:: ##.... ##: ##:. ###:\n");
    printf(":::::::::::::::::::::::: ##:::::::: ########: ##:::. ##:::: ##:::: ##:::: ##: ##::. ##:'####: ##:::: ##: ##::. ##:\n");
    printf("::::::::::::::::::::::::..:::::::::........::..:::::..:::::..:::::..::..::::..::....::..:::::..:::::..::...::::..:\n");
    printf(reset);
    printf(""merah"Author : Reza Eka Firmansyah && Rayyan Nabil Abrary"reset" \n");

    do {
    load(tabbarang);
    printf("==================================================================================================================\n");
    printf("||                      "biru" SELAMAT DATANG DI PROGRAM MANAJEMEN INVENTARIS TOKO PERTANIAN "reset"                         ||\n");
    printf("==================================================================================================================\n");

        printf("|| "biru"NO"reset" ======================================= "biru"PILIH MENU PROGRAM"reset" ===============================================||\n");
        printf("|| "ijo"1."reset" || "ijo"LIHAT INVENTARIS"reset"           ||  "ijo"MELIHAT INVENTARIS TOKO SAAT INI"reset"                                        ||\n");
        printf("|| "ijo"2."reset" || "ijo"UPDATE INVENTARIS"reset"          ||  "ijo"MENAMBAH ATAU MENGURANGI STOK / MEHPERBARUI HARGA"reset"                       ||\n");
        printf("|| "ijo"3."reset" || "ijo"CARI DATA BARANG"reset"           ||  "ijo"MENCARI ATAU MENGURUTKAN DATA BARANG"reset"                                    ||\n");
        printf("|| "merah"0."reset" || "merah"KELUAR"reset"                     ||  "merah"KELUAR PROGRAM"reset"                                                          ||\n");
        printf("==================================================================================================================\n");

        printf(biru);
        printf("Masukkan Pilihan : ");
        scanf("%d", &pil);
        printf(reset);
        
        switch(pil) {
            case 1 : 
                tampil(tabbarang);
                break;
            case 2 : 
                menuStok(subpil,tabbarang);
                break;
            case 3 : 
                menucData(subpil,tabbarang);
                break;
            case 0 : 
                clear();
                printf(kuning);
                printf(" $$$$$$\\   $$$$$$\\  $$\\      $$\\ $$$$$$$\\   $$$$$$\\  $$$$$$\\          $$$$$\\ $$\\   $$\\ $$\\      $$\\ $$$$$$$\\   $$$$$$\\  \n");
                printf("$$  __$$\\ $$  __$$\\ $$$\\    $$$ |$$  __$$\\ $$  __$$\\ \\_$$  _|         \\__$$ |$$ |  $$ |$$$\\    $$$ |$$  __$$\\ $$  __$$\\ \n");
                printf("$$ /  \\__|$$ /  $$ |$$$$\\  $$$$ |$$ |  $$ |$$ /  $$ |  $$ |              $$ |$$ |  $$ |$$$$\\  $$$$ |$$ |  $$ |$$ /  $$ |\n");
                printf("\\$$$$$$\\  $$$$$$$$ |$$\\$$\\$$ $$ |$$$$$$$  |$$$$$$$$ |  $$ |              $$ |$$ |  $$ |$$\\$$\\$$ $$ |$$$$$$$  |$$$$$$$$ |\n");
                printf(" \\____$$\\ $$  __$$ |$$ \\$$$  $$ |$$  ____/ $$  __$$ |  $$ |        $$\\   $$ |$$ |  $$ |$$ \\$$$  $$ |$$  ____/ $$  __$$ |\n");
                printf("$$\\   $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |      $$ |  $$ |  $$ |        $$ |  $$ |$$ |  $$ |$$ |\\$  /$$ |$$ |      $$ |  $$ |\n");
                printf("\\$$$$$$  |$$ |  $$ |$$ | \\_/ $$ |$$ |      $$ |  $$ |$$$$$$\\       \\$$$$$$  |\\$$$$$$  |$$ | \\_/ $$ |$$ |      $$ |  $$ |\n");
                printf(" \\______/ \\__|  \\__|\\__|     \\__|\\__|      \\__|  \\__|\\______|       \\______/  \\______/ \\__|     \\__|\\__|      \\__|  \\__|\n");
                printf(reset);
                break;
            default :   
                printf(merah"Input Angka Sesuai Menu Yang Tertera(1/2/3/0)"reset);
                break;
                    
        }
        if (pil != 0){
            printf(merah"\nTekan"reset" "ijo"Enter"reset" "merah"Untuk Kembali Ke Menu Utama..."reset);
            getchar();
            getchar();
            clear();
        }
    }while(pil!=0);

    return 0;
}