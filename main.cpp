#include <iostream>
#define MAXTAM 4
using namespace std;
//const int MAXTAM=25;
struct lista{
    int vet[MAXTAM];
    int tam;
    int primeiro;
    int ultimo;
};
char menu() {
    char c;
    cout << "\nopcoes: " <<endl;
    cout << "i: inserir" <<endl;
    cout << "m: mostrar" << endl;
    cout << "p: insere p=0"<<endl;
    cout << "q: insere na posição desejada"<<endl;
    cout << "s: sair"<<endl;
    cout << "\nEntre com sua opcao: ";
    cin >> c;
    return c;
}

int main(){
    lista l;
    char opcao='N';
    //l.primeiro=0;
    l.tam=0;
    l.primeiro=0;
    l.ultimo=0;
    opcao = menu();
    while(opcao!='s') {
        switch(opcao) {
            case 'e': // excluir de qualquer posicao
            case 'E':
                if(l.tam>0) {
                    int pos;
                    do {
                        cout<< "Entre com a posicao: [1.." <<l.tam<<"]: ";
                        cin>>ws>>pos;
                    } while(pos <1 || pos>(l.tam));
                    for(int i=(pos);i<l.tam;i++){
                        l.vet[i-1]=l.vet[i];
                    }
                    l.tam--;
                }
                break;

            case 'i':
            case 'I':
                if(l.tam==0) {
                    l.primeiro=0;
                    l.ultimo=0;
                    cout<< "Entre com o numero: ";
                    cin>>ws>>l.vet[0];
                    l.tam=1;
                }else if(l.tam<MAXTAM) {
                    cout<< "Entre com o numero: ";
                    cin>>ws>>l.vet[(l.ultimo+1)%MAXTAM];
                    l.ultimo=(l.ultimo+1)%MAXTAM;
                    l.tam++;
                } else {
                    cout<< "Erro ao inserir, lista esta cheia!" << endl;
                }
                break;
            case 'm':
            case 'M':
                cout << endl;
                for(int i=0;i<l.tam;i++) {
                    if(i!=0)
                        cout << ' ';
                    cout<< l.vet[i];
                }
                cout << endl;
                break;
            case 'p': // inserir na primeira posicao
            case 'P':
                if(l.tam<MAXTAM) {
                    for(int i=l.tam;i>0;i--){
                        l.vet[i]=l.vet[i-1];
                    }
                    cout<< "Entre com o numero: ";
                    cin>>ws>>l.vet[0];
                    l.tam++;
                } else {
                    cout<< "Erro ao inserir, lista esta cheia!" << endl;
                }
                break;
            case 'q': // inserir qualquer posicao
            case 'Q':
                if(l.tam<MAXTAM) {
                    int pos;
                    do {
                        cout<< "Entre com a posicao: [1.." <<l.tam+1<<"]: ";
                        cin>>ws>>pos;
                    } while(pos <1 || pos>(l.tam+1));
                    for(int i=l.tam;i>(pos-1);i--){
                        l.vet[i]=l.vet[i-1];
                    }
                    cout<< "Entre com o numero: ";
                    cin>>l.vet[pos-1];
                    l.tam++;
                } else {
                    cout<< "Erro ao inserir, lista esta cheia!" << endl;
                }
                break;

            default:
                cout<<"opcao invalida" << endl;
        }
        opcao=menu();
    }
    return 0;
}
