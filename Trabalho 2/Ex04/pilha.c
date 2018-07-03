#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pilha.h"

struct Pilha{
	int info;
	struct Pilha *prox;
};

pilha cria_pilha(){
	return NULL;
}

int pilha_vazia(pilha p){
	return !p;
}

int push(pilha *p, int x){
	pilha aux=(pilha)malloc(sizeof(struct Pilha));
	if(aux==NULL) return 0;
	aux->info=x;
	aux->prox=*p;
	*p=aux;
	return 1;
}

int pop(pilha *p, int *x){
	if(pilha_vazia(*p)) return 0;
	pilha aux=*p;
	*x=aux->info;
	*p=(*p)->prox;
	free(aux);
	return 1;
}

int ler_topo(pilha p, int *x){
	if(pilha_vazia(p)) return 0;
	*x=p->info;
	return 1;
}

int print(pilha p){
	if(p==NULL) return 0;
	for(pilha aux=p;aux!=NULL;aux=aux->prox)
		printf("%d\n", aux->info);
	return 1;
}

int escopo_valido(const char *s){
    int x=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(') x++;
        if(s[i]==')') x--;
        if(x<0) return false;
    }
	if(x>0) return false;
    return true;
}

// int pesquisa(pilha p, int c){
//     if(pilha_vazia(p)) return false;
//     for(pilha aux=p;aux!=NULL;aux=aux->prox)
//         if(aux->info==c) return true;
//     return false;
// }

// int cont_literais(const char *s){
//     int x=0;
//     pilha p=cria_pilha();
//     for(int i=0;s[i]!='\0';i++){
//         if(s[i]>='A' && s[i]<='J'){
//             if(!pesquisa(p,s[i])){
//                 push(&p,s[i]);
//                 x++;
//             }
//         }
//     }
//     return x;
// }

int infixa_posfixa(const char *inf, char *pos){
	if(inf==NULL || pos==NULL) return 0;
	int x,j=0;
	pilha p=cria_pilha();
	for(int i=0;inf[i]!='\0';i++){
        if(inf[i]==')'){
			if(!pop(&p,&x)) return 0;
			pos[j++]=x;
			pos[j++]=')';
		}
		else if(inf[i]=='+' || inf[i]=='-' || inf[i]=='*' 
        || inf[i]=='/' || inf[i]=='^'){
			push(&p,inf[i]);		
		}
		else pos[j++]=inf[i];
	}
	pos[j]='\0';
	return 1;
}

int resultado_pos(const char *s, int *lit){
	if(s==NULL || lit==NULL) return 0;
	pilha p=cria_pilha(), pos=cria_pilha();
	int x=0,num1,num2,p1,p2;
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='A' && s[i]<='J'){
			push(&p,lit[s[i]-'A']);
			push(&pos,i);
		}
		if(s[i]=='+'){
			pop(&pos,&p2);
			pop(&pos,&p1);
			x+=lit[s[p1]-'A']+lit[s[p2]-'A'];
			// pop(&p,&num2);
			// pop(&p,&num1);
			// x+=num1+num2;
			// printf("num1: %d\nnum2: %d\nx: %d\n\n", num1,num2,x);
		} 
		if(s[i]=='-'){
			pop(&p,&num1);
			pop(&p,&num2);
			x+=num2-num1;
			printf("num1: %d\nnum2: %d\nx: %d\n\n", num1,num2,x);
		}
		if(s[i]=='*'){
			pop(&p,&num1);
			pop(&p,&num2);
			x+=num2*num1;
			printf("num1: %d\nnum2: %d\nx: %d\n\n", num1,num2,x);
		}
		if(s[i]=='/'){
			pop(&p,&num1);
			pop(&p,&num2);
			x+=num2/num1;
			printf("num1: %d\nnum2: %d\nx: %d\n\n", num1,num2,x);
		}
		if(s[i]=='^'){
			pop(&p,&num1);
			pop(&p,&num2);
			x+=pow(num2,num1);
			printf("num1: %d\nnum2: %d\nx: %d\n\n", num1,num2,x);
		}
	}
	return x;
}

// int resultado_pos(const char *s, int *lit, int n){
// 	if(s==NULL || lit==NULL) return 0;
// 	int x=0, num1, num2;
// 	pilha p=cria_pilha();
// 	for(int i=0;s[i]!='\0';i++){
// 		if(s[i]>='A' && s[i]<='J'){
// 			push(&p,lit[s[i]-'A']);
// 			printf("literal: %c vale %d\n", s[i], lit[s[i]-'A']);
// 		}
// 		if(s[i]=='+'){
// 			pop(&p,&num2);
// 			pop(&p,&num1);
// 			// x+=num1+num2;
// 			x+= (n==2) ? num1+num2 : num1;
// 			printf("num1=%d\n", num1);
// 			printf("num2=%d\n", num2);
// 			printf("X=%d\n", x);
// 			// x+= (!x) ? num2 : num1+num2;
// 		}
// 	}
// 	return x;
// }