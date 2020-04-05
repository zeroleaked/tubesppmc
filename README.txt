input: n (gram), input_text (file.txt), banyak_kata (jumlah kata yang perlu dicetak)

arrKata : array of words, disini gue tulis pake []

dictionary: arrKata* key, arrKata* value, int length
lookup table yang ada di naskah soal, dependen terhadap n
key			value
[to, be]	[or, just]
[be, or]	[just]

1. Baca file sebagai arrKata ('.'',' termasuk non-whitespace)
2. Bikin tabel kayak di naskah sebagai dictionary
3. ambil satu elemen dari keys untuk dijadikan awal (arrKata key) inisial
4. fungsi random:
		input: arrKata
		output: kata
	contoh:
		input: [I, see, a]
		output: see
		
5. Looping
	sampai banyak_kata sudah dicetak:
		arrKata value = lookup(key)
		kata_baru = random(value)
		hapus kata pertama key dan tambahkan kata_baru (ngegeser) | key = &key[1]
		
		[to,be] -> 'just' -> [to, be, just] -> [be, just]
		
		
Pembagian tugas
struct initialize, append, print buat debug,

Bagian konfigurasi: zir
	struct arrKata, dictionary
	fungsi:
		void initializeArrKata (arrKata *arr_kata) done
			output: *arr_kata
		void pushArrKata (arrKata arr_kata, char *kata) done
		void printArrKata (arrKata) done
		void freeArrKata (arrKata *ptr) done
		void initializeDictionary (dictionary *ptr)
		void pushDictionary (dictionary tabel_lookup, arrKata *key, arrKata *value)
		void printDictionary (dictionary tabel_lookup)
		void freeDictionary (dictionary *ptr)
		
Bagian input: habibi
	fungsi:
		void inputN (int *n)
		void inputBanyakKata (int *banyak_kata)
		void inputText (arrKata *input_text)
 		
Bagian dictionary: salman
	fungsi:
		void createDictionary (int n, arrKata input_text, dictionary *lookup_table)
			bikin dictionary:
				output: *lookup_table
		void lookupDictionary (dictionary lookup_table, arrKata key, arrKata *value)
			lookup:
				output: *value
			
Bagian pengacakan: mik
	fungsi:
		void randomKey (dictionary lookup_table, arrKata *random_key)
			ngambil arrKata key random dari dictionary:
				output: *random_key
		void randomWord (arrKata array_kata, char **kata_random)
			ngambil kata random dari arrKata:
				output: *kata_random
		
Bagian handling/flow: ken 
	looping nomor 5
	
	
repo github kita
main -	|- konfigurasi	-|- konfigurasi.h
	|
	|- input	-|- input.h
	|
	|- lookup	-|- lookup.h
	|
	|- pengacakan	-|- pengacakan.h
	|
	|- flow		-|- flow.h
	|
	|- main.c
