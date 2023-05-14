#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Assalamualaikum\n");
    printf("Selamat datang di Bank MCA syariah \n");
    printf("Silahkan masukkan kartu ATM anda\n");
    printf("==============================\n");
  
    // Inisialisasi PIN awal
    int pin = 11;
    // Inisialisasi saldo awal
    float balance = 50;
    // Inisialisasi variabel-variabel lain yang dibutuhkan
    int choice, login_attempt = 0;
    int transfer_account_number;
    int id_pelanggan;
    int nomor_ponsel;
    float transfer_amount, top_up_dana, top_up_gopay, token_listrik, isi_pulsa,top_up_ovo, withdrawal_amount;

    // Loop while untuk mengulang login hingga maksimal 3 kali percobaan
    while (login_attempt < 3) {
        // Meminta pengguna memasukkan PIN
        int input_pin;
        printf("Masukkan PIN anda: ");
        scanf("%d", &input_pin);
        
        // Jika PIN benar, tampilkan menu opsi
        if (input_pin == pin) {
            printf("Login berhasil!\n");
            while (1) {
                printf("\nMenu Transaksi\n");
                printf("1. Info Saldo\n");
                printf("2. Setor Tunai\n");
                printf("3. Tarik Tunai\n");
                printf("4. Transfer\n");
                printf("5. Top Up\n");
                printf("6. Logout\n");
                printf("Pilih Transaksi: ");
                scanf("%d", &choice);
                
                // Switch case untuk setiap opsi pada menu
                switch (choice) {
                    case 1:
                        printf("Saldo anda: %.2f\n", balance);
                        break;
                    case 2:
                        printf("Masukkan jumlah deposit: ");
                        float deposit_amount;
                        scanf("%f", &deposit_amount);
                        balance += deposit_amount;
                        printf("Setor Tunai berhasil. Saldo anda: %.2f\n", balance);
                        break;
                    case 3:
                        printf("Masukkan jumalh Tarik Tunai: ");
                        scanf("%f", &withdrawal_amount);
                        if (withdrawal_amount > balance) {
                            printf("Maaf saldo anda tidak mencukupi.\n");
                        } else {
                            balance -= withdrawal_amount;
                            printf("Transaksi berhasil. Sisa saldo anda: %.2f\n", balance);
                        }
                        break;
                    case 4:
                        printf("Masukkan No rekening tujuan: ");
                        scanf("%d", &transfer_account_number);
                        printf("Masukkan jumlah transfer: ");
                        scanf("%f", &transfer_amount);
                        if (transfer_amount > balance){
                            printf("Maaf saldo anda tidak mencukupi.\n");
                        } else {
                            balance -= transfer_amount;
                            printf("Transaksi berhasil. sisa saldo anda: %.2f\n", balance);
                        }
                        break;
                    case 5:
                        printf("Top up menu\n");
                        printf("1. Top up Dana\n");
                        printf("2. Top up Gopay\n");
                        printf("3. Token Listrik\n");
                        printf("4. Top up Ovo\n");
                        printf("5. Isi Pulsa\n");
                        printf("Pilih transaksi: ");
                        int top_up_choice;
                        scanf("%d", &top_up_choice);
                        switch (top_up_choice) {
                            case 1:
                            printf("Masukkan No ponsel : ");
                            scanf("%d", &nomor_ponsel);
                            printf("Masukkan jumlah top up : ");
                            scanf("%f", &top_up_dana);
                            if (top_up_dana > balance){
                            printf("Maaf saldo anda tidak mencukupi.\n");

} else {
                            balance -= top_up_dana;
                            printf("Transaksi berhasil. sisa saldo anda: %.2f\n", balance);
                        }
                                break;
                            case 2:
                             printf("Masukkan No ponsel : ");
                            scanf("%d", &nomor_ponsel);
                            printf("Masukkan jumlah top up : ");
                            scanf("%f", &top_up_gopay);
                            if (top_up_gopay > balance){
                            printf("Maaf saldo anda tidak mencukupi.\n");
                            } else {
                            balance -= top_up_gopay;
                            printf("Transaksi berhasil. sisa saldo anda: %.2f\n", balance);
                        }
                                break;
                            case 3:
                             printf("Masukkan No id pelanggan: ");
                        scanf("%d", &id_pelanggan);
                                printf("Masukkan jumlah top up: ");
                                scanf("%f", &token_listrik);
                                if (token_listrik > balance){
                            printf("Maaf saldo anda tidak mencukupi.\n");
                            } else {
                            balance -= token_listrik;
                            printf("Transaksi berhasil. sisa saldo anda: %.2f\n", balance);
                        }
                                break;   
                              case 4:
                               printf("Masukkan No ponsel anda: ");
                        scanf("%d", &nomor_ponsel);
                                printf("Masukkan jumlah top up: ");
                                scanf("%f", &top_up_ovo);
                                 if (top_up_gopay > balance){
                            printf("Maaf saldo anda tidak mencukupi.\n");
                            } else {
                            balance -= top_up_ovo;
                            printf("Transaksi berhasil. sisa saldo anda: %.2f\n", balance);
                        }
                                break;  
                              case 5:
                              printf("Masukkan No ponsel anda: ");
                        scanf("%d", &nomor_ponsel);
                                printf("Masukkan jumlah  top up: ");
                                scanf("%f", &isi_pulsa);
                              
                                 if (isi_pulsa > balance){
                            printf("Maaf saldo anda tidak mencukupi.\n");
                            } else {
                            balance -= isi_pulsa;
                            printf("Transaksi berhasil. sisa saldo anda: %.2f\n", balance);
                        }
                                break;
                            default:
                                printf("Invalid option.\n");
                                break;
                        }
                        break;
                    case 6:
                        // Keluar dari menu dan kembali ke menu login
                        printf("Logout successful.\n");
                        login_attempt = 3;
                        break;
                    default:
                        printf("Invalid option.\n");
                        break;
                }
            }
        } else {
            // Jika PIN salah, tampilkan pesan error dan tingkatkan jumlah percobaan
            printf("PIN salah. Silahkan coba lagi.\n");
            login_attempt++;
        }
    }
    // Jika sudah 3 kali percobaan login dan masih gagal, keluar dari program
    if (login_attempt == 3) {
        printf("Melampaui batas PIN Salah. ATM dikunci.\n");
    }
    return 0;
}