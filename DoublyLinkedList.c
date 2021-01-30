#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>


struct node {
	int data;
	struct node* next;
	struct node* prev;
};
struct node* list = NULL;

//push fonksiyonu başa yeni eleman ekler listeyi oluşturmakta kullanılır.
void push(struct node** head, int item) {
	struct node *yeni = (struct node*)malloc(sizeof(struct node));
	yeni->data = item;
	yeni->next = (*head);
	yeni->prev = NULL;
	if (*head != NULL) {
		(*head)->prev = yeni;
	}
	(*head) = yeni;
}

void printList(struct node* head) {
	struct node* gecici = head;
	while (gecici != NULL) {
		printf("%d\t", gecici->data);
		gecici = gecici->next;
	}
}

// Düğüm değeri sonrası yeni düğüm ekleme fonksiyonu.
void ekle(int b) {
	struct node* yeni = (struct node*)malloc(sizeof(struct node));
	struct node* gecici = list;
	int c;
	printf("\nHangi dugum degerinden sonra eklensin= ");
	scanf("%d", &c);

	do{
						
		if (gecici->data == c) {
			yeni->data = b;
			yeni->next = gecici->next;
			if(gecici->next!=NULL) //Son elemandan sonrası için if yazdım.
				yeni->next->prev = yeni;
			gecici->next = yeni;
			yeni->prev = gecici;
			printf("\nYeni olusan liste:\n");
	        printList(list); //yeni listeyi görüntülemek için ekledim.
			break;
		}
		gecici=gecici->next;
		
		if(gecici->next == NULL && gecici->data != c){ //Girilen deger listede yok ise bu koşul çalışır.
			printf("\nHatali Giris! Boyle bir dugum degeri yok!");
			break;
			getch();
		}
				  
	}while(gecici != NULL);
}

int main() {

	int a, b, n;
	srand(time(NULL));
	
	printf("Dugum Sayisi Giriniz: ");
	scanf("%d", &a);
	
	for (int i = 0; i < a; i++) {
		n = rand() % 500;       //Random sayılar üretip push fonksiyonuna random sayıları yolladım.
		push(&list, n);
	}
	
	printList(list);
	printf("\n\nEklemek Istenen Deger= ");
	scanf("%d", &b);
	
	ekle(b);
	
	printf("\n\nDurdurmak icin bir tusa basin...");
    getch();

}
