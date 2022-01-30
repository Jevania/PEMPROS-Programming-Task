## String

Pada sesi ini anda diminta untuk menyelesaikan dua buah persoalan yang akan melatih imajinasi serta kemampuan anda dalam memanipulasi string. Pada dasarnya string adalah a sequence of char-typed values yang diakhiri dengan ```\0```. Karakteristik string memungkinkan array digunakan sebagai media penyimpanan string.

Untuk dapat menyelesaikan kedua persoalan berikut, anda harus memiliki penguasaan yang baik terhadap konsep Memory Allocation, dan Array.

### Task 01: Icarus Message (score: 40pts; file : t03_01.c)
Icarus Message adalah teks yang penulisannya menggunakan nilai ASCII (desimal) dari setiap karakter penyusunnya. Setiap nilai ASCII pada Icarus Message ditulis dalam tiga digit.

Tugas anda adalah menuliskan sebuah program yang akan membaca Icarus Message dalam bentuk sebaris masukan berupa string (```str```) dari ```stdin``` dengan panjang minimum 3 karakter dan maksimum 60 karakter, ```strlen(str) -> 3 ... 60```. String berisi karakter-karakter numerik, yang setiap tiga karakternya merupakan nilai desimal dari suatu karakter ASCII. Ketika karakter-karakter ASCII tersebut digabungkan akan terbentuk pesan Icarus. Tugas anda adalah menampilkan pesan Icarus tersebut ke ```stdout``` dalam satu baris keluaran. Untuk membantu anda memahami persoalan, perhatikan contoh berikut dengan seksama.

Diberikan sebuah baris masukan (string) dengan panjang maksimum 60.
```
099105104117121033
```
Jika didekomposisi, untuk setiap tiga karakter adalah nilai desimal dari karakter ASCII, maka:
1. tiga karakter pertama "099" adalah nilai ASCII dari karakter 'c';
2. tiga karakter berikutnya "105" adalah nilai ASCII dari karakter 'i';
3. tiga karakter berikutnya "104" adalah nilai ASCII dari karakter 'h';
4. tiga karakter berikutnya "117" adalah nilai ASCII dari karakter 'u';
5. tiga karakter berikutnya "121" adalah nilai ASCII dari karakter 'y'; dan
6. tiga karakter terakhir "033" adalah nilai ASCII dari karakter '!'.

Selanjutnya, jika digabungkan maka pesan Icarus yang diperoleh adalah ```"cihuy!"```.

#### Example 1
Input
```
089111117044032109101044032038032067

```
Output
```
You, me, & C

```
#### Example 2
Input
```
074117115116052067111100101

```
Output
```
Just4Code

```

### Task 02: Icarus Messanger (score: 60pts; file : t03_02.c)
Turikul dan Ucok, dua sahabat sejati, baru saja menyelesaikan sebuah program untuk membaca dan menerjemahkan Icarus Message (t03_01). Turikul dam Ucok berencana untuk mengembangkan sebuah program lainnya yang akan membaca sebuah teks dan menerjemahkannya ke bentuk Icarus Message. Belum rencana ini terwujud, Turikul sudah dipanggil pulang oleh opungnya. Beruntung pada saat yang bersamaan Butet datang dan menawarkan diri untuk membantu Ucok merealisasikan rencana Turikul. Ucok menyetujui ide tersebut dan mereka pun mulai bekerja.

Program akan menerima sebaris teks (```str```) dari ```stdin``` dengan panjang minimum 1 karakter dan maksimum 20 karakter. Untuk setiap karakter pada teks kemudian dikonversi menjadi nilai ASCII (desimal) untuk selanjutnya ditampilkan dalam satu baris keluaran ke ```stdout```. Nilai ASCII (desimal) ditulis dalam tiga digit. Perhatikan ilustrasi berikut.

Program akan membaca sebaris masukan (```str```) dari ```stdin``` dengan panjang 1 s.d. 20.
```
Big O

```
Selanjutnya, program akan mengkonversi setiap karakter menjadi nilai ASCII (desimal) dalam tiga digit.
1. karakter pertama 'B' dikonversi menjadi 066 sesuai dengan nilai ASCIInya yang ditulis dalam tiga digit;
2. karakter berikutnya 'i' dikonversi menjadi 105 sesuai dengan nilai ASCIInya yang ditulis dalam tiga digit;
3. karakter berikutnya 'g' dikonversi menjadi 103 sesuai dengan nilai ASCIInya yang ditulis dalam tiga digit;
4. karakter berikutnya ' ' dikonversi menjadi 032 sesuai dengan nilai ASCIInya yang ditulis dalam tiga digit; dan
5. karakter terakhir 'O' dikonversi menjadi 079 sesuai dengan nilai ASCIInya yang ditulis dalam tiga digit.

Dengan demikian, Icarus Message yang terbentuk dan ditampilak dalam satu baris keluaran ke ```stdout``` adalah
```
066105103032079

```

#### Example 1
Input
```
Jaka Sembung

```
Output
```
074097107097032083101109098117110103

```
#### Example 2
Input
```
c_total=blackscreen

```
Output
```
099095116111116097108061098108097099107115099114101101110

```

## Submission
1. t03_01.c
2. t03_02.c
3. changelog.txt

## How to submit?
Please see https://youtu.be/g0BQ195-aWo