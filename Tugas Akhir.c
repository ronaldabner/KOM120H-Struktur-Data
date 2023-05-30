#include <stdio.h> // digunakan untuk menyediakan fungsi-fungsi standar input-output bahasa C seperti printf() dan scanf()
#include <stdlib.h> // digunakan untuk menyediakan fungsi-fungsi standar malloc() untuk mengalokasikan memori dan exit() untuk menghentikan program secara paksa.
#include <string.h> // digunakan untuk menyediakan fungsi strcpy()
#define V 10 // 
#include <conio.h> // berfungsi mendefinisikan fungsi getch() untuk implementasi menu interaktif di program C



typedef struct Layanan {
    // Komponen-komponen informasi dalam LL
	int kodelayanan;	
	char namalayanan[20];
	int ruangantersedia;
	struct Layanan *next; // Komponen pointer untuk menunjuk node berikutnya
} Layanan;

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
	Layanan Layanan; 
} Pemesanan;

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
// Nilai 0 menunjukkan tidak adanya hubungan antara simpul tersebut, sedangkan nilai non-0 menunjukkan adanya hubungan dengan bobot atau nilai tertentu.

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
            // Penggunaan switch yang berisikan pilihan-pilihan submenu yang akan dijalankan berdasarkan input pengguna.
            scanf("%d", &pilihsubmenu);
            switch(pilihsubmenu) {
                // Setelah program selesai dieksekusi, program kembali ke halaman utama menggunakan goto label pada menu;
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
            // Fungsi untuk mengakhiri program dengna keluar dari program secara normal. 
            exit(0);
            break;
        }

        // Pilihan di luar pilihan yang ada
        else {
            system("cls");
            printf("Pilihan tidak tersedia, Silakan memasukkan ulang input!");
            getch();
            break;
        }
    }

    // Apakah diperlukan?
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

// Fungsi yang menginisialisasi nilai anggota dari struct Layanan (Parameter menerima input dari tambahlayanan())
void masuklayanan(int kodelayanan, char namalayanan[], int ruangantersedia1) {
    // Membuat node baru menggunakan malloc() untuk mengalokasikan memori dengan ukuran sizeof(Layanan) (struct Layanan)
    // newnode = alamat memori yang dialokasikan untuk node baru dan disimpan dalam variabel newnode
	Layanan* newnode = (Layanan*)malloc(sizeof(Layanan)); 
    // Menginisialisasi nilai anggota struct Layanan dari newnode, yaitu kodelayanan dengan nilai yang diterima dari parameter kodelayanan
	newnode->kodelayanan = kodelayanan; 
    // Menyalin string namalayanan dari parameter char namalayanan[] ke anggota struct "namalayanan" sehingga string namalayanan memiliki nilai string baru.
	strcpy(newnode->namalayanan, namalayanan);
    // Menginisialisasi nilai anggota struct Layanan, yaitu ruangantersedia dengan nilai yang diterima dari parameter kodelayanan
	newnode->ruangantersedia = ruangantersedia1; 
    // Mengatur pointer next dari node baru agar menunjuk ke node pertama saat ini. Jika linked list masih kosong, maka head bernilai NULL.
	newnode->next = head; 
    // Mengubah pointer head untuk menunjuk ke node baru (newnode). newnode akan menjadi node pertama dalam linked list.
    head = newnode;
}

// Fungsi pilihsubmenu == 2. Fungsi mengubah input pada submenu == 1 dari pengguna.
void updatelayanan() {
    // current adalah variabel lokal untuk menunjuk ke node.
	Layanan *current;
   	char namalayananbaru[50];
   	int num, ruangantersedia;
	system("cls");
	
	printf("--------------\n");
	printf("Update Layanan\n");
	printf("--------------\n");
	
	printf("Masukkan Kode Layanan yang Ingin di Ubah : ");		
	scanf("%d", &num); 
	fflush(stdin);
	
	// head = newnode;
    // Kondisi apabila pengguna belum memasukkan/menghapus input pada pilihsubmenu == 1
	if(head==NULL) {
		printf("List Masih Kosong"); 
        getch(); 
        system("cls"); 
        return;
	}
	
    // Mengubah pointer head menjadi current untuk menunjuk ke node baru (newnode). 
	// head = newnode;
	current = head;
	while(current!=NULL) {
        // Memeriksa kodelayanan (num) yang dimasukkan pengguna untuk mengupdate layanan yang sesuai dengan kodelayanan yang dimasukkan pada submenu == 1
	 	if(num==current->kodelayanan) {
	 		printf("--------------\n");
	 		printf("Masukkan Nama Layanan: ");
            // Memasukkan nama layanan baru
	      	scanf("%s", &namalayananbaru);
            // Menyalin string namalayanan dari input nama layanan baru ke anggota struct "namalayanan" sehingga string namalayanan memiliki nilai string baru.
	      	strcpy(current->namalayanan, namalayananbaru);
	      	printf("Jumlah Ruangan yang Tersedia	: ");
            // Memasukkan jumlah ruangan tersedia baru
	      	scanf("%d", &ruangantersedia);
            // Memperbarui jumlah ruangan tersedia dari input ruangan tersedia ke anggota struct "ruangantersedia"
	      	current->ruangantersedia = ruangantersedia;
			return;
		}
        // Menggeser pointer current ke node berikutnya. 
        // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
		current=current->next;
	}
    
	printf("\tKode Layanan %d Tidak Berada di dalam List", num);
	getch(); 
    system("cls");
}

// Fungsi pilihsubmenu == 3. Fungsi melihat daftar layanan dan jumlah kamar yang tersedia dari input pengguna.
void lihatlayanan() {
    // Deklarasi variabel pointer lihat dengan tipe data struct Layanan
    Layanan* lihat;
    system("cls"); 
    printf("\n");

	// head = newnode;
    // Kondisi memeriksa pointer ke node apakah pengguna sudah memasukkan input pada pilihmenu == 1 && pilihsubmenu == 1
    if(head==NULL) {
        // Jika belum memasukkan/menghapus masukan input (Bernilai NULL)
        printf("\n\tData Layanan Kosong\n");
    }
    else { 
        printf("--------------\n");
        printf("Lihat Layanan\n");
        printf("--------------");
        // Mengubah pointer head menjadi lihat untuk menunjuk ke node baru (newnode). 
        lihat = head; 
            
        while(lihat != NULL) { 
            // Fungsi akan terus mengeluarkan detail layanan sebanyak-banyaknya hingga mencapai akhir dari input pengguna
            printf("\nKode Layanan: %d", lihat->kodelayanan);
            printf("\nNama Layanan: %s", lihat->namalayanan);
            printf("\nRuangan Tersedia: %d", lihat->ruangantersedia);
            // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
            lihat = lihat->next;
        } 
    }
    getch(); 
    system("cls");
}

// Fungsi pilihsubmenu == 4. Fungsi menghapus input dari pengguna menggunakan free().
void hapuslayanan() {
    system("cls");	
    // Menginisialisasi variabel pointer temp dengan nilai NULL
    Layanan *temp = NULL;
    int num;
	
	printf("--------------\n");
	printf("HAPUS Layanan\n");
	printf("--------------\n");
	printf("Masukkan List Layanan Yang ingin di Hapus : ");		
	scanf("%d", &num);

	// head = newnode;
    // Kondisi apabila pengguna belum memasukkan/menghapus input pada pilihsubmenu == 1
	if(head==NULL) {
		printf("\nList Masih Kosong");
		getch(); 
        system("cls"); 
        return;
	}

    // Memeriksa kodelayanan (num) yang dimasukkan pengguna untuk menghapus layanan dengan kodelayanan yang sesuai pada input submenu == 1
	if(num==head->kodelayanan) {
        // Mengubah pointer head menjadi temp (Variabel sementara) untuk menunjuk ke node baru (newnode). 
		temp = head;
        // Mengubah pointer head untuk menunjuk node berikutnya
		head = head->next;
        // Fungsi free digunakan untuk menghapus layanan berdasarkan kodelayanan yang sesuai dengan input pengguna
		free(temp);
		return;
	}
	
    // Mengubah pointer head menjadi p untuk menunjuk ke node baru (newnode). 
	p = head;
	while(p->next!=NULL) {	
    // Selama node tidak kosong, fungsi akan terus memeriksa node berikutnya dalam linked list 
		if(p->next->kodelayanan==num) {
            // Memeriksa kodelayanan (num) yang dimasukkan pengguna untuk menghapus layanan dengan kodelayanan yang sesuai pada submenu == 1 pada node berikutnya
            // Mengubah pointer node berikutnya menjadi temp (Variabel sementara) untuk menunjuk ke node baru (newnode). 
			temp = p->next;
            // Mengubah pointer node berikutnya ke node setelah node berikutnya.
			p->next = temp->next;
            // Fungsi free digunakan untuk menghapus layanan berdasarkan kodelayanan yang sesuai dengan input pengguna
			// Membebaskan memori node berikutnya
            free(temp);
			getch(); 
            system("cls");
			return;
		}
        // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
		p = p->next;
	}
	printf("\n\tKode Layanan %d Tidak Berada di dalam List", num);
	getch(); 
    system("cls");
}

// Fungsi pilihsubmenu == 5. Fungsi melihat daftar layanan dan jumlah kamar yang tersedia berdasarkan kode layanan
void detaillayanan() {
    system("cls"); 
    printf("\n");
    int search_detail;
    int Pesanan;
    // Deklarasi variabel pointer detail dan letak dengan tipe data struct Layanan
    Layanan* detail;
    Layanan* letak;
    // Deklarasi variabel pointer lihat dengan tipe data struct Pemesanan
    Pemesanan* lihat;

	// head = newnode;
    // Kondisi memeriksa pointer ke node apakah pengguna sudah memasukkan input pada pilihsubmenu == 1
    if(head==NULL) {
        // Jika belum memasukkan/menghapus masukan input (Bernilai NULL)
        printf("Detail Layanan Kosong\n");
    }
	else {
	 	printf("--------------\n");
    	printf("Lihat Detail Layanan\n");
    	printf("--------------\n");
        // Mengubah pointer head menjadi detail untuk menunjuk ke node baru (newnode). 
    	detail = head; 
        
		while(detail != NULL) { 
            // Fungsi akan terus mengeluarkan daftar kode layanan beserta nama layanannya sebanyak-banyaknya hingga mencapai akhir dari input pengguna
        	printf("\n[%d]\t[%s] \n", detail->kodelayanan, detail->namalayanan);
            // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
            detail = detail->next; 
		}

		printf("Masukkan kode layanan yang ingin dilihat detailnya: ");
		scanf("%d", &search_detail);
        // Mengubah pointer head menjadi letak untuk menunjuk ke node baru (newnode) pada fungsi masuklayanan().
        // Mengubah pointer head1 menjadi letak untuk menunjuk ke node baru (newnode) pada fungsi masukpemesanan().
		letak = head;
		lihat = head1;
		while(letak!=NULL) {
            // Selama node tidak kosong, fungsi akan terus memeriksa node dalam linked list 
			if(search_detail==letak->kodelayanan) {
                // Fungsi akan mengeluarkan detail layanan berdasarkan kodelayanan yang sesuai dengan input pengguna
                printf("\nKode Layanan		: %d", letak->kodelayanan);
        		printf("\nNama Layanan		: %s", letak->namalayanan);
        		printf("\nRuangan Tersedia	: %d", letak->ruangantersedia);
                
				while (lihat != NULL) {
                    // Selama node tidak kosong, fungsi akan terus memeriksa node dalam linked list
                    // Jika kodelayanan sesuai
					if(letak->kodelayanan == lihat->kodelayanan) {
                        // Menghasilkan keluaran nama-nama pemesan layanan tersebut berdasarkan kode layanan
						printf("\nNama Pemesan 	: %s \n", lihat->nama);
                        // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
						lihat = lihat->next;
						Pesanan = 1;
					}
					else {
                        // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
						lihat = lihat->next;
						Pesanan = 0;
					}
				}

                // Jika tidak ada pemesan pada kode layanan tersebut,
				if (Pesanan == 0) {
					printf("\n\tLayanan belum dipesan");
				}
			}
            // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
			letak = letak->next;
		}
    }
    getch();
    system("cls");
}

// Fungsi pilihmenu == 2
void tambahpemesanan() {
	system("cls"); 
    system("color 03");
    int no_antrian, kodelayanan, no_kamar, tanggal, bulan, tahun;
    char namapemesan[50], namalayanan[40];
	fflush(stdin);
	printf("----------------------\n");
	printf("Buat Pemesanan Layanan\n");
	printf("----------------------\n");
	printf("No Antrian: ");
	scanf ("%d",&no_antrian); 
    fflush(stdin); // Membersihkan buffer masukan sebelum mengambil input dari pengguna
	printf("Nama Pemesan: ");
	scanf("%s", &namapemesan); 	
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

	masukpemesanan(no_antrian, kodelayanan, no_kamar, tanggal, bulan, tahun, namapemesan, namalayanan);
	getch();
    system("cls");
}

// Fungsi dengan 8 parameter, menerima nilai yang diteruskan dari fungsi tambahpemesanan()
void masukpemesanan(int no_antrian, int kodelayanan, int no_kamar,int tanggal,int bulan,int tahun,char namapemesan[],char namalayanan[]) {
    // Membuat node baru menggunakan malloc() untuk mengalokasikan memori dengan ukuran sizeof(Pemesanan) (struct Pemesanan)
    // newnode = alamat memori yang dialokasikan untuk node baru dan disimpan dalam variabel newnode
    Pemesanan* newnode = (Pemesanan*)malloc(sizeof(Pemesanan)); 
    // Menginisialisasi nilai anggota struct Pemesanan dari newnode, yaitu no_antrian dengan nilai yang diterima dari parameter int no_antrian
	newnode->no_antrian = no_antrian; 
    // Menyalin string namapemesan dari parameter char namapemesan[] ke anggota struct "nama" sehingga string nama memiliki nilai string baru.
	strcpy(newnode->nama, namapemesan);
	newnode->kodelayanan = kodelayanan;
    // Menyalin string namalayanan dari parameter char namalayanan[] ke anggota struct "namalayanan" sehingga string namalayanan memiliki nilai string baru.
	strcpy(newnode->namalayanan, namalayanan);
    // Menginisialisasi nilai anggota struct Pemesanan dari newnode, yaitu no_kamar dengan nilai yang diterima dari parameter int no_kamar
	newnode->no_kamar = no_kamar; 
    // Menginisialisasi nilai anggota struct Pemesanan dari newnode, yaitu tanggal dengan nilai yang diterima dari parameter int tanggal
	newnode->tanggal = tanggal; 
    // Menginisialisasi nilai anggota struct Pemesanan dari newnode, yaitu bulan dengan nilai yang diterima dari parameter int bulan
	newnode->bulan = bulan; 
    // Menginisialisasi nilai anggota struct Pemesanan dari newnode, yaitu tahun dengan nilai yang diterima dari parameter int tahun
	newnode->tahun = tahun;
    // Mengatur pointer next dari node baru (newnode) agar menunjuk ke node pertama saat ini. Jika linked list masih kosong, maka head bernilai NULL.
	newnode->next = head1; 
    // Mengubah pointer head1 untuk menunjuk ke node baru (newnode). newnode akan menjadi node pertama dalam linked list.
	head1 = newnode;
}

// Implementasi graf untuk melihat daftar pemesanan
void lihatpemesanan(int graph[V][V]) {
    // Deklarasi variabel pointer lihat dengan tipe data struct Pemesanan
	Pemesanan* lihat;
	system("cls"); 
    system("color 03");
    // Kondisi memeriksa pointer ke node apakah pengguna sudah memasukkan input pada pilihmenu == 2 && pilihsubmenu == 1
	if (head1 == NULL) {
		printf (" Tidak Ada Proses Pemesanan Layanan ");
	}
	else {
		printf("-----------------------------\n");
		printf("Lihat Proses Pemesanan Layanan\n");
		printf("-----------------------------");
        // Mengubah pointer head menjadi detail untuk menunjuk ke node baru (newnode). 
		lihat = head1;
		while (lihat!= NULL) {
            // Fungsi akan terus mengeluarkan daftar detail pesanan sampai akhir input pengguna
			printf("\n\nNo Antrian: %d", lihat->no_antrian);
			printf("\nNama Pemesan: %s", lihat->nama);
			printf("\nKode Layanan: %d", lihat->kodelayanan);
			printf("\nNama Layanan: %s", lihat->namalayanan);
			printf("\nJumlah Layanan: %d", lihat->no_kamar);
			printf("\nTanggal Pesan: %d", lihat->tanggal);
			printf("\nBulan: %d", lihat->bulan);
			printf("\nTahun: %d", lihat->tahun); 
            printf("\n");
            // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
			lihat = lihat->next;
		}
	}
    getch(); 
    system("cls");
}
