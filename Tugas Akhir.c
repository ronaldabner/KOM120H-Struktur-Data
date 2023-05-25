#include <stdio.h> // digunakan untuk menyediakan fungsi-fungsi standar input-output bahasa C seperti printf() dan scanf()
#include <stdlib.h> // digunakan untuk menyediakan fungsi-fungsi standar malloc() untuk mengalokasikan memori dan exit() untuk menghentikan program secara paksa.
#include <string.h> // digunakan untuk menyediakan fungsi strcpy()
#define V 10 // 
#include <conio.h> // berfungsi mendefinisikan fungsi getch() untuk implementasi menu interaktif di program C

// struct Layanan {
// 	int kodelayanan;	
// 	char namalayanan[20];
// 	int ruangantersedia;
// 	struct Layanan *next;	
// }; typedef struct Layanan Lyn;

typedef struct Layanan {
    // Komponen-komponen informasi dalam LL
	int kodelayanan;	
	char namalayanan[20];
	int ruangantersedia;
	struct Layanan *next; // Komponen pointer untuk menunjuk node berikutnya
} Layanan;

// struct Pemesanan {
// 	struct Pemesanan *next;
// 	int no_antrian;
// 	char nama[20];	
// 	int kodelayanan;
// 	char namalayanan[20];
// 	int no_kamar;
// 	int tanggal;
// 	int bulan;
// 	int tahun;
// 	struct Layanan Lyn;	
// }; typedef struct Pemesanan Pesan;

typedef struct Pemesanan {
	struct Pemesanan *next;
	int no_antrian;
	char nama[20];	
	int kodelayanan;
	char namalayanan[20];
	int no_kamar;
	int tanggal;
	int bulan;
	int tahun;
	Layanan Layanan; // Komponen pointer untuk menunjuk node berikutnya
} Pemesanan;

// struct Login{
// 	struct Login *next; 
// 	char username[50];
// 	char password[50];
// 	struct Pemesanan pesan;
// }akun[50]; typedef struct Login Lg;

typedef struct Login {
	struct Login *next;
	char username[50];
	char password[50];
	Pemesanan Pemesanan;
} Login;

// Login akun[50];

// Deklarasi fungsi setiap menu (Fungsi diletakkan di bawah fungsi main)
void tambahlayanan();
void masuklayanan();
void updatelayanan();
void lihatlayanan();    
void hapuslayanan();
void detaillayanan();
void tambahpemesanan();
void masukpemesanan();
void lihatpemesanan();

// void dijkstra(int G[V][V],int n, int startnode, int targetnode);
// void ubahgraph();

// Lg* loginakun(Lg *);
// void lihatakun(Lg *);
// struct Layanan *head = NULL;
Layanan *head = NULL;
// struct Layanan *p = NULL;
Layanan *p = NULL;
// struct Pemesanan *head1 = NULL;
Pemesanan *head1 = NULL;
// struct Pemesanan *p1=NULL;
Pemesanan *p1 = NULL;

int graph[V][V] =  {{0, 1, 0, 0, 0, 0, 0, 0},
				   { 0, 0, 2, 2, 3, 0, 0, 0},
				   { 1, 0, 0, 0, 0, 0, 0, 0},
				   { 0, 0, 1, 0, 0, 0, 3, 0},
				   { 0, 0, 0, 2, 0, 3, 0, 0},
				   { 0, 0, 3, 0, 0, 0, 0, 2},
				   { 0, 0, 0, 0, 1, 0, 0, 1},
				   { 0, 0, 0, 0, 0, 0, 0, 0}};

int main () {
    // Deklarasi variabel pilihan untuk masuk ke dalam menu berdasarkan input pengguna
    int pilihmenu, pilihsubmenu;
	// Login *Login;	
	// Login = NULL;	

    // Membersihkan layar console
    // Cara lainnya:
    // https://www.geeksforgeeks.org/clear-console-c-language/
    system("cls");
    // Mengatur warna latar belakang console
    system("color 03");
    // Kode warna 
    // 0 = Black (Warna original pada Visual Studio Code)
    // 1 = Blue
    // 2 = Green
    // 3 = Aqua
    // 4 = Red
    // 5 = Purple
    // 6 = Yellow
    // 7 = White
    // 8 = Gray
    // 9 = Light Blue
    // A = Light Green
    // B = Light Aqua
    // C = Light Red
    // D = Light Purple
    // E = Light Yellow
    // F = Bright White
	printf("------------------------------------\n");
	printf("TUGAS AKHIR STRUKTUR DATA\n");
	printf("PROGRAM ANTRIAN LAYANAN KECANTIKAN\n");
	printf("------------------------------------\n");
	printf("Cheisha Amanda G6401211084\n");
    printf("Hariz Krisha Muhammad G6401211106\n");
	printf("Ronald Abner G6401211110\n");
	printf("------------------------------------\n");
	printf("Tekan tombol apa saja untuk melanjutkan");
    getch();
    // Fungsi untuk membaca satu karakter dari input tanpa menunggu adanya penekanan tombol "Enter" (newline) dan karakter yang ditekan tidak akan ditampilkan ke layar. 
    // getch() tidak sama dengan getchar()


    // Menghapus semua teks sebelumnya yang ditampilkan ke layar sehingga mendapat tampilan layar kosong.
    system("cls");
    system("color 03");
	printf("----------------------------------\n");	
    printf("Selamat Datang\n");	
    printf("----------------------------------\n");		
    printf("Silakan login terlebih dahulu untuk melanjutkan\n");
    getch();

    // Menyimpan akun login
	// lg = loginakun(lg);

    do {
        // Sebuah label menu sebagai penanda titik tertentu dalam program. Eksekusi program mengarah ke label menggunakan perintah "goto"
        menu:
        system("cls");
        system("color 03");
		printf("----------------------------\n");
		printf("Menu\n");
		printf("----------------------------\n");
		printf("1. Informasi Layanan yang Tersedia\n");
		printf("2. Informasi Pemesanan Layanan\n");
		printf("3. Daftar Antrian Layanan\n");
		printf("4. Keluar\n");
		printf("----------------------------\n");
		printf("Masukkan Pilihan Anda: ");
        scanf("%d", &pilihmenu);
        
        if(pilihmenu == 1) {
            system("cls");
            system("color 03");
            printf("----------------------------\n");
            printf("SubMenu\n");
            printf("----------------------------\n");
            printf("1. Menambah Layanan\n");
            printf("2. Mengubah Layanan\n");
            printf("3. Melihat Daftar Layanan dan Kamar yang Tersedia\n");
            printf("4. Menghapus Layanan\n");
            printf("5. Melihat Detail Layanan\n");
            printf("----------------------------\n");
            printf("Masukkan Pilihan Anda: ");
            scanf("%d", &pilihsubmenu);
            switch(pilihsubmenu) {
                case 1:
                    tambahlayanan();
                    break;
                    goto menu;
                case 2:
                    updatelayanan();
                    break;
                    goto menu;
                case 3:
                    lihatlayanan();
                    break;
                    goto menu;
                case 4:
                    hapuslayanan();
                    break;
                    goto menu;
                case 5:
                    detaillayanan();
                    break;
                    goto menu;
            }
        }
        else if(pilihmenu == 2) {
            system("cls");
            system("color 03");
            printf("----------------------------\n");
            printf("SubMenu\n");
            printf("----------------------------\n");
            printf("1. Pemesanan Layanan\n");
            printf("2. Proses Pemesanan Layanan\n");
            printf("----------------------------\n");
            printf("Masukkan Pilihan Anda: ");
            scanf("%d", &pilihsubmenu);
            switch(pilihsubmenu) {
                case 1:
                    tambahpemesanan();
                    break;
                    goto menu;
                case 2:
                    lihatpemesanan();
                    break;
                    goto menu;
            }            
        }
        // Detail Antrian (-) (Melihat seberapa panjang antrian)
        // else if(pilihmenu == 3) {
        //     system("cls");
        //     system("color 03");
        //     printf("----------------------------\n");
        //     printf("SubMenu\n");
        //     printf("----------------------------\n");
        //     printf("1. \n");
        //     printf("2. \n");
        //     printf("----------------------------\n");
        //     printf("Masukkan Pilihan Anda: ");
        //     scanf("%d", &pilihsubmenu);
        //     switch(pilihsubmenu) {
        //         case 1:
        //             // lihatantrian();
        //             // break;
        //             // goto menu;
        //         case 2:
        //             // lihatantrian();
        //             // break;
        //             // goto menu;
        //     }            
        // }
        // Keluar dari program
        else if(pilihmenu == 4) {
            system("cls");
            system("color 03");
            printf("");
            getch();
            exit(0);
            break;
        }
        // Pilihan di luar pilihan yang ada
        else {
            system("cls");
            printf("Pilihan Tidak Tersedia, Silakan memasukkan ulang input!");
            getch();
            break;
        }
    }

    while(pilihsubmenu != 10);
    return 0;
    // akhir:
    //     exit(0);
}

// Menyimpan profil akun yang akan digunakan
// Lg* loginakun(Lg *lg){
// 	Lg *log;
// 	log = malloc(sizeof(Lg));
// 	log->next = NULL;
	
// 	system("cls"); system("color 06");

// 	printf("\n---------------\n");
// 	printf("LOGIN AKUN\n");
// 	printf("---------------\n");
// 	printf("USERNAME: ");
// 	gets(log->username);
// 	printf("PASSWORD: ");
// 	gets(log->password);

// 	if(log == NULL){
// 		lg = log;
// 	}
// 	else{
// 		log->next = lg;
// 	}

//     printf("\n");
//     return log;
// }

// Melihat profil akun yang sedang digunakan
// void lihatakun(Lg *lg){
	
// 	system("cls");
// 	printf("-----------------------\n");
// 	printf("Lihat Akun Saya\n");
// 	printf("-----------------------");	
// 	while(lg != NULL){
// 		printf("\nUsername: %s", lg->username);
// 		printf("\nPassword: ******");
// 		lg= lg->next;
// 	} 
//     getch(); 
//     system("cls");
// }

// Definisi fungsi (Fungsi diletakkan di bawah fungsi main)
// Fungsi pilihmenu == 1 
// Fungsi pilihsubmenu == 1. Fungsi menerima input dari pengguna.
void tambahlayanan() {
	system("cls");
    int kodelayanan;
    int ruangantersedia1;
    char namalayanan[50];

	fflush(stdin);
	printf("--------------\n");
	printf("Tambah Layanan\n");
	printf("--------------\n");
	printf("Kode Layanan: ");
	scanf("%d", &kodelayanan);  
    fflush(stdin);
	printf("Nama Layanan: ");
	scanf("%s", &namalayanan); 	
    fflush(stdin);
	printf("Ruangan Tersedia: ");
    scanf("%d",&ruangantersedia1); 	
    fflush(stdin);
	masuklayanan(kodelayanan,namalayanan,ruangantersedia1);
	getch();
    system("cls");
}

// Fungsi yang menginisialisasi nilai anggota dari struct Layanan (Menerima input dari tambahlayanan())
void masuklayanan(int kodelayanan, char namalayanan[], int ruangantersedia1) {
	Layanan* newnode = (Layanan*)malloc(sizeof(Layanan)); 
	newnode->kodelayanan = kodelayanan; 
	strcpy(newnode->namalayanan, namalayanan);
	newnode->ruangantersedia = ruangantersedia1; 
	newnode->next = head; 
	head = newnode;
}

// Fungsi pilihsubmenu == 2. Fungsi mengubah input pada submenu == 1 dari pengguna.
void updatelayanan() {
	Layanan *current;
   	char namalayanan1[50];
   	int num, ruangantersedia;
	system("cls");
	
	printf("--------------\n");
	printf("Update Layanan\n");
	printf("--------------\n");
	
	printf("Masukkan Kode Layanan yang Ingin di Ubah : ");		
	scanf("%d", &num);
	fflush(stdin);
	
	if(head==NULL){
        // Kondisi apabila pengguna belum memasukkan/menghapus input pada pilihsubmenu == 1
		printf("List Masih Kosong"); 
        getch(); 
        system("cls"); 
        return;
	}
	
	current = head;
	while(current!=NULL){
        // Memeriksa apakah kodelayanan yang dimasukkan sesuai dengan kodelayanan yang dimasukkan pada submenu == 1
	 	if(num==current->kodelayanan){
	 		printf("--------------\n");
	 		printf("Masukkan Nama Layanan: ");
	      	scanf("%s", &namalayanan1);
	      	strcpy(current->namalayanan, namalayanan1);
	      	printf("Jumlah Ruangan yang Tersedia	: ");
	      	scanf("%d", &ruangantersedia);
	      	current->ruangantersedia = ruangantersedia;
			return;
		}
		current=current->next;
	}
	printf("\tKode Layanan %d Tidak Berada di dalam List", num);
	getch(); 
    system("cls");
}

// Fungsi pilihsubmenu == 3. Fungsi melihat detail input dari pengguna.
void lihatlayanan() {
    Layanan* lihat;
    system("cls"); 
    printf("\n");

    if(head==NULL){
        printf("\n\tData Layanan Kosong\n");
    }
    else{ 
    printf("--------------\n");
    printf("Lihat Layanan\n");
    printf("--------------");
    lihat = head; 
        
		while(lihat != NULL){ 
            // Fungsi akan terus mengeluarkan detail layanan sebanyak yang dimasukkan pengguna
            printf("\nKode Layanan: %d", lihat->kodelayanan);
            printf("\nNama Layanan: %s", lihat->namalayanan);
            printf("\nRuangan Tersedia: %d", lihat->ruangantersedia);
            lihat = lihat->next;
        } 
    }
    getch(); 
    system("cls");
}

// Fungsi pilihsubmenu == 4. Fungsi menghapus input dari pengguna menggunakan free().
void hapuslayanan() {
    system("cls");	
    Layanan *temp = NULL;
    int num;
	
	printf("--------------\n");
	printf("HAPUS Layanan\n");
	printf("--------------\n");
	printf("Masukkan List Layanan Yang ingin di Hapus : ");		
	scanf("%d", &num);
	
	if(head==NULL) {
    // Kondisi apabila pengguna belum memasukkan/menghapus input pada pilihsubmenu == 1
		printf("\nList Masih Kosong");
		getch(); 
        system("cls"); 
        return;
	}
	
	if(num==head->kodelayanan) {	//Mencek list pertama
    // Kondisi memeriksa input dari pengguna apakah input yang dimasukkan == kodelayanan yang dipilih
		temp = head;
		head = head->next;
		free(temp);
		return;
	}
	
	p = head;
	while(p->next!=NULL){	//Mencek list berikutnya
    // Fungsi akan terus memeriksa input selanjutnya yang dimasukkan pengguna hingga akhir dari input pengguna
		if(p->next->kodelayanan==num){
        // Kondisi memeriksa input dari pengguna apakah input yang dimasukkan == kodelayanan yang dipilih
        // Penghapusan Data Linked List
			temp = p->next;
			p->next = temp->next;
			free(temp);
			getch(); 
            system("cls");
			return;
		}
		p = p->next;
	}
	printf("\n\tKode Layanan %d Tidak Berada di dalam List", num);
	getch(); 
    system("cls");
}

// Fungsi pilihsubmenu == 5. Fungsi menerima input dari pengguna.
void detaillayanan() {
    system("cls"); 
    printf("\n");
    int search_detail;
    int kembali;
    Layanan* detail;
    Layanan* letak;
    Pemesanan* lihat;

    if(head==NULL){
    // Kondisi apabila pengguna belum memasukkan/menghapus input pada pilihsubmenu == 1
        printf("Detail Layanan Kosong\n");
    }
	else{
	 	printf("--------------\n");
    	printf("Lihat Detail Layanan\n");
    	printf("--------------\n");
    	detail = head; 
        
		while(detail != NULL){ 
        // Fungsi akan terus membuat daftar detail layanan berdasarkan input yang dimasukkan pengguna hingga akhir dari input pengguna
        	printf("\n[%d]\t[%s] \n", detail->kodelayanan, detail->namalayanan);
			// Fungsi memeriksa input selanjutnya yang dimasukkan pengguna hingga akhir dari input pengguna
            detail = detail->next; 
		}
		printf("Masukkan kode layanan yang ingin dilihat detailnya: ");
		scanf("%d", &search_detail);
		
		letak = head;
		lihat = head1;
		while(letak!=NULL){
			if(search_detail==letak->kodelayanan){
				printf("\n\tKode Layanan		: %d", letak->kodelayanan);
        		printf("\n\tNama Layanan		: %s", letak->namalayanan);
        		printf("\nRuangan Tersedia		: %d", letak->ruangantersedia);
				while (lihat != NULL){
					if(letak->kodelayanan == lihat->kodelayanan){
						printf("\n\tNama Pemesan 		: %s \n", lihat->nama);
						lihat = lihat->next;
						kembali =1;
					}
					else{
						lihat = lihat->next;
						kembali =0;
					}
				}
				if (kembali == 0){
					printf("\n\tLayanan belum dipesan");
				}
			}
			letak = letak->next;
		}
    }
    getch();
    system("cls");
}

// Implementasi Linked List
// Fungsi pilihmenu == 2
// Fungsi dengan 8 parameter, menerima nilai yang diteruskan fungsi tambahpemesanan()
void tambahpemesanan() {
	system("cls"); 
    system("color 03");
    int no_antrian, kodelayanan, no_kamar, tanggal, bulan, tahun;
    char nampes[50], namalayanan[40];
	fflush(stdin);
	printf("----------------------\n");
	printf("Buat Pemesanan Layanan\n");
	printf("----------------------\n");
	printf("No Antrian: ");
	scanf ("%d",&no_antrian); 
    fflush(stdin);
	printf("Nama Pemesan: ");
	scanf("%s", &nampes); 	
    fflush(stdin);
	printf("Kode Layanan: ");
	scanf ("%d",&kodelayanan); 
    fflush(stdin);
	printf("Nama Layanan: ");
	scanf("%s", &namalayanan); 	
    fflush(stdin);
	printf("No Kamar: ");
	scanf("%d", &no_kamar); 	
    fflush(stdin);
	printf("Tanggal: ");
	scanf("%d", &tanggal); 	
    fflush(stdin);
	printf("Bulan: ");
	scanf("%d", &bulan); 	
    fflush(stdin);
	printf("Tahun: ");
	scanf("%d", &tahun); 	
    fflush(stdin);

	masukpemesanan(no_antrian, kodelayanan, no_kamar, tanggal, bulan, tahun, nampes, namalayanan);
	getch();
    system("cls");
}

void masukpemesanan(int no_antrian, int kodelayanan, int no_kamar,int tanggal,int bulan,int tahun,char nampes[],char namalayanan[]) {
	Pemesanan* newnode = (Pemesanan*)malloc(sizeof(Pemesanan)); 
	newnode->no_antrian = no_antrian; 
	strcpy(newnode->nama, nampes);
	newnode->kodelayanan = kodelayanan; 
	strcpy(newnode->namalayanan, namalayanan);
	newnode->no_kamar = no_kamar; 
	newnode->tanggal = tanggal; 
	newnode->bulan = bulan; 
	newnode->tahun = tahun; 
	newnode->next = head1; 
	head1 = newnode;
}

// Implementasi graf untuk melihat daftar pemesanan
void lihatpemesanan(int graph[V][V]) {
	struct Pemesanan* lihat;
	system("cls"); 
    system("color 03");
	
	if (head1 == NULL){
		printf (" Tidak Ada Proses Pemesanan Layanan ");
	}
	else{
		printf("-----------------------------\n");
		printf("Lihat Proses Pemesanan Layanan\n");
		printf("-----------------------------");
		lihat = head1;
		while (lihat!= NULL){
			printf("\n\nNo Antrian: %d", lihat->no_antrian);
			printf("\nNama Pemesan: %s", lihat->nama);
			printf("\nKode Layanan: %d", lihat->kodelayanan);
			printf("\nNama Layanan: %s", lihat->namalayanan);
			printf("\nJumlah Layanan: %d", lihat->no_kamar);
			printf("\nTanggal Pesan: %d", lihat->tanggal);
			printf("\nBulan: %d", lihat->bulan);
			printf("\nTahun: %d", lihat->tahun); 
            printf("\n");
			lihat = lihat->next;
		}
	}
    getch(); 
    system("cls");
}