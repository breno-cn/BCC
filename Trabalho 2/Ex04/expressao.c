#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pilha.h"
#include "fila.h"

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
	int x=0, num1, num2, op, flag=0;
	pilha p=cria_pilha();
	fila sinal=cria_fila();
	for(int i=0;s[i]!='\0';i++){
		if(s[i]>='A' && s[i]<='J') push(&p,lit[s[i]-'A']);
		if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'
		 || s[i]=='^'){
			insere_fim(sinal,s[i]);
			}
	}
	while(!fila_vazia(sinal)){
		if(!flag){
			remove_ini(sinal, &op);
			pop(&p,&num2);
			pop(&p,&num1);
			if(op=='+') x+=num1+num2;
			if(op=='-') x+=num1-num2;
			if(op=='*') x+=num1*num2;
			if(op=='/') x+=num1/num2;
			if(op=='^') x+=pow(num1,num2);
			flag=1;
		}
		if(flag){
			remove_ini(sinal,&op);
			pop(&p,&num1);
			if(op=='+') x+=num1;
			if(op=='-') x-=num1;
			if(op=='*') x*=num1;
			if(op=='/') x/=num1;
			if(op=='^') x=pow(num1,x);
		}
	}
	return x;
}