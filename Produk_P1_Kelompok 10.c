#include <stdio.h> // digunakan untuk menyediakan fungsi-fungsi standar input-output bahasa C seperti printf() dan scanf()
#include <stdlib.h> // digunakan untuk menyediakan fungsi-fungsi standar malloc() untuk mengalokasikan memori dan exit() untuk menghentikan program secara paksa.
#include <string.h> // digunakan untuk menyediakan fungsi strcpy()
#define V 10 // 
#include <conio.h> // berfungsi mendefinisikan fungsi getch() untuk implementasi menu interaktif di program C

// Penggunaan typedef supaya tidak perlu menuliskan tag struct pada deklarasi variabel

typedef struct Layanan {
    // Komponen-komponen informasi dalam LL
	int kodelayanan;	
	char namalayanan[50];
	int ruangantersedia;
	struct Layanan *next; // Komponen pointer untuk menunjuk node (struct) berikutnya
} Layanan;

typedef struct Pemesanan {
	struct Pemesanan *next;
	char nama[50];	
	int kodelayanan;
	char namalayanan[50];
	int no_kamar;
	int tanggal;
	int bulan;
	int tahun;
	Layanan Layanan; // Anggota struct juga menjadi struct  
} Pemesanan;

typedef struct Login {
	struct Login *next; // Komponen pointer untuk menunjuk node (struct) berikutnya
	char username[255];
	char password[255];
	Pemesanan Pemesanan; // Anggota struct juga menjadi struct
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
void lihatantrian();
void hapusantrian();

// Untuk memanipulasi linked list
// head: Pointer yang menunjuk ke head (awal) linked list Layanan.
// p: Pointer yang digunakan untuk melakukan iterasi melalui linked list Layanan.
// head1: Pointer yang menunjuk ke head (awal) linked list Pemesanan.
// p1: Pointer yang digunakan untuk melakukan iterasi melalui linked list Pemesanan.
Layanan *head = NULL;
Layanan *p = NULL;
Pemesanan *head1 = NULL;
Pemesanan *p1 = NULL;

int main () {
    // Deklarasi variabel pilihan untuk masuk ke dalam menu berdasarkan input pengguna
    int pilihmenu, pilihsubmenu;

    // Membersihkan layar console
    // Cara lainnya:
    // https://www.geeksforgeeks.org/clear-console-c-language/
    system("cls");
    // Mengatur warna latar belakang console
    system("color 05");
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
    printf("--------------------------------------------\n");
	printf("     TUGAS AKHIR KOM120H Struktur Data\n");
	printf("    ~PROGRAM ANTRIAN LAYANAN KECANTIKAN~\n");
	printf("--------------------------------------------\n");
    getch();
    system("color 04");
	printf("      Cheisha Amanda [ G6401211084 ]\n");
    getch();
    system("color 06");
    printf("  Hariz Krisha Muhammad  [ G6401211106 ]\n");
    getch();
    system("color 02");
	printf("       Ronald Abner [ G6401211110 ]\n");
	printf("--------------------------------------------\n");
    getch();
    system("color 05");
	printf("  Tekan tombol apa saja untuk melanjutkan");
    getch();
    // Fungsi untuk membaca satu karakter dari input tanpa menunggu adanya penekanan tombol "Enter" (newline) dan karakter yang ditekan tidak akan ditampilkan ke layar. 
    // getch() tidak sama dengan getchar()


    // Menghapus semua teks sebelumnya yang ditampilkan ke layar sehingga mendapat tampilan layar kosong.
    system("cls");
    system("color 05");
	printf("-----------------------------------------------\n");	
    printf("Selamat datang di Program Layanan Kecantikan\n");	
    printf("-----------------------------------------------\n");
    getch();


    do {
        // Sebuah label menu sebagai penanda titik tertentu dalam program. Eksekusi program mengarah ke label menggunakan perintah "goto"
        menu:
        system("cls");
        system("color 05");
		printf("-------------------------------------------\n");
		printf("\t\t   MENU\n");
		printf("-------------------------------------------\n");
		printf("1. Informasi Program Layanan Kecantikan\n");
		printf("2. Informasi Pemesanan Layanan Kecantikan\n");
		printf("3. Daftar Antrian Layanan Kecantikan\n");
		printf("4. Keluar\n");
		printf("-------------------------------------------\n");
		printf("          Masukkan pilihan anda: ");
        scanf("%d", &pilihmenu);
        
        if(pilihmenu == 1) {
            system("cls");
            system("color 05");
            printf("--------------------------------------------------\n");
            printf("     (1) Informasi Program Layanan Kecantikan\n");
            printf("--------------------------------------------------\n");
            printf("1. Menambah Layanan Kecantikan\n");
            printf("2. Memperbarui Layanan Kecantikan\n");
            printf("3. Melihat Informasi Layanan Kecantikan\n");
            printf("4. Menghapus Layanan Kecantikan\n");
            printf("5. Melihat Detail Layanan Kecantikan\n");
            printf("--------------------------------------------------\n");
            printf("\t    Masukkan pilihan anda: ");
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
            system("color 05");
            printf("--------------------------------------------------\n");
            printf("    (2) Informasi Pemesanan Layanan Kecantikan\n");
            printf("--------------------------------------------------\n");
            printf("1. Pemesanan Layanan\n");
            printf("2. Proses Pemesanan Layanan\n");
            printf("--------------------------------------------------\n");
            printf("Masukkan pilihan anda: ");
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
        else if(pilihmenu == 3) {
            system("cls");
            system("color 05");
	        printf("----------------------------------------------\n");
            printf("       (3) Antrian Layanan Kecantikan\n");
	        printf("----------------------------------------------\n");
            printf("1. Melihat daftar antrian \n");
            printf("2. Menghapus daftar antrian \n");
	        printf("----------------------------------------------\n");
            printf("           Masukkan pilihan anda: ");
            scanf("%d", &pilihsubmenu);
            switch(pilihsubmenu) {
                case 1:
                    lihatantrian();
                    break;
                    goto menu;
                 case 2:
                    hapusantrian();
                    break;
                    goto menu;
             }            
         }

        // Keluar dari program
        else if(pilihmenu == 4) {
            system("cls");
            system("color 04");
            printf("Tekan tombol apa saja untuk keluar");
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
    while(pilihsubmenu != 10);
    return 0;
}

// Definisi fungsi (Fungsi diletakkan di bawah fungsi main)
// Fungsi pilihmenu == 1 
// Fungsi pilihsubmenu == 1. Fungsi menerima input dari pengguna.
void tambahlayanan() {
	system("cls");
    system("color 02");
    int kodelayanan;
    int ruangantersedia1;
    char namalayanan[50];
	fflush(stdin);
	printf("----------------------------------------------\n");
	printf("      (1.1) Menambah Layanan Kecantikan\n");
	printf("----------------------------------------------\n");
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
    system("color 02");
	Layanan *current;
   	char namalayananbaru[50];
   	int num, ruangantersedia;
	system("cls");
	
	printf("----------------------------------------------\n");
	printf("     (1.2) Memperbarui Layanan Kecantikan\n");
	printf("----------------------------------------------\n");

	printf("Masukkan kode layanan yang ingin diubah: ");		
	scanf("%d", &num); 
	fflush(stdin);
	
	// head = newnode;
    // Kondisi apabila pengguna belum memasukkan/menghapus input pada pilihsubmenu == 1
	if(head==NULL) {
        system("color 04");
        printf("----------------------------------------------\n");
		printf("              List Masih Kosong\n"); 
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
	        printf("----------------------------------------------\n");
	 		printf("Masukkan nama layanan: ");
            // Memasukkan nama layanan baru
	      	scanf("%s", &namalayananbaru);
            // Menyalin string namalayanan dari input nama layanan baru ke anggota struct "namalayanan" sehingga string namalayanan memiliki nilai string baru.
	      	strcpy(current->namalayanan, namalayananbaru);
	      	printf("Jumlah ruangan yang tersedia: ");
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
    printf("----------------------------------------------\n");
    system("color 04");
	printf("  Kode layanan %d tidak berada di dalam list", num);
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
        system("color 04");
        printf("----------------------------------------------\n");
        printf("  (1.3) Melihat informasi Layanan Kecantikan\n");
        printf("----------------------------------------------\n");
        // Jika belum memasukkan/menghapus masukan input (Bernilai NULL)
        printf("  Tidak ada informasi layanan yang tersedia\n");
    }
    else { 
        printf("----------------------------------------------\n");
        printf("  (1.3) Melihat informasi Layanan Kecantikan\n");
        printf("----------------------------------------------\n");
        // Mengubah pointer head menjadi lihat untuk menunjuk ke node baru (newnode). 
        lihat = head; 
            
        while(lihat != NULL) { 
            // Fungsi akan terus mengeluarkan detail layanan sebanyak-banyaknya hingga mencapai akhir dari input pengguna
            printf("Kode Layanan: %d\n", lihat->kodelayanan);
            printf("Nama Layanan: %s\n", lihat->namalayanan);
            printf("Ruangan Tersedia: %d\n", lihat->ruangantersedia);
            printf("----------------------------------------------\n");
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
    system("color 04");
    // Menginisialisasi variabel pointer temp dengan nilai NULL
    Layanan *temp = NULL;
    int num;
	
	printf("----------------------------------------------\n");
    printf("      (1.4) Menghapus Layanan Kecantikan\n");
	printf("----------------------------------------------\n");
	printf("Masukkan kode layanan yang ingin dihapus: ");		
	scanf("%d", &num);

	// head = newnode;
    // Kondisi apabila pengguna belum memasukkan/menghapus input pada pilihsubmenu == 1
	if(head==NULL) {
    	printf("----------------------------------------------\n");
		printf("              List masih kosong");
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
    system("color 02");
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
        system("color 04");
        printf("----------------------------------------------\n");
        printf("    (1.5) Melihat Detail Layanan Kecantikan\n");
        printf("----------------------------------------------\n");
        // Jika belum memasukkan/menghapus masukan input (Bernilai NULL)
        printf("            Detail layanan kosong\n");
    }
	else {
        printf("----------------------------------------------\n");
        printf("    (1.5) Melihat Detail Layanan Kecantikan\n");
        printf("----------------------------------------------\n");
        printf("Kode Layanan        Nama Layanan\n");
        // Mengubah pointer head menjadi detail untuk menunjuk ke node baru (newnode). 
    	detail = head; 
        
		while(detail != NULL) { 
            // Fungsi akan terus mengeluarkan daftar kode layanan beserta nama layanannya sebanyak-banyaknya hingga mencapai akhir dari input pengguna
        	printf("    (%d)             %s\n", detail->kodelayanan, detail->namalayanan);
            // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
            detail = detail->next; 
		}

        printf("---------------------------------------------------\n");
		printf("Masukkan kode layanan yang ingin dilihat detailnya: \n");
		scanf("%d", &search_detail);
        // Mengubah pointer head menjadi letak untuk menunjuk ke node baru (newnode) pada fungsi masuklayanan().
        // Mengubah pointer head1 menjadi letak untuk menunjuk ke node baru (newnode) pada fungsi masukpemesanan().
		letak = head;
		lihat = head1;
		while(letak!=NULL) {
            // Selama node tidak kosong, fungsi akan terus memeriksa node dalam linked list 
			if(search_detail==letak->kodelayanan) {
                printf("---------------------------------------------------\n");
                // Fungsi akan mengeluarkan detail layanan berdasarkan kodelayanan yang sesuai dengan input pengguna
                printf("Kode Layanan		: %d\n", letak->kodelayanan);
        		printf("Nama Layanan		: %s\n", letak->namalayanan);
        		printf("Ruangan Tersedia	: %d\n", letak->ruangantersedia);
                
				while (lihat != NULL) {
                    // Selama node tidak kosong, fungsi akan terus memeriksa node dalam linked list
                    // Jika kodelayanan sesuai
					if(letak->kodelayanan == lihat->kodelayanan) {
                        printf("---------------------------------------------------\n");
                        // Menghasilkan keluaran nama-nama pemesan layanan tersebut berdasarkan kode layanan
						printf("Nama Pemesan 	: %s \n", lihat->nama);
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
                    system("color 04");
                    printf("---------------------------------------------------\n");
					printf("               Layanan belum dipesan");
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
    system("color 02");
    int kodelayanan, no_kamar, tanggal, bulan, tahun;
    char namapemesan[50], namalayanan[40];
	fflush(stdin);
    printf("--------------------------------------------------\n");
	printf("        Buat Pemesanan Layanan Kecantikan\n");
    printf("--------------------------------------------------\n");
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

	masukpemesanan(kodelayanan, no_kamar, tanggal, bulan, tahun, namapemesan, namalayanan);
	getch();
    system("cls");
}

// Fungsi dengan 8 parameter, menerima nilai yang diteruskan dari fungsi tambahpemesanan()
void masukpemesanan(int kodelayanan, int no_kamar,int tanggal,int bulan,int tahun,char namapemesan[],char namalayanan[]) {
    // Membuat node baru menggunakan malloc() untuk mengalokasikan memori dengan ukuran sizeof(Pemesanan) (struct Pemesanan)
    // newnode = alamat memori yang dialokasikan untuk node baru dan disimpan dalam variabel newnode
    Pemesanan* newnode = (Pemesanan*)malloc(sizeof(Pemesanan)); 
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
void lihatpemesanan() {
    // Deklarasi variabel pointer lihat dengan tipe data struct Pemesanan
	Pemesanan* lihat;
	system("cls"); 
    system("color 02");
    // Kondisi memeriksa pointer ke node apakah pengguna sudah memasukkan input pada pilihmenu == 2 && pilihsubmenu == 1
	if (head1 == NULL) {
        system("color 04");
        printf("--------------------------------------------------\n");
		printf(" (2.2) Lihat Daftar Pemesanan Layanan Kecantikan\n");
        printf("--------------------------------------------------\n");
		printf ("     Tidak ada pemesanan Layanan kecantikan ");
	}
	else {
        printf("--------------------------------------------------\n");
		printf(" (2.2) Lihat Daftar Pemesanan Layanan Kecantikan\n");
        printf("--------------------------------------------------\n");
        // Mengubah pointer head menjadi detail untuk menunjuk ke node baru (newnode). 
		lihat = head1;
		while (lihat!= NULL) {
            // Fungsi akan terus mengeluarkan daftar detail pesanan sampai akhir input pengguna
			printf("Nama Pemesan: %s\n", lihat->nama);
			printf("Kode Layanan: %d\n", lihat->kodelayanan);
			printf("Nama Layanan: %s\n", lihat->namalayanan);
			printf("Jumlah Layanan: %d\n", lihat->no_kamar);
			printf("Tanggal Pesan: %d\n", lihat->tanggal);
			printf("Bulan: %d\n", lihat->bulan);
			printf("Tahun: %d\n", lihat->tahun); 
            printf("--------------------------------------------------\n");
            // Menggunakan perulangan while untuk melanjutkan pengecekan node berikutnya hingga akhir dari input pengguna
			lihat = lihat->next;
		}
	}
    getch(); 
    system("cls");
}

// Fungsi pilihmenu == 3
void lihatantrian() {
    system("cls");
    system("color 05");
	printf("----------------------------------------------------------------------------------------------------------------\n");
    printf("                                    (3.1) Daftar Antrian Layanan Kecantikan\n");
	printf("----------------------------------------------------------------------------------------------------------------\n");

    // Check if the queue is empty
    if (head1 == NULL) {
        system("color 04");
        printf("                                            Tidak ada antrian\n");
        getch();
        return;
    }

    Pemesanan* current = head1;
    int counter = 1;

    printf("No. |                     Nama                     | Kode Layanan | Nama Layanan | No. Kamar | Tanggal Pemesanan\n");
	printf("----------------------------------------------------------------------------------------------------------------\n");

    while (current != NULL) {
    printf(" %d     %s                                                %d            %s             %d          %02d-%02d-%04d\n", counter, current->nama, current->kodelayanan, current->namalayanan, current->no_kamar, current->tanggal, current->bulan, current->tahun);
        current = current->next;
        counter++;
    }
    getch();
}

void hapusantrian() {
    system("cls");
    system("color 04");
    printf("----------------------------------------------\n");
    printf("         (3.2) Hapus Daftar Antrian\n");
    printf("----------------------------------------------\n");

    // Check if the queue is empty
    if (head1 == NULL) {
        printf("          Tidak ada daftar antrian\n");
        getch();
        return;
    }

    int position;
    printf("Masukkan nomor antrian yang ingin dihapus: ");
    scanf("%d", &position);

    if (position < 1) {
        printf("Nomor antrian tidak valid.\n");
        getch();
        return;
    }

    // Special case: Deleting the first node
    if (position == 1) {
        system("color 02");
        Pemesanan* temp = head1;
        head1 = head1->next;
        free(temp);
        printf("Antrian berhasil dihapus.\n");
        getch();
        return;
    }

    // Traverse to the node before the position
    Pemesanan* current = head1;
    int counter = 1;
    while (counter < position - 1 && current != NULL) {
        current = current->next;
        counter++;
    }

    // Check if position is out of range
    if (current == NULL || current->next == NULL) {
        printf("Nomor antrian tidak valid.\n");
        getch();
        return;
    }

    // Delete the node at the given position
    Pemesanan* temp = current->next;
    current->next = temp->next;
    free(temp);
    system("color 02");
    printf("----------------------------------------------\n");
    printf("Antrian berhasil dihapus.\n");
    getch();
}