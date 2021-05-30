#include <stdio.h>
#include <stdlib.h>

struct node {
	char english_word[30];
	char spanish_word[30];
	struct node *engleft, *engright, *engparent;
	struct node *spanleft, *spanright, *spanparent;
};

struct node* newNodeEng(char * item, char *itemspan) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	strcpy(temp->english_word, item);
	temp->engleft = temp->engright = NULL;
	temp->spanleft = temp->spanright = NULL;
	temp->engparent = temp->spanparent = NULL;
	return temp;
}

struct node* newNodeSpanish(char * item, char * item2) {
	struct node* temp = (struct node*)malloc(sizeof(struct node));
	strcpy(temp->spanish_word, item);
	strcpy(temp->english_word, item2);
	temp->engleft = temp->engright = NULL;
	temp->spanleft = temp->spanright = NULL;
	temp->engparent = temp->spanparent = NULL;
	return temp;
}

struct node* insertenglish(struct node* node, char * words, char * words2) {
	if (node == NULL) {
		return newNodeEng(words, words2);
	}
	if (words[0] < node->english_word[0]) {
		node->engleft = insertenglish(node->engleft, words, words2);
		node->engleft->engparent = node;
	}
	else if (words[0] > node->english_word[0]) {
		node->engright = insertenglish(node->engright, words, words2);
		node->engright->engparent = node;
	}
	else if (words[1] < node->english_word[1]) {
		node->engleft = insertenglish(node->engleft, words, words2);
		node->engleft->engparent = node;
	}
	else if (words[1] > node->english_word[1]) {
		node->engright = insertenglish(node->engright, words, words2);
		node->engright->engparent = node;
	}
	return node;
}

struct node* insertspanish(struct node* node, char * words, char * words2) {
	if (node == NULL)
		return newNodeSpanish(words, words2);
	if (words[0] < node->spanish_word[0]) {
		node->spanleft = insertspanish(node->spanleft, words, words2);
	}
	else if (words[0] > node->spanish_word[0]) {
		node->spanright = insertspanish(node->spanright, words, words2);
	}
	else if (words[1] < node->spanish_word[1]) {
		node->spanleft = insertspanish(node->spanleft, words, words2);
	}
	else if (words[1] > node->spanish_word[1]) {
		node->spanright = insertspanish(node->spanright, words, words2);
	}
	return node;
}

struct node* searchEnglish(struct node* root, char * words, char * words2) {
	if (root == NULL || strcmp(root->english_word, words) == 0) {
		if (root != NULL) {
			strcpy(root->spanish_word, words2);
		}
		return root;
	}
	else if (root->english_word[0] < words[0]) {
		return searchEnglish(root->engright, words, words2);
	}
	else if (root->english_word[0] > words[0]) {
		return searchEnglish(root->engleft, words, words2);
	}
	else if (root->english_word[1] > words[1]) {
		return searchEnglish(root->engleft, words, words2);
	}
	else if (root->english_word[1] < words[1]) {
		return searchEnglish(root->engright, words, words2);	
	}
}
char w[30];
int flag = 1;
struct node* searchSpanish(struct node* root, char * words) {
	if (root == NULL)
		return;
	if (flag == 1) {
		if (strcmp(root->spanish_word, words) == 0 ) {
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp = root;
			if (temp->spanparent != NULL)
				printf("The parent node in spanish is: %s/%s\n", temp->spanparent->spanish_word, temp->spanparent->english_word);
			if (temp->engparent != NULL)
				printf("The parent node in english is: %s/%s\n", temp->engparent->spanish_word, temp->engparent->english_word);
			if (temp->spanleft != NULL)
				printf("The left child in spanish is: %s/%s\n", temp->spanleft->spanish_word, temp->spanleft->english_word);
			if (temp->spanright != NULL)
				printf("The right child in spanish is: %s/%s\n", temp->spanright->spanish_word, temp->spanright->english_word);
			if (temp->engleft != NULL)
				printf("The left child in english is: %s/%s\n", temp->engleft->spanish_word, temp->engleft->english_word);
			if (temp->engright != NULL)
				printf("The right child in english is: %s/%s\n", temp->engright->spanish_word, temp->engright->english_word);
			flag = 0;
			strcpy(w, temp->english_word);
		}
	}
	searchSpanish(root->spanleft, words);
	searchSpanish(root->spanright, words);
}

struct node* searchEnglishWord(struct node* root, char * words) {
	if (root == NULL)
		return;
	if (flag == 1) {
		if (strcmp(root->english_word, words) == 0) {
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp = root;
			if (temp->spanparent != NULL)
				printf("The parent node in spanish is: %s/%s\n", temp->spanparent->spanish_word, temp->spanparent->english_word);
			if (temp->engparent != NULL)
				printf("The parent node in english is: %s/%s\n", temp->engparent->spanish_word, temp->engparent->english_word);
			if (temp->spanleft != NULL)
				printf("The left child in spanish is: %s/%s\n", temp->spanleft->spanish_word, temp->spanleft->english_word);
			if (temp->spanright != NULL)
				printf("The right child in spanish is: %s/%s\n", temp->spanright->spanish_word, temp->spanright->english_word);
			if (temp->engleft != NULL)
				printf("The left child in english is: %s/%s\n", temp->engleft->spanish_word, temp->engleft->english_word);
			if (temp->engright != NULL)
				printf("The right child in english is: %s/%s\n", temp->engright->spanish_word, temp->engright->english_word);
			flag = 0;
			strcpy(w, temp->spanish_word);
		}
	}
	searchEnglishWord(root->engleft, words);
	searchEnglishWord(root->engright, words);
}

void sorting(struct node* node, struct node* head) {
	if (node == NULL)
		return;
	if (node->spanleft != NULL) {
		node->spanleft->spanparent = node;
	}
	if (node->spanright != NULL) {
		node->spanright->spanparent = node;
	}
	sorting(node->spanleft, head);
	sorting(node->spanright, head);
	node = searchEnglish(head, node->english_word, node->spanish_word);
}

struct node* readFile(struct node * head) {
	FILE * fptr;
	char eng[30];
	char spanish[30];
	int count = 0;
	if ((fptr = fopen("translator.in", "r")) == NULL) {
		printf("File Not Open!\n");
	}
	while (fscanf(fptr, "%s %s\n", &spanish, &eng) == 2) {
		if (count == 0) {
			head = insertenglish(head, eng, spanish);
		}
		else {
			insertenglish(head, eng, spanish);
		}
		count++;
	}
	fclose(fptr);
	count = 0;
	FILE * fptr2;
	if ((fptr2 = fopen("translator.in", "r")) == NULL) {
		printf("File Not Open!\n");
	}
	while (fscanf(fptr, "%s %s\n", &spanish, &eng) == 2) {
		insertspanish(head, spanish, eng);
		count++;
	}
	sorting(head, head);
	fclose(fptr2);
	return head;
}

int main() {
	struct node * head = NULL;
	head = readFile(head);
	printf("Please Enter 1 for Spanish Word and 2 for English word\n 0 for Exit\n");
	char input[20];
	gets(input);
	char words[30];
	while (atoi(input) != 0) {
		if (atoi(input) == 1) {
			printf("Please Enter the words\n");
			gets(words);
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp = searchSpanish(head, words);
			flag = 1;
			temp = searchEnglishWord(head, w);
			flag = 1;
		}
		else if (atoi(input) == 2) {
			printf("Please Enter the words\n");
			gets(words);
			struct node* temp = (struct node*)malloc(sizeof(struct node));
			temp = searchEnglishWord(head, words);
			flag = 1;
			temp = searchSpanish(head, w);
			flag = 1;
		}
		printf("Please Enter 1 for Spanish Word and 2 for English word\n 0 for Exit \n");
		gets(input);
	}
	return 0;
}
